#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest.h"
#include "../src/lexer.h" // Assuming you have a lexer implementation in lexer.h/cpp
#include "../src/token.h" // Assuming you have a TokenType::implementation in token.h/cpp
#include <vector>

TEST_CASE("NextToken Test") {
  std::string input = R"(let five = 5;
  let ten = 10;

  let add = fn(x, y) {
    x + y;
  };

  let result = add(five, ten);
  !-/*5;
  5 < 10 > 5;

  if (5 < 10) {
    return true;
  } else {
    return false;
  }

  10 == 10;
  10 != 9;
)";

  std::vector<std::pair<TokenType, std::string>> tests = {
      {TokenType::LET, "let"},     {TokenType::IDENT, "five"},
      {TokenType::ASSIGN, "="},    {TokenType::INT, "5"},
      {TokenType::SEMICOLON, ";"}, {TokenType::LET, "let"},
      {TokenType::IDENT, "ten"},   {TokenType::ASSIGN, "="},
      {TokenType::INT, "10"},      {TokenType::SEMICOLON, ";"},
      {TokenType::LET, "let"},     {TokenType::IDENT, "add"},
      {TokenType::ASSIGN, "="},    {TokenType::FUNCTION, "fn"},
      {TokenType::LPAREN, "("},    {TokenType::IDENT, "x"},
      {TokenType::COMMA, ","},     {TokenType::IDENT, "y"},
      {TokenType::RPAREN, ")"},    {TokenType::LBRACE, "{"},
      {TokenType::IDENT, "x"},     {TokenType::PLUS, "+"},
      {TokenType::IDENT, "y"},     {TokenType::SEMICOLON, ";"},
      {TokenType::RBRACE, "}"},    {TokenType::SEMICOLON, ";"},
      {TokenType::LET, "let"},     {TokenType::IDENT, "result"},
      {TokenType::ASSIGN, "="},    {TokenType::IDENT, "add"},
      {TokenType::LPAREN, "("},    {TokenType::IDENT, "five"},
      {TokenType::COMMA, ","},     {TokenType::IDENT, "ten"},
      {TokenType::RPAREN, ")"},    {TokenType::SEMICOLON, ";"},
      {TokenType::BANG, "!"},      {TokenType::MINUS, "-"},
      {TokenType::SLASH, "/"},     {TokenType::ASTERISK, "*"},
      {TokenType::INT, "5"},       {TokenType::SEMICOLON, ";"},
      {TokenType::INT, "5"},       {TokenType::LT, "<"},
      {TokenType::INT, "10"},      {TokenType::GT, ">"},
      {TokenType::INT, "5"},       {TokenType::SEMICOLON, ";"},
      {TokenType::IF, "if"},       {TokenType::LPAREN, "("},
      {TokenType::INT, "5"},       {TokenType::LT, "<"},
      {TokenType::INT, "10"},      {TokenType::RPAREN, ")"},
      {TokenType::LBRACE, "{"},    {TokenType::RETURN, "return"},
      {TokenType::TRUE, "true"},   {TokenType::SEMICOLON, ";"},
      {TokenType::RBRACE, "}"},    {TokenType::ELSE, "else"},
      {TokenType::LBRACE, "{"},    {TokenType::RETURN, "return"},
      {TokenType::FALSE, "false"}, {TokenType::SEMICOLON, ";"},
      {TokenType::RBRACE, "}"},    {TokenType::INT, "10"},
      {TokenType::EQ, "=="},       {TokenType::INT, "10"},
      {TokenType::SEMICOLON, ";"}, {TokenType::INT, "10"},
      {TokenType::NOT_EQ, "!="},   {TokenType::INT, "9"},
      {TokenType::SEMICOLON, ";"}, {TokenType::ENDOF, ""},
  };

  Lexer l(input);

  for (size_t i = 0; i < tests.size(); ++i) {
    Token tok = l.nextToken();
    CHECK(tok.type == tests[i].first);
    CHECK(tok.literal == tests[i].second);
  }
}
