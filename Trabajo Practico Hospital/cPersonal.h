#pragma once

#include "cFecha.h"
#include <string>
using namespace std;

class cPersonal
{
public:
	cPersonal(string dni, cFecha fecha, string nom, string sexo);
	virtual ~cPersonal() = 0;
	void Imprimir();
	string to_string();
	string getID() { return DNI; };
	string getNombre() { return Nombre; };

protected:
	string DNI;
	cFecha Fecha_nacimiento;
	string Nombre;
	string Sexo;
};

