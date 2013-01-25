
#include <string>

namespace resource
{

  class isotope
  {
  public:
    isotope(int A=1, int Z=1, bool meta=false);

    int A();
    
    int Z();
    
    int zaid();

  private:
    int a_, z_;
    bool meta_;
  };
  
}
