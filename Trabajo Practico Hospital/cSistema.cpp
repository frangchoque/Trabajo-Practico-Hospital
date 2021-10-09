#define _CRT_SECURE_NO_WARNINGS
#include "cSistema.h"
#include "cMedico.h"

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
	

}



cSistema::~cSistema() {
	delete Lista_Hist_Clinicas;
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

	try {
		Lista_Personal->Agregar(personal);
	}
	catch (exception* error)
	{
		throw error;
	}
}


cHistoriaClinica* cSistema::Buscar_por_DNI(string dni) {

	return Lista_Hist_Clinicas->Buscar_por_string(dni);
}


float cSistema::CalcularGananciaTotal() {
	//imprimir ganancias del ultimo mes 
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	int mes = aux->tm_mon - 1;//el mes (actual - 1) es el ultimo mes
	ListaT<cIntervencion>* aux1;
	cIntervencion* intervencion;
	float Ganancia = 0.0;

	for (int i = 0; i < Lista_Hist_Clinicas->getCA(); i++)
	{
		aux1 = Lista_Hist_Clinicas->Buscar_por_pos(i)->getIntervencion();
		if (mes == aux1->Buscar_por_pos(i)->getMes()) {

			Ganancia += aux1->Buscar_por_pos(i)->getMonto();

		}
	}
	return Ganancia;
}


void cSistema::EliminarPersonal(cPersonal*personal) {
	cPersonal* aux1 = NULL;
	cPersonal* aux2 = NULL;
	cPersonal* aux3 = NULL;
	cMedico* medico = NULL;
	cEnfermero* enfermero = NULL;
	for (int i = 0; i < Lista_Personal->getCA(); i++)
	{
		aux1 = Lista_Personal->Buscar_por_pos(i);//me devuelve un  personal (medico o enfermero)
		aux2 = dynamic_cast<cMedico*>(aux1); // me fijo si es medico
		aux3 = dynamic_cast<cEnfermero*>(aux1);//si es enfermero
		if (aux2 != NULL) {
			medico = dynamic_cast<cMedico*>(aux2);
			Lista_Personal->Eliminar(medico->getID());
		}
		if (aux3 != NULL) {
			enfermero = dynamic_cast<cEnfermero*>(aux2);
			Lista_Personal->Eliminar(enfermero->getID());
		}
	}
}




void cSistema::ImprimirProcedimientos(cMedico* medico, cFecha* fecha) {

	cHistoriaClinica* aux;
	aux=medico->getRegistro();
	aux->Imprimir_Intervenciones(fecha);
}

void cSistema::AgregarIntervencion_al_Historial(cIntervencion* intervencion, cPaciente* paciente)
{
	
cHistoriaClinica* historial_clinico_paciente;
	
historial_clinico_paciente = Buscar_por_DNI(paciente->getDNI());//retorno el historial clinico del paciente	
 
 historial_clinico_paciente->AgregarIntervencion(intervencion);//agrego la nueva intervencion del paciente a la lista de intervenciones 
}




void cSistema::Asociar_Medico_Paciente(cPaciente* paciente)
{
	cPersonal* aux1=NULL;
	cPersonal* aux2=NULL;
	cMedico* medico;
	cPractica* practica = NULL;
	cConsulta* consulta = NULL;
	cCirugia* cirugia = NULL;
	string Profesion;
	string dolor=paciente->getProblemaString();
	if (paciente != NULL) {
		//retorna un medico libre
		for (int i = 0; i < Lista_Personal->getCA(); i++)
		{
			aux1 = Lista_Personal->Buscar_por_pos(i);//me devuelve un  personal (medico o enfermero)
			aux2 = dynamic_cast<cMedico*>(aux1); // me fijo si es medico
			
			if (aux2 != NULL) {//se encontro un medico
				medico = dynamic_cast<cMedico*>(aux2);
				Profesion = medico->getEspecialidad();
				
				if (Profesion == Problema_Especilidad(dolor)) {//me fijo si el medico es de la profesion correcta para el problema del paciente
					
					if (medico->getOcupado() == true) { medico->setOcupado(false);/*lo desocupo para poder usarlo*/}

					string dolor2 = Problema_Especilidad(dolor);//que medico necesita segun su problema
					if (dolor2 == "Practica") {
						practica->setMedico(medico);
						practica->RealizarIntervencion(paciente);
					}
					else if (dolor2 == "Cirugia") {
						cirugia->setMedico(medico);
						cirugia->RealizarIntervencion(paciente);
					}
					if (dolor == "Consulta") {
						consulta->setMedico(medico);
						consulta->RealizarIntervencion(paciente);
					}
					else { medico = NULL; }//no se encontro ningun medico para el problema entonces libero el puntero
				}

			}

		}
	}
}

string cSistema::Problema_Especilidad(string problema)
{
	if (problema == "Problemas_de_Vision" || problema == "COVID") { return "Practica"; }
	else if (problema == "DolorPecho" || problema == "DolorAbdominal") { return "Cirugia"; }
	if (problema == "Tos" || problema == "Fiebre") { return "Consulta"; }
	else { return "No se encontro especialidad"; }

}
