#pragma once
#include "cIntervencion.h"
class cConsulta :
    public cIntervencion
{

public:
	cConsulta();
	~cConsulta();

	void Imprimir();
	void RealizarIntervencion();
	string to_string();

private:
	string Indicaciones;
};

