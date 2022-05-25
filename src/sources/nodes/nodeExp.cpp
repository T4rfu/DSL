#include "nodeExp.h"
#include <cmath>

NodeExp::NodeExp(const int& lineNum):
        Node(NODE_EXP, lineNum) {}

void NodeExp::action(InterpreterArgs* args) const {
    if (args->getStack().size() >= 2) {
        auto arg2 = args->getStack().top();
        args->getStack().pop();
        auto arg1 = args->getStack().top();
        args->getStack().pop();
        args->getStack().push((int)(pow(arg1, arg2)));

    } else {
        throw std::string("function doesn't return any value on line: ") + std::to_string(lineNum);
    }
}