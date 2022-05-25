#pragma once

#include "node.h"

class NodeNotEq final: public Node {
public:
    NodeNotEq(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};