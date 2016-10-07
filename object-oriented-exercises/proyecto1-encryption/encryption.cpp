//
//  main.cpp
//  Proyecto_1Parcial
//
//  Created by Hernán Iruegas Villarreal on 12/09/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;



int main(){
    
    //Declaración de variables
    ifstream archEntrada;
    ofstream archSalida;
    string  sNombreEntrada, sNombreSalida, sOriginal = "0123456789+-*/", sEncript, sEncriptNoBlank, sNumUno=" ", sNumDos=" ",        cNumReal, cNumRealDos;
    char ch;
    int iPosUno, iPosDos, iAcumUno, iAcumDos, iOperador=0;
    
    
    //pedir y abrir los archivos a manipular
    cin>>sNombreEntrada;
    cin>>sNombreSalida;
    archEntrada.open(sNombreEntrada);
    archSalida.open(sNombreSalida);
    
    
    //quitar espacios en blanco a la encripcion
    getline(archEntrada, sEncript);
    for(int iA=0;iA<=sEncript.length();iA++)
    {
        if(sEncript[iA] != ' ')
            sEncriptNoBlank += sEncript[iA];
    }
    
    
    while(!archEntrada.eof())
    {
        //reinicio variables
        cNumReal="", cNumRealDos="", iAcumUno=0, iAcumDos=0;
        
        archEntrada>>sNumUno>>ch>>sNumDos;
        
        //decripto los numeros, asociando su letra con alguna en sEncriptNoBlank
        //los pongo en strings al reves para que el acumulador sepa cuantos numeros hay en total y pueda ejecutarse
        //en el mismo for
        //Ej: BCD=245...se guarda en string como 542...acumulador=(5*10^0)+(4*10^1)+(2*10^2)=245
        for(int iA=sNumUno.length()-1, iB=0, iPotencia=0; iA>=0; iA--, iB++, iPotencia++)
        {
            iPosUno = sEncriptNoBlank.find(sNumUno[iA]);
            cNumReal += sOriginal[iPosUno];
            iAcumUno += (((int)cNumReal[iB]-48) * pow(10, iPotencia));
        }
    
        for(int iA=sNumDos.length()-1, iB=0, iPotencia=0; iA>=0; iA--, iB++, iPotencia++)
        {
            iPosDos = sEncriptNoBlank.find(sNumDos[iA]);
            cNumRealDos += sOriginal[iPosDos];
            iAcumDos += (((int)cNumRealDos[iB]-48) * pow(10, iPotencia));
        }
        
        
        //asociar el operador con una operaccion
        iOperador = sEncriptNoBlank.find(ch);
        
        if(((int)sOriginal[iOperador])==42)
            archSalida<<"("<<iAcumUno<<") "<<"* "<<"("<<iAcumDos<<") = "<<iAcumUno*iAcumDos<<endl;
        else
        {
            if(((int)sOriginal[iOperador])==43)
                archSalida<<"("<<iAcumUno<<") "<<"+ "<<"("<<iAcumDos<<") = "<<iAcumUno+iAcumDos<<endl;
            else
            {
                if(((int)sOriginal[iOperador])==47)
                    archSalida<<"("<<iAcumUno<<") "<<"/ "<<"("<<iAcumDos<<") = "<<iAcumUno/iAcumDos<<endl;
                else
                    archSalida<<"("<<iAcumUno<<") "<<"- "<<"("<<iAcumDos<<") = "<<iAcumUno-iAcumDos<<endl;
            }
        }
    }

    archEntrada.close();
    archSalida.close();
    
    return 0;
}