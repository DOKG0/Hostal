#ifndef HUESPED_H_
#define HUESPED_H_
#include <string>

class Huesped {

private:
	std::string nombre;
	std::string email;
	bool esFinger;

public:
	Huesped();
	Huesped(std::string, std::string, bool);

	~Huesped();

	void setNombre(std::string);
	void setEmail(std::string);
	void setEsfinger(bool);
	
	std::string getNombre();
	std::string getEmail();
	bool getEsfinger();

	//virtual ~Huesped();
};

#endif 