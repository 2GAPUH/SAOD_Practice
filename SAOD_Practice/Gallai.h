#pragma once
#include "DefineValue.h"

class Gallai
{
#pragma region ST
private:
    Gallai();
    Gallai(Gallai&);
    Gallai(Gallai&&);
    static Gallai* instance;
    ~Gallai();
public:
    static Gallai* GetInstance();
    static void DestroyInstance();
#pragma endregion 
private:
    std::vector<int> computeShifts(const std::string& sub);

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

