#pragma once
#include <mutex>
// #include <thread>
#include <memory>
#include "macro.h"
#include <iostream>

namespace orz
{
template<typename T>
class Singleton {
public:
  static T* GetInstance() {
    static std::once_flag flag;
    std::call_once(flag, [&]() { _singleton.reset(new T()); });
    return _singleton.get();
  }

protected:
  Singleton() {}
  ~Singleton() {}
  static std::unique_ptr<T> _singleton;

private:
  DISALLOW_COPY_AND_ASSIGN(Singleton);

};

template<typename T>
std::unique_ptr<T> Singleton<T>::_singleton = nullptr;
} // namespace orz
