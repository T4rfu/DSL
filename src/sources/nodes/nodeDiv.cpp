#include "nodeDiv.h"
#include <iostream>

NodeDiv::NodeDiv(const int& lineNum):
Node(NODE_DIV, lineNum) {}

void NodeDiv::action(InterpreterArgs* args) const {
    if (args->getStack().size() >= 2) {
        auto arg2 = args->getStack().top();
        args->getStack().pop();
        auto arg1 = args->getStack().top();
        args->getStack().pop();


        if(arg2 != 0)
             args->getStack().push(arg1 / arg2);
         else
             throw std::string(" Are you retarded?");

    } else {
        throw std::string("function doesn't return any value on line: ") + std::to_string(lineNum);
    }
}