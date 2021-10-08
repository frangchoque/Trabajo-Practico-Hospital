#include "cPersonal.h"
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
	cPaciente* Paciente = new cPaciente(false, "Judith Thomas", fecha, ObraSocial::OSDE, "39284539", 'F', Problema::Fiebre, false);

	//Obtengo la lista de medicamentos
	ListaT<cMedicamento>* Medicamentos = ((cEnfermero*)Enfermero)->getInventario();

	//Creo medicamentos
	cMedicamento* Medicamento = new cMedicamento("Bayer", "Ibuprofeno", fecha);//Fiebre, COVID
	Medicamentos->Agregar(Medicamento);
	Medicamento = new cMedicamento("Vick", "Vaporub", fecha);//Tos
	Medicamentos->Agregar(Medicamento);
	Medicamento = new cMedicamento("Irix", "Lagrimas de ojo", fecha);//Problemas de vision
	Medicamentos->Agregar(Medicamento);
	Medicamento = new cMedicamento("Bayer", "Anestesia", fecha);//Dolor de pecho y dolor abdominal



	cSistema* Hospital = new cSistema();

	//Agrego a los enfermeros
	Hospital->AñadirPersonal(Enfermero);
	Enfermero = NULL;
	Enfermero = new cEnfermero("25938423", *fecha, "Alan Acevedo", "M", false);
	Hospital->AñadirPersonal(Enfermero);
	
	//Intento provocar un error
	Enfermero = NULL;
	try
	{
		Hospital->AñadirPersonal(Enfermero);
	}
	catch(exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	//Agrego a los medicos
	Hospital->AñadirPersonal(Medico);
	Medico = new cMedico("34929842", *fecha, "Eduardo Santillan", "M", 133243, Especialidad::MedicoGuardia);
	Hospital->AñadirPersonal(Medico);

	//Intento provocar otro error
	try
	{
		Hospital->AñadirPersonal(Medico);//Lo agrego de nuevo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Medico = new cMedico("30128374", *fecha, "Alicia Casas", "F", 385932, Especialidad::CirujanoCardioVascular);
	Hospital->AñadirPersonal(Medico);
	Medico = new cMedico("20494294", *fecha, "Gaston Heraldo", "M", 123000, Especialidad::CirujanoGeneral);
	Hospital->AñadirPersonal(Medico);
	Medico = new cMedico("29000123", *fecha, "Valeria Degiusti", "F", 394852, Especialidad::Oftalmologo);
	Hospital->AñadirPersonal(Medico);

	Hospital->IngresarPaciente(Paciente);
	Paciente = new cPaciente(true, "Pablo Serrano", fecha, ObraSocial::CBA, "40239424", 'M', Problema::Problemas_de_Vision, false);
	Hospital->IngresarPaciente(Paciente);
	Paciente = new cPaciente(true, "Facundo Kepler", fecha, ObraSocial::DEF, "24189371", 'M', Problema::DolorPecho, true);//Cirugia
	Hospital->IngresarPaciente(Paciente);
	Paciente = new cPaciente(true, "Tamara Faraday", fecha, ObraSocial::HIG, "36128916", 'F', Problema::DolorAbdominal, false);
	//No va a ser posible una cirugia 
	Hospital->IngresarPaciente(Paciente);



	delete Paciente;
	delete Hospital;

	return 0;
}