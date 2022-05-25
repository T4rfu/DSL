cmake_minimum_required(VERSION 3.22)
project(MyPL)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/headers)
include_directories(src/sources)
include_directories(src/headers/nodes)
include_directories(src/sources/nodes)

add_executable(
        MyPL

        src/sources/main.cpp

        src/headers/token.h
        src/sources/token.cpp

        src/headers/lexer.h
        src/sources/lexer.cpp

        src/headers/node.h
        src/sources/node.cpp

        src/headers/parser.h
        src/sources/parser.cpp

        src/headers/nodes/nodeCodeBlock.h
        src/sources/nodes/nodeCodeBlock.cpp

        src/headers/nodes/nodeAssignVar.h
        src/sources/nodes/nodeAssignVar.cpp

        src/headers/nodes/nodeVar.h
        src/sources/nodes/nodeVar.cpp

        src/headers/nodes/nodeVal.h
        src/sources/nodes/nodeVal.cpp

        src/headers/nodes/nodeSum.h
        src/sources/nodes/nodeSum.cpp

        src/headers/nodes/nodeSub.h
        src/sources/nodes/nodeSub.cpp

        src/headers/nodes/nodeMul.h
        src/sources/nodes/nodeMul.cpp

        src/headers/nodes/nodeDiv.h
        src/sources/nodes/nodeDiv.cpp

        src/headers/nodes/nodeExp.h
        src/sources/nodes/nodeExp.cpp

        src/headers/nodes/nodePrint.h
        src/sources/nodes/nodePrint.cpp

        src/headers/nodes/nodeIf.h
        src/sources/nodes/nodeIf.cpp

        src/headers/nodes/nodeSmaller.h
        src/sources/nodes/nodeSmaller.cpp

        src/headers/nodes/nodeSmallerOrEq.h
        src/sources/nodes/nodeSmallerOrEq.cpp

        src/headers/nodes/nodeGreater.h
        src/sources/nodes/nodeGreater.cpp

        src/headers/nodes/nodeGreaterOrEq.h
        src/sources/nodes/nodeGreaterOrEq.cpp

        src/headers/nodes/nodeEq.h
        src/sources/nodes/nodeEq.cpp

        src/headers/nodes/nodeNotEq.h
        src/sources/nodes/nodeNotEq.cpp

        src/headers/nodes/nodeWhile.h
        src/sources/nodes/nodeWhile.cpp

        src/headers/interpreterArgs.h
        src/sources/interpreterArgs.cpp

        src/headers/interpreter.h
        src/sources/interpreter.cpp
)
