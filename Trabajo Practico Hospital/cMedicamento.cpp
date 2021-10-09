#include "cMedicamento.h"

cMedicamento::cMedicamento(string Marca, string Nombre, cFecha* vencimiento) {
	this->Marca = Marca;
	this->Nombre = Nombre;
	Vencimiento = vencimiento;
}



cMedicamento::~cMedicamento() {

}





void cMedicamento::Imprimir() {
	cout << this->to_string() << endl;
}


string cMedicamento::to_string() {
	string aux = "\nMarca: " + Marca + "\nNombre: " + Nombre + "\nFecha de vencimiento: " + this->Vencimiento->tm_to_string_Fecha();
	return  aux;
}