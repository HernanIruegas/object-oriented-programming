#include "perro.h"
using namespace std;
class beagle : public perro
{
	public:

		beagle();
		beagle(int cantPatas, string comida, char tipo, string nombre, char color);
		char getColor();
		void setColor(char color);
		void muestraDatos();

	private:

		char color;
};

beagle::beagle():perro()
{
	color = 'a';
}

beagle::beagle(int cantPatas, string comida, char tipo, string nombre, char color):perro(cantPatas, comida, tipo, nombre)
{
	this->color = color;
}

char beagle::getColor()
{
	return color;
}

void beagle::setColor(char color)
{
	this->color = color;
}

void beagle::muestraDatos()
{
	cout<<"Cantidad de Patas: "<<cantPatas<<" "
	<<"Comida: "<<comida<<" "
	<<"Tipo: "<<tipo<<" "
	<<"Nombre: "<<nombre<<" "
	<<"Color: "<<color<<endl;
}