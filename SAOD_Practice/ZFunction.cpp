#include "ZFunction.h"

ZFunction* ZFunction::instance = nullptr;

ZFunction::ZFunction()
{
}

ZFunction::~ZFunction()
{
}

ZFunction* ZFunction::GetInstance()
{
    if (instance == nullptr)
        instance = new ZFunction();
    return instance;
}

void ZFunction::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> ZFunction::z_func(const std::string s)
{
    int n = s.length();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

std::vector<int> ZFunction::findSubstring(const std::string& main, const std::string& sub)
{
    std::string concat_string = sub+ "$" + main;
    std::vector<int> z_values = z_func(concat_string);
    int substring_length = sub.length();
    std::vector<int> results;
    for (int i = substring_length + 1; i < concat_string.length(); ++i) {
        if (z_values[i] == substring_length) {
            results.push_back(i - substring_length - 1);
        }
    }
    return results;
}






