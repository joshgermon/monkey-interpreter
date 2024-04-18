#include "token.h"
#include <string>

class Lexer {
public:
  std::string input;
  Lexer(std::string);
  void readChar();
  Token nextToken();

private:
  int position;
  int readPosition;
  char ch;
};

Lexer::Lexer(std::string lexer_input) { input = lexer_input; }

void Lexer::readChar() {
  if (readPosition >= input.length()) {
    ch = 0;
  } else {
    ch = input[readPosition];
  }
  position = readPosition;
  readPosition += 1;
}

Token Lexer::nextToken() {
  Token token;
  switch (ch) {
  case '=':
    token = Token(TokenType::ASSIGN, ch);
    break;
  case ';':
    token = Token(TokenType::SEMICOLON, ch);
    break;
  case '(':
    token = Token(TokenType::LPAREN, ch);
    break;
  case ')':
    token = Token(TokenType::RPAREN, ch);
    break;
  case ',':
    token = Token(TokenType::COMMA, ch);
    break;
  case '+':
    token = Token(TokenType::PLUS, ch);
    break;
  case '{':
    token = Token(TokenType::LBRACE, ch);
    break;
  case '}':
    token = Token(TokenType::RBRACE, ch);
    break;
  case 0:
    token = Token(); // EOF token
    break;
  default:
    token = Token(TokenType::ILLEGAL, ch);
    break;
  }
  readChar();
  return token;
}
