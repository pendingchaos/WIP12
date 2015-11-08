#ifndef UTILS_H
#define UTILS_H

template <typename D, typename S>
D union_cast(S src)
{
    union
    {
        D d;
        S s;
    } u;
    u.s = src;
    return u.d;
}

#endif // UTILS_H
