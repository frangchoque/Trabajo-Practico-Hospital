#pragma once
#include "cIntervencion.h"
#include "cPaciente.h"
class cConsulta :
    public cIntervencion
{
private:
	string Indicaciones;
	//eProblema Dolor;//para saber que indicaciones dar

public:
	cConsulta(cFecha* FyH, cMedico* medico);
	~cConsulta();

	
	void RealizarIntervencion(cPaciente* paciente);
	string to_string();
	void Imprimir();

};

