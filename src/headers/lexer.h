#pragma once


#include <list>
#include <string>
#include <regex>

#include "token.h"

class Lexer
{
private:
	std::list<Token> tokens;
	std::list<std::pair<std::string, std::regex>> lexems;

public:
	Lexer();
	void readFile(std::string path);
	bool checkToken(std::string input);	
	void addToken(std::string input, int lineNum);
	std::list<Token> getTokens() const;

	void print();
};
