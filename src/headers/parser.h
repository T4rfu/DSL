#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <regex>
#include "node.h"
#include "token.h"

class Parser {
private:
    Node *node;

public:
    Parser(Node *node);

    void addTokens(std::list<Token> tokens);

    void parseVarAssignment(std::list<Token> tokens);

    void parseIf(std::list<Token> tokens);

    void parseWhile(std::list<Token> tokens);

    void parseFor(std::list<Token> tokens);

    void parsePrint(std::list<Token> tokens);

    std::list<Node *> parseOperations(std::list<Token> tokens);

    std::list<Node *> parseLogicOperations(std::list<Token> tokens);

    std::list<Token> toPostfix(std::list<Token> tokens, const std::string& typeOperation, const std::function<short(std::string type)>& m);

    std::list<Token> toLogicPostfix(std::list<Token> tokens);

    Node* addMakedTree(std::list<Node*> nodes);

    void parseLine(std::list<Token> &tokens);
};
