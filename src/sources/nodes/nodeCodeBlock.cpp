
#include "nodeCodeBlock.h"

NodeCodeBlock::NodeCodeBlock(const int& lineNum):
Node(NODE_BLOCK, lineNum)
{}

void NodeCodeBlock::action(InterpreterArgs* args) const {
}
