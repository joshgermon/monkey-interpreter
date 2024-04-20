#include "repl.h"
#include "lexer.h"
#include <iostream>

constexpr const char* prompt = ">>";

void Repl::start() {
  while(true) {
    // TODO: not quite sure why this prints for every token literal
    std::cout << prompt;

    std::string userInput;
    std::cin >> userInput;

    Lexer lexer(userInput);

    for(Token tok = lexer.nextToken(); tok.type != TokenType::ENDOF; tok = lexer.nextToken()) {
      std::cout << "Literal::" << tok.literal << std::endl;
    }
  }
}
