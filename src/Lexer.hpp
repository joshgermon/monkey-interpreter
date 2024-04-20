#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"
#include <string>

class Lexer {
public:
  std::string input;
  char ch;
  Lexer(std::string lexerInput): input(lexerInput), position(0), readPosition(0) { readChar(); };
  Token nextToken();

private:
  int position;
  int readPosition;
  void readChar();
  void skipWhitespace();
  std::string readIdentifier();
  std::string readNumber();
};


bool isLetter(char ch);

#endif // !LEXER_HPP
