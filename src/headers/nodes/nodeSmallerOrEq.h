#pragma once

#include "node.h"

class NodeSmallerOrEq final: public Node {
public:
    NodeSmallerOrEq(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};