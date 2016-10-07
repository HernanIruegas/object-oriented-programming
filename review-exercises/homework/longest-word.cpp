//
//  main.cpp
//  tarea2Strings
//
//  Created by Hernán Iruegas Villarreal on 18/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;



void cantidadPalabrasNumeroCaracteres(string sLinea, int iCase)
{
    int iEspacios=1, iCont=0, iArr[20], iB=0, iMax, iPalabra=0, iContB=0, iD;
    string sPalabraMasLarga;
    
    //Para encontrar el número de palabras
    //Para guardar la cantidad de caracteres (dentro de un arreglo) que cada palabra tiene
    for(int iA=0; iA<sLinea.length();iA++)
    {
        if(sLinea[iA]== ' ')
        {
            iEspacios++;
            iArr[iB]=iCont;
            iB++;
            iCont=0;
            
        }
        else
        {
            iCont++;
            if(iA==sLinea.length()-1)
            {
                iArr[iB]=iCont;
                iB++;
            }
        }
    }
    
    //Para encontrar que palabra es la más larga
    iMax= -10000;
    for(int iA=0; iA<iB; iA++)
    {
        if(iArr[iA]>iMax)
        {
            iMax=iArr[iA];
            iPalabra = iA+1;
        }
    }
    
    //para desplegar la palabra más larga
    //Ya tengo el número de la palabra dentro de la oración
    //Ya tengo el número de caracteres de la palabra más larga
    //Lo unico que tengo que hacer es empezar desde su caracter inicial e imprimir los siguientes (poner limites)
    iD=1;
    if(iD==iPalabra)
    {
        for(int iA=iContB; iA<=iMax+iContB; iA++)
            sPalabraMasLarga += sLinea[iA];
    }
    else
    {
        for(int iA=0; iA<sLinea.length();iA++)
        {
            if(sLinea[iA]== ' ')
            {
                iD++;
                if(iD==iPalabra)
                {
                    for(int iA=iContB+1; iA<=iMax+iContB; iA++)
                        sPalabraMasLarga += sLinea[iA];
                }
            }
            else
                iContB++;
        }
    }
    cout<<"Case "<<iCase<<": "<<iEspacios<<" "<<sPalabraMasLarga<<endl;
}


int main(){
    
    //Declaración de variables
    string sLinea;
    int iCase=1;
    
    getline(cin,sLinea);
        while(sLinea!="END")
        {
            cantidadPalabrasNumeroCaracteres(sLinea, iCase);
            getline(cin,sLinea);
            iCase++;
        }
    return 0;
}