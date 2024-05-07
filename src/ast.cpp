#include "ast.h"
#include <memory>
#include <string>

std::string Program::tokenLiteral() {
  if (statements.size() > 0) {
    return statements[0].tokenLiteral();
  } else {
    return "";
  }
}

std::unique_ptr<Node> LetStatement::statementNode() { }

std::string LetStatement::tokenLiteral() {
  return token.literal;
}

std::unique_ptr<Node> Identifier::expressionNode() { }

std::string Identifier::tokenLiteral() {
  return token.literal;
}
