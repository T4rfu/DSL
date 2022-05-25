#include "lexer.h"

#include <iostream>
#include <fstream>

Lexer::Lexer()
: lexems({
	{"WHILE", std::regex("while")},
	{"IF", std::regex("if")},
	{"PRINT", std::regex("vomit")},

	{"VAR", std::regex("[a-z][A-Za-z0-9]*")},
	{"ASSIGN", std::regex("\\=")},
	{"NUMBER", std::regex("[1-9]+[0-9]*|(0)|/([-]?[1-9]+[0-9]*/) ")},
	{"OPERATION", std::regex(R"(\+|\-|\/|\*|\^)")},
	{"LOG_OPERATION", std::regex(R"(\=\=|\>\=|\<\=|\<|\>|\!\=)")},

	{"LBR", std::regex("\\(")},
	{"RBR", std::regex("\\)")},
	{"LFBR", std::regex("\\{")},
	{"RFBR", std::regex("\\}")},

	{"END", std::regex("\\n")}
	
})
{}

void Lexer::readFile(std::string path)
{
    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open()) { throw std::string("file doesn't exist"); }

    int lineNum = 1;
    char ch;
    std::string token = "";
    while(fin.get(ch))
    {
        if(ch == ' ' || ch == '\t') { continue; } //space char

        token += ch;
        if(!token.empty() && checkToken(token)) { continue; }
        else
        {
            addToken(token.substr(0, token.size() - 1), lineNum);
            token = token[token.size() - 1];
        }
        if(ch == '\n') { lineNum++; }
    }
    if(checkToken(token)){ addToken(token, lineNum); }


    if(tokens.back().getType() != "END") { addToken("\n", lineNum); }
}

bool Lexer::checkToken(std::string input)
{
	for(auto lexem : lexems)
	{
		if(std::regex_match(input, lexem.second))
		{
			return true;
		}
	}
	return false;
}

void Lexer::addToken(std::string input, int lineNum) {

    std::cout<<"|"<<input<<"|"<<'\n';
	for(auto lexem : lexems)
	{
		if(std::regex_match(input, lexem.second))
		{
			tokens.push_back(Token(lexem.first, input, lineNum));
			return;
		}
	}

	throw std::string("lexem not found") + std::string(input);

}

void Lexer::print()
{
	for(auto token : tokens) {
		std::cout<<"type:|"<<'\t'<<token.getType()<<'\t'<<"|value:|"<<token.getValue()<<'\t'<<"|line:|"<<token.getLine()<<"|\n";
	}
	
}

std::list<Token> Lexer::getTokens() const{
    return tokens;
}

