#include "Gallai.h"

Gallai* Gallai::instance = nullptr;

Gallai::Gallai()
{
}

Gallai::~Gallai()
{
}

Gallai* Gallai::GetInstance()
{
    if (instance == nullptr)
        instance = new Gallai();
    return instance;
}

void Gallai::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> Gallai::computeShifts(const std::string& sub)
{
    if (sub.empty())
        return {};

    std::vector<int> shifts(sub.size() + 1);
    shifts[0] = -1;
    int shift = -1;

    for (size_t pos = 0; pos < sub.size(); ++pos) {
        while (shift >= 0 && sub[pos] != sub[shift]) {
            shift = shifts[shift];
        }
        shifts[pos + 1] = ++shift;
    }
    return shifts;
}


std::vector<int> Gallai::findSubstring(const std::string& main, const std::string& sub)
{
    if (sub.empty())
        return {};

    std::vector<int> shifts = computeShifts(sub);
    std::vector<int> result;
    size_t startPos = 0;
    int match = 0;
    size_t stringSize = main.size();
    size_t subSize = sub.size();

    for (size_t i = 0; i < stringSize; ++i) {
        while (match > 0 && sub[match] != main[i]) {
            match = shifts[match];
        }
        if (sub[match] == main[i]) {
            ++match;
            if (match == subSize) {
                result.push_back(static_cast<int>(startPos));
                startPos += subSize - shifts[subSize];
                match = 0;
            }
        }
        else {
            startPos = i + 1;
            match = 0;
        }
    }

    return result;
}

