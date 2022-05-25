#include "nodeVal.h"

NodeVal::NodeVal(int val, const int& lineNum):
        Node(NODE_VAL, lineNum), val(val) {}

void NodeVal::action(InterpreterArgs* args) const {
    args->getStack().push(val);
}