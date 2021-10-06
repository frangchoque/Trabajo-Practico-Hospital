#pragma once
#include "cPersonal.h"
#include "enums.h"
#include "cPaciente.h"

class cMedico :
    public cPersonal
{

public:
	cMedico(string dni, cFecha* fecha, string nom, string sexo,int matricula,eEspecialidad especialidad_e);
	virtual ~cMedico();

	void AgregarIntervencion();
	void DarAlta(cPaciente* paciente);
	void Imprimir();
	void Internar_paciente(cPaciente* paciente);
	void ModificarIndicaciones();
	string to_string();

private:
	eEspecialidad especialidad;
	const unsigned int Matricula;
};

