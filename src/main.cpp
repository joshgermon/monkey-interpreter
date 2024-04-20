#include "repl.h"
#include <iostream>

int main() {
  std::cout << "==== Monkey Interpreter ====" << std::endl;

  Repl repl;
  repl.start();

  std::cout << "==== END ====" << std::endl;
}

