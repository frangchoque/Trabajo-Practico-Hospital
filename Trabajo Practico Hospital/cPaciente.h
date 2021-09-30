#pragma once
#include "enums.h"
#include <string>
#include"cFecha.h"
using namespace std;

class cPaciente
{
private:
	bool Afiliado;
	string DNI;
	cFecha* Fecha_nacimiento;
	string Nombre;
	unsigned int Numero_afiliado;
	eObraSocial Obra_social;
	eProblema Problema;
	string Sexo;

public:
	cPaciente(bool afiliado,string nombre,cFecha*nacimiento,eObraSocial obra_social,string dni,string sexo,eProblema problema);
	virtual ~cPaciente();
	void NumeroAfiliado();//si esta afiliado le asigna un numero de afiliado
	void Imprimir();
	string to_string();


};

