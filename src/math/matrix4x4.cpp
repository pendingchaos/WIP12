#include "math/matrix4x4.h"

#include "math/matrix3x3.h"
#include "math/quaternion.h"

#include <cmath>
#include <x86intrin.h>

Matrix4x4::Matrix4x4()
{
    float *m[4] = {data[0], data[1], data[2], data[3]};

    m[0][0] = 1.0f; m[1][0] = 0.0f; m[2][0] = 0.0f; m[3][0] = 0.0f;
    m[0][1] = 0.0f; m[1][1] = 1.0f; m[2][1] = 0.0f; m[3][1] = 0.0f;
    m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = 1.0f; m[3][2] = 0.0f;
    m[0][3] = 0.0f; m[1][3] = 0.0f; m[2][3] = 0.0f; m[3][3] = 1.0f;
}

Matrix4x4::Matrix4x4(_NoInit) {}

Matrix4x4::Matrix4x4(const Matrix3x3& other)
{
    data[0][0] = other[0][0];
    data[1][0] = other[1][0];
    data[2][0] = other[2][0];
    data[3][0] = 0.0f;

    data[0][1] = other[0][1];
    data[1][1] = other[1][1];
    data[2][1] = other[2][1];
    data[3][1] = 0.0f;

    data[0][2] = other[0][2];
    data[1][2] = other[1][2];
    data[2][2] = other[2][2];
    data[3][2] = 0.0f;

    data[0][3] = 0.0f;
    data[1][3] = 0.0f;
    data[2][3] = 0.0f;
    data[3][3] = 1.0f;
}

Matrix4x4::Matrix4x4(const Float4& row1,
                     const Float4& row2,
                     const Float4& row3,
                     const Float4& row4)
{
    data[0][0] = row1.x;
    data[0][1] = row1.y;
    data[0][2] = row1.z;
    data[0][3] = row1.w;

    data[1][0] = row2.x;
    data[1][1] = row2.y;
    data[1][2] = row2.z;
    data[1][3] = row2.w;

    data[2][0] = row3.x;
    data[2][1] = row3.y;
    data[2][2] = row3.z;
    data[2][3] = row3.w;

    data[3][0] = row4.x;
    data[3][1] = row4.y;
    data[3][2] = row4.z;
    data[3][3] = row4.w;
}

#pragma GCC push_options
#pragma GCC target("avx")

#ifndef set_from_m128
#define set_from_m128(vb, va) _mm256_insertf128_ps(_mm256_castps128_ps256(vb), va, 1)
#endif

inline static __m256 __attribute__((always_inline, artificial)) loadHelper2(const float *a)
{
    return set_from_m128(_mm_loadu_ps(a), _mm_loadu_ps(a));
}

Matrix4x4 Matrix4x4::operator * (const Matrix4x4& other) const
{
    Matrix4x4 result(NoInit);

    /*for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            float sum = 0.0f;

            for (int k = 0; k < 4; ++k)
            {
                sum += data[i][k] * other.data[k][j];
            }

            result.data[i][j] = sum;
        }
    }*/

    __m128 otherRow0 __attribute__((aligned(16))) = _mm_loadu_ps(other.data[0]);
    __m128 otherRow1 __attribute__((aligned(16))) = _mm_loadu_ps(other.data[1]);
    __m128 otherRow2 __attribute__((aligned(16))) = _mm_loadu_ps(other.data[2]);
    __m128 otherRow3 __attribute__((aligned(16))) = _mm_loadu_ps(other.data[3]);

    __m128 newRow0 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(data[0][0]));
    newRow0 = _mm_add_ps(newRow0, _mm_mul_ps(otherRow1, _mm_set1_ps(data[0][1])));
    newRow0 = _mm_add_ps(newRow0, _mm_mul_ps(otherRow2, _mm_set1_ps(data[0][2])));
    newRow0 = _mm_add_ps(newRow0, _mm_mul_ps(otherRow3, _mm_set1_ps(data[0][3])));

    __m128 newRow1 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(data[1][0]));
    newRow1 = _mm_add_ps(newRow1, _mm_mul_ps(otherRow1, _mm_set1_ps(data[1][1])));
    newRow1 = _mm_add_ps(newRow1, _mm_mul_ps(otherRow2, _mm_set1_ps(data[1][2])));
    newRow1 = _mm_add_ps(newRow1, _mm_mul_ps(otherRow3, _mm_set1_ps(data[1][3])));

    __m128 newRow2 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(data[2][0]));
    newRow2 = _mm_add_ps(newRow2, _mm_mul_ps(otherRow1, _mm_set1_ps(data[2][1])));
    newRow2 = _mm_add_ps(newRow2, _mm_mul_ps(otherRow2, _mm_set1_ps(data[2][2])));
    newRow2 = _mm_add_ps(newRow2, _mm_mul_ps(otherRow3, _mm_set1_ps(data[2][3])));

    __m128 newRow3 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(data[3][0]));
    newRow3 = _mm_add_ps(newRow3, _mm_mul_ps(otherRow1, _mm_set1_ps(data[3][1])));
    newRow3 = _mm_add_ps(newRow3, _mm_mul_ps(otherRow2, _mm_set1_ps(data[3][2])));
    newRow3 = _mm_add_ps(newRow3, _mm_mul_ps(otherRow3, _mm_set1_ps(data[3][3])));

    _mm_store_ps(result.data[0], newRow0);
    _mm_store_ps(result.data[1], newRow1);
    _mm_store_ps(result.data[2], newRow2);
    _mm_store_ps(result.data[3], newRow3);

    /*result.data[0][0] = data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0] + data[0][2] * other.data[2][0] + data[0][3] * other.data[3][0];
    result.data[0][1] = data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1] + data[0][2] * other.data[2][1] + data[0][3] * other.data[3][1];
    result.data[0][2] = data[0][0] * other.data[0][2] + data[0][1] * other.data[1][2] + data[0][2] * other.data[2][2] + data[0][3] * other.data[3][2];
    result.data[0][3] = data[0][0] * other.data[0][3] + data[0][1] * other.data[1][3] + data[0][2] * other.data[2][3] + data[0][3] * other.data[3][3];

    result.data[1][0] = data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0] + data[1][2] * other.data[2][0] + data[1][3] * other.data[3][0];
    result.data[1][1] = data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1] + data[1][2] * other.data[2][1] + data[1][3] * other.data[3][1];
    result.data[1][2] = data[1][0] * other.data[0][2] + data[1][1] * other.data[1][2] + data[1][2] * other.data[2][2] + data[1][3] * other.data[3][2];
    result.data[1][3] = data[1][0] * other.data[0][3] + data[1][1] * other.data[1][3] + data[1][2] * other.data[2][3] + data[1][3] * other.data[3][3];

    result.data[2][0] = data[2][0] * other.data[0][0] + data[2][1] * other.data[1][0] + data[2][2] * other.data[2][0] + data[2][3] * other.data[3][0];
    result.data[2][1] = data[2][0] * other.data[0][1] + data[2][1] * other.data[1][1] + data[2][2] * other.data[2][1] + data[2][3] * other.data[3][1];
    result.data[2][2] = data[2][0] * other.data[0][2] + data[2][1] * other.data[1][2] + data[2][2] * other.data[2][2] + data[2][3] * other.data[3][2];
    result.data[2][3] = data[2][0] * other.data[0][3] + data[2][1] * other.data[1][3] + data[2][2] * other.data[2][3] + data[2][3] * other.data[3][3];

    result.data[3][0] = data[3][0] * other.data[0][0] + data[3][1] * other.data[1][0] + data[3][2] * other.data[2][0] + data[3][3] * other.data[3][0];
    result.data[3][1] = data[3][0] * other.data[0][1] + data[3][1] * other.data[1][1] + data[3][2] * other.data[2][1] + data[3][3] * other.data[3][1];
    result.data[3][2] = data[3][0] * other.data[0][2] + data[3][1] * other.data[1][2] + data[3][2] * other.data[2][2] + data[3][3] * other.data[3][2];
    result.data[3][3] = data[3][0] * other.data[0][3] + data[3][1] * other.data[1][3] + data[3][2] * other.data[2][3] + data[3][3] * other.data[3][3];*/

    return result;
}
#pragma GCC pop_options

Float4 Matrix4x4::operator * (const Float4& other) const
{
    return Float4(reinterpret_cast<const Float4 *>(data)->dot(other),
                  reinterpret_cast<const Float4 *>(&data[1])->dot(other),
                  reinterpret_cast<const Float4 *>(&data[2])->dot(other),
                  reinterpret_cast<const Float4 *>(&data[3])->dot(other));
}

Matrix4x4 Matrix4x4::operator / (float other) const
{
    const float *m[4] = {data[0], data[1], data[2], data[3]};

    return Matrix4x4(Float4(m[0][0]/other, m[1][0]/other, m[2][0]/other, m[3][0]/other),
                     Float4(m[0][1]/other, m[1][1]/other, m[2][1]/other, m[3][1]/other),
                     Float4(m[0][2]/other, m[1][2]/other, m[2][2]/other, m[3][2]/other),
                     Float4(m[0][3]/other, m[1][3]/other, m[2][3]/other, m[3][3]/other));
}

Matrix4x4 Matrix4x4::transpose() const
{
    const float *m[4] = {data[0], data[1], data[2], data[3]};

    return Matrix4x4(Float4(m[0][0], m[1][0], m[2][0], m[3][0]),
                     Float4(m[0][1], m[1][1], m[2][1], m[3][1]),
                     Float4(m[0][2], m[1][2], m[2][2], m[3][2]),
                     Float4(m[0][3], m[1][3], m[2][3], m[3][3]));
}

float Matrix4x4::determinant() const
{
#define d data
    return double(d[3][0])*d[2][1]*d[1][2]*d[0][3] - double(d[2][0])*d[3][1]*d[1][2]*d[0][3] - double(d[3][0])*d[1][1]*d[2][2]*d[0][3] + double(d[1][0])*d[3][1]*d[2][2]*d[0][3] +
           double(d[2][0])*d[1][1]*d[3][2]*d[0][3] - double(d[1][0])*d[2][1]*d[3][2]*d[0][3] - double(d[3][0])*d[2][1]*d[0][2]*d[1][3] + double(d[2][0])*d[3][1]*d[0][2]*d[1][3] +
           double(d[3][0])*d[0][1]*d[2][2]*d[1][3] - double(d[0][0])*d[3][1]*d[2][2]*d[1][3] - double(d[2][0])*d[0][1]*d[3][2]*d[1][3] + double(d[0][0])*d[2][1]*d[3][2]*d[1][3] +
           double(d[3][0])*d[1][1]*d[0][2]*d[2][3] - double(d[1][0])*d[3][1]*d[0][2]*d[2][3] - double(d[3][0])*d[0][1]*d[1][2]*d[2][3] + double(d[0][0])*d[3][1]*d[1][2]*d[2][3] +
           double(d[1][0])*d[0][1]*d[3][2]*d[2][3] - double(d[0][0])*d[1][1]*d[3][2]*d[2][3] - double(d[2][0])*d[1][1]*d[0][2]*d[3][3] + double(d[1][0])*d[2][1]*d[0][2]*d[3][3] +
           double(d[2][0])*d[0][1]*d[1][2]*d[3][3] - double(d[0][0])*d[2][1]*d[1][2]*d[3][3] - double(d[1][0])*d[0][1]*d[2][2]*d[3][3] + double(d[0][0])*d[1][1]*d[2][2]*d[3][3];
#undef d
}

#pragma GCC push_options
#pragma GCC target("avx")
Matrix4x4 Matrix4x4::inverse() const
{
    float d = determinant();

    if (d == 0.0f)
    {
        return Matrix4x4();
    }

    d = 1.0f / d;

    __m128 det __attribute__((aligned(16))) = _mm_set1_ps(d);

    __m128 row0 __attribute__((aligned(16))) = _mm_loadu_ps(data[0]);
    __m128 row1 __attribute__((aligned(16))) = _mm_loadu_ps(data[1]);
    __m128 row2 __attribute__((aligned(16))) = _mm_loadu_ps(data[2]);
    __m128 row3 __attribute__((aligned(16))) = _mm_loadu_ps(data[3]);

    _MM_TRANSPOSE4_PS(row0, row1, row2, row3);

    __m128 mask __attribute__((aligned(16))) = _mm_setr_ps(1.0f, -1.0f, 1.0f, -1.0f);

//---------------------------------------------------------------------------------------------------
    __m128 temp0 __attribute__((aligned(16))) = _mm_permute_ps(row1, _MM_SHUFFLE(2, 1, 3, 2));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row2, _MM_SHUFFLE(1, 3, 2, 3)));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row3, _MM_SHUFFLE(0, 0, 0, 1)));

    __m128 temp1 __attribute__((aligned(16))) = _mm_permute_ps(row1, _MM_SHUFFLE(1, 3, 2, 3));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(2, 1, 3, 2)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(0, 0, 0, 1)));
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row1, _MM_SHUFFLE(2, 3, 3, 3));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row1, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row1, _MM_SHUFFLE(1, 1, 2, 2));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row1, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp0 = _mm_mul_ps(temp0, det);

    Matrix4x4 m(Matrix4x4::NoInit);
    _mm_store_ps(m.data[0], temp0);

//---------------------------------------------------------------------------------------------------
    temp0 = _mm_permute_ps(row0, _MM_SHUFFLE(1, 3, 2, 3));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row2, _MM_SHUFFLE(2, 1, 3, 2)));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row3, _MM_SHUFFLE(0, 0, 0, 1)));

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(2, 1, 3, 2));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(1, 3, 2, 3)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(0, 0, 0, 1)));
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(2, 3, 3, 3));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(1, 1, 2, 2));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp0 = _mm_mul_ps(temp0, det);

    _mm_store_ps(m.data[1], temp0);

//---------------------------------------------------------------------------------------------------
    temp0 = _mm_permute_ps(row0, _MM_SHUFFLE(2, 1, 3, 2));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row1, _MM_SHUFFLE(1, 3, 2, 3)));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row3, _MM_SHUFFLE(0, 0, 0, 1)));

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(1, 3, 2, 3));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(2, 1, 3, 2)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(0, 0, 0, 1)));
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(2, 3, 3, 3));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(1, 1, 2, 2));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row3, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp0 = _mm_mul_ps(temp0, det);

    _mm_store_ps(m.data[2], temp0);

//---------------------------------------------------------------------------------------------------
    temp0 = _mm_permute_ps(row0, _MM_SHUFFLE(1, 3, 2, 3));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row1, _MM_SHUFFLE(2, 1, 3, 2)));
    temp0 = _mm_mul_ps(temp0, _mm_permute_ps(row2, _MM_SHUFFLE(0, 0, 0, 1)));

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(2, 1, 3, 2));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(1, 3, 2, 3)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(0, 0, 0, 1)));
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(2, 3, 3, 3));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(1, 1, 2, 2));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(0, 0, 0, 1)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_add_ps(temp0, temp1);

    temp1 = _mm_permute_ps(row0, _MM_SHUFFLE(0, 0, 0, 1));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row1, _MM_SHUFFLE(1, 1, 2, 2)));
    temp1 = _mm_mul_ps(temp1, _mm_permute_ps(row2, _MM_SHUFFLE(2, 3, 3, 3)));
    temp1 = _mm_mul_ps(temp1, mask);
    temp0 = _mm_sub_ps(temp0, temp1);

    temp0 = _mm_mul_ps(temp0, det);

    _mm_store_ps(m.data[3], temp0);

    return m;
    /*#define c data
    Matrix4x4 m(NoInit);
    m.data[0][0] = d * (c[2][1]*c[3][2]*c[1][3] - c[3][1]*c[2][2]*c[1][3] + c[3][1]*c[1][2]*c[2][3] - c[1][1]*c[3][2]*c[2][3] - c[2][1]*c[1][2]*c[3][3] + c[1][1]*c[2][2]*c[3][3]);
    m.data[0][1] = d * (c[3][1]*c[2][2]*c[0][3] - c[2][1]*c[3][2]*c[0][3] - c[3][1]*c[0][2]*c[2][3] + c[0][1]*c[3][2]*c[2][3] + c[2][1]*c[0][2]*c[3][3] - c[0][1]*c[2][2]*c[3][3]);
    m.data[0][2] = d * (c[1][1]*c[3][2]*c[0][3] - c[3][1]*c[1][2]*c[0][3] + c[3][1]*c[0][2]*c[1][3] - c[0][1]*c[3][2]*c[1][3] - c[1][1]*c[0][2]*c[3][3] + c[0][1]*c[1][2]*c[3][3]);
    m.data[0][3] = d * (c[2][1]*c[1][2]*c[0][3] - c[1][1]*c[2][2]*c[0][3] - c[2][1]*c[0][2]*c[1][3] + c[0][1]*c[2][2]*c[1][3] + c[1][1]*c[0][2]*c[2][3] - c[0][1]*c[1][2]*c[2][3]);

    m.data[1][0] = d * (c[3][0]*c[2][2]*c[1][3] - c[2][0]*c[3][2]*c[1][3] - c[3][0]*c[1][2]*c[2][3] + c[1][0]*c[3][2]*c[2][3] + c[2][0]*c[1][2]*c[3][3] - c[1][0]*c[2][2]*c[3][3]);
    m.data[1][1] = d * (c[2][0]*c[3][2]*c[0][3] - c[3][0]*c[2][2]*c[0][3] + c[3][0]*c[0][2]*c[2][3] - c[0][0]*c[3][2]*c[2][3] - c[2][0]*c[0][2]*c[3][3] + c[0][0]*c[2][2]*c[3][3]);
    m.data[1][2] = d * (c[3][0]*c[1][2]*c[0][3] - c[1][0]*c[3][2]*c[0][3] - c[3][0]*c[0][2]*c[1][3] + c[0][0]*c[3][2]*c[1][3] + c[1][0]*c[0][2]*c[3][3] - c[0][0]*c[1][2]*c[3][3]);
    m.data[1][3] = d * (c[1][0]*c[2][2]*c[0][3] - c[2][0]*c[1][2]*c[0][3] + c[2][0]*c[0][2]*c[1][3] - c[0][0]*c[2][2]*c[1][3] - c[1][0]*c[0][2]*c[2][3] + c[0][0]*c[1][2]*c[2][3]);

    m.data[2][0] = d * (c[2][0]*c[3][1]*c[1][3] - c[3][0]*c[2][1]*c[1][3] + c[3][0]*c[1][1]*c[2][3] - c[1][0]*c[3][1]*c[2][3] - c[2][0]*c[1][1]*c[3][3] + c[1][0]*c[2][1]*c[3][3]);
    m.data[2][1] = d * (c[3][0]*c[2][1]*c[0][3] - c[2][0]*c[3][1]*c[0][3] - c[3][0]*c[0][1]*c[2][3] + c[0][0]*c[3][1]*c[2][3] + c[2][0]*c[0][1]*c[3][3] - c[0][0]*c[2][1]*c[3][3]);
    m.data[2][2] = d * (c[1][0]*c[3][1]*c[0][3] - c[3][0]*c[1][1]*c[0][3] + c[3][0]*c[0][1]*c[1][3] - c[0][0]*c[3][1]*c[1][3] - c[1][0]*c[0][1]*c[3][3] + c[0][0]*c[1][1]*c[3][3]);
    m.data[2][3] = d * (c[2][0]*c[1][1]*c[0][3] - c[1][0]*c[2][1]*c[0][3] - c[2][0]*c[0][1]*c[1][3] + c[0][0]*c[2][1]*c[1][3] + c[1][0]*c[0][1]*c[2][3] - c[0][0]*c[1][1]*c[2][3]);

    m.data[3][0] = d * (c[3][0]*c[2][1]*c[1][2] - c[2][0]*c[3][1]*c[1][2] - c[3][0]*c[1][1]*c[2][2] + c[1][0]*c[3][1]*c[2][2] + c[2][0]*c[1][1]*c[3][2] - c[1][0]*c[2][1]*c[3][2]);
    m.data[3][1] = d * (c[2][0]*c[3][1]*c[0][2] - c[3][0]*c[2][1]*c[0][2] + c[3][0]*c[0][1]*c[2][2] - c[0][0]*c[3][1]*c[2][2] - c[2][0]*c[0][1]*c[3][2] + c[0][0]*c[2][1]*c[3][2]);
    m.data[3][2] = d * (c[3][0]*c[1][1]*c[0][2] - c[1][0]*c[3][1]*c[0][2] - c[3][0]*c[0][1]*c[1][2] + c[0][0]*c[3][1]*c[1][2] + c[1][0]*c[0][1]*c[3][2] - c[0][0]*c[1][1]*c[3][2]);
    m.data[3][3] = d * (c[1][0]*c[2][1]*c[0][2] - c[2][0]*c[1][1]*c[0][2] + c[2][0]*c[0][1]*c[1][2] - c[0][0]*c[2][1]*c[1][2] - c[1][0]*c[0][1]*c[2][2] + c[0][0]*c[1][1]*c[2][2]);
    #undef c

    return m;*/
}
#pragma GCC pop_options

void Matrix4x4::multTrans(const Float3& translation)
{
    data[0][3] = data[0][0] * translation.x + data[0][1] * translation.y + data[0][2] * translation.z + data[0][3];
    data[1][3] = data[1][0] * translation.x + data[1][1] * translation.y + data[1][2] * translation.z + data[1][3];
    data[2][3] = data[2][0] * translation.x + data[2][1] * translation.y + data[2][2] * translation.z + data[2][3];
    data[3][3] = data[3][0] * translation.x + data[3][1] * translation.y + data[3][2] * translation.z + data[3][3];
}

void Matrix4x4::multScale(const Float3& scale)
{
    data[0][0] = data[0][0] * scale.x;
    data[0][1] = data[0][1] * scale.x;
    data[0][2] = data[0][2] * scale.x;

    data[1][0] = data[1][0] * scale.y;
    data[1][1] = data[1][1] * scale.y;
    data[1][2] = data[1][2] * scale.y;

    data[2][0] = data[2][0] * scale.z;
    data[2][1] = data[2][1] * scale.z;
    data[2][2] = data[2][2] * scale.z;
}

void Matrix4x4::multQuat(const Quaternion& quat)
{
    Float4 axisAngle = quat.getAxisAndAngle();

    float angle = axisAngle.w;
    Float3 axis = axisAngle.getXYZ().normalize();

    float s = std::sin(angle);
    float c = std::cos(angle);

    Float3 temp(axis * (1.0f - c));

    float rotate[3][3];
    rotate[0][0] = temp.x*axis.x + c;
    rotate[1][0] = temp.x*axis.y + s*axis.z;
    rotate[2][0] = temp.x*axis.z - s*axis.y;

    rotate[0][1] = temp.y*axis.x - s*axis.z;
    rotate[1][1] = temp.y*axis.y + c;
    rotate[2][1] = temp.y*axis.z + s*axis.x;

    rotate[0][2] = temp.z*axis.x + s*axis.y;
    rotate[1][2] = temp.y*axis.y - s*axis.x;
    rotate[2][2] = temp.z*axis.z + c;

    data[0][0] = data[0][0]*rotate[0][0] + data[0][1]*rotate[1][0] + data[0][2]*rotate[2][0];
    data[1][0] = data[1][0]*rotate[0][0] + data[1][1]*rotate[1][0] + data[1][2]*rotate[2][0];
    data[2][0] = data[2][0]*rotate[0][0] + data[2][1]*rotate[1][0] + data[2][2]*rotate[2][0];

    data[0][1] = data[0][0]*rotate[0][1] + data[0][1]*rotate[1][1] + data[0][2]*rotate[2][1];
    data[1][1] = data[1][0]*rotate[0][1] + data[1][1]*rotate[1][1] + data[1][2]*rotate[2][1];
    data[2][1] = data[2][0]*rotate[0][1] + data[2][1]*rotate[1][1] + data[2][2]*rotate[2][1];

    data[0][2] = data[0][0]*rotate[0][2] + data[0][1]*rotate[1][2] + data[0][2]*rotate[2][2];
    data[1][2] = data[1][0]*rotate[0][2] + data[1][1]*rotate[1][2] + data[1][2]*rotate[2][2];
    data[2][2] = data[2][0]*rotate[0][2] + data[2][1]*rotate[1][2] + data[2][2]*rotate[2][2];
}

Matrix4x4 Matrix4x4::translate(const Float3& translation)
{
    return Matrix4x4(Float4(1.0f, 0.0f, 0.0f, translation.x),
                     Float4(0.0f, 1.0f, 0.0f, translation.y),
                     Float4(0.0f, 0.0f, 1.0f, translation.z),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::scale(const Float3& scale)
{
    return Matrix4x4(Float4(scale.x, 0.0f, 0.0f, 0.0f),
                     Float4(0.0f, scale.y, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, scale.z, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotate(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(c, -s, 0.0f, 0.0f),
                     Float4(s, c, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, 1.0f, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotatex(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(1.0f, 0.0f, 0.0f, 0.0f),
                     Float4(0.0f, c, -s, 0.0f),
                     Float4(0.0f, s, c, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotatey(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(c, 0.0f, s, 0.0f),
                     Float4(0.0f, 1.0f, 0.0f, 0.0f),
                     Float4(-s, 0.0f, c, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotatez(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(c, -s, 0.0f, 0.0f),
                     Float4(s, c, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, 1.0f, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::perspective(float fov, float aspect, float near, float far)
{
    float e = std::tan(M_PI_2 - fov / 2.0f);

    float fpn = far + near;
    float fmn = far - near;

    return Matrix4x4(Float4(e/aspect, 0.0, 0.0f, 0.0f),
                     Float4(0.0f, e, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, -(fpn / fmn), -((2.0f * far * near)/fmn)),
                     Float4(0.0f, 0.0f, -1.0f, 0.0f));
}

Matrix4x4 Matrix4x4::orthographic(float left,
                                  float right,
                                  float bottom,
                                  float top,
                                  float near,
                                  float far)
{
    float tx = (right+left) / (right-left);
    float ty = (top+bottom) / (top-bottom);
    float tz = (far+near) / (far-near);

    return Matrix4x4(Float4(2.0f/(right-left), 0.0f, 0.0f, tx),
                     Float4(0.0f, 2.0f/(top-bottom), 0.0f, ty),
                     Float4(0.0f, 0.0f, -2.0f/(far-near), tz),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::lookAt(const Position3D& eye,
                            const Position3D& center,
                            const Direction3D& up)
{
    return lookAtDir(eye, center - eye, up);
}

Matrix4x4 Matrix4x4::lookAtDir(const Position3D& eye,
                               const Direction3D& dir,
                               const Direction3D& up)
{
    Direction3D up_ = up.normalize();

    Float3 f = dir.normalize();

    Float3 s = f.cross(up_);
    Float3 u = s.normalize().cross(f);

    return Matrix4x4(Float4(s.x, s.y, s.z, -s.dot(eye)),
                     Float4(u.x, u.y, u.z, -u.dot(eye)),
                     Float4(-f.x, -f.y, -f.z, f.dot(eye)),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}
