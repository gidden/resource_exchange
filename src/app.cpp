
#include "isotope.h"

#include <iostream>

using namespace std;
using namespace resource;

int main()
{
  isotope i(92,235);
  cout << i.A() << " " << i.Z() << " " << i.zaid() << endl;

  return 0;
}
