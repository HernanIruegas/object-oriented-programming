//
//  main.cpp
//  palindrome
//
//  Created by Hernán Iruegas Villarreal on 20/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//
//  A00817021

#include <iostream>
#include <string>
using namespace std;

string quitarEspacios(string sLinea)
{
    //Declaración de variables
    string sLineaNoEspacios;
    
    //Le quito los espacios a la oración y se crea un nuevo arreglo
    for(int iA=0; iA<sLinea.length(); iA++)
    {
        if(sLinea[iA] != ' ')
            sLineaNoEspacios += sLinea[iA];
    }
    return sLineaNoEspacios;
}

bool palindrome(string sLinea)
{
    //Declaración de variables
    string sNoEspacios, sNuevaLinea;
    bool bPalindrome=true;
    
    //función para quitar espacios a oración original
    sNoEspacios = quitarEspacios(sLinea);
    
    //Se crea un nuevo string con la oración escrita al reves
    for(int iB=sNoEspacios.length()-1; iB>=0; iB--)
    {
        sNuevaLinea += sNoEspacios[iB];
    }
    
    //Se compara la oración original contra la nueva oración(al reves), a ver si son iguales o no
    for(int iA=0; iA<sNoEspacios.length(); iA++)
    {
        if((int)sNoEspacios[iA] != (int)sNuevaLinea[iA])
        {
           if((int)sNoEspacios[iA] != ((int)sNuevaLinea[iA]+32) &&  (int)sNoEspacios[iA] != ((int)sNuevaLinea[iA]-32))
               bPalindrome = false;
        }
    }
    return bPalindrome;
}

int main(){
    
    //Declaración de variables
    string sLinea;
    
    getline(cin,sLinea);
    while(sLinea != "END")
    {
        if(palindrome(sLinea))
            cout<<"YES\n";
        else
            cout<<"NO\n";
        
        getline(cin,sLinea);
    }
    return 0;
}
