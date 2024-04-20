#pragma once

#include <string>

enum class TokenType {
  ILLEGAL,
  ENDOF,
  IDENT,
  INT,
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  FUNCTION,
  LET,
  ASSIGN,
  PLUS,
  MINUS,
  BANG,
  ASTERISK,
  SLASH,
  LT,
  GT,
  TRUE,
  FALSE,
  IF,
  ELSE,
  RETURN,
  EQ,
  NOT_EQ
};

class Token {
public:
    std::string literal;
    TokenType type;
    Token(TokenType type, char ch) : type(type), literal(1, ch) {}
    Token(TokenType type, std::string str) : type(type), literal(str) {}
    Token() : type(TokenType::ENDOF), literal("") {}
};

TokenType lookupIdent(std::string ident);
