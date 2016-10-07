//
//  main.cpp
//  Saddle Point
//
//  Created by Hernán Iruegas Villarreal on 12/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//  A00817021

#include <iostream>
using namespace std;

int menorRenglonMayorColumna(int iMat[9][9], int iDim, int &iR, int &iC)
{
    
    //Declaración de variables
    int iMax, iMin; //iR=0, iC=0;
    
    //Encontrar el número más pequeño del renglón
    for(int i=0; i<iDim; i++)
    {
        iMin=1000000;
        for(int j=0; j<iDim; j++)
        {
            if(iMat[i][j]<iMin)
            {
                iMin= iMat[i][j];
                iR= i;
                iC= j;
            }
        }
        
        //Ya se cual es el valor más pequeño del renglón correspondiente, ahora hay que verificar
        //que sea el mayor de su columna correspondiente
        iMax=iMin;
        
        //Recorro solo la columan del número más grande en su renglón
        for(int i=0, j=iC; i<iDim; i++)
        {
            if(iMax<iMat[i][j])
                iMax=iMat[i][j];
        }
    
        if(iMax == iMin)
        {
            return 1;
        }
    }
    return 0;
}

int mayorRenglonMenorColumna(int iMat[9][9], int iDim, int &iR, int &iC)
{
    
    //Declaración de variables
    int iMax, iMin; //iR=0, iC=0;

    
    //Encontrar el número más grande del renglón
    for(int i=0; i<iDim; i++)
    {
        iMax=-1000000;
        for(int j=0; j<iDim; j++)
        {
            if(iMat[i][j]>iMax)
            {
                iMax= iMat[i][j];
                iR= i;
                iC= j;
            }
        }
        
        //Ya se cual es el valor más grande del renglón correspondiente, ahora hay que verificar
        //que sea el menor de su columna correspondiente
        iMin=iMax;
        
         for(int i=0, j=iC; i<iDim; i++)
         {
             if(iMin>iMat[i][j])
                 iMin=iMat[i][j];
         }
         
        //Recorro solo la columan del número más grande en su renglón
        if(iMin == iMax)
        {
            return 1;
        }
    }
    return 0;
}

int main() {
    
    //Declaración de variables
    int iDim, iMat[9][9], iR, iC;
    
    //Verificar que sea una matriz cuadrada de maximo 10 y minimo 1
    cin>>iDim;
    while(iDim<1 || iDim>10)
    {
        cin>>iDim;
    }
    
    //Obtener numeros de la matriz
    for(int i=0; i<iDim; i++)
    {
        for(int j=0; j<iDim; j++)
        {
            cin>>iMat[i][j];
        }
    }
   
    if(mayorRenglonMenorColumna(iMat, iDim, iR, iC)==1)
        cout<<iR<<" "<<iC<<endl;
        else
        {
            if(menorRenglonMayorColumna(iMat, iDim, iR, iC)==1)
                cout<<iR<<" "<<iC<<endl;
            else
                cout<<"-1 -1"<<endl;
        }
    
    return 0;
}
