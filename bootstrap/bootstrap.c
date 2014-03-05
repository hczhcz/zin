#include "bootstrap.h"

#define ZIN_MODE ZIN_MODE_READ
#include "bootstrap.lst"
#define ZIN_MODE ZIN_MODE_WRITE
#include "bootstrap.lst"
#undef ZIN_MODE
