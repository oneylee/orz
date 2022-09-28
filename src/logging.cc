#include "logging.h"
#include "util.h"
#include <iostream>
#include <stdio.h>
#include <ctime>

namespace orz
{
const char* Logging::_level_str[Logging::MAX] = {
    "FATAL",
    "ERROR",
    "WARN ",
    "INFO ",
    "DEBUG",};

  bool Logging::Logv(LEVEL level, const char* filename, int line,
      const char* func, const char* fmt...) {
    // std::cout << _level_str[level] << " " << filename << " " << line << " " << func;
    char buf[10240];
    char* start = buf;
    char* end = start + 10240;
    *start++ = '[';

    time_t tt = time(nullptr);
    struct tm tm;
    localtime_r(&tt, &tm);
    size_t offset = strftime(start, end - start, "%F %T", &tm);
    start += offset;
    *start++ = ']';
    *start++ = '-';
    *start++ = '[';

    offset = snprintf(start, end - start, "%s]-[%llu]-[%s]: ", _level_str[level], 
        orz::Util::GetPid(), orz::Util::GetProcessName(orz::Util::GetPid()).data());
    start += offset;

    va_list al;
    offset = snprintf(start, end - start, fmt, al);
    start += offset;

    start = std::min(start, end - 2);
    *++start = '\n';
    *++start = '\0';

    std::cout << buf << std::endl;
    return true;
  }
  
} // namespace orz
