#pragma once

#include "node.h"

class NodeCodeBlock final: public Node {
public:
    NodeCodeBlock(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};