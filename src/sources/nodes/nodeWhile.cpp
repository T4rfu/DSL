#include "nodeWhile.h"
#include "interpreter.h"

#include <iostream>

NodeWhile::NodeWhile(const int& lineNum, Node* nodeCondition, Node* nodeAction):
        Node(NODE_WHILE, lineNum), nodeCondition(nodeCondition), nodeAction(nodeAction) {}

void NodeWhile::action(InterpreterArgs* args) const {

    Interpreter interpreterCondition(args);

    Interpreter interpreterAction(args);

    while(true)
    {
        interpreterCondition.execute(nodeCondition);

        if(!args->getStack().top()){ break; }
        args->getStack().pop();

        interpreterAction.execute(nodeAction);
    }

}