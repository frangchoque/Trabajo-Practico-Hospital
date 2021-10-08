#include "cPersonal.h"
#include "cEnfermero.h"
#include "cSistema.h"
#include <stdlib.h>
#include <time.h>
#include "cFecha.h"
#include "enums.h"
#include "cListaT.h"


int main() {
	srand(time(NULL));
	cFecha* fecha = new cFecha(20, 4, 1984, 20, 43);
	cPersonal* Enfermero = new cEnfermero("29432903", *fecha, "Augusto Condori", "M", true);
	cPersonal* Medico = new cMedico("28839204", *fecha, "Belen Azcuenaga", "F", 290472, Especialidad::Anestesiologo);
	cPaciente* Paciente1 = new cPaciente(false, "Judith Thomas", fecha, ObraSocial::OSDE, "39284539", 'F', Problema::Fiebre, false);

	//Obtengo la lista de medicamentos
	ListaT<cMedicamento>* Medicamentos = ((cEnfermero*)Enfermero)->getInventario();

	//Creo medicamentos
	cMedicamento* Medicamento = new cMedicamento("Bayer", "Lisopresol", fecha);
	Medicamentos->Agregar(Medicamento);

	cSistema* Hospital = new cSistema();

	//Agrego a los enfermeros
	Hospital->A�adirPersonal(Enfermero);
	Enfermero = NULL;
	Enfermero = new cEnfermero("25938423", *fecha, "Alan Acevedo", "M", false);
	Hospital->A�adirPersonal(Enfermero);
	
	//Intento provocar un error
	Enfermero = NULL;
	try
	{
		Hospital->A�adirPersonal(Enfermero);
	}
	catch(exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	//Agrego a los medicos
	Hospital->A�adirPersonal(Medico);
	Medico = new cMedico("34929842", *fecha, "Eduardo Santillan", "M", 133243, Especialidad::MedicoGuardia);
	Hospital->A�adirPersonal(Medico);

	//Intento provocar otro error
	try
	{
		Hospital->A�adirPersonal(Medico);//Lo agrego de nuevo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Medico = new cMedico("30128374", *fecha, "Alicia Casas", "F", 385932, Especialidad::CirujanoCardioVascular);
	Hospital->A�adirPersonal(Medico);
	Medico = new cMedico("20494294", *fecha, "Gaston Heraldo", "M", 123000, Especialidad::CirujanoGeneral);
	Hospital->A�adirPersonal(Medico);
	Medico = new cMedico("29000123", *fecha, "Valeria Degiusti", "F", 394852, Especialidad::Oftalmologo);
	Hospital->A�adirPersonal(Medico);

	Hospital->IngresarPaciente(Paciente1);





	//delete Enfermero;
	//delete Medico;
	delete Paciente1;
	delete Hospital;

	return 0;
}