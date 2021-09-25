#pragma once
#include "cMedico.h"

class cIntervencion
{

public:
	cIntervencion();
	virtual ~cIntervencion();
	cMedico* m_cMedico;

	void Imprimir();
	virtual void RealizarIntervencion();
	string to_string();

protected:
	string Diagnostico;
	cFecha FechayHora;
	float Monto;

};

