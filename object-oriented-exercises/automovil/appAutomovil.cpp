//
//  appAutomovil.cpp
//  automovil
//
//  Created by Hernán Iruegas Villarreal on 08/09/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;
#include "automovil.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

int carreritas(automovil arrCarros[])
{
    int iKmAvanzar;
    bool bGana = false;
    
    while(bGana==false)
    {
        iKmAvanzar = rand()%(101-50)+50;//rango entre 50-100
        
        for(int iA=0; iA<=4; iA++)
        {
            //Si puede avanzar, avanza y se modifican sus propiedades
            if(arrCarros[iA].avanza(iKmAvanzar))
            {
                arrCarros[iA].setKilometros(arrCarros[iA].getKilometros() + iKmAvanzar);
                    //Checar si ya gano el carro
                    if(arrCarros[iA].getKilometros()>=1000)
                    {
                        bGana = true;
                        return iA+1;
                        break;
                    }
                arrCarros[iA].setGasolina(arrCarros[iA].getGasolina() - (iKmAvanzar/arrCarros[iA].getRendimiento()));
            }
            //Si no puede avanzar, solo llena el tanque
            else
                arrCarros[iA].llenaTanque();
        }
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int iGanador;
    automovil arrCarros[5];
    
    //desplegar caracteristicas iniciales
    for(int iA=0; iA<=4; iA++)
    {
        cout<<"Caracteristicas del carro #"<<iA+1<<" al inicio de la carrera"<<":\n"
        <<"Kilometraje = "<<arrCarros[iA].getKilometros()<<"\n"
        <<"Capacidad del Tanque = "<<arrCarros[iA].getCapTanque()<<"\n"
        <<"Kms X Litro = "<<arrCarros[iA].getRendimiento()<<"\n"<<endl;
    }
    
    iGanador=carreritas(arrCarros);
    
    //desplegar caracteristicas finales
    for(int iA=0; iA<=4; iA++)
    {
        cout<<"Caracteristicas del carro #"<<iA+1<<" al final de la carrera"<<":\n"
        <<"Kilometraje = "<<arrCarros[iA].getKilometros()<<"\n"
        <<"Capacidad del Tanque = "<<arrCarros[iA].getCapTanque()<<"\n"
        <<"Kms X Litro = "<<arrCarros[iA].getRendimiento()<<"\n"<<endl;
    }
    
    //Desplegar el carro ganador
    switch(iGanador)
    {
        case 1:
            cout<<"GANÓ EL CARRO #"<<iGanador<<"!"<<endl;
            break;
        case 2:
            cout<<"GANÓ EL CARRO #"<<iGanador<<"!"<<endl;
            break;
        case 3:
            cout<<"GANÓ EL CARRO #"<<iGanador<<"!"<<endl;
            break;
        case 4:
            cout<<"GANÓ EL CARRO #"<<iGanador<<"!"<<endl;
            break;
        case 5:
            cout<<"GANÓ EL CARRO #"<<iGanador<<"!"<<endl;
            break;
    }
    return 0;
}