#pragma once
#include "DefineValue.h"



class BoyerMooreHorspool
{
#pragma region ST
private:
    BoyerMooreHorspool();
    BoyerMooreHorspool(BoyerMooreHorspool&);
    BoyerMooreHorspool(BoyerMooreHorspool&&);
    static BoyerMooreHorspool* instance;
    ~BoyerMooreHorspool();
public:
    static BoyerMooreHorspool* GetInstance();
    static void DestroyInstance();
#pragma endregion 
private:
    std::vector<int> computeShifts(const std::string& sub);

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

