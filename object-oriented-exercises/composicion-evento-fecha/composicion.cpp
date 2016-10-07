//
//  main.cpp
//  composicion
//
//  Created by Hernán Iruegas Villarreal on 23/09/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;
#include "evento.h"

int main() {
    
    /*
    evento eUno;
    fecha fUno(20,01,2016);
    fecha fDos(23,01,2016);
    evento eDos("MI FIESTA", fUno, fDos);
    eUno.print();
    eDos.print();
    cout<<"Los días de el evento DOS son "<<eDos.calculaDias()<<endl;
    */
    
    //declaracion de variables
    string sN, sRespuesta;
    fecha fI, fF;
    int iD, iM, iA;
    evento arr[5];
    
    for(int iB=0; iB<=4; iB++)
    {
        cout<<"Ingrese el nombre del evento: ";
        cin>>sN;
        cout<<"Fecha inicial\n";
        cout<<"Ingrese el día: ";
        cin>>iD;
        cout<<"Ingrese el mes: ";
        cin>>iM;
        cout<<"Ingrese el año: ";
        cin>>iA;
        fI = fecha(iD, iM, iA);
    
        cout<<"\n";
        
        cout<<"Fecha Final\n";
        cout<<"Ingrese el día: ";
        cin>>iD;
        cout<<"Ingrese el mes: ";
        cin>>iM;
        cout<<"Ingrese el año: ";
        cin>>iA;
        fF = fecha(iD, iM, iA);
    
        arr[iB] = evento(sN, fI, fF);
        cout<<"\n";
        arr[iB].print();
    
        cout<<"Los días del evento "<<iB+1<<" son "<<arr[iB].calculaDias()<<"\n"<<endl;
        
        cout<<"\n";
        cout<<"\n";
    }
    return 0;
}