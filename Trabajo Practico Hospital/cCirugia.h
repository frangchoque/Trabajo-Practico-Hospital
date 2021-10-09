#pragma once
#include "cPaciente.h"
#include "cIntervencion.h"
#include "cEnfermero.h"
#include"cMedicamento.h"
#include"cListaT.h"
#include<iostream>
using namespace std;

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
	cCirugia(cFecha*FyH ,cMedico* medico1,cFecha*alta,cMedico*medicoadicional,cEnfermero*enfermero);
	virtual ~cCirugia();


	void Prequirurgico(cPaciente* paciente); // Asegura si el paciente puede ser intervenido o no 
	void RealizarIntervencion(cPaciente* paciente); //interviene al paciente

	//Getter del medicamento
	int getDuracion() { return Duracion; };

	
	//imprimir

	string to_string();
	void Imprimir();


};

