#include "BoyerMooreHorspool.h"

BoyerMooreHorspool* BoyerMooreHorspool::instance = nullptr;

BoyerMooreHorspool::BoyerMooreHorspool()
{
}

BoyerMooreHorspool::~BoyerMooreHorspool()
{
}

BoyerMooreHorspool* BoyerMooreHorspool::GetInstance()
{
    if (instance == nullptr)
        instance = new BoyerMooreHorspool();
    return instance;
}

void BoyerMooreHorspool::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> BoyerMooreHorspool::computeShifts(const std::string& sub)
{
    const int subLength = sub.length();
    std::vector<int> shifts(ASCII_SIZE, subLength);

    for (int i = 0; i < subLength - 1; ++i) 
    {
        shifts[static_cast<unsigned char>(sub[i])] = subLength - 1 - i;
    }

    return shifts;
}


std::vector<int> BoyerMooreHorspool::findSubstring(const std::string& main, const std::string& sub)
{
    const int mainLen = main.length();
    const int subLen = sub.length();

    std::vector<int> shiftTable = computeShifts(sub);
    std::vector<int> result;

    int i = subLen - 1;

    while (i < mainLen) {
        int j = subLen - 1;
        int k = i;

        while (j >= 0 && main[k] == sub[j]) {
            --k;
            --j;
        }

        if (j < 0) {
            result.push_back(k + 1);
            i += subLen;
        }
        else {
            int shift = shiftTable[static_cast<unsigned char>(main[i])];
            i += std::max(1, shift);
        }
    }

    return result;
}

