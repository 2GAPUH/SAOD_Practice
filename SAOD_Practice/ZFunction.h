#pragma once
#include "DefineValue.h"


class ZFunction
{
#pragma region ST
private:
    ZFunction();
    ZFunction(ZFunction&);
    ZFunction(ZFunction&&);
    static ZFunction* instance;
    ~ZFunction();
public:
    static ZFunction* GetInstance();
    static void DestroyInstance();
#pragma endregion 
private:
    std::vector<int> z_func(const std::string s);

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);

};

