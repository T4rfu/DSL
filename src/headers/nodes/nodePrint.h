#pragma once

#include "node.h"

class NodePrint final: public Node {
public:
    NodePrint(const int& lineNum);

    void action(InterpreterArgs* args) const override;
};