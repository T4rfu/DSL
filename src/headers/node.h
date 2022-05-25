#pragma once

#include <list>

#include <string>
#include "interpreterArgs.h"

enum NodeType {
    NODE_VAR,
    NODE_VAL,

    NODE_MUL,
    NODE_DIV,
    NODE_SUM,
    NODE_SUB,
    NODE_EXP,

    NODE_SMALLER,
    NODE_SMALLER_OR_EQUAL,
    NODE_GREATER,
    NODE_GREATER_OR_EQUAL,
    NODE_EQUAL,
    NODE_NOT_EQUAL,

    NODE_ASSIGN_VAR,

    NODE_PRINT,

    NODE_IF,

    NODE_WHILE,

    NODE_BLOCK
};

class Node {
protected:
    std::list<Node*> children;

public:
    Node(const NodeType type, const int lineNum);
    ~Node();

    NodeType getType();

    void addChildFront(Node *child);
    void addChildBack(Node *child);

    std::list<Node*> getChildren() const;

    //action
    //Expression(const ExpressionType& type, const int& lineNum);

    NodeType getType() const;
    virtual void action(InterpreterArgs* args) const = 0;

    bool isOperation() const;

protected:
    const NodeType type;
    const int lineNum;

};