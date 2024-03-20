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

void ZFunction::z_func(const std::string& s, std::vector<int>& z)
{
    int n = s.size();
    z.resize(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

std::vector<int> ZFunction::findSubstring(const std::string& main, const std::string& sub)
{
    std::vector<int> occurrences;
    if (sub.empty())
        return occurrences; // ѕроверка дл€ случа€, когда подстрока пуста€
    std::vector<int> z;
    int strSize = main.size();
    z_func(sub + "$" + main, z);

    int subSize = sub.size();
    for (int i = subSize + 1; i < strSize; i++) {
        if (z[i] == subSize)
            occurrences.push_back(i - subSize - 1); 
    }

    return occurrences;
}






