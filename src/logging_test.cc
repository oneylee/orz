#include <iostream>
#include "logging.h"

int main()
{
  auto ll = orz::Singleton<orz::Logging>::GetInstance()->SetLogFileName("log.log")->SetLevel(orz::Logging::DEBUG);
  // auto log = orz::Singleton<orz::Logging>::GetInstance()->SetLevel(orz::Logging::DEBUG);

  // std::cout << orz::Singleton<orz::Logging>::GetInstance()->GetLevel() << std::endl;
  ORZ_DEBUG("hello");
  ORZ_INFO("INFO");
  return 0;
}

// g++ -g -std=c++11 logging_test.cc logging.cc -lpthread