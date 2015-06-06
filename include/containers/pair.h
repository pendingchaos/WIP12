#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair
{
    public:
        inline Pair() {}

        inline Pair(const T1& value1_,
                    const T2& value2_) : value1(value1_),
                                         value2(value2_) {}

        bool operator == (const Pair<T1, T2>& other) const
        {
            return value1 == other.value1 and value2 == other.value2;
        }

        T1 value1;
        T2 value2;
};

#endif // PAIR_H
