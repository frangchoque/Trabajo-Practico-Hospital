#include "cHistoriaClinica.h"
//#include "cPaciente.h"
//#include "cCirugia.h"
//#include "cConsulta.h"
//#include "cPractica.h"

unsigned int cHistoriaClinica::Contador = 1;
cHistoriaClinica::cHistoriaClinica(cPaciente* paciente) :ID(std::to_string(Contador)) {
	Numero_afiliado = paciente->Numero_afiliado;
	Nombre = paciente->Nombre;
	DNI = paciente->DNI;
	Fecha_nacimiento = paciente->Fecha_nacimiento;
	Edad = paciente->Edad;
	Afiliado = paciente->Afiliado;
	Obra_social = paciente->Obra_social;
	Sexo = paciente->Sexo;

	Internado = false;//Lo cambio si realizo la cirugia
	L_intervenciones = new ListaT<cIntervencion>();
	Contador++;

}



cHistoriaClinica::~cHistoriaClinica() {
	delete L_intervenciones;
}

void cHistoriaClinica::setInternado()
{
	Internado = true;
}

void cHistoriaClinica::setAlta()
{
	Internado = false;
}



void cHistoriaClinica::Imprimir_Intervenciones(cFecha fecha)
{
	bool aux;
	cIntervencion* intervencion;

	for (int i = 0; i < L_intervenciones->getCA(); i++)
	{
		intervencion = (*L_intervenciones)[i];//Uso sobrecarga []
		aux = fecha.CompararFecha(fecha, (intervencion->getFecha()));
		if (aux)
		{
			intervencion->Imprimir();
		}
	}
}





void cHistoriaClinica::AgregarIntervencion(cIntervencion* nueva_intervencion)
{
	(*L_intervenciones) + nueva_intervencion;//Uso sobrecarga +
}

void cHistoriaClinica::Imprimir() {
	cout << this->to_string() << endl;
}


string cHistoriaClinica::to_string() {
	string aux = "\nNombre: " + Nombre + "\nDNI: " + DNI + "\nEdad: " + std::to_string(Edad) + "\nSexo: " + "\nFecha de nacimiento: " +
		Fecha_nacimiento.tm_to_string_Fecha() + Sexo + "\nObra social: " + ObraSocial_to_string(Obra_social) + "\nID: " + ID;
	if (Afiliado)
	{
		aux += "\nNumero de afiliado: " + std::to_string(Numero_afiliado);
	}
	else
	{
		aux += "\nNo afiliado";
	}
	if (Internado)
		aux += "\nInternado";
	else
		aux += "\nNo internado";
	return aux;
}

/*cIntervencion* cHistoriaClinica::CrearIntervencion(cFecha FyH, cMedico* medico, unsigned int tipo)
{
	cIntervencion* aux = NULL;
	if (tipo == 0)
	{
		aux = new cPractica(FyH, medico);
	}
	else if (tipo == 1)
	{
		aux = new cConsulta(FyH, medico);
	}
	else if (tipo == 2)
	{
		aux = NULL;
		//aux = new cCirugia(&FyH, medico);//Problemas
	}

	return aux;
}*/

/*void cHistoriaClinica::Imprimir_Intervenciones_Medico_Fecha(cMedico* aux, cFecha fecha)
{
	for (int i = 0; i < L_intervenciones->getCA(); i++)
	{
		if ((*L_intervenciones)[i]->getMedico()->getID() == aux->getID())
		{
			this->Imprimir_Intervenciones(fecha);
		}
	}

}*/
