#pragma once

#include "cFecha.h"
#include <string>
using namespace std;

class cPersonal
{
public:
	cPersonal(string dni,cFecha fecha,string nom,string sexo);
	virtual ~cPersonal();
	void Imprimir();
	string to_string();
	string getID() { return DNI; };

protected:
	string DNI;
	cFecha Fecha_nacimiento;
	string Nombre;
	string Sexo;
};

