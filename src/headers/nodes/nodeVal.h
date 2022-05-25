#pragma once

#include "node.h"

class NodeVal final: public Node {
public:
    NodeVal(int val, const int& lineNum);

    void action(InterpreterArgs* args) const override;
private:
    int val;
};