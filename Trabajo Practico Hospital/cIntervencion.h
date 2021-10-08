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
	cIntervencion(cFecha* FyH, cMedico* medico1);
	virtual ~cIntervencion();


	void Imprimir();
	virtual void RealizarIntervencion(cPaciente* paciente) = 0;
	string to_string();
	float getMonto() { return Monto; }
	cMedico* getMedico() { return m_cMedico; }
	cFecha* getFecha() { return FechayHora; }
	string getID() { return "Algo"; };//No es necesario en la lista
	int getMes() { return FechayHora->getMes(); };
	void setMedico(cMedico* _medico) { m_cMedico = _medico; };
};

