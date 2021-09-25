#pragma once
#include "cIntervencion.h"
class cPractica :
    public cIntervencion
{

public:
	cPractica();
	~cPractica();

	void Imprimir();
	void PedirAutorizacion();
	void RealizarIntervencion();
	string to_string();

private:
	bool Autorizacion_Obra_social;
	string Informe;

};

