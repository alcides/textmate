#include "symbols.hpp"
int local_double(int n) { return n * 2; }
int main() {
  const char* greeting = "Olá 🌍"; int result = local_double(3);
  return shared_add(result, local_double(4));
}
