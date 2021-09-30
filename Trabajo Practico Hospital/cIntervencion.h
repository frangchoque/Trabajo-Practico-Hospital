#pragma once
#include "cMedico.h"

class cIntervencion
{
protected:
	string Diagnostico;
	cFecha* FechayHora;
	float Monto;
	cMedico* m_cMedico;

public:
	cIntervencion(cFecha*FyH,cMedico*medico1);
	virtual ~cIntervencion();
	

	void Imprimir();
	virtual void RealizarIntervencion();
	string to_string();


};

