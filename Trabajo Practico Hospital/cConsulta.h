#pragma once
#include "cIntervencion.h"
class cConsulta :
    public cIntervencion
{

public:
	cConsulta(cFecha* FyH, cMedico* medico1,eProblema dolor);
	~cConsulta();

	void Imprimir();
	void RealizarIntervencion();
	string to_string();

private:
	string Indicaciones;
	eProblema Dolor;//para saber que indicaciones dar
};

