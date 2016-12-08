#include "hora.h"

class reserva
{
	private:

		string claveServicio;
		int idCliente, duracion;
		hora horaInicio;

	public:

		reserva();
		reserva(string claveServicio, int idCliente, hora horaInicio, int duracion);
		string getClaveServicio();
		int getidCliente();
		hora getHoraInicio();
		int getDuracion();
		void setClaveServicio(string claveServicio);
		void setIdCliente(int idCliente);
		void setHoraInicio(hora horaInicio);
		void setDuracion(int duracion);
		hora calculaHoraFinReservacion(hora horaInicio, int duracion);
};

reserva::reserva()
{
	hora horaUno;
	hora horaDefault;
	claveServicio = "0";
	idCliente = 0;
	duracion = 0;
	horaInicio = horaUno;
}

reserva::reserva(string claveServicio, int idCliente, hora horaInicio, int duracion)
{
	this->claveServicio =claveServicio;
	this->idCliente =idCliente; 
	this->horaInicio =horaInicio;
	this->duracion =duracion;
}

string reserva::getClaveServicio()
{
	return claveServicio;
}

int reserva::getidCliente()
{
	return idCliente;
}

/*checar si puedo hacer esto o necesito el get para hora*/
hora reserva::getHoraInicio()
{
	return horaInicio;
}

int reserva::getDuracion()
{
	return duracion;
}

void reserva::setClaveServicio(string claveServicio)
{
	this->claveServicio = claveServicio;
}

void reserva::setIdCliente(int idCliente)
{
	this->idCliente = idCliente;
}

void reserva::setHoraInicio(hora horaInicio)
{
	this->horaInicio = horaInicio;
}

void reserva::setDuracion(int duracion)
{
	this->duracion = duracion;
}

/*me falta implementar el metodo, hay que checar que piden*/
hora reserva::calculaHoraFinReservacion(hora horaInicio, int duracion)
{
	int minTotales = horaInicio.getHora() * 60 + horaInicio.getMinu() + duracion;
	int horaNueva = minTotales/60 % 24;
	int minNuevos = minTotales % 60;
	hora horaFin(horaNueva, minNuevos);

	return horaFin;
}














