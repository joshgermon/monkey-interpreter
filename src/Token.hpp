#pragma once

#include <string>

enum class TokenType {
  ILLEGAL,
  ENDOF,
  IDENT,
  INT,
  ASSIGN,
  PLUS,
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  FUNCTION,
  LET
};

class Token {
public:
    std::string literal;
    TokenType type;
    Token(TokenType type, char ch) : type(type), literal(1, ch) {}
    Token() : type(TokenType::ENDOF), literal("") {}
};

TokenType lookupIdent(std::string ident);
