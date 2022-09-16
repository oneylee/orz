#include "util.h"
#include <unistd.h>
#include <sys/syscall.h>

namespace orz
{
static const uint32_t BUF_LEN = 10240;

uint64_t Util::GetPid() {
  return getpid();
}

uint64_t Util::GetTid() {
  return syscall(SYS_gettid);
}

std::string Util::GetProcessName(uint64_t pid) {
  std::string path("/proc/");
  if (pid == 0) {
    path.append(std::to_string(GetPid()));
  } else {
    path.append(std::to_string(pid));
  }
  path.append("/exe");

  char buf[BUF_LEN] = {0};
  ssize_t len = readlink(path.data(), buf, BUF_LEN);
  if (len == -1) perror("readlink error: ");
  if (len == -1 || len > BUF_LEN) return "UNKNOWN";

  buf[len] = '\0';
  for (int i = len; i >= 0; --i) {
    if (buf[i] == '/') {
      ++i;
      return std::string(buf + i, len - i);
    }
  }
  return std::string(buf);
}
  
} // namespace orz

