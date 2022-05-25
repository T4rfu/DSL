#include "node.h"


Node::Node(const NodeType type, const int lineNum):
lineNum(lineNum), type(type)
{}

Node::~Node() {
    for (auto child: children) {
        delete child;
    }
}

NodeType Node::getType() {
    return type;
}

void Node::addChildFront(Node* child) {
    children.push_front(child);
}

void Node::addChildBack(Node* child) {
    children.push_back(child);
}

std::list<Node *> Node::getChildren() const {
    return children;
}

bool Node::isOperation() const {
    return(type == NODE_SUM ||
           type == NODE_SUB ||
           type == NODE_MUL ||
           type == NODE_DIV ||
           type == NODE_EXP ||
           type == NODE_EQUAL ||
           type == NODE_NOT_EQUAL ||
           type == NODE_GREATER_OR_EQUAL ||
           type == NODE_SMALLER_OR_EQUAL ||
           type == NODE_SMALLER ||
            type == NODE_GREATER
    );
}
