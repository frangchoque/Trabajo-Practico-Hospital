#pragma once
#include "enums.h"
#include <string>
using namespace std;

class cPaciente
{

public:
	cPaciente();
	virtual ~cPaciente();

	void Imprimir();
	string to_string();

private:
	bool Afiliado;
	string DNI;
	cFecha Fecha_nacimiento;
	string Nombre;
	unsigned int Numero_afiliado;
	eObraSocial Obra_social;
	eProblema Problema;
	string Sexo;
};

