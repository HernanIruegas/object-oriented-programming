//
//  main.cpp
//  archivosTexto_enClase
//
//  Created by Hernán Iruegas Villarreal on 23/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int mayor(int iC1, int iC2, int iC3)
{
   if(iC1>iC2 && iC1>iC3)
       return iC1;
    else
    {
        if(iC2>iC3)
            return iC2;
        else
            return iC3;
    }
}

double prom(int iC1, int iC2, int iC3)
{
    double dProm;
    
    dProm=((iC1+iC2+iC3)/3);
    
    return dProm;
}

void leerArchivo()
{
    string sNom, sNomArchivo, sNomSalida;
    int iC1, iC2, iC3;
    ifstream archEnt;
    ofstream archSalida;
    
    cout<<"Dar el nombre del archivo entrada: ";
    cin>>sNomArchivo;
    cout<<"Dar el nombre del archivo de salida: ";
    cin>>sNomSalida;
    
    
    archEnt.open(sNomArchivo);
    archSalida.open(sNomSalida);
    
    while(!archEnt.eof())
    {
        archEnt >> sNom >> iC1 >> iC2 >> iC3;
        cout<<sNom<<" "<<prom(iC1, iC2, iC3)<<"La cal. mayor es: "<<mayor(iC1, iC2, iC3)<<endl;
    }
    archEnt.close();
    archSalida.close();
}

int main(){
    
    leerArchivo();

    return 0;
}
