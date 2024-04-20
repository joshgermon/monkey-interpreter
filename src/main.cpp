#include <iostream>

// Function to traverse the string and
// print the characters of the string
void TraverseString(std::string &str)
{
    // Traverse the string
    for (int i = 0; i < str.length(); i++) {

        // Print current character
      std::cout << str[i]<< " " << std::endl;
    }

}

int main() {
  std::cout << "==== Monkey Interpreter ====" << std::endl;
std::string input = R"(
    let five = 5;
    let ten = 10;
    let add = fn(x, y) {
        x + y;
    };
    let result = add(five, ten);
)";

  TraverseString(input);

  std::cout << "==== END ====" << std::endl;
}

