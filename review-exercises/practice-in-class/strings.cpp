//
//  main.cpp
//  strings practice
//
//  Created by Hernán Iruegas Villarreal on 16/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string invierte(string sEntrada)
{
    string sSalida;
    
    for(int iA= sEntrada.length()-1; iA>=0; --iA)
    {
        sSalida += sEntrada[iA];
    }
    return sSalida;
    
    //a = 8; x=a++;  x=8 y a=9 (asigna y luego incrementa)
    //a = 8; x=++a;  x=9 y a=9 (incrementa y despues asigna)
    //un caracter es un entero
    
}

int cantidadPalabras(string sLinea)
{
    int iEspacios=1;
    
    for(int iA=0; iA<sLinea.length();++iA)
    {
        if(sLinea[iA]== ' ')
            iEspacios++;
    }
    if(sLinea.length()>0)
        return iEspacios;
    else
        return 0;
        
}

string quitaVocales(string sEntrada)
{
    string sSalida;
    char ch;
    
    for(int iA=0; iA<sEntrada.length(); ++iA)
    {
        ch= sEntrada[iA];
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u')
        {
            sSalida += ch;
        }
    }
    return sSalida;
}

/*
string codigo(string sEntrada)
{
    string sSalida;
    
    for(int iA=0; iA<sEntrada.length(); ++iA)
    {
        sSalida += ('Z'+ sEntrada[iA] +'A');
    }
    
    return sSalida;
}
 */

int main() {
    
    string sLinea;
    cout<<"Dar la linea: ";
    getline(cin,sLinea);
    cout<<"La linea invertida es: "<<invierte(sLinea)<<endl;
    cout<<"La cantidad de palabras es: "<<cantidadPalabras(sLinea)<<endl;
    cout<<"Quitando vocales: "<<quitaVocales(sLinea)<<endl;
    //cout<<"Codificando es: "<<codigo(sLinea)<<endl;

    
    return 0;
}
