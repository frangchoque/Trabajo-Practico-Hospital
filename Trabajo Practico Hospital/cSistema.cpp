#include "cSistema.h"


cSistema::cSistema(cLista_HIstorias_Clinicas* lista_historial, ListaT<cPersonal>* lista_personal) {

	
	if (lista_personal != NULL)
		Lista_Personal = lista_personal;
	else
	Lista_Personal = new ListaT<cPersonal>();
}



cSistema::~cSistema() {

	delete Lista_Personal;
}


void cSistema::IngresarPaciente(cPaciente* paciente)
{
	cMedico* aux;
	if (paciente != NULL) {
	
		//retorna un medico libre
		for (int i = 0; i < Lista_Personal->getCA(); i++)
		{
			
		}
		
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

void cSistema::AgregarIntervencion_al_Historial(cIntervencion* intervencion, cPaciente* paciente)
{
	cLista_HIstorias_Clinicas* aux;
	cLista_HIstorias_Clinicas* aux1;
	aux1=aux->BuscarHistoriaClinica(paciente);

}


string cSistema::to_string() {

	return  NULL;
}