#pragma once

#include "node.h"

class NodeGreaterOrEq final: public Node {
public:
    NodeGreaterOrEq(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};