#pragma once

#include "node.h"

class NodeEq final: public Node {
public:
    NodeEq(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};