#include "interpreterArgs.h"

InterpreterArgs::InterpreterArgs()
{}

std::map<std::string, int>& InterpreterArgs::getVariables()
{
    return variables;
}

std::stack<int>& InterpreterArgs::getStack() {
    return stack;
}