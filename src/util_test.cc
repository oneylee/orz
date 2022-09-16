#include "util.h"
#include <iostream>

int main() {
  std::cout << orz::Util::GetPid() << std::endl;
  std::cout << orz::Util::GetTid() << std::endl;
  std::cout << orz::Util::GetProcessName() << std::endl;
  return 0;
}