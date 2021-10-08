#pragma once
#include "cPaciente.h"
#include "cIntervencion.h"
#include "cEnfermero.h"
#include"cMedicamento.h"
#include"cListaT.h"

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
	ListaT<cMedicamento> medicamento; 
public:
	//constructor
	cCirugia(cMedico* medico1,cFecha*alta,cMedico*medicoadicional,cEnfermero*enfermero);
	virtual ~cCirugia();


	void Prequirurgico(cPaciente* paciente); // Asegura si el paciente puede ser intervenido o no 
	void RealizarIntervencion(cPaciente* paciente); //interviene al paciente

	//Getter del medicamento
	cMedicamento* getmedicamento() { return medicamento; };
	int getDuracion() { return Duracion; };

	
	//imprimir

	string to_string();
	void Imprimir();


};

