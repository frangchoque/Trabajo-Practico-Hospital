#pragma once

#include <string>
#include "cFecha.h"
using namespace std;

class cPersonal
{
public:
	cPersonal(string dni,cFecha fecha,string nom,string sexo);
	virtual ~cPersonal();

	void Imprimir();
	string to_string();

protected:
	string DNI;
	cFecha Fecha_nacimiento;
	string Nombre;
	string Sexo;

};

