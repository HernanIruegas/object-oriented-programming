#include <iostream>
using namespace std;
#include "renta_carro.h"
#include <string.h>


int main()
{
    //Declaración de variables
    int iClave, iModelo, iKm, iD, iM, iA, dias_renta, iResp, iCont=0;
    string sMarca, nomCliente;
    carro autoUno;
    fecha fecha_renta;
	renta_carro arr[5];
    
    cout<<"Desea rentar un carro (si = 1, no = 0)? ";
    cin>>iResp;
    while(iResp==1 && iCont<2)
    {
    
        //Construyo el carro a rentar
        cout<<"Qué clave del vehiculo es? ";
        cin>>iClave;
        cout<<"Qué marca es el vehiculo? ";
        cin>>sMarca;
        cout<<"Qué modelo es el vehiculo? ";
        cin>>iModelo;
        cout<<"Cuántos km tiene? ";
        cin>>iKm;
    
        autoUno = carro(iClave, sMarca, iModelo, iKm);
        
        //escribe el nombre de la persona a rentar el carro
        cout<<"Escriba su nombre: ";
        cin>>nomCliente;
    
        //construyo la fecha en la que se renta el carro
        cout<<"Escriba el día de hoy: ";
        cin>>iD;
        cout<<"Escriba el mes de hoy: ";
        cin>>iM;
        cout<<"Escriba el año de hoy: ";
        cin>>iA;
    
        fecha_renta = fecha(iD, iM, iA);
        
        //los dias a rentar el carro
        cout<<"Escribe los días a rentar el carro: ";
        cin>>dias_renta;
    
        //construyo la info. para una renta de un carro
        arr[iCont] = renta_carro(autoUno, nomCliente, fecha_renta, dias_renta);
    
        arr[iCont].print();
    
        iCont++;
            if(iCont<2)
            {
                cout<<"Desea rentar otro carro (si = 1, no = 0)? ";
                cin>>iResp;
            }
    }
    
    /* esto es para iniciliazar con valores default
	for(int iA=0; iA<5; iA++)
	{
		arr[iA].print();
		cout<<"\n\n";
	}*/

	return 0; 
	
}