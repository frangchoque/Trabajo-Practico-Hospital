#include "cEnfermero.h"
#include "cFecha.h"

cEnfermero::cEnfermero(string dni, cFecha* fecha, string nom, string sexo,bool turno):cPersonal(dni, fecha, nom, sexo),Matricula(GenerarMatricula()) {
	Turno = turno;

}
ListaT<cMedicamento>* cEnfermero::Inventario = new ListaT<cMedicamento>();


cEnfermero::~cEnfermero() {
	delete Inventario;//Capaz que falle, estar atentos a posibles correcciones
}


string cEnfermero::GenerarMatricula()
{
	int aux1, aux2, aux3;
	srand(time(NULL));
	 aux1 = (rand() % 4) + 1;
	 aux2 = (rand() % 4);
	 aux3 = (rand() % 5) + 1;
	 return "AMS" + aux1 + aux2 + aux3;
}


void cEnfermero::AdministrarMedicamento(cMedicamento* medicamento) {
	//Hacer que en la operacion se lo pidan y si esta vencido busque otro, o que cancele todo
	try
	{
		Verificar_vencimiento(medicamento);
	}
	catch (exception* error)
	{

	}

}


void cEnfermero::Imprimir() {
	cout << this->to_string() << endl;
}


string cEnfermero::to_string() {

	string aux = "\nTurno: " + Turno_to_string() + "\nMatricula: " + Matricula;//Rehacer para que imprima lo del padre
	return aux;
}


void cEnfermero::Verificar_vencimiento(cMedicamento* medicamento) {
	cFecha* aux = new cFecha();//Fecha de hoy
	if (aux->getAnio() > medicamento->Vencimiento->getAnio())//La fecha ya paso
		throw new exception("El medicamento ya vencio");
	if (aux->getAnio() < medicamento->Vencimiento->getAnio())
		return;//No tengo nada que hacer
	if (aux->getMes()>medicamento->Vencimiento->getMes())//Ya vencio
		throw new exception("El medicamento ya vencio");
	if (aux->getMes() < medicamento->Vencimiento->getMes())
		return;//No vencio
	//Solo queda el caso de que los meses coincidan
	if (aux->getDia() >= medicamento->Vencimiento->getDia())
		throw new exception("El medicamento ya vencio");
	else
		return;
	//Revisar cFecha. No me permite acceder a sus funciones


}

string cEnfermero::Turno_to_string()
{
	if (Turno)
		return "Dia";
	else
		return "Noche";
}

ListaT<cMedicamento>* cEnfermero::getInventario()
{
	return Inventario;
}
