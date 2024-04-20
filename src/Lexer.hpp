#pragma once

#include "Token.hpp"
#include <string>

class Lexer {
public:
  std::string input;
  char ch;
  Lexer(std::string lexerInput)
      : input(lexerInput), position(0), readPosition(0) {
    readChar();
  };
  Token nextToken();

private:
  int position;
  int readPosition;
  void readChar();
  char peekChar();
  void skipWhitespace();
  std::string readIdentifier();
  std::string readNumber();
};

bool isLetter(char ch);
