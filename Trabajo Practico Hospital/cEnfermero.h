#pragma once
#include <ctime>
#include "cPersonal.h"
#include "cMedicamento.h"
#include "cListaT.h"


using namespace std;
class cEnfermero :
    public cPersonal
{

public:
	cEnfermero(string dni, cFecha fecha, string nom, string sexo,bool turno);
	~cEnfermero();
	string GenerarMatricula();
	void AdministrarMedicamento(cMedicamento* medicamento);
	void Imprimir();
	string to_string();
	void Verificar_vencimiento(cMedicamento* medicamento);
	string Turno_to_string();
	static ListaT<cMedicamento>* getInventario();

private:
	const string Matricula;
	bool Turno;//true=dia false=noche

	static ListaT<cMedicamento>* Inventario;//Hago una lista static para que todos los enfermeros pueden acceder a ella
};

