#include "nodeVar.h"
#include <string>

#include <iostream>

NodeVar::NodeVar(std::string name, const int& lineNum)
: Node(NODE_VAR, lineNum), name(name) {}

void NodeVar::action(InterpreterArgs* args) const {
    if (!callVariableFrom(args->getVariables(), args->getStack() ) ) {
        throw std::string("usage of undeclared var on line: ") + std::to_string(lineNum);
    }
    return;
}

bool NodeVar::callVariableFrom(std::map<std::string, int>& container, std::stack<int>& stack) const {
    auto it = container.find(name);
    if (it != container.end()) {
        stack.push(it->second);
        return true;
    }
    return false;
}