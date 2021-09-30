#include "cConsulta.h"


cConsulta::cConsulta(cFecha* FyH, cMedico* medico1, eProblema dolor):cIntervencion(FyH,medico1) {
	Dolor = dolor;
	Indicaciones = "Todavia no hay indicaciones";
}



cConsulta::~cConsulta() {

}





void cConsulta::Imprimir() {

}


void cConsulta::RealizarIntervencion() {

}


string cConsulta::to_string() {


}