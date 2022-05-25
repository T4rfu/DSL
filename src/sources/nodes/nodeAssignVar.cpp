#include "nodeAssignVar.h"
#include <iostream>
NodeAssignVar::NodeAssignVar(std::string name, const int& lineNum):
        Node(NODE_ASSIGN_VAR, lineNum), name(name) {}

void NodeAssignVar::action(InterpreterArgs* args) const {
    args->getVariables().insert_or_assign(name, args->getStack().top());

    args->getStack().pop();
}