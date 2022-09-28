#pragma once
#include "macro.h"
#include "singleton.h"

namespace orz
{
class Logging {
public:
  enum LEVEL {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    MAX,
  };

  enum TYPE {
    CONSOLE,
    FILE,
    ALL,
  };

  Logging() : _level(INFO), _type(FILE) {}

  ~Logging() {};

  bool Logv(LEVEL level, const char* filename, 
      int line, const char* func, const char* fmt...);

  Logging* SetLogFileName(const std::string& filename) {
    _filename = std::move(filename);
    return orz::Singleton<orz::Logging>::GetInstance();
  }

  LEVEL GetLevel() const { return _level; }
  Logging* SetLevel(LEVEL level) {
    _level = level;
    return orz::Singleton<orz::Logging>::GetInstance();
  }

  TYPE GetOutType() const { return _type; }
  Logging* SetOutType(TYPE type) {
    _type = type;
    return orz::Singleton<orz::Logging>::GetInstance();
  }

private:
  static const char* _level_str[Logging::MAX];
  std::string _filename;
  LEVEL _level;
  TYPE _type;
};


// #define hlog(level, ...) orz::Singleton<orz::Logging>::GetInstance()->Logv(level, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define hlog(level, ...)  \
  do {                                                                        \
    if (level <= orz::Singleton<orz::Logging>::GetInstance()->GetLevel()) {   \
      orz::Singleton<orz::Logging>::GetInstance()->Logv(level,                \
          __FILE__, __LINE__, __func__, __VA_ARGS__);                         \
    }                                                                         \
  } while(false)


#define ORZ_DEBUG(...) hlog(orz::Logging::DEBUG, __VA_ARGS__)
#define ORZ_INFO(...) hlog(orz::Logging::INFO, __VA_ARGS__)
#define ORZ_WARN(...) hlog(orz::Logging::WARN, __VA_ARGS__)
#define ORZ_ERROR(...) hlog(orz::Logging::ERROR, __VA_ARGS__)
#define ORZ_FATAL(...) hlog(orz::Logging::FATAL, __VA_ARGS__)


} // orz end
