#include "cPersonal.h"

cPersonal::cPersonal(string dni, cFecha fecha, string nom, string sexo) {
	DNI = dni;
	Fecha_nacimiento = fecha;
	Nombre = nom;
	Sexo = sexo;
}


cPersonal::~cPersonal() {

}


void cPersonal::Imprimir() {
	cout << this->to_string() << endl;
}


string cPersonal::to_string() {//No se porque marca error. Revisar.
	return "\nDNI: "+DNI+"\nNombre: "+Nombre+"\n"+"\nSexo: " + Sexo + "\n Fecha de nacimiento: "+ Fecha_nacimiento.tm_to_string_Fecha();
}


