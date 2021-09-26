#pragma once
#include "cPersonal.h"
#include "enums.h"
class cMedico :
    public cPersonal
{

public:
	cMedico();
	virtual ~cMedico();

	void AgregarIntervencion();
	void DarAlta();
	void Imprimir();
	void Internar_paciente();
	void ModificarIndicaciones();
	string to_string();

private:
	eEspecialidad especialidad;
	const unsigned int Matricula;
};

