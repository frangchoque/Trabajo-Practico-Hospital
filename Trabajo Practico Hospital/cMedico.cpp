#include "cMedico.h"
#include "cHistoriaClinica.h"

cMedico::cMedico(string dni, cFecha fecha, string nom, string sexo, int matricula, eEspecialidad especialidad_e) :cPersonal(dni, fecha, nom, sexo), Matricula(matricula) {
	especialidad = especialidad_e;
	Registro = NULL;
	Ocupado = false;//esta libre
}

cMedico::~cMedico() {

}

//Practica: Problemas de vision, Covid
	//Cirugia: Dolor en el pecho, dolor abdominal
	//Consulta: Tos, fiebre
void cMedico::AgregarIntervencion(cIntervencion* nuevo)
{
	if (nuevo == NULL)
		throw new exception("Puntero NULL");
	Registro->AgregarIntervencion(nuevo);
}

void cMedico::DarAlta() {
	Registro->setAlta();

	Registro = NULL;//El medico deja de estar a cargo del paciente

}


void cMedico::Imprimir() {
	cout << this->to_string() << endl;
}


void cMedico::Internar_paciente() {
	Registro->setInternado();
}


string cMedico::ModificarIndicaciones(Problema problema) {
	int aux = FuncionRand(2, 0);
	if (problema == Problema::Tos)//Despues cambiarlo a return
	{
		if (aux == 0)
		{
			return "\nTomese un descanso y llame si surgen problemas";
		}
		else if (aux == 1)
		{
			return "\nCompre un antigripal, tome 1 dosis cada 8 horas y tomese la temperatura cada 12";
		}
		else
		{
			return "\nPongase en cuarentena e informe sobre la evolucion de la enfermedad.";
		}
	}
	if (problema == Problema::Fiebre)
	{
		if (aux == 0)
		{
			return "\nDuerma y tome agua";
		}
		else if (aux == 1)
		{
			return "\nTomese un ibuprofeno 400mg";
		}
		else
		{
			return "\nSientese y espere, le vamos a inyectar un tranquilizante";
		}
	}


}


string cMedico::to_string() {
	string aux = ((cPersonal*)this)->to_string();
	aux = aux + "\nEspecialidad: " + Especialidad_to_string(this->especialidad);
	return  aux;
}

bool cMedico::getOcupado()
{
	return Ocupado;
}

string cMedico::getEspecialidad()
{
	return Especialidad_to_string(especialidad);
}

void cMedico::setHistoriaClinica(cHistoriaClinica* registro)
{
	Ocupado = true;//Porque le asigno un registro para que trabaje
	Registro = registro;
	if (registro == NULL)
		Ocupado = false;
}

void cMedico::setInternado()
{
	Registro->setInternado();
}

void cMedico::setAlta()
{
	Registro->setAlta();
}

