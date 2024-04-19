#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"
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

#endif // !LEXER_HPP
