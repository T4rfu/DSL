#pragma once

#include "string"

class Token
{
public:
	Token(std::string type, std::string value, int lineNum);

	std::string getType() const;
	std::string getValue() const;
    int getLine() const;
	void setValue(std::string value);

	//Token& operator=(const Token& from);

private:
	int lineNum;
	std::string type;
	std::string value;
};
