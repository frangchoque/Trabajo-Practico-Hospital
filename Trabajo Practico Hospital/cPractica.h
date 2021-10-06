#pragma once
#include "cIntervencion.h"
class cPractica :
    public cIntervencion
{

private:
	bool Autorizacion_Obra_social;
	string Informe;

public:
	cPractica(cFecha* FyH, cMedico* medico1);
	~cPractica();

	void Imprimir();
	void PedirAutorizacion(cPaciente* paciente);
	void RealizarIntervencion(cPaciente* paciente);
	string to_string();


};

