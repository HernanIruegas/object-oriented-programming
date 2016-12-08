#include <iostream>
#include <fstream>
using namespace std;
#include "aparato.h"
#include "cancha.h"
#include "reserva.h"

//variable global
//para poder mostrar las reservaciones nuevas dentro del arreglo (el arreglo se actualiza)
int reserTot;

int menu()
{
	int respuesta;

	cout<<"¿Qué opción desea escoger?\n"
	<<"Menu de opciones:\n"
	<<"1) Consultar lista de servicios\n"
	<<"2) Consultar lista de reservaciones\n"
	<<"3) Consultar reservaciones de un servicio\n"
    <<"4) Consultar reservaciones de una hora en especifico\n"
	<<"5) Hacer una reservación\n"
	<<"6) Terminar"<<endl;
	cin>>respuesta;

	return respuesta;
}


/*************************************************
se leen los servicios de un archivo de texto y se guardan en el
arreglo de apuntadores como objetos de aparato o de cancha, que 
son las clases derivadas de servicio, la cual es una clase abstracta
se obtiene el valor de cuantos servicios existen
**************************************************/
void initServicios(servicio *apunServ[20], int &i)
{
    string claveServicio, descripcion, deporte;
    ifstream servicios;
    int tiempoMax, cantMaxPers;
    double costoX15min, costoXhora;
    char tipoServicio, instructor;
    bool conInstructor;
    
    servicios.open("servicios.txt");
    
    while(!servicios.eof() && i < 20)
    {
        servicios>>claveServicio;
        if(claveServicio[0]=='C' || claveServicio[0]=='E' || claveServicio[0]=='B')
        {
            servicios>>tiempoMax>>tipoServicio>>costoX15min>>instructor;
            if(instructor == 'T')
                conInstructor = true;
            else
                conInstructor = false;
            
            getline(servicios, descripcion);
            apunServ[i] = new aparato(claveServicio, tiempoMax, tipoServicio, costoX15min, conInstructor, descripcion);
        }
        else
        {
            servicios>>tiempoMax>>tipoServicio>>costoXhora>>cantMaxPers;
            getline(servicios, deporte);
            apunServ[i] =  new cancha(claveServicio, tiempoMax, tipoServicio, costoXhora, cantMaxPers, deporte);
        }
        i++; 
    }
    servicios.close();
}

/*************************************************
se leen las reservas de un archivo de texto y se guardan en el arreglo,
se obtiene el valor de cuantas reservas existen
**************************************************/
void initReservas(reserva arrReserva[50], int &i)
{
    string claveServicio;
    ifstream reservas;
    int horaReserva, minutos, duracion, idCliente;
    
    reservas.open("reserva.txt");
    
    while(!reservas.eof() && i < 50)
    {
        if(reservas>>claveServicio>>horaReserva>>minutos>>duracion>>idCliente)
        {
            hora horaCreada(horaReserva, minutos);
            arrReserva[i] = reserva(claveServicio, idCliente, horaCreada, duracion);
            i++;
        }
    }
    reservas.close();
}


/*************************************************
CASE 1: muestra todos los datos de cada servicio
**************************************************/
void consultaServicios(int servTot, servicio *apunServ[20])
{
    for(int i=0; i<servTot; i++)
        apunServ[i]->muestra();
}


/*************************************************
CASE 2: muestra datos de cada reservación
**************************************************/
void consultaReservaciones(reserva arrReserva[50], servicio *apunServ[20], int servTot, int reserTot)
{
    for(int i=0, aux=0; i<reserTot; i++, aux++)
    {
        cout<<"Clave del servicio: "<<arrReserva[i].getClaveServicio()<<endl;
        cout<<"ID del cliente: "<<arrReserva[i].getidCliente()<<endl;
        hora horaInicio = arrReserva[i].getHoraInicio();
        cout<<"Hora de inicio de reserva: "<<horaInicio;
        hora horaFin = arrReserva[i].calculaHoraFinReservacion(horaInicio, arrReserva[i].getDuracion());
        cout<<"Hora de terminación de reserva: "<<horaFin;
        for(int i=0; i<servTot; i++)
        {
            if(arrReserva[aux].getClaveServicio() == apunServ[i]->getClave())
                cout<<"Costo de la reservación: "<<apunServ[i]->calculaCosto(arrReserva[aux].getDuracion())<<endl;
        }
        cout<<"\n";
    }
    cout<<"\n";
}


/*************************************************
CASE 3: Consulta reservaciones de un servicio
**************************************************/
void consultReserServ(string claveServicio, servicio *apunServ[20], reserva arrReserva[50], int servTot, int reserTot)
{
    cout<<"\n";
    int aux = 0;
    for(int i=0; i<servTot; i++)
    {
        if(claveServicio == apunServ[i]->getClave())
            apunServ[i]->muestra();
    }
    for(int i=0; i<reserTot; i++)
    {
        if(claveServicio == arrReserva[i].getClaveServicio())
        {
            cout<<"Reservación #"<<aux<<":\n";
            hora horaInicio = arrReserva[i].getHoraInicio();
            cout<<"Hora de comienzo: "<<horaInicio;
            hora horaFin = arrReserva[i].calculaHoraFinReservacion(arrReserva[i].getHoraInicio(), arrReserva[i].getDuracion());
            cout<<"Hora de terminación: "<<horaFin<<endl;
            aux++;
        }
    }
}


/*************************************************
CASE 4: reservaciones de hora especifica
**************************************************/
void reserHora(int horaUsuario, int minUsuario, int reserTot, reserva arrReserva[50], int servTot, servicio *apunServ[20])
{
    cout<<"\n";
    for(int i=0; i<reserTot; i++)
    {
        if(horaUsuario >= arrReserva[i].getHoraInicio().getHora() && horaUsuario <= arrReserva[i].calculaHoraFinReservacion(arrReserva[i].getHoraInicio(), arrReserva[i].getDuracion()).getHora())
        {
               if(minUsuario >= arrReserva[i].getHoraInicio().getMinu() || minUsuario <= arrReserva[i].calculaHoraFinReservacion(arrReserva[i].getHoraInicio(), arrReserva[i].getDuracion()).getMinu())
               {
                  
                  int auxreserva = i;
                  for(int i=0; i<servTot; i++)
                  {
                      if(arrReserva[auxreserva].getClaveServicio() == apunServ[i]->getClave())
                      {
                          apunServ[i]->muestra();
                      }
                  }
               }
        }
    }
}


/*************************************************
verificar que la clave que dio el usuario esté en el arreglo de servicios
se obtiene en que posición está el servicio dentro del arreglo
**************************************************/
bool claveExiste(string claveServicio, servicio *apunServ[20], int servTot, int &aux)
{
    bool existe = false;
    
    for(int i=0; i<servTot; i++)
    {
        if(claveServicio == apunServ[i]->getClave())
        {
            aux = i;
            existe = true;
        }
    }
    return existe;
}


int pedirCveServ(servicio *apunServ[20], int servTot, string &claveServicio, int &idCliente)
{
    int aux=0;
    
    cout<<"Ingresa el id del cliente: ";
    cin>>idCliente;
    cout<<"Ingresa la clave del servicio: ";
    cin>>claveServicio;
    
    while(!claveExiste(claveServicio, apunServ, servTot, aux))
    {
        cout<<"La clave que ingreso no existe, ingrese una clave valida: ";
        cin>>claveServicio;
        claveExiste(claveServicio, apunServ, servTot, aux);
    }
    
    int auxiliar = aux;
    return auxiliar;
}


/*************************************************
verificar que la duración que dio el usuario no sobrepase el maximo de tiempo
que puede ser rentado el servicio
**************************************************/
bool duraPermitida(int duracion, int auxiliar, servicio *apunServ[auxiliar], int servTot)
{
    bool permitido = false;
    
    if(duracion <= apunServ[auxiliar]->getTiempoMax())
        permitido = true;
    
    return permitido;
}


void duraServ(int auxiliar, servicio *apunServ[auxiliar], int servTot, int &duracion)
{
    cout<<"¿Cuántos minutos desea reservar el servicio: ?";
    cin>>duracion;
    
    while(!duraPermitida(duracion, auxiliar, apunServ, servTot))
    {
        int duraRespuesta;
        cout<<"¿El tiempo que quiere reservar el servicio excede al tiempo máximo que se puede reservar\nDesea reservarlo por menos tiempo (1) o no reservarlo (0)";
        cin>>duraRespuesta;
        if(duraRespuesta == 1)
        {
            cout<<"¿Cuántos minutos desea reservar el servicio: ?";
            cin>>duracion;
            duraPermitida(duracion, auxiliar, apunServ, servTot);
        }
        else
            break;
    }
}

/*************************************************
verificar que la hora en la que quiere reservar el usuario no entre en conflicto
con la hora de alguna otra reservación de ese mismo servicio
**************************************************/
bool horaDisponible(hora horaCreada, int auxiliar, int reserTot, reserva arrReserva[50], int duracion, servicio *apunServ[auxiliar])
{
    bool disponible = true;
    
    for(int i=0; i<reserTot; i++)
    {
        if(apunServ[auxiliar]->getClave() == arrReserva[i].getClaveServicio())
        {
            if((arrReserva[i].getHoraInicio() <= horaCreada && horaCreada <= arrReserva[i].calculaHoraFinReservacion(arrReserva[i].getHoraInicio(), arrReserva[i].getDuracion())) || (arrReserva[i].getHoraInicio() <= (horaCreada+duracion) && (horaCreada+duracion) <= arrReserva[i].calculaHoraFinReservacion(arrReserva[i].getHoraInicio(), arrReserva[i].getDuracion())))
            {
                    disponible = false;
                    hora ini = arrReserva[i].getHoraInicio();
                    cout<<"Hora de inicio de reservación: "<<ini;
                    hora fini =arrReserva[i].calculaHoraFinReservacion(arrReserva[i].getHoraInicio(), arrReserva[i].getDuracion());
                    cout<<"Hora de finalización de reservación: "<<fini;
                    //hora hcreada =horaCreada+duracion;
                    //cout<<horc;
            }
        }
    }
    return disponible;
}


hora horaPermitida(int auxiliar, int reserTot, reserva arrReserva[50], int duracion, servicio *apunServ[20])
{
    bool horaDisp;
    int horaUsuario, minUsuario;
    
    cout<<"Ingresa la hora a la que deseas reservar: (formato 10 20)";
    cin>>horaUsuario>>minUsuario;
    hora horaCreada(horaUsuario, minUsuario);
    horaDisp = horaDisponible(horaCreada, auxiliar, reserTot, arrReserva, duracion, apunServ);
    
    while(horaDisp == false)
    {
        cout<<"No se puede reservar a esa hora ya que entra en conflicto con alguna otra reservación de ese servicio\n ";
        cout<<"Ingresa la hora a la que deseas reservar: (formato 10 20)";
        cin>>horaUsuario>>minUsuario;
        hora horaCreada(horaUsuario, minUsuario);
        horaDisp = horaDisponible(horaCreada, auxiliar, reserTot, arrReserva, duracion, apunServ);
    }
    
    return horaCreada;
}



/*************************************************
CASE 5: hacer una reservación
el arreglo de reservaciones se expande y actualiza la variable reserTot
**************************************************/
void hacerReservacion(servicio *apunServ[20], int servTot, reserva arrReserva[50], int reserTot)
{
    int idCliente, aux=0, duracion;
    string claveServicio;
    int horaUsuario, minUsuario;
    bool existe, permitido, horaDisp;
    hora horaInicio;
    
    int auxiliar = pedirCveServ(apunServ, servTot, claveServicio, idCliente);
    duraServ(auxiliar, apunServ, servTot, duracion);
    horaInicio = horaPermitida(auxiliar, reserTot, arrReserva, duracion,  apunServ);
    arrReserva[reserTot] = reserva(claveServicio, idCliente, horaInicio, duracion);
    
    cout<<"El costo por rentar el servicio es: $"<<apunServ[auxiliar]->calculaCosto(duracion)<<endl;
    reserTot++;
}


/*************************************************
CASE 6: actualizar el archivo de reservaciones, agregando las 
nuevas que se hicieron; terminar el programa
**************************************************/
void updateReserv(int reserTot, reserva arrReserva[50])
{
    ofstream reserActualizadas;
    
    reserActualizadas.open("reserva.txt");
    
    for(int i=0; i<reserTot; i++)
    {
        //cout<<"hola";
        reserActualizadas<<arrReserva[i].getClaveServicio()<<" "<<arrReserva[i].getHoraInicio().getHora()<<" "<<arrReserva[i].getHoraInicio().getMinu()<<" "<<arrReserva[i].getDuracion()<<" "<<arrReserva[i].getidCliente()<<endl;
    }
    
    reserActualizadas.close();
}



/*************************************************
MENU DE OPCIONES, EL USUARIO JUEGA
**************************************************/
void menuOpciones(int respuesta, int servTot, int reserTot, servicio *apunServ[20], reserva arrReserva[50])
{
    string claveServicio;
    int horaUsuario, minUsuario;
    
    while(respuesta != 6)
    {
        switch(respuesta)
        {
            case 1:
                consultaServicios(servTot, apunServ);
                break;
                
            case 2:
                consultaReservaciones(arrReserva, apunServ, servTot, reserTot);
                break;
                
            case 3:
                cout<<"Ingrese la clave del servicio: ";
                cin>>claveServicio;
                consultReserServ(claveServicio, apunServ, arrReserva, servTot, reserTot);
                break;
                
            case 4:
                int horaUsuario, minUsuario;
                cout<<"Ingrese la hora: ";
                cin>>horaUsuario;
                cout<<"Ingrese los minutos: ";
                cin>>minUsuario;
                reserHora(horaUsuario, minUsuario, reserTot, arrReserva, servTot, apunServ);
                break;
                
            case 5:
                hacerReservacion(apunServ, servTot, arrReserva, reserTot);
                reserTot++;
                break;
        }
        respuesta = menu();
    }
    if(respuesta == 6)
        updateReserv(reserTot, arrReserva);
}



int main(){

	servicio *apunServ[20];//guardo objetos de clases aparato y cancha
	reserva arrReserva[50];
	int respuesta;
			
    //se leen servicios y se conoce cuántos hay
    int i =0;
    initServicios(apunServ, i);
    int servTot = i;
    
    //se leen reservas y se conoce cuántas hay
    i = 0;
    initReservas(arrReserva, i);
    reserTot = i;
    
    //menu de opciones
	respuesta = menu();
    menuOpciones(respuesta, servTot, reserTot, apunServ, arrReserva);
    
    //liberar la memoria asignada a las variables creadas
    for (int i=0; i<servTot; i++)
            delete apunServ[i];
    
	return 0;
}






























