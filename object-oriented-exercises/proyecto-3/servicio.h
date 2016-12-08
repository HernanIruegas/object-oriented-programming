#ifndef servicio_h
#define servicio_h

class servicio{
	
	protected:

		string clave;
		int tiempoMax;
		char tipo;

	public:

		servicio();
        virtual ~servicio();
		servicio(string clave, int tiempoMax, char tipo);
		string getClave();
		int getTiempoMax();
		char getTipo();
		void setClave(string clave);
		void setTiempoMax(int tiempoMax);
		void setTipo(char tipo);
		virtual void muestra() = 0;
		virtual double calculaCosto(int minutos) = 0;

};

servicio::servicio()
{
	clave = "0";
	tiempoMax = 0;
	tipo = 'C';
}
servicio::~servicio()
{
    
}

servicio::servicio(string clave, int tiempoMax, char tipo)
{
	this->clave = clave;
	this->tiempoMax = tiempoMax;
	this->tipo = tipo;
}

string servicio::getClave()
{
	return clave;
}

int servicio::getTiempoMax()
{
	return tiempoMax;
}

char servicio::getTipo()
{
	return tipo;
}

void servicio::setClave(string clave)
{
	this->clave = clave;
}

void servicio::setTiempoMax(int tiempoMax)
{
	this->tiempoMax = tiempoMax;
}

void servicio::setTipo(char tipo)
{
	this->tipo = tipo;
}


#endif













