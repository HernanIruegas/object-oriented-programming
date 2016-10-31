#include "hora.h"

class vuelo
{
	public:

		vuelo();
		vuelo(string numVuelo, string cveOrigen, string cveDestino, hora horaSalida);
		string getNumVuelo();
		string getClaveOrigen();
		string getClaveDestino();
		hora getHoraSalida();
		int getCantidadPasajeros();
		int getListaPasajeros(int indice);
		void setNumVuelo(string numVuelo);
		void setClaveOrigen(string cveOrigen);
		void setClaveDestino(string cveDestino);
		void setHora(hora horaUno);
		bool setListaPasajeros(int id);

	private:

		string numVuelo, cveOrigen, cveDestino;
		hora horaSalida;
		int cantidadPasajeros, listaPasajeros[10];
		//en listaPasajeros se almacena el id de cada uno de los pasajeros 
		//que van en el vuelo
		//cantidadPasajeros almacena la cantidad de datos que hay en el arreglo listaPasajeros
};

vuelo::vuelo()
{
	hora horaSalidaDefault;

	numVuelo = "1";
	cveOrigen = "2222";
	cveDestino = "3333"; 
	horaSalida = horaSalidaDefault;
	cantidadPasajeros = 0; 
}

string vuelo::getNumVuelo()
{
	return numVuelo;
}

string vuelo::getClaveOrigen()
{
	return cveOrigen;
}

string vuelo::getClaveDestino()
{
	return cveDestino;
}

hora vuelo::getHoraSalida()
{
	return horaSalida;
}

int vuelo::getListaPasajeros(int indice)
{
	return listaPasajeros[indice];
}

void vuelo::setNumVuelo(string numVuelo)
{
	this->numVuelo = numVuelo;
}

void vuelo::setClaveOrigen(string cveOrigen)
{
	this->cveOrigen = cveOrigen;
}

void vuelo::setClaveDestino(string cveDestino)
{
	this->cveDestino = cveDestino;
}

void vuelo::setHora(hora horaUno)
{
	horaSalida = horaUno;
}

//agregar un pasajero a la lista de pasajeros (se agrega el id del pasajero)
bool vuelo::setListaPasajeros(int id)
{
	//verifica el vuelo no está lleno
	if(cantidadPasajeros == 30)
	{
		cout<<"El vuelo está lleno"<<endl;
		return false;
	}

	//verifica que el id no se repita en la lista de pasajeros
	for(int iA=0; iA<cantidadPasajeros; iA++)
	{
		if(listaPasajeros[iA] == id)
		{
			cout<<"Este pasajero se repite en el vuelo"<<endl;
			return false;
		}
	}

	//se agrega el id del pasajero nuevo y se incrementa la cantidad de pasajeros
	listaPasajeros[cantidadPasajeros] = id;
	cantidadPasajeros++;
	cout<<"Se agrego el pasajero al vuelo con exito"<<endl;
	return true;
}

int vuelo::getCantidadPasajeros()
{
	return cantidadPasajeros;
}



//cual es el maximo de pasajeros por vuelo? preguntar  wicho
//como inicializar listapasajeros en constructor default, deberia inicializaro pero noc como




















