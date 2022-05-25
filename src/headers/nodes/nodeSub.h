#pragma once

#include "node.h"

class NodeSub final: public Node {
public:
    NodeSub(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};