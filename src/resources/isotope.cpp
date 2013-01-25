
#include "isotope.h"

using namespace std;
using namespace resource;

isotope::isotope(int A, int Z, bool meta) :
  a_(A), z_(Z), meta_(meta)
{
}

int isotope::A()
{
  return a_;
}

int isotope::Z()
{
  return z_;
}

int isotope::zaid()
{
  return 10000*a_ + 10*z_ + (meta_ ? 1 : 0);
}
