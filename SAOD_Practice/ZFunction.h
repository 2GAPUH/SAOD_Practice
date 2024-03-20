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
    void z_func(const std::string& s, std::vector<int>& z);

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);

};

