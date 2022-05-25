#include <iostream>
#include <string>

#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

#include "nodeCodeBlock.h"

int main(int argc, char* argv[])
{

	try
	{
		Lexer lexer;
		lexer.readFile("../example.dsl");//(std::string)argv[1]
		lexer.print();

        Node *app = new NodeCodeBlock(0);
        Parser parser(app);
        parser.addTokens(lexer.getTokens());

        Interpreter interpreter(new InterpreterArgs());
        interpreter.execute(app);

	}
	catch(std::string error)
	{
		std::cout<<"error code:"<<error<<'\n';
	}

}