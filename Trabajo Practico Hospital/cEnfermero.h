#pragma once
#include <ctime>
#include "cPersonal.h"
#include "cMedicamento.h"
using namespace std;
class cEnfermero :
    public cPersonal
{

public:
	cEnfermero(bool turno, string dni, cFecha fecha, string nom, string sexo);
	virtual ~cEnfermero();
	string GenerarMatricula();
	void AdministrarMedicamento();
	void Imprimir();
	string to_string();
	void Verificar_vencimiento(cMedicamento* medicamento);

private:
	const string Matricula;
	bool Turno;//true=dia false=noche
};

