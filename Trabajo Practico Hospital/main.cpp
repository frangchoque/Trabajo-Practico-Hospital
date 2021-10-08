#include "cPersonal.h"
#include "cEnfermero.h"
#include "cSistema.h"
#include <stdlib.h>
#include <time.h>
#include "cFecha.h"
#include "enums.h"


int main() {
	srand(time(NULL));
	cFecha* fecha = new cFecha(20, 4, 1984, 20, 43);
	cPersonal* Enfermero = new cEnfermero("29432903", *fecha, "Augusto Condori", "M", true);
	cPersonal* Medico = new cMedico("28839204", *fecha, "Belen Azcuenaga", "F", 290472, Especialidad::Anestesiologo);
	


	//creo una lista del Personal
	ListaT<cPersonal>* ListaPersonal = new ListaT<cPersonal>(10);//no se 
	ListaPersonal.Agregar(Enfermero);

	cSistema* Hospital = new cSistema(/*ListaHistorial,*/ListaPersonal);



	delete Enfermero;
	delete Medico;
	delete Hospital;

	return 0;
}