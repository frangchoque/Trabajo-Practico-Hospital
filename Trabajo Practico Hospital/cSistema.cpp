#include "cSistema.h"


cSistema::cSistema(ListaT<cHistoriaClinica>* lista_historial_paciente, ListaT<cPersonal>* lista_personal) {

	
	if (lista_personal != NULL)
		Lista_Personal = lista_personal;
	else
	Lista_Personal = new ListaT<cPersonal>();
	if (lista_historial_paciente != NULL)
		Lista_Hist_Clinicas = lista_historial_paciente;
	else
		Lista_Hist_Clinicas = new ListaT<cHistoriaClinica>();
	m_personal = NULL;
	L_Historias = NULL;

}



cSistema::~cSistema() {

	delete Lista_Personal;
}


void cSistema::IngresarPaciente(cPaciente* paciente)
{
	cHistoriaClinica* historial_paciente = NULL;
	cIntervencion* intervencion = NULL;
	historial_paciente = Buscar_por_DNI(paciente->getDNI());
	if (historial_paciente != NULL) {//ya existe el historial clinico del paciente
	
		Asociar_Medico_Paciente(paciente);

	}
	else {//le creo una historia clinica
		historial_paciente = new cHistoriaClinica(paciente,intervencion,false);
		Asociar_Medico_Paciente(paciente);
	}

	

}



void cSistema::AñadirPersonal(cPersonal* personal) {

	Lista_Personal->Agregar(personal);
}


cHistoriaClinica* cSistema::Buscar_por_DNI(string dni) {

	return Lista_Hist_Clinicas->Buscar_por_string(dni);
}


void cSistema::CalcularGananciaTotal() {

}


void cSistema::EliminarPersonal() {

}


void cSistema::Imprimir() {

}


void cSistema::ImprimirProcedimientos(cMedico* medico, cFecha fecha) {

}

void cSistema::AgregarIntervencion_al_Historial(cIntervencion* intervencion, cPaciente* paciente)
{
	
cHistoriaClinica* historial_clinico_paciente;
	
historial_clinico_paciente = Buscar_por_DNI(paciente->getDNI());//retorno el historial clinico del paciente	
 
 historial_clinico_paciente->AgregarIntervencion(intervencion);//agrego la nueva intervencion del paciente a la lista de intervenciones 
}


string cSistema::to_string() {

	return  NULL;
}

void cSistema::Asociar_Medico_Paciente(cPaciente* paciente)
{
	cPersonal* aux1=NULL;
	cPersonal* aux2=NULL;
	cMedico* medico;
	if (paciente != NULL) {
		//retorna un medico libre
		for (int i = 0; i < Lista_Personal->getCA(); i++)
		{
			aux1 = Lista_Personal->Buscar_por_pos(i);//me devuelve un  personal (medico o enfermero)
			aux2 = dynamic_cast<cMedico*>(aux1); // me fijo si es medico
			if (aux2 != NULL) {//se encontro un medico
				medico = dynamic_cast<cMedico*>(aux2);


			}

		}
	}
}
