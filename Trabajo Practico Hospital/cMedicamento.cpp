#include "cMedicamento.h"

cMedicamento::cMedicamento(string Marca, string Nombre, cFecha* vencimiento) {
	this->Marca = Marca;
	this->Nombre=Nombre;
	Vencimiento = vencimiento;
}



cMedicamento::~cMedicamento() {

}





void cMedicamento::Imprimir() {

}


string cMedicamento::to_string() {

	return  NULL;
}