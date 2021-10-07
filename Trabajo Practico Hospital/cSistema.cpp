#include "cSistema.h"


cSistema::cSistema() {

	Lista_Historias_Clinicas = new ListaT<cHistoriaClinica>();
	Lista_Personal = new ListaT<cPersonal>();
	
}



cSistema::~cSistema() {
	delete Lista_Historias_Clinicas;
	delete Lista_Personal;
}


void cSistema::IngresarPaciente(cPaciente* paciente)
{
	
	if (paciente != NULL) {
	


	}

}



void cSistema::AñadirPersonal(cPersonal* personal) {

}


cHistoriaClinica* cSistema::Buscar_por_DNI(string dni) {

	return  NULL;
}


void cSistema::CalcularFananciaTotal() {

}


void cSistema::EliminarPersonal() {

}


void cSistema::Imprimir() {

}


void cSistema::ImprimirProcedimientos(cMedico* medico, cFecha fecha) {

}


string cSistema::to_string() {

	return  NULL;
}