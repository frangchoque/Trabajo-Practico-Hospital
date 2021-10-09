#define _CRT_SECURE_NO_WARNINGS
#include "cSistema.h"
#include "cConsulta.h"
#include "cCirugia.h"
#include "cPractica.h"
//#include "cMedico.h"

cSistema::cSistema(ListaT<cHistoriaClinica>* lista_historial_paciente, ListaT<cPersonal>* lista_personal) {


	if (lista_personal != NULL)
		Lista_Personal = lista_personal;
	else
		Lista_Personal = new ListaT<cPersonal>();
	if (lista_historial_paciente != NULL)
		Lista_Hist_Clinicas = lista_historial_paciente;
	else
		Lista_Hist_Clinicas = new ListaT<cHistoriaClinica>();
	Ganancia = 0;
}



cSistema::~cSistema() {
	delete Lista_Hist_Clinicas;
	delete Lista_Personal;
}


void cSistema::IngresarPaciente(cPaciente* paciente, bool CirugiaAmbulatoria)
{
	cHistoriaClinica* historial_paciente = NULL;
	cIntervencion* intervencion = NULL;
	cMedico* medico = NULL;
	string especialista;
	cFecha* Hoy = new cFecha();
	cMedico* medico_aux = NULL;
	cEnfermero* enfermero = NULL;

	try {
		medico = Asociar_Medico_Paciente(paciente);//Ya separamos un medico especifico segun su problema
	}
	catch (exception* error)
	{
		throw error;
	}
	historial_paciente = medico->getRegistro();
	especialista = this->Problema_Especilidad(paciente->getProblemaString());
	if (especialista == "Interno")
	{
		intervencion = new cConsulta(*Hoy, medico);
	}
	else if (especialista == "Medico de guardia" || especialista == "Oftalmologo")
	{
		intervencion = new cPractica(*Hoy, medico);
	}
	else if (especialista == "Cirujano Cardiovascular" || especialista == "Cirujano General")
	{
		medico_aux = (cMedico*)Buscar_Tipo_Personal(1);
		enfermero = (cEnfermero*)Buscar_Tipo_Personal(2);
		intervencion = new cCirugia(medico, medico_aux, enfermero, *Hoy, CirugiaAmbulatoria);
		((cCirugia*)intervencion)->setAmbulatoria(CirugiaAmbulatoria);
	}

	intervencion->RealizarIntervencion(paciente);

	medico->AgregarIntervencion(intervencion);
	medico->setHistoriaClinica(NULL);
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


void cSistema::CalcularGananciaTotal() {
	//imprimir ganancias del ultimo mes 
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	aux->tm_mon - 1;//el mes actual - 1 es el ultimo mes

	for (int i = 0; i < Lista_Hist_Clinicas->getCA(); i++)
	{
		for (int j = 0; j < ((*Lista_Hist_Clinicas)[i]->getIntervencion())->getCA(); j++)
		{
			if (((*((*Lista_Hist_Clinicas)[i]->getIntervencion()))[j]->getFecha()).getMes() == aux->tm_mon);
			Ganancia += (*((*Lista_Hist_Clinicas)[i]->getIntervencion()))[j]->getMonto();
		}
	}

}


void cSistema::EliminarPersonal(cPersonal* personal) {
	try {
		Lista_Personal->Eliminar(personal->getID());
	}
	catch (exception* error)
	{
		throw error;
	}
}


void cSistema::Imprimir() {
	cout << this->to_string() << endl;
}


void cSistema::ImprimirProcedimientos(cMedico* medico, cFecha fecha) {
	ListaT<cIntervencion>* aux = NULL;
	for (int i = 0; i < Lista_Hist_Clinicas->getCA(); i++)
	{
		aux = (*Lista_Hist_Clinicas)[i]->getIntervencion();
		for (int j = 0; j < aux->getCA(); j++)
		{
			if ((*aux)[j]->getMedico()->getID() == medico->getID())
			{
				(*aux)[j]->Imprimir();
			}
		}
	}

}

void cSistema::AgregarIntervencion_al_Historial(cIntervencion* intervencion, cPaciente* paciente)
{

	cHistoriaClinica* historial_clinico_paciente;

	historial_clinico_paciente = Buscar_por_DNI(paciente->getDNI());//retorno el historial clinico del paciente	

	historial_clinico_paciente->AgregarIntervencion(intervencion);//agrego la nueva intervencion del paciente a la lista de intervenciones 
}


string cSistema::to_string() {

	string aux = "\nGanancia: " + std::to_string(Ganancia);
	return aux;
}

cMedico* cSistema::Asociar_Medico_Paciente(cPaciente* paciente)
{
	cPersonal* aux1 = NULL;
	cPersonal* aux2 = NULL;
	cMedico* medico;
	string Profesion;
	string dolor = paciente->getProblemaString();
	string dolor2;
	cHistoriaClinica* Historial = NULL;

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

					if (medico->getOcupado() == true) {
						medico->setOcupado(false);/*lo desocupo para poder usarlo*/
					}
					Historial = Buscar_por_DNI(paciente->getDNI());
					if (Historial == NULL)
					{
						Historial = new cHistoriaClinica(paciente);
						(*Lista_Hist_Clinicas) + Historial;
					}
					medico->setHistoriaClinica(Historial);

					return medico;//Para usarlo despues

					/*dolor2 = Problema_Especilidad(dolor);//que medico necesita segun su problema
					if (dolor2 == "Practica") { m_Intervencion->RealizarIntervencion(paciente); }
					else if (dolor2 == "Cirugia") { m_Intervencion->RealizarIntervencion(paciente); }
					if (dolor == "Consulta") { m_Intervencion->RealizarIntervencion(paciente); }
					else { medico = NULL; }//no se encontro ningun medico para el problema entonces libero el puntero*/

				}

			}

		}
	}
	else {
		throw new exception("ERROR. Puntero NULL");
	}
}

string cSistema::Problema_Especilidad(string problema)//Dejo los anestesiologos para la cirugia
{
	if (problema == "Problemas_de_Vision")
	{
		return "Oftalmologo";
	}
	else if (problema == "COVID")
	{
		return "Medico de guardia";
	}
	else if (problema == "DolorPecho")
	{
		return "Cirujano Cardiovascular";
	}
	else if (problema == "DolorAbdominal")
	{
		return "Cirujano General";
	}
	if (problema == "Tos")
	{
		return "Interno";
	}
	else if (problema == "Fiebre") {
		return "Interno";
	}
	else { return "No se encontro especialidad"; }

}

cPersonal* cSistema::Buscar_Tipo_Personal(unsigned int Tipo)
{
	cPersonal* aux = NULL;
	string Especialidad;
	for (int i = 0; i < Lista_Personal->getCA(); i++)
	{
		if (Tipo == 1)//Medico anestesiologo
		{
			if (dynamic_cast<cMedico*>((*Lista_Personal)[i]) != NULL)
			{
				aux = (*Lista_Personal)[i];
				Especialidad = ((cMedico*)aux)->getEspecialidad();
				if (Especialidad == "Anestesiologo")
				{
					return aux;//Devuelvo un anestesiologo
				}
			}
		}
		else//Enfermero
		{
			if (dynamic_cast<cEnfermero*>((*Lista_Personal)[i]) != NULL)
			{
				aux = (*Lista_Personal)[i];
				return aux;
			}
		}
	}
}
