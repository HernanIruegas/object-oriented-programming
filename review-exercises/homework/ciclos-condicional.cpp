//
//  main.cpp
//  Repaso ciclos y condicional
//
//  Created by Hernán Iruegas Villarreal on 11/08/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//
//Hernán Iruegas Villarreal
//A00817021

#include <iostream>
using namespace std;

void sumaPares(int iN)
{
    //Declaración de variables
    int iAcum=0;
    
    for(int iA=100;iA<1000;iA++)
    {
        //Declaración de variables
        int iB;
        
        //Primera asignación. Quitar el tercer digito de iA
        iB= iA/10;
        
        if(iA+iB==iN)
        {
            iAcum++;
            cout<<iA<<" + "<<iB<<" = "<<iN<<endl;
        }
        else
        {
            //Segunda asignación. Quitar el segundo digito de iA
            iB=(iA/100*10)+iA%10;
            if(iA+iB==iN)
            {
                iAcum++;
                cout<<iA<<" + "<<iB<<" = "<<iN<<endl;
            }
            else
            {
                //Tercera asignación. Quitar el primer digito de iA
                iB=iA%100;
                if(iA+iB==iN)
                {
                    iAcum++;
                    cout<<iA<<" + "<<iB<<" = "<<iN<<endl;
                }
            }
        }
    }
    
    cout<<"Total de pares = "<<iAcum<<endl;
}

int main() {
    
    //Declaración de variables
    int iN;
    
    cout<<"Ingrese un número entero de 3 digitos: ";
    cin>>iN;
    sumaPares(iN);
    
    return 0;
}
