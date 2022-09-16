#pragma once

#define DISALLOW_COPY_AND_ASSIGN(type)  \
  type(const type&) = delete;           \
  type& operator=(const type&) = delete
