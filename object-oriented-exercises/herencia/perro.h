#include "animal.h"
using namespace std;
class perro : public animal
{
	public:

		perro();
		perro(int cantPatas, string comida, char tipo, string nombre);
		string getNombre();
		void setNombre(string nombre);
		string habla();
		void muestraDatos();

	protected:

		string nombre;
};

perro::perro():animal()
{
	nombre = "max";
}

perro::perro(int cantPatas, string comida, char tipo, string nombre):animal(cantPatas, comida, tipo)
{
	this->nombre = nombre;
}

string perro::getNombre()
{
	return nombre;
}

void perro::setNombre(string nombre)
{
	this->nombre = nombre;
}

string perro::habla()
{
	return "GUAU GUAU";
}

void perro::muestraDatos()
{
	cout<<"Cantidad de Patas: "<<cantPatas<<" "
	<<"Comida: "<<comida<<" "
	<<"Tipo: "<<tipo<<" "
	<<"Nombre: "<<nombre<<endl;
}