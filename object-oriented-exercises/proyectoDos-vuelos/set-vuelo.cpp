#include <iostream>
#include <fstream>
using namespace std;
#include "vuelo.h"
#include "pasajero.h"
#include "aeropuerto.h"

int menu()
{
	int iResp;

	cout<<"Eliga la opción que desea realizar:\n"
		<<"1) Consulta de todos los vuelos disponibles\n"
		<<"2) Dar de alta un pasajero en un vuelo\n"
		<<"3) Consulta de vuelo por hora\n"
		<<"4) Consulta por número de vuelo\n"
		<<"5) Consulta de vuelos de un aeropuerto\n"
		<<"6) Consulta la lista de vuelos en los que va un pasajero\n"
		<<"0) Para salir de menu"<<endl;

	cin>>iResp;
	return iResp;
}

bool claveOrigenExiste(aeropuerto arrAereo[5], string cveOrigen)
{
	for(int iA=0; iA<5; iA++)
	{
		if(cveOrigen == arrAereo[iA].getClave())
			return true;
	}
	cout<<"Esta clave de origen no existe, intente de nuevo"<<endl;
	return false;
}

bool claveDestinoExiste(aeropuerto arrAereo[5], string cveDestino)
{
	for(int iA=0; iA<5; iA++)
	{
		if(cveDestino == arrAereo[iA].getClave())
			return true;
	}

	cout<<"Esta clave de destino no existe, intente de nuevo"<<endl;
	return false;
}

bool pasajeroExiste(pasajero arrPasajero[30], int idPasajero)
{
	for(int iA=0; iA<30; iA++)
	{
		if(arrPasajero[iA].getId() == idPasajero)
			return true;
	}
	return false;
}

int vueloExiste(vuelo arrVuelo[10], string sClaveOrigenVuelo, string sClaveDestinoVuelo)
{
	for(int iA=0; iA<10; iA++)
	{
		if(arrVuelo[iA].getClaveOrigen() == sClaveOrigenVuelo && arrVuelo[iA].getClaveDestino() == sClaveDestinoVuelo)
			return iA;
	}
	return -1;
}

void vuelosPorHora(vuelo arrVuelo[10], hora horaIgual)
{
	bool existe = false;
	for(int iA=0; iA<10; iA++)
	{
		if(arrVuelo[iA].getHoraSalida().getHora() == horaIgual.getHora() && arrVuelo[iA].getHoraSalida().getMinu() == horaIgual.getMinu())
		{
			cout<<"Número de vuelo: "<<arrVuelo[iA].getNumVuelo()<<"\n"
			<<"Clave de origen: "<<arrVuelo[iA].getClaveOrigen()<<"\n"
			<<"Clave de destino: "<<arrVuelo[iA].getClaveDestino()<<"\n"<<endl;
			existe = true;
		}
	}
	if(existe == false)
	{
		cout<<"No existe un vuelo con esta hora: ";
		horaIgual.print();
	}
}

void numVueloExiste(vuelo arrVuelo[10], string sNumeroVuelo, pasajero arrPasajero[30])
{
	
	int indiceVuelo, idPasajero;
	bool existe = false;


	for(int iA=0; iA<10; iA++)
	{
		if(arrVuelo[iA].getNumVuelo() == sNumeroVuelo)
		{
			cout<<"Clave de origen: "<<arrVuelo[iA].getClaveOrigen()<<"\n"
			<<"Clave de destino: "<<arrVuelo[iA].getClaveDestino()<<"\n"
			<<"Hora de salida: ";
			arrVuelo[iA].getHoraSalida().print();
			cout<<"Cantidad de pasajeros: "<<arrVuelo[iA].getCantidadPasajeros()<<endl;

			indiceVuelo = iA;//es igual al vuelo en el que estoy interesado

			//desplegar los nombres de los pasajeros
			//puedo accesar a los pasajeros de  un vuelo a ttraves de su arrglo listapasajeros (tiene id's)
			//tengo que encontrar el id del pasajero en el arreglo de pasjeros posibles (30)
			//recorro el arreglo que contiene los id's de los pasajeros del vuelo en el que estoy interesado
			//después de obtener el id del pasajero, recorro el arreglo de todos los posibles pasajeros, comparando
			//a ver si el id del pasajero del vuelo, es igual al id del pasajero del arreglo de pasajeros totales
			for(int iA=0; iA<10; iA++)//10 el número máximo de pasajeros por vuelo
			{
				idPasajero = arrVuelo[indiceVuelo].getListaPasajeros(iA);

				for(int iA=0; iA<30; iA++)
				{
					if(arrPasajero[iA].getId() == idPasajero)
					{	
						cout<<arrPasajero[iA].getNombre()<<endl;
						break;
					}
				}
			}
		}
	}
	
	if(existe == false)
	{
		cout<<"No existe un vuelo con este número de vuelo: "<<sNumeroVuelo<<endl;
	}
}

void vuelosPorClave(aeropuerto arrAereo[5], vuelo arrVuelo[10], string sClaveAero)
{
	//recorro el arreglo de todas las claves de los aeropuertos "arrAereo"
	//busco que la clave que me dieron sea una clave posible aceptada
	//ahora con esa clave del aeropuerto, recorro el arreglo de todos los vuelos
	//busco que la clave que me dieron sea igual a alguna clave (ya sea de origen o destino) de los vuelos existentes 
	for(int iA=0; iA<5; iA++)
	{
		if(arrAereo[iA].getClave() == sClaveAero)
		{
			for(int iA=0; iA<10; iA++)
			{
				if(sClaveAero == arrVuelo[iA].getClaveOrigen() || sClaveAero == arrVuelo[iA].getClaveDestino())
				{
					cout<<"Número de vuelo: "<<arrVuelo[iA].getNumVuelo()<<"\n"
					<<"Clave de origen: "<<arrVuelo[iA].getClaveOrigen()<<"\n"
					<<"Clave de destino: "<<arrVuelo[iA].getClaveDestino()<<"\n"
					<<"Hora de salida: ";
					arrVuelo[iA].getHoraSalida().print();
				}
			}
			break;
		}
	}
}

void vuelosDePasajero(pasajero arrPasajero[30], vuelo arrVuelo[10], int idPasajero)
{
	//recorro el arreglo de todos los pasajeros que existen en "arrPasajero"
	//verifico que el id que me dieron pertenezca a un pasajero que exista
	//con este id existente, recorro el arreglo de vuelos "arrVuelo"
	//checo si el id del pasajero está dentro de algun vuelo
	//si lo esta, imprimo todos los datos del vuelo
	for(int iA=0; iA<30; iA++)
	{
		if(idPasajero == arrPasajero[iA].getId())
		{
			for(int iA=0; iA<10; iA++)
			{
				if(idPasajero == arrVuelo[iA].getListaPasajeros(iA))
				{
					cout<<"Número de vuelo: "<<arrVuelo[iA].getNumVuelo()<<"\n"
					<<"Clave de origen: "<<arrVuelo[iA].getClaveOrigen()<<"\n"
					<<"Clave de destino: "<<arrVuelo[iA].getClaveDestino()<<"\n"
					<<"Hora de salida: ";
					arrVuelo[iA].getHoraSalida().print();
					cout<<"Cantidad de pasajeros: "<<arrVuelo[iA].getCantidadPasajeros()<<endl;
				}
				break;
			}
		}
	}

}

int main()
{
	//declaración de variables
	aeropuerto arrAereo[5];//tengo a los aeropuertos con clave y ciudad
	pasajero arrPasajero[30];//tengo a los pasajeros con id y nombre
	vuelo arrVuelo[10];//tengo 10 objetos de tipo vuelo
	ifstream aeropuertos;
	ifstream pasajeros;
	string sClave, sCiudad, sNombre, numVuelo, cveOrigen, cveDestino, sClaveOrigenVuelo, sClaveDestinoVuelo, sNumeroVuelo, sClaveAero;
	int iId, i=0, iHora, iMinu, iRespVuelo, iRespMenu, idPasajero, vueloExisteIndice, horaVuelo, minuVuelo;
	hora horaSalida, horaIgual;

	//abrir archivos de texto para leer datos
	aeropuertos.open("aeropuertos.txt");
	pasajeros.open("pasajeros.txt");

	//capturo los datos de los aeropuertos = clave(abreviación) y ciudad
	while(!aeropuertos.eof())
	{
		aeropuertos >> sClave >> sCiudad;
		arrAereo[i] = aeropuerto(sClave, sCiudad);
		i++;
	}
	
	//capturo los datos de los pasajeros = id y nombre
	i=0;
	while(!pasajeros.eof())
	{
		pasajeros >> iId;
		getline(pasajeros, sNombre);
		arrPasajero[i] = pasajero(iId, sNombre);
		i++;
	}

	//crear vuelos sin pasajeros
	i=0;
	cout<<"Desea agregar un vuelo (si=1, no=0): ";
	cin>>iRespVuelo;
	while(iRespVuelo == 1)
	{
		cout<<"Asigna el número de vuelo: ";
		cin>>numVuelo;
		arrVuelo[i].setNumVuelo(numVuelo);
		cout<<"Escribe la clave de origen: ";
		cin>>cveOrigen;
		//valido que la clave de origen sea valida (exista)
		while(!claveOrigenExiste(arrAereo, cveOrigen))
		{
			cout<<"Escribe la clave de origen: ";
			cin>>cveOrigen;
		}
		arrVuelo[i].setClaveOrigen(cveOrigen);
		cout<<"Escribe la clave de destino: ";
		cin>>cveDestino;
		//valido que la clave de destino sea valida (exista)
		while(!claveDestinoExiste(arrAereo, cveDestino))
		{
			cout<<"Escribe la clave de destino: ";
			cin>>cveDestino;
		}
		arrVuelo[i].setClaveDestino(cveDestino);

		//se crea el objeto hora
		cout<<"Escribe la hora de salida: (formato: 1 30)";
		cin>> iHora >> iMinu;
		horaSalida = hora(iHora, iMinu);
		arrVuelo[i].setHora(horaSalida);

	i++;
	cout<<"Desea agregar otro vuelo (si=1, no=0): ";
	cin>>iRespVuelo;
	}
	
	//crear menu de opciones
	iRespMenu = menu();
	while(iRespMenu != 0)
	{
		switch(iRespMenu)
		{
			case 1:
				for(int iA=0; iA<1; iA++)
				{
					cout<<"Número de vuelo: "<<arrVuelo[iA].getNumVuelo()<<"\n"
					<<"Clave de origen: "<<arrVuelo[iA].getClaveOrigen()<<"\n"
					<<"Clave de destino: "<<arrVuelo[iA].getClaveDestino()<<"\n"
					<<"Hora de salida: ";
					arrVuelo[iA].getHoraSalida().print();
					cout<<"Cantidad de pasajeros: "<<arrVuelo[iA].getCantidadPasajeros()<<endl;
				}
				break;
			case 2:
				//validar el id del pasajero
				cout<<"Teclee el id del pasajero: ";
				cin>>idPasajero;
				while(!pasajeroExiste(arrPasajero, idPasajero))
				{
					cout<<"Teclee el id del pasajero: ";
					cin>>idPasajero;
				}

				//validar la clave del vuelo
				cout<<"Teclee la clave de origen del vuelo: ";
				cin>>sClaveOrigenVuelo;
				cout<<"Teclee la clave de destino del vuelo: ";
				cin>>sClaveDestinoVuelo;
				vueloExisteIndice = vueloExiste(arrVuelo, sClaveOrigenVuelo, sClaveDestinoVuelo);
				while(vueloExisteIndice == -1)
				{
					cout<<"Teclee la clave de origen del vuelo: ";
					cin>>sClaveOrigenVuelo;
					cout<<"Teclee la clave de destino del vuelo: ";
					cin>>sClaveDestinoVuelo;
					vueloExisteIndice = vueloExiste(arrVuelo, sClaveOrigenVuelo, sClaveDestinoVuelo);
				}

				//el pasajero y el vuelo si existen, entonces agrego el pasajero al vuelo
				arrVuelo[vueloExisteIndice].setListaPasajeros(idPasajero);
				break;

			case 3:
				//validar hora correcta
				cout<<"Ingresa la  hora del vuelo (solo hora): ";
				cin>>horaVuelo;
				while(horaVuelo<0 || horaVuelo>23)
					cin>>horaVuelo;
				//validar minutos correctos
				cout<<"Ingresa los minutos del vuelo (solo minutos): ";
				cin>>minuVuelo;
				while(minuVuelo<0 || minuVuelo>59)
					cin>>minuVuelo;
				//crear objeto de tipo hora y checar si algún vuelo tiene esta misma hora
				horaIgual = hora(horaVuelo, minuVuelo);
				vuelosPorHora(arrVuelo,  horaIgual);
				break;

			case 4:
				cout<<"Teclee el número del vuelo: ";
				cin>>sNumeroVuelo;
				numVueloExiste(arrVuelo, sNumeroVuelo, arrPasajero);
				break;
			
			case 5:
				cout<<"Teclee la clave del aeropuerto: ";
				cin>>sClaveAero;
				vuelosPorClave(arrAereo, arrVuelo, sClaveAero);
				break;

			case 6:
				cout<<"Teclee el id del pasajero: ";
				cin>>idPasajero;
				vuelosDePasajero(arrPasajero, arrVuelo, idPasajero);
				break;
		}
		iRespMenu = menu();
	}

	//cerrar archivos de texto de donde se capturaron datos
	aeropuertos.close();
	pasajeros.close();

	return 0;
}











