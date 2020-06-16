#include <iostream>
#include <string>
#include <vector>

// using namespace std;
int main() {
  std::vector<std::string> brothers{"David", "Singhal", "oops"};
  for (std::string const &brother : brothers) {
    std::cout << "Hello " << brother << '\n';
  }
  return 0;
}
