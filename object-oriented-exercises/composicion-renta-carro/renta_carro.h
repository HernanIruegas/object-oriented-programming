#include "carro.h"
#include "fecha.h"

class renta_carro
{
	public:

		renta_carro();
		renta_carro(carro autoUno, string nomCliente, fecha fecha_renta, int dias_renta);
		carro getAutomovil();
		string getNomCliente();
		fecha getFecha_renta();
		int getDiasRenta();
		void setAutomovil(carro automovil);
		void setNomCliente(string nomCliente);
		void setFechaRenta(fecha fecha_renta);
		void setDiasRenta(int dias_renta);
		void print();

	private:

		carro automovil;
		string nomCliente;
		fecha fecha_renta;
		int dias_renta;
};


renta_carro::renta_carro()
{
	carro autoUno;
	fecha fechaRenta;

	automovil = autoUno;
	nomCliente = "Hernan";
	this->fecha_renta = fechaRenta;
	dias_renta = 100;
}

renta_carro::renta_carro(carro autoUno, string nomCliente, fecha fecha_renta, int dias_renta)
{
	automovil = autoUno;
	this->nomCliente = nomCliente;
	this->fecha_renta = fecha_renta;
	this->dias_renta = dias_renta;
}

carro renta_carro::getAutomovil()
{
	return automovil;
}

string renta_carro::getNomCliente()
{
	return nomCliente;
}

fecha renta_carro::getFecha_renta()
{
	return fecha_renta;
}

int renta_carro::getDiasRenta()
{
	return dias_renta;
}

void renta_carro::setAutomovil(carro automovil)
{
	this->automovil = automovil;
}

void renta_carro::setNomCliente(string nomCliente)
{
	this-> nomCliente = nomCliente;
}

void renta_carro::setFechaRenta(fecha fecha_renta)
{
	this->fecha_renta = fecha_renta;
}

void renta_carro::setDiasRenta(int dias_renta)
{
	this->dias_renta = dias_renta;
}

void renta_carro::print()
{
	cout<<"Las caracteristicas del automovil son: "<<endl;
	getAutomovil().print();
	cout<<"El nombre del cliente es: "<<nomCliente<<endl;
	cout<<"La fecha es: ";
	getFecha_renta().print();
	cout<<"Los dias de renta son: "<<dias_renta<<endl;
}













