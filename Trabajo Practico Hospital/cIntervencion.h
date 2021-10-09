#pragma once
//#include "cMedico.h"
class cPaciente;
class cMedico;
#include <string>
#include "cFecha.h"
//class cFecha;

using namespace std;

class cIntervencion
{
protected:
	string Diagnostico;
	cFecha FechayHora;
	float Monto;
	cMedico* Medico_Principal;

public:
	cIntervencion(cFecha FyH, cMedico* medico1);
	virtual ~cIntervencion();


	void Imprimir();
	virtual void RealizarIntervencion(cPaciente* paciente) = 0;
	string to_string();
	float getMonto() { return Monto; }
	cMedico* getMedico();
	cFecha getFecha();
	string getID() { return "Algo"; };//No es necesario en la lista

};


