#pragma once
#include <string>
#include "cFecha.h"

using namespace std;

class cMedicamento
{

public:
	cMedicamento();
	~cMedicamento();

	void Imprimir();
	string to_string();

private:
	string Marca;
	string Nombre;
	cFecha Vencimiento;

};

