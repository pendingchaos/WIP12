#ifndef MISC_MACROS_H
#define MISC_MACROS_H

#include <cmath>

namespace _do_not_ever_ever_use_this_namespace
{
class _do_not_ever_ever_use_this_type {};
}

#define NO_COPY(className) private:\
    className(const className&) {}\
    className& operator = (const className&) {return *this;}\
protected:\
    className(_do_not_ever_ever_use_this_namespace::_do_not_ever_ever_use_this_type) {}

#define NO_COPY_INHERITED(className, parent) private:\
    className(const className&)\
    : parent(_do_not_ever_ever_use_this_namespace::_do_not_ever_ever_use_this_type()) {}\
    className& operator = (const className&) {return *this;}\
protected:\
    className(_do_not_ever_ever_use_this_namespace::_do_not_ever_ever_use_this_type)\
    : parent(_do_not_ever_ever_use_this_namespace::_do_not_ever_ever_use_this_type()) {}

#define _STR(...) #__VA_ARGS__
#define STR(...) _STR(__VA_ARGS__)

#define _JOIN2(x, y) x##y
#define _JOIN(x, y) _JOIN2(x, y)
#define JOIN(x, y) _JOIN(x, y)

#define ADD_VOIDP(pointer, toAdd) static_cast<void *>(static_cast<char *>(pointer) + (toAdd))
#define CADD_VOIDP(pointer, toAdd) static_cast<const void *>(static_cast<const char *>(pointer) + (toAdd))

#define SUB_VOIDP(pointer, toSub) static_cast<void *>(static_cast<char *>(pointer) - (toSub))
#define CSUB_VOIDP(pointer, toSub) static_cast<const void *>(static_cast<const char *>(pointer) - (toSub))

#define _NUM_ARGS(a, b, c, d, e, f, g, h, i, j, k, l,\
                  m, n, o, p, q, r, s, t, u, v, w, x, y,\
                  z, ab, ac, ad, ae, af, ag, ah, N, ...) N

#define NUM_ARGS(...) _NUM_ARGS(,##__VA_ARGS__, 32, 31, 30, 29, 28, 27, 26, 25, 24,\
                                23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12,\
                                11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define _FOR_EACH0(op, ...)
#define _FOR_EACH1(op, a1) op(a1)
#define _FOR_EACH2(op, a1, a2) op(a1) op(a2)
#define _FOR_EACH3(op, a1, a2, a3) op(a1) op(a2) op(a3)
#define _FOR_EACH4(op, a1, a2, a3, a4) op(a1) op(a2) op(a3) op(a4)
#define _FOR_EACH5(op, a1, a2, a3, a4, a5) op(a1) op(a2) op(a3) op(a4) op(a5)
#define _FOR_EACH6(op, a1, a2, a3, a4, a5, a6) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6)
#define _FOR_EACH7(op, a1, a2, a3, a4, a5, a6, a7) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7)
#define _FOR_EACH8(op, a1, a2, a3, a4, a5, a6, a7, a8) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8)
#define _FOR_EACH9(op, a1, a2, a3, a4, a5, a6, a7, a8, a9) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9)
#define _FOR_EACH10(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10)
#define _FOR_EACH11(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11)
#define _FOR_EACH12(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12)
#define _FOR_EACH13(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13)
#define _FOR_EACH14(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14)
#define _FOR_EACH15(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15)
#define _FOR_EACH16(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16)
#define _FOR_EACH17(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17)
#define _FOR_EACH18(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18)
#define _FOR_EACH19(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19)
#define _FOR_EACH20(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20)
#define _FOR_EACH21(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21)
#define _FOR_EACH22(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22)
#define _FOR_EACH23(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23)
#define _FOR_EACH24(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24)
#define _FOR_EACH25(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25)
#define _FOR_EACH26(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26)
#define _FOR_EACH27(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26) op(a27)
#define _FOR_EACH28(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26) op(a27) op(a28)
#define _FOR_EACH29(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26) op(a27) op(a28) op(a29)
#define _FOR_EACH30(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26) op(a27) op(a28) op(a29) op(a30)
#define _FOR_EACH31(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26) op(a27) op(a28) op(a29) op(a30) op(a31)
#define _FOR_EACH32(op, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32) op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8) op(a9) op(a10) op(a11) op(a12) op(a13) op(a14) op(a15) op(a16) op(a17) op(a18) op(a19) op(a20) op(a21) op(a22) op(a23) op(a24) op(a25) op(a26) op(a27) op(a28) op(a29) op(a30) op(a31) op(a32)

#define FOR_EACH(op, ...) JOIN(_FOR_EACH, NUM_ARGS(__VA_ARGS__))(op, __VA_ARGS__)

#define _FOR_N0(op)
#define _FOR_N1(op) op(0)
#define _FOR_N2(op) op(0) op(1)
#define _FOR_N3(op) op(0) op(1) op(2)
#define _FOR_N4(op) op(0) op(1) op(2) op(3)
#define _FOR_N5(op) op(0) op(1) op(2) op(3) op(4)
#define _FOR_N6(op) op(0) op(1) op(2) op(3) op(4) op(5)
#define _FOR_N7(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6)
#define _FOR_N8(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7)
#define _FOR_N9(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8)
#define _FOR_N10(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9)
#define _FOR_N11(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10)
#define _FOR_N12(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11)
#define _FOR_N13(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12)
#define _FOR_N14(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13)
#define _FOR_N15(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14)
#define _FOR_N16(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15)
#define _FOR_N17(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16)
#define _FOR_N18(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17)
#define _FOR_N19(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18)
#define _FOR_N20(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19)
#define _FOR_N21(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20)
#define _FOR_N22(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21)
#define _FOR_N23(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22)
#define _FOR_N24(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23)
#define _FOR_N25(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24)
#define _FOR_N26(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25)
#define _FOR_N27(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25) op(26)
#define _FOR_N28(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25) op(26) op(27)
#define _FOR_N29(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25) op(26) op(27) op(28)
#define _FOR_N30(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25) op(26) op(27) op(28) op(29)
#define _FOR_N31(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25) op(26) op(27) op(28) op(29) op(30)
#define _FOR_N32(op) op(0) op(1) op(2) op(3) op(4) op(5) op(6) op(7) op(8) op(9) op(10) op(11) op(12) op(13) op(14) op(15) op(16) op(17) op(18) op(19) op(20) op(21) op(22) op(23) op(24) op(25) op(26) op(27) op(28) op(29) op(30) op(31)

#define FOR_N(op, n) JOIN(_FOR_N, n)(op)

#define CALL_METHOD_POINTER(object, pointer, ...) ((object).*(pointer))(__VA_ARGS__)

#define STATIC_ASSERT_FAIL_IF_FALSE(condition) static char JOIN(staticAssertionAt, __LINE__)[(condition) ? 1 : -1] __attribute__((unused)) = {' '};
#define STATIC_ASSERT_FAIL_IF_TRUE(condition) STATIC_ASSERT_FAIL_IF_FALSE(not (condition))

#define RADIANS(angle) ((angle) * (M_PI / 180.0))
#define DEGREES(angle) ((angle) * (180.0 / M_PI))

#define FORCE_INLINE inline __attribute__((always_inline))

#define UNUSED(x) do {(void)sizeof((x));} while (0)

#endif // MISC_MACROS_H
