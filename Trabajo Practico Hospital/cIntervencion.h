#pragma once
#include "cMedico.h"
class cPaciente;
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
	virtual void RealizarIntervencion(cPaciente* paciente)=0;
	string to_string();


};

