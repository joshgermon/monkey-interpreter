#include "lexer.h"
#include "token.h"
#include <string>

bool isLetter(char ch) {
  return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

bool isDigit(char ch) { return '0' <= ch && ch <= '9'; }

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

  skipWhitespace();

  switch (ch) {
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
  case '{':
    token = Token(TokenType::LBRACE, ch);
    break;
  case '}':
    token = Token(TokenType::RBRACE, ch);
    break;
  case '=':
    if(peekChar() == '=') {
      char initCh = ch;
      readChar();
      token = Token(TokenType::EQ, std::string { initCh, ch });
    }else {
      token = Token(TokenType::ASSIGN, ch);
    }
    break;
  case '+':
    token = Token(TokenType::PLUS, ch);
    break;
  case '-':
    token = Token(TokenType::MINUS, ch);
    break;
  case '!':
    if(peekChar() == '=') {
      char initCh = ch;
      readChar();
      token = Token(TokenType::NOT_EQ, std::string { initCh, ch });
    }else {
      token = Token(TokenType::BANG, ch);
    }
    break;
    token = Token(TokenType::BANG, ch);
    break;
  case '/':
    token = Token(TokenType::SLASH, ch);
    break;
  case '*':
    token = Token(TokenType::ASTERISK, ch);
    break;
  case '<':
    token = Token(TokenType::LT, ch);
    break;
  case '>':
    token = Token(TokenType::GT, ch);
    break;
  case 0:
    token = Token(); // EOF token
    break;
  default:
    if (isLetter(ch)) {
      // If char is a letter read the full "word" and save to literal
      token.literal = readIdentifier();
      // Check against keywords
      token.type = lookupIdent(token.literal);
      // Return early as lookupIdent already calls readChar();
      return token;
    } else if (isDigit(ch)) {
      token.type = TokenType::INT;
      token.literal = readNumber();
      // Return early as lookupNumber already calls readChar(); **HOLY FUKC&&&&
      return token;
    } else {
      token = Token(TokenType::ILLEGAL, ch);
    }
    break;
  }
  readChar();
  return token;
}

std::string Lexer::readIdentifier() {
  int pos = position;
  while (isLetter(ch)) {
    readChar();
  }
  // Calculate the length of the digit
  int length = position - pos;
  // Extract the identifier using substr
  return input.substr(pos, length);
}

std::string Lexer::readNumber() {
  int pos = position;
  while (isDigit(ch)) {
    readChar();
  }

  // Calculate the length of the digit
  int length = position - pos;
  // Extract the identifier using substr
  return input.substr(pos, length);
}

void Lexer::skipWhitespace() {
  // Continue progressing while the current char is whitespace
  while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
    readChar();
  }
}

char Lexer::peekChar() {
  if (readPosition >= input.length()) {
    return 0;
  }
  return input[readPosition];
}
