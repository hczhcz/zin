#ifndef ZIN_BOOTSTRAP_H
#define ZIN_BOOTSTRAP_H

#include "../base/_all.h"

#define ZIN_MODE ZIN_MODE_HEADER_PROTO
#include "_list.inc"
#define ZIN_MODE ZIN_MODE_HEADER_READ
#include "_list.inc"
#define ZIN_MODE ZIN_MODE_HEADER_WRITE
#include "_list.inc"
#undef ZIN_MODE

#endif
