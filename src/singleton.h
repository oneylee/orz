#pragma once
#include <mutex>
// #include <thread>
#include <memory>
#include "macro.h"

namespace orz
{
template<typename T>
class Singleton {
public:
  static T* GetInstance() {
    std::once_flag flag;
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
static std::unique_ptr<T> Singleton<T>::_singleton;
} // namespace orz
