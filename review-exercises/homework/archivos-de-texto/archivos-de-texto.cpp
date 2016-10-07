//
//  main.cpp
//  ArchivosTextoTarea
//
//  Created by Hernán Iruegas Villarreal on 25/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//


#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void haceTodo()
{
    //Declaración de variables
    string sNomArchivo, sNomArchivoSegundo, sNomSalida, sEnunciado="",sEnunciado2="";
    ifstream archEntrada, archEntradaSegundo;
    ofstream archSalida;
    
    //pedir los nombres de los archivos de entrada y salida
    cin>>sNomArchivo;
    cin>>sNomArchivoSegundo;
    cin>>sNomSalida;
    
    //abrir los archivos especificados
    archEntrada.open(sNomArchivo);
    archEntradaSegundo.open(sNomArchivoSegundo);
    archSalida.open(sNomSalida);
    
    getline(archEntrada, sEnunciado);
    getline(archEntradaSegundo, sEnunciado2);
    while(sEnunciado != "" || sEnunciado2 != "")
    {
        if(sEnunciado != "")
            archSalida<<sEnunciado<<endl;
        if(sEnunciado2 != "")
            archSalida<<sEnunciado2<<endl;
        sEnunciado="";
        sEnunciado2="";
        getline(archEntrada, sEnunciado);
        getline(archEntradaSegundo, sEnunciado2);
    }
    
    archEntrada.close();
    archEntradaSegundo.close();
    archSalida.close();
}

int main(){
    
    haceTodo();
  
    return 0;
}
