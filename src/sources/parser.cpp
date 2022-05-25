#include "parser.h"

#include "node.h"

#include "nodeSum.h"
#include "nodeSub.h"
#include "nodeMul.h"
#include "nodeDiv.h"
#include "nodeExp.h"

#include "nodePrint.h"

#include "nodeVar.h"
#include "nodeVal.h"

#include "nodeIf.h"
#include "nodeSmaller.h"
#include "nodeSmallerOrEq.h"
#include "nodeGreater.h"
#include "nodeGreaterOrEq.h"
#include "nodeEq.h"
#include "nodeNotEq.h"

#include "nodeWhile.h"

#include "nodeCodeBlock.h"
#include "nodeAssignVar.h"


#include <stack>
Parser::Parser(Node* node)
: node(node)
{
}

void Parser::addTokens(std::list<Token> tokens)
{
    std::list<Token> tokenLine;

    int openedBrackets = 0;// (
    int openedBraces = 0;// {

    int lineErrorBracket = 0;
    int lineErrorBrace = 0;
    //bool operation = false;
    bool endLine = false;
    for( auto token : tokens)
    {
        const auto type = token.getType();

        if (type == "LBR") {
            openedBrackets++;
            lineErrorBracket = token.getLine();
        } else if (type == "RBR") {
            openedBrackets--;
        } else if (type == "LFBR") {
            openedBraces++;
            lineErrorBrace = token.getLine();
        } else if (type == "RFBR") {
            openedBraces--;
        }

        if( (type == "END") && (openedBraces == 0) && (openedBrackets == 0) )
        {
            if(!tokenLine.empty())
            {
                parseLine(tokenLine);
            }
            tokenLine.clear();
        } else
        {
            tokenLine.push_back(token);
        }

    }

    if(openedBraces != 0)
    {
        throw std::string("expected brace on line: ") + std::to_string(lineErrorBrace);
    }

    if(openedBrackets != 0)
    {
        throw std::string("expected bracket on line: ") + std::to_string(lineErrorBracket);
    }


}


void Parser::parseLine(std::list<Token>& tokens) {
    for (auto token : tokens )
    {
        std::cout<<token.getType()<<" ";
    }
    std::cout<<'\n';

    const auto & type = tokens.front().getType();

    if(type == "VAR")
    {
        parseVarAssignment(tokens);
    } else if(type == "WHILE")
    {
        parseWhile(tokens);
    } else if(type == "IF")
    {
        parseIf(tokens);
    } else if(type == "PRINT")
    {
        parsePrint(tokens);
    }

}

void Parser::parseVarAssignment(std::list<Token> tokens)
{
//    std::cout<<"----\n";
//    for(auto token : tokens)
//    {
//        std::cout<<"type: "<<token.getType()<<" value: "<<token.getValue()<<'\n';
//    }

    const auto & token = tokens.front();

    auto nodeChild = new NodeAssignVar(token.getValue(), token.getLine());


    tokens.pop_front();
    tokens.pop_front();

    nodeChild->addChildBack(addMakedTree(parseOperations(tokens)));

    node->addChildBack(nodeChild);

}


void Parser::parseIf(std::list<Token> tokens)
{
    tokens.pop_front();//remove if
    tokens.pop_front();//remove (

    std::list<Token> conditionTokens;
    int amount = 0;
    for (auto token : tokens)
    {
        if(token.getType() == "LFBR")//until token '{'
        {
            break;
        }
        amount++;
        conditionTokens.push_back(token);
    }
    conditionTokens.pop_back();//remove last token ')'

    for(int i = 0; i < amount; i++)
    {
        tokens.pop_front();
    }

    tokens.pop_front();//remove token '{'
    tokens.pop_back();//remove token '}'

    auto nodeCondition = addMakedTree(parseLogicOperations(conditionTokens));
    auto nodeBlock = new NodeCodeBlock(tokens.front().getLine());

    Parser parser(nodeBlock);
    parser.addTokens(tokens);

    node->addChildBack(new NodeIf(tokens.front().getLine(), nodeCondition, nodeBlock));
}

void Parser::parseWhile(std::list<Token> tokens)
{
    tokens.pop_front();//remove if
    tokens.pop_front();//remove (

    std::list<Token> conditionTokens;
    int amount = 0;
    for (auto token : tokens)
    {
        if(token.getType() == "LFBR")//until token '{'
        {
            break;
        }
        amount++;
        conditionTokens.push_back(token);
    }
    conditionTokens.pop_back();//remove last token ')'

    for(int i = 0; i < amount; i++)
    {
        tokens.pop_front();
    }

    tokens.pop_front();//remove token '{'
    tokens.pop_back();//remove token '}'

    auto nodeCondition = addMakedTree(parseLogicOperations(conditionTokens));
    auto nodeBlock = new NodeCodeBlock(tokens.front().getLine());

    Parser parser(nodeBlock);
    parser.addTokens(tokens);

    node->addChildBack(new NodeWhile(tokens.front().getLine(), nodeCondition, nodeBlock));
}

void Parser::parsePrint(std::list<Token> tokens)
{
    tokens.pop_front();
    tokens.pop_front();
    tokens.pop_back();

    auto nodeChild = new NodePrint(tokens.front().getLine());

    nodeChild->addChildBack(addMakedTree(parseOperations(tokens)));
    node->addChildBack(nodeChild);

}

std::list<Node *> Parser::parseOperations(std::list<Token> tokens)
{
    std::list<Node*> nodes;
    for(auto token: toPostfix(tokens, "OPERATION", [](std::string type)
    {
        if (type == "*" || type == "/") { return 1; }
        else if (type == "+" || type == "-") { return 2; }
        else { return 3; }
    }))
    {
        auto type = token.getType();
        if(type == "OPERATION") {
            auto op = token.getValue();
            if (op == "+") {
                nodes.push_back(new NodeSum(token.getLine()));
            } else if (op == "-") {
                nodes.push_back(new NodeSub(token.getLine()));
            } else if (op == "*") {
                nodes.push_back(new NodeMul(token.getLine()));
            } else if (op == "/") {
                nodes.push_back(new NodeDiv(token.getLine()));
            } else if (op == "^") {
                nodes.push_back(new NodeExp(token.getLine()));
            }
        } else if(type == "NUMBER")
        {
            nodes.push_back(new NodeVal(std::stoi(token.getValue()), token.getLine()));
        }
        else if(type == "VAR")
        {
            nodes.push_back(new NodeVar(token.getValue(), token.getLine()));
        }

    }

    return nodes;
}

std::list<Node *> Parser::parseLogicOperations(std::list<Token> tokens)
{
    std::list<Node*> nodes;
    for(auto token: toPostfix(tokens, "LOG_OPERATION", [](std::string type)
    {
        if (type == ">" || type == ">=" || type == "<" || type == "<=") { return 1; }
        else if (type == "==") { return 2; }
        else{ return 4; }
    }))
    {
        auto type = token.getType();
        if(type == "LOG_OPERATION")
        {
            auto op = token.getValue();
            if (op == "<") {
                nodes.push_back(new NodeSmaller(token.getLine()));
            } else if (op == "<=") {
                nodes.push_back(new NodeSmallerOrEq(token.getLine()));
            } else if (op == "==") {
                nodes.push_back(new NodeEq(token.getLine()));
            } else if (op == ">") {
                nodes.push_back(new NodeGreater(token.getLine()));
            } else if (op == ">=") {
                nodes.push_back(new NodeGreaterOrEq(token.getLine()));
            } else if (op == "!=") {
                nodes.push_back(new NodeNotEq(token.getLine()));
            }
        } else if(type == "NUMBER")
        {
            nodes.push_back(new NodeVal(std::stoi(token.getValue()), token.getLine()));
        }
        else if(type == "VAR")
        {
            nodes.push_back(new NodeVar(token.getValue(), token.getLine()));
        }
    }

    return nodes;
}

std::list<Token> Parser::toPostfix(std::list<Token> tokens, const std::string& typeOperation, const std::function<short(std::string type)>& m )
{
    std::list<Token> postfix;
    std::stack<Token> operators;

    for (const auto &token: tokens) {
        const auto& type = token.getType();

        if (type == "LBR")
        {
            operators.push(token);
        } else if (type == "RBR")
        {
            while (operators.top().getType() != "LBR")
            {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        } else if (type == typeOperation)
        {
            while ( !operators.empty() && ( m(token.getValue()) >= m(operators.top().getValue()) ) ) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        } else {
            postfix.push_back(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}


Node* Parser::addMakedTree(std::list<Node*> nodes)
{
    std::stack<Node*> st;

    for (const auto& node: nodes) {
        if (node->isOperation()) {
            node->addChildFront(st.top());
            st.pop();
            node->addChildFront(st.top());
            st.pop();
        }
        st.push(node);
    }
    Node* result = st.top();
    st.pop();

    return result;

}