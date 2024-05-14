#pragma once

#include "token.h"
#include <memory>
#include <string>
#include <vector>

class Node {
  public:
    virtual std::string tokenLiteral() = 0;
};

class Statement: public Node {
  private:
    virtual std::unique_ptr<Node> statementNode() = 0;
};

class Expression: public Node {
  private:
    virtual std::unique_ptr<Node> expressionNode() = 0;
};

class Program: public Node {
  public:
    std::string tokenLiteral() override;
    std::vector<std::unique_ptr<Statement>> statements;
};

class Identifier: public Expression {
  public:
    Identifier(Token token, std::string value): token(token), value(value) {};
    std::string tokenLiteral() override;
    std::unique_ptr<Node> expressionNode() override;
    Token token;
    std::string value;
};

class LetStatement: public Statement {
  public:
    LetStatement(Token token): token(token) {};
    std::string tokenLiteral() override;
    std::unique_ptr<Node> statementNode() override;
    Token token;
    Identifier name;
    Expression* value;
};

