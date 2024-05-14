#include "parser.h"
#include "ast.h"
#include "token.h"
#include "vector"
#include <memory>

void Parser::nextToken() {
  curToken = peekToken;
  peekToken = lexer.nextToken();
}

std::unique_ptr<Statement> Parser::parseStatement() {
  switch (curToken.type) {
    case TokenType::LET:
      return parseLetStatement();
    default:
        return nullptr;
  }
}

std::unique_ptr<LetStatement> Parser::parseLetStatement() {
  auto stmt = std::make_unique<LetStatement>(curToken);
  if(!expectPeek(TokenType::IDENT)) {
    return std::unique_ptr<LetStatement>(nullptr);
  }

  stmt->name = Identifier(curToken, curToken.literal);

  if(!expectPeek(TokenType::ASSIGN)) {
    return std::unique_ptr<LetStatement>(nullptr);
  }

  while(curTokenIs(TokenType::SEMICOLON)) {
    // TODO: skipping expressions until semicolon
    nextToken();
  }

  return stmt;
}

bool Parser::peekTokenIs(TokenType token) {
  return peekToken.type == token;
}

bool Parser::curTokenIs(TokenType token) {
  return curToken.type == token;
}

bool Parser::expectPeek(TokenType token) {
  if(peekTokenIs(token)) {
    nextToken();
    return true;
  } else {
    return false;
  }
}

std::unique_ptr<Program> Parser::parseProgram() {
  auto program = std::make_unique<Program>();
  program->statements = std::vector<std::unique_ptr<Statement>>();

  while(curToken.type != TokenType::ENDOF) {
    auto stmt = parseStatement();
    if(stmt != nullptr) {
      program->statements.push_back(stmt);
    }
    nextToken();
  }

  return program;
}
