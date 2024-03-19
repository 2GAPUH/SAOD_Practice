#pragma once
#include "DefineValue.h"

class BruteForce
{
#pragma region ST
private:
    BruteForce();
    BruteForce(BruteForce&);
    BruteForce(BruteForce&&);
    static BruteForce* instance;
    ~BruteForce();
public:
    static BruteForce* GetInstance();
    static void DestroyInstance();
#pragma endregion 

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

