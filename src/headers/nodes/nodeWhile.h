#pragma once

#include "node.h"

class NodeWhile final: public Node {
public:
    NodeWhile(const int& lineNum, Node* nodeCondition, Node* nodeAction);

    void action(InterpreterArgs* args) const override;

private:
    Node* nodeCondition;
    Node* nodeAction;
};