#pragma once

#include "node.h"

class NodeMul final: public Node {
public:
    NodeMul(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};