#ifndef __IMPLICANT__
#define __IMPLICANT__

#include <set>

class Implicant {
private:
    int m_bits{};
    std::set<int> m_wildcards{};

public:
    Implicant(int bits, std::set<int> wildcards);
    bool differsByOneBit(Implicant & imp);
};

#endif