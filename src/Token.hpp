#ifndef TOKEN_H
#define TOKEN_H

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
    TokenType type;
    Token(TokenType type, char ch) : type(type), literal(1, ch) {}
    Token() : type(TokenType::ENDOF), literal("") {}

private:
  std::string literal;
};

#endif // TOKEN_H

