#include "nodeIf.h"
#include "interpreter.h"

NodeIf::NodeIf(const int& lineNum, Node* nodeCondition, Node* nodeAction):
        Node(NODE_IF, lineNum), nodeCondition(nodeCondition), nodeAction(nodeAction) {}

void NodeIf::action(InterpreterArgs* args) const {

    Interpreter interpreterCondition(args);
    interpreterCondition.execute(nodeCondition);
    if(args->getStack().top())
    {
        Interpreter interpreterAction(args);
        interpreterAction.execute(nodeAction);
    }
}