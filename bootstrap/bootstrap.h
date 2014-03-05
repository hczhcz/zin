#ifndef ZIN_BOOTSTRAP_H
#define ZIN_BOOTSTRAP_H

#include "../base/base.lst"

#define ZIN_MODE ZIN_MODE_HEADER_PROTO
#include "bootstrap.lst"
#define ZIN_MODE ZIN_MODE_HEADER_READ
#include "bootstrap.lst"
#define ZIN_MODE ZIN_MODE_HEADER_WRITE
#include "bootstrap.lst"
#undef ZIN_MODE

#endif
