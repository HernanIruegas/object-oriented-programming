#include "servicio.h"
using namespace std;

class cancha : public servicio{

	private:

		double costoXhora;
		int cantMaxPers;
		string deporte;

	public:

		cancha();
		cancha(string clave, int tiempoMax, char tipo, double costoXhora, int cantMaxPers, string deporte);
		double getCostoXhora();
		int getCantMaxPers();
		string getDeporte();
		void setCostoXhora(double costoXhora);
		void setCantMaxPers(int cantMaxPers);
		void setDeporte(string deporte);
		void muestra();
		double calculaCosto(int minutos);
};

cancha::cancha():servicio()
{
	costoXhora = 25;
	cantMaxPers = 0;
	deporte = " ";

}

cancha::cancha(string clave, int tiempoMax, char tipo, double costoXhora, int cantMaxPers, string deporte):servicio(clave, tiempoMax, tipo)
{
	this->costoXhora = costoXhora;
	this->cantMaxPers = cantMaxPers;
	this->deporte = deporte;
}

double cancha::getCostoXhora()
{
	return costoXhora;
}

int cancha::getCantMaxPers()
{
	return cantMaxPers;
}

string cancha::getDeporte()
{
	return deporte;
}

void cancha::setCostoXhora(double costoXhora)
{
	this->costoXhora = costoXhora;
}

void cancha::setCantMaxPers(int cantMaxPers)
{
 	this->cantMaxPers = cantMaxPers;
}

void cancha::setDeporte(string deporte)
{
	this->deporte = deporte;
}

void cancha::muestra()
{
	cout<<"Servicio: Cancha\n"
	<<"Clave: "<<clave<<"\n"
	<<"Tiempo Maximo: "<<tiempoMax<<"\n"
	<<"Tipo: "<<tipo<<"\n"
	<<"costoXhora: "<<costoXhora<<"\n"
	<<"cantMaxPers: "<<cantMaxPers<<"\n"
	<<"Deporte: "<<deporte<<endl;
    cout<<"\n";
}

double cancha::calculaCosto(int minutos)
{
    return ceil(double(minutos)/60) * costoXhora;
}






















