#pragma once
#include <string>

namespace orz
{
class Util {
public:
  static uint64_t GetTid();
  static uint64_t GetPid();
  static std::string GetProcessName(uint64_t pid = 0);
};
} // namespace orz