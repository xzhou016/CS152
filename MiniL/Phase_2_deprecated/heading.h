// -*- c++ -*- 
// heading.h

// The following line suppresses an unused-function warning.

#include <set.h>
#include <string.h>
#include <map.h>
#include <list.h>
#include <vector.h>
#include <sstream.h>
#include <cassert.h>
#include <cctype.h>
#include <cstring.h>
#include <stack.h>
#include <stdio.h>

inline std::string itoa( int x ) {  // converts an integer to a string.
  ostringstream s;
  s << x;
  return s.str();
}




