#pragma once

#include "ast.h"
#include "lexer.h"
#include "token.h"
#include <memory>

class Parser {
  Lexer &lexer;

  Token curToken;
  Token peekToken;

public:
  Parser(Lexer &lexer) : lexer(lexer) {
    // Read two tokens, so curToken and peekToken are both set
    nextToken();
    nextToken();
  };
  std::unique_ptr<Program> parseProgram();

private:
  void nextToken();
  bool expectPeek(TokenType token);
  bool peekTokenIs(TokenType token);
  bool curTokenIs(TokenType token);
  std::unique_ptr<Statement> parseStatement();
  std::unique_ptr<LetStatement> parseLetStatement();
};

