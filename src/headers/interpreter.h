#pragma once

#include <list>
#include <map>
#include <stack>

#include "node.h"


class Interpreter final{
private:

    InterpreterArgs* args;

public:
    Interpreter(InterpreterArgs* args);

    ~Interpreter();

    void execute(const Node*);

};