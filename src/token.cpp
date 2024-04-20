#include "Token.hpp"
#include <unordered_map>


TokenType lookupIdent(std::string ident) {
  static const std::unordered_map<std::string, TokenType> keywords = {
    {"let", TokenType::LET },
    {"fn", TokenType::FUNCTION },
  };

  // Find keyword, if it exists, return enum value
  auto keywordItr = keywords.find(ident);
  if (keywordItr != keywords.end()) {
    return keywordItr->second; // AKA the value
  }

  // Otherwise return identifier
  return TokenType::IDENT;
}

