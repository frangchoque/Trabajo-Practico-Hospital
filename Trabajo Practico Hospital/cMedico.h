#pragma once
#include "cPersonal.h"
#include "enums.h"
class cHistoriaClinica;


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
	string ModificarIndicaciones();
	string to_string();
	bool getOcupado();
	string getEspecialidad();
	void setOcupado(bool var) { Ocupado = var; };
	unsigned int getMatricula() { return Matricula; }
	cHistoriaClinica* getRegistro() { return Registro; }
private:
	eEspecialidad especialidad;
	const unsigned int Matricula;
	cHistoriaClinica* Registro;
	bool Ocupado;
};

