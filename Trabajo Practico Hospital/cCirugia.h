#pragma once
#include "cPaciente.h"
#include "cIntervencion.h"
//#include "cEnfermero.h"
#include"cMedicamento.h"
#include"cListaT.h"
//#include "cPersonal.h"
class cEnfermero;

class cCirugia :
	public cIntervencion
{
private:
	bool Ambulatoria;
	unsigned int Duracion;//Minutos
	cFecha Fecha_Hora_inicio;
	cFecha Fecha_Alta;
	string Nombre_Procedimiento;
	cMedico* MedicoAdicional;
	cEnfermero* Enfermero;
	ListaT<cMedicamento>* Inventario;
public:
	//constructor
	cCirugia(cMedico* medico1, cMedico* medicoadicional, cEnfermero* enfermero, cFecha FyH, bool ambulatoria = false);
	~cCirugia();


	void Prequirurgico(cPaciente* paciente); // Asegura si el paciente puede ser intervenido o no 
	void RealizarIntervencion(cPaciente* paciente); //interviene al paciente


	int getDuracion() { return Duracion; };
	void setAmbulatoria(bool ambulatoria) { Ambulatoria = ambulatoria; };

	//imprimir

	string to_string();
	void Imprimir();


};
