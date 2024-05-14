#include "../lib/doctest.h"
#include "../src/parser.h"
#include "../src/lexer.h"
#include <iostream>
#include <memory>
#include <string>

bool testLetStatement(std::unique_ptr<Statement> s, std::string &name) {
    if (s.tokenLiteral() != "let") {
        std::cerr << "s.tokenLiteral not 'let'. got=" << s.tokenLiteral() << std::endl;
        return false;
    }

    // C++ doesn't have a direct equivalent of Go's type assertion.
    // We use dynamic_cast for runtime type checking.
    const LetStatement* letStmt = dynamic_cast<const LetStatement*>(&s);
    if (!letStmt) {
        std::cerr << "s not *ast.LetStatement. got=" << typeid(s).name() << std::endl;
        return false;
    }

    if (letStmt->name.value != name) {
        std::cerr << "letStmt.Name.Value not '" << name << "'. got=" << letStmt->name.value << std::endl;
        return false;
    }

    // Assuming Name is a string in LetStatement. Adjust according to your actual implementation.
    if (letStmt->name.token.literal != name) {
        std::cerr << "s.Name not '" << name << "'. got=" << letStmt->name.token.literal << std::endl;
        return false;
    }

    return true;
}

TEST_CASE("Parser Test") {
  std::string input = R"(
  let x = 5;
  let y = 10;
  let foobar = 838383;
  )";

  Lexer lexer(input);
  Parser parser(lexer);

  auto program = parser.parseProgram();

  if(program->statements.size() != 3) {
    FAIL("program.statements does not contain 3 statements.");
  }

  std::vector<std::string> testsExpectedIdentifiers{ "x", "y", "foobar" };

  for (size_t i = 0; i < testsExpectedIdentifiers.size(); ++i) {
    auto statement = std::move(program->statements[i]);
    CHECK(testLetStatement(statement, testsExpectedIdentifiers[i]));
  }
}
