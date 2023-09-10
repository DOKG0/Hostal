#ifndef DTHUESPED_H
#define DTHUESPED_H
#include <string>

//DTHuesped
class DTHuesped{
  private:
    std::string nombre;
    std::string email;
    bool esFinger;
  
  public:
    DTHuesped();
    DTHuesped(std::string _nombre, std::string _email, bool _esFinger);
    DTHuesped(DTHuesped&);
    ~DTHuesped();

    std::string getNombre();
    std::string getEmail();
    bool getEsFinger();
};

#endif 