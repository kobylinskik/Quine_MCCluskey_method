#include "Implicant.h"
#include "mathFun.h"
#include <algorithm>

Implicant::Implicant(int bits, std::set<int> wildcards)
    : m_bits{bits}, m_wildcards{wildcards} {

                    };

bool Implicant::differsByOneBit(Implicant & imp) {
    return mathFun::differByOneBit(m_bits, imp.m_bits) && m_wildcards.size() == imp.m_wildcards.size() &&
           std::all_of(m_wildcards.begin(), m_wildcards.end(), [imp](int wildcard) { return imp.m_wildcards.find(wildcard) != imp.m_wildcards.end(); });
};