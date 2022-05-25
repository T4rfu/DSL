#pragma once

#include "node.h"

class NodeDiv final: public Node {
public:
    NodeDiv(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};