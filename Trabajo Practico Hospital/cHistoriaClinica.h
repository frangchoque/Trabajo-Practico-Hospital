#pragma once
#include "cIntervencion.h"
#include "cPaciente.h"
#include <string>
#include "enums.h"
#include  "cFecha.h"
using namespace std;

class cHistoriaClinica
{

public:
	cHistoriaClinica();
	virtual ~cHistoriaClinica();
	cIntervencion* m_cIntervencion;
	cPaciente* m_cPaciente;

	void Imprimir();
	string to_string();

private:
	/**
	 * si no esta afiliado, no tiene numero de afiliado
	 */
	bool Afiliado;
	static unsigned int Contador;
	const string DNI;
	const cFecha Fecha_nacimiento;
	const unsigned int ID;
	bool Internado;
	string Nombre;
	unsigned int Numero_afiliado;
	eObraSocial Obra_social;
	string Sexo;
};

