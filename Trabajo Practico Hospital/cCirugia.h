#pragma once
#include "cPaciente.h"
#include "cIntervencion.h"
#include "cEnfermero.h"

class cCirugia :
    public cIntervencion
{

public:
	cCirugia();
	virtual ~cCirugia();
	cEnfermero* m_cEnfermero;
	cMedico* m_cMedico;
	cMedicamento* m_cMedicamento;

	void Imprimir();
	void Prequirurgico(cPaciente* paciente);
	void RealizarIntervencion();
	string to_string();

private:
	cFecha Alta;
	bool Ambulatoria;
	unsigned int Duracion;
	cFecha Fecha_Hora_inicio;
	string Procedimiento;

};

