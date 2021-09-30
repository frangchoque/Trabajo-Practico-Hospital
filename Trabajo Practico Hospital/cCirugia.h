#pragma once
#include "cPaciente.h"
#include "cIntervencion.h"
#include "cEnfermero.h"

class cCirugia :
    public cIntervencion
{
private:
	cFecha* Alta;
	bool Ambulatoria;
	unsigned int Duracion;
	cFecha* Fecha_Hora_inicio;
	string Procedimiento;
	cMedico* MedicoAdicional;
	cEnfermero* Enfermero;
	//falta lista de medicamentos
public:
	cCirugia(cFecha* FyH, cMedico* medico1,cFecha*alta,cFecha*FyHinicio,unsigned int duracion,bool ambulatoria,cMedico*medicoadicional,cEnfermero*enfermero);
	virtual ~cCirugia();
	cEnfermero* m_cEnfermero;
	cMedico* m_cMedico;
	cMedicamento* m_cMedicamento;

	void Imprimir();
	void Prequirurgico(cPaciente* paciente);
	void RealizarIntervencion();
	string to_string();



};

