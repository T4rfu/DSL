#pragma once

#include <list>
#include <map>
#include <stack>
#include <string>

class InterpreterArgs final{
private:
    std::map<std::string, int> variables;
    std::stack<int> stack;
public:
    InterpreterArgs();
    std::map<std::string, int>& getVariables();
    std::stack<int>& getStack();
};