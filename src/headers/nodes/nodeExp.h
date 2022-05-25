#pragma once

#include "node.h"

class NodeExp final: public Node {
public:
    NodeExp(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};