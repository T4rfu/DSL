#pragma once

#include "node.h"

class NodeSum final: public Node {
public:
    NodeSum(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};