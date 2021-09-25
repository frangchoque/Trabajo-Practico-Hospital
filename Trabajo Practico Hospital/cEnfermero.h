#pragma once
#include "cPersonal.h"
#include "cMedicamento.h"

class cEnfermero :
    public cPersonal
{

public:
	cEnfermero();
	virtual ~cEnfermero();

	void AdministrarMedicamento();
	void Imprimir();
	string to_string();
	void Verificar_vencimiento(cMedicamento* medicamento);

private:
	const unsigned int Matricula;
	/**
	 * true=dia false=noche
	 */
	bool Turno;
};

