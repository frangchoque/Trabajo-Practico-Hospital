#pragma once
#include <string>
#include "cFecha.h"

using namespace std;

class cMedicamento
{
private:
	string Marca;
	string Nombre;
	cFecha* Vencimiento;
public:
	cMedicamento(string Marca,string Nombre,cFecha*vencimiento);
	~cMedicamento();

	void Imprimir();
	string to_string();



};

