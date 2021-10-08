#pragma once
#include "cPaciente.h"
#include "cIntervencion.h"
#include "cEnfermero.h"
#include"cMedicamento.h"

class cCirugia :
    public cIntervencion
{
private:
	cFecha* Alta;
	bool Ambulatoria;
	int Duracion;
	cFecha* Fecha_Hora_inicio;
	string Nombre_Procedimiento;
	cMedico* MedicoAdicional;
	cEnfermero* Enfermero;
	cMedicamento* medicamento; // ver como va la lista
public:
	cCirugia(cFecha* FyH, cMedico* medico1,cFecha*alta,bool ambulatoria,cMedico*medicoadicional,cEnfermero*enfermero);
	virtual ~cCirugia();

	void Prequirurgico(cPaciente* paciente);
	void RealizarIntervencion(cPaciente* paciente);
	cMedicamento* getmedicamento() { return medicamento; };


	string to_string();
	void Imprimir();


};

