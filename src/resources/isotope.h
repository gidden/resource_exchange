
namespace resource
{

  class isotope
  {
  public:
    /// constructor, defaults to hydrogen
    isotope(int A=1, int Z=1, bool meta=false);

    /// @return the atomic number
    int A();
    
    /// @return the proton number
    int Z();

    /// @return the meta stable state flag
    bool meta();
    
    /// @return the ZAID number
    int zaid();

  private:
    int a_, z_;
    bool meta_;
  };
  
}
