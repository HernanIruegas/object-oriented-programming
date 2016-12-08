#include "servicio.h"
#include <math.h>
using namespace std;

class aparato : public servicio{

	private:

		double costoX15min;
		bool conInstructor;
		string descripcion;

	public:

		aparato();
		aparato(string clave, int tiempoMax, char tipo, double costoX15min, bool conInstructor, string descripcion);
		double getCostoX15min();
		bool getConInstructor();//checar si tengo que hacer get y set para var bool
		string getDescripcion();
		void setCostoX15min(double costoX15min);
		void setConInstructor(bool conInstructor);//checar si tengo que hacer get y set para var bool
		void setDescripcion(string descripcion);
		void muestra();
		double calculaCosto(int minutos);



};

aparato::aparato():servicio()
{
	costoX15min = 10;
	conInstructor= false;
	descripcion = " ";
}

aparato::aparato(string clave, int tiempoMax, char tipo, double costoX15min, bool conInstructor, string descripcion):servicio(clave, tiempoMax, tipo)
{
	this->costoX15min = costoX15min;
	this->conInstructor = conInstructor;
	this->descripcion = descripcion;
}

double aparato::getCostoX15min()
{
	return costoX15min;
}

bool aparato::getConInstructor()
{
	return conInstructor;
}

string aparato::getDescripcion()
{
	return descripcion;
}

void aparato::setCostoX15min(double costoX15min)
{
	this->costoX15min = costoX15min;
}

void aparato::setConInstructor(bool conInstructor)
{
	this->conInstructor = conInstructor;
}

void aparato::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

void aparato::muestra()
{
	cout<<"Servicio: Aparato\n"
	<<"Clave: "<<clave<<"\n"
	<<"Tiempo Maximo: "<<tiempoMax<<"\n"
	<<"Tipo: "<<tipo<<"\n"
	<<"costoX15min: "<<costoX15min<<"\n"
	<<"conInstructor: "<<conInstructor<<"\n"
	<<"descripcion: "<<descripcion<<endl;
    cout<<"\n";
}

double aparato::calculaCosto(int minutos)
{
    return ceil(double(minutos)/15) * costoX15min;
}













