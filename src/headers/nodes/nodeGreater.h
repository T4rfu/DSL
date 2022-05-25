#pragma once

#include "node.h"

class NodeGreater final: public Node {
public:
    NodeGreater(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};