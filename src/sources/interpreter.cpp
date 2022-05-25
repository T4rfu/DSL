#include "interpreter.h"
#include "node.h"


Interpreter::Interpreter(InterpreterArgs* args)
: args(args)
{}

Interpreter::~Interpreter()
{}

void Interpreter::execute(const Node* tree)
{
    for (auto node: tree->getChildren())
    {
        execute(node);
    }

    tree->action(args);
}