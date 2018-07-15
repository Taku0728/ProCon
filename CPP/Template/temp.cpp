#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while( std::getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

int count(const std::string &lhs, const std::string &rhs)
{
    int n(0), s0(lhs.size()), s1(rhs.size());
    for (int i(0); i < s0 - s1 + 1; ++i) {
        if (rhs == lhs.substr(i, s1)) {
            ++n;
        }
    }
    return n;
}

int count(const std::string &lhs, char rhs)
{
    int n(0);
    for (unsigned i(0); i < lhs.size(); ++i) {
        if (rhs == lhs[i]) {
            ++n;
        }
    }
    return n;
}

void replace(std::string &s0, const std::string &s1, const std::string &s2)
{
    unsigned l(s1.size());
    for (unsigned i(0); i < s0.size() - l + 1; ++i) {
        if (s1 == s0.substr(i, l)) {
            s0.replace(i, l, s2);
        }
    }
}
