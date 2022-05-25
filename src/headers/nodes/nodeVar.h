#pragma once

#include "node.h"

class NodeVar final: public Node {
public:
    NodeVar(std::string name, const int& lineNum);

    void action(InterpreterArgs* args) const override;

private:

    bool callVariableFrom(std::map<std::string, int>& container, std::stack<int>& stack) const;
    std::string name;
};