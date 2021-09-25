#pragma once

#include <string>
using namespace std;

class cPersonal
{
public:
	cPersonal();
	virtual ~cPersonal();

	void Imprimir();
	string to_string();

protected:
	string DNI;
	cFecha Fecha_nacimiento;
	string Nombre;
	string Sexo;

};

