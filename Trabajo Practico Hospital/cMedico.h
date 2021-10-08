#pragma once
#include "cPersonal.h"
#include "enums.h"
#include "cHistoriaClinica.h"

class cMedico :
    public cPersonal
{


public:
	cMedico(string dni, cFecha fecha, string nom, string sexo,int matricula,eEspecialidad especialidad_e);
	~cMedico();

	void AgregarIntervencion();
	void DarAlta();
	void Imprimir();
	void Internar_paciente();
	void ModificarIndicaciones();
	string to_string();
	bool getOcupado();
	string getEspecialidad();
private:
	eEspecialidad especialidad;
	const unsigned int Matricula;
	cHistoriaClinica* Registro;
	bool Ocupado;
};

