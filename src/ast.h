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
    std::vector<Statement> statements;
};

class Identifier: public Expression {
  public:
    std::string tokenLiteral() override;
    std::unique_ptr<Node> expressionNode() override;
    Token token;
    std::string value;
};

class LetStatement: public Statement {
  public:
    std::string tokenLiteral() override;
    std::unique_ptr<Node> statementNode() override;
    Token token;
    Identifier name;
    Expression* value;
};

