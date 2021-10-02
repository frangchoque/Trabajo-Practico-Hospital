#include "cSistema.h"


cSistema::cSistema(ListaT<cHistoriaClinica>* lista_HistClinicas, ListaT<cPersonal>* lista_Personal) {

	if (lista_HistClinicas != NULL) {
		L_cHistoriaClinica = lista_HistClinicas;
	}
	else L_cHistoriaClinica = new ListaT<cHistoriaClinica>();
	if (lista_HistClinicas != NULL) {
		L_cPersonal= lista_Personal;
	}
	else 	L_cPersonal = new ListaT<cPersonal>();
	
}



cSistema::~cSistema() {

}





void cSistema::AgregarHistoriaClinica(cPaciente* paciente) {

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