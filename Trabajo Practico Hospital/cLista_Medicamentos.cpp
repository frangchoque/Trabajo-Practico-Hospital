#include "cLista_Medicamentos.h"

cLista_Medicamentos::cLista_Medicamentos(unsigned int tam) :ListaT<cMedicamento>(tam) {


}

void cLista_Medicamentos::AgregarMedicamento(cMedicamento* remedio)
{
	Agregar(remedio);
}

string cLista_Medicamentos::getmedicamento(cMedicamento* remedio)
{
	return remedio->getNombre();
}


