#include "../lib/doctest.h"
#include "../src/Token.hpp"
#include "../src/Lexer.hpp"
#include <utility>
#include <vector>

// Test case for the add function
TEST_CASE("Test Lexer::nextToken") {
 const char* input = "=+(){},;";

 std::vector<std::pair<TokenType, char>> tokenVariants = {
  { TokenType::ASSIGN, '=' },
  { TokenType::PLUS, '+' },
  { TokenType::LPAREN, '('},
  { TokenType::RPAREN, '}'},
  { TokenType::LBRACE, '{'},
  { TokenType::LBRACE, '{'},
  { TokenType::COMMA, ','},
  { TokenType::SEMICOLON, ';'},
  { TokenType::ENDOF, ' '},
 };

 Lexer lexer(input);

 for(const auto& tt : tokenVariants) {
    TokenType expectedToken = tt.first;
    char literal = tt.second;

    SUBCASE("Testing Token Variant") {
      Token tok = lexer.nextToken();
      CHECK(tok.type == expectedToken);
    }
 }

}
