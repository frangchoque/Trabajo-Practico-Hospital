#pragma once
#include"cListaT.h"
#include "cPersonal.h"

class cListaPersonal:
	public ListaT<cPersonal>
{

public:
	cListaPersonal(unsigned int tam);

#pragma endregion

#pragma region Metodos

	
	template <class TipoPersonal>
	void ListarPersonal();


	//Agregar Alquiler, verifica que el vehiculo no se superponga
	void AgregarItem(cPersonal* item); //sobreescribo el de cListaT porque necesito hacer otras verificaciones

	//To String
	string To_String();

	//AgregarAlquiler
	void operator+(cPersonal* item); //sobreescribo el de lista
};

template<class TipoPersonal>
inline void cListaPersonal::ListarPersonal()
{	TipoPersonal* aux = NULL;
	



}
	
