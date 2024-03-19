#include "BruteForce.h"


BruteForce* BruteForce::instance = nullptr;

BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}

BruteForce* BruteForce::GetInstance()
{
    if (instance == nullptr)
        instance = new BruteForce();
    return instance;
}

void BruteForce::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> BruteForce::findSubstring(const std::string& main, const std::string& sub)
{
    int maxCount = sub.length();
    std::vector<int> result;

    for (auto it1 = main.begin(); it1 != main.end(); ++it1)
    {
        int count = 0;
        for (auto it2 = it1; it2 != main.end() && count < maxCount; ++it2)
        {
            if (*it2 == sub[count])
            {
                ++count;
                if (count == maxCount)
                {
                    result.push_back(std::distance(main.begin(), it1));
                    break;
                }
            }
            else
            {
                it1 += count;
                break;
            }
        }
    }

    return result;
}








