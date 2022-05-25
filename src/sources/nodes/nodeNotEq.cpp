#include "nodeNotEq.h"

NodeNotEq::NodeNotEq(const int& lineNum):
Node(NODE_NOT_EQUAL, lineNum) {}

void NodeNotEq::action(InterpreterArgs* args) const {
    if (args->getStack().size() >= 2) {
        auto arg2 = args->getStack().top();
        args->getStack().pop();
        auto arg1 = args->getStack().top();
        args->getStack().pop();

        args->getStack().push( (arg1 != arg2) ? 1 : 0 );

    } else {
        throw std::string("function doesn't return any value on line: ") + std::to_string(lineNum);
    }
}