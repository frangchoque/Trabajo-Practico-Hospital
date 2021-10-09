#pragma once
#include <string>
#include "cFecha.h"

class cEnnfermero;
using namespace std;

class cMedicamento
{
private:
	string Marca;
	string Nombre;
	cFecha* Vencimiento;
	friend class cEnfermero;

public:
	cMedicamento(string Marca,string Nombre,cFecha*vencimiento);
	~cMedicamento();

	string getNombre() { return Nombre; };
	void Imprimir();
	string to_string();
	string getID() { return Nombre; };//Para la lista

};

