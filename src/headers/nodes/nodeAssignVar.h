#pragma once

#include <string>

#include "node.h"

class NodeAssignVar final: public Node {
public:
    NodeAssignVar(std::string name, const int& lineNum);

    void action(InterpreterArgs* args) const override;
private:
    std::string name;
};