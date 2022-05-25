#include "token.h"

Token::Token(std::string type, std::string value, int lineNum)
: type(type), value(value), lineNum(lineNum)
{
}

std::string Token::getType() const
{
	return type;
}

std::string Token::getValue() const
{
	return value;
}

void Token::setValue(std::string value)
{
	value = value;
}

int Token::getLine() const {
    return lineNum;
}