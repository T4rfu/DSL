#pragma once

#include "node.h"

class NodeIf final: public Node {
public:
    NodeIf(const int& lineNum, Node* nodeCondition, Node* nodeAction);

    void action(InterpreterArgs* args) const override;

private:
    Node* nodeCondition;
    Node* nodeAction;
};