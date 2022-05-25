#pragma once

#include "node.h"

class NodeSmaller final: public Node {
public:
    NodeSmaller(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};