//
//  evento.h
//  composicion
//
//  Created by Hernán Iruegas Villarreal on 23/09/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#ifndef evento_h
#define evento_h
#include "fecha.h"

class evento
{
    public:
    evento();
    evento(string sN, fecha fI, fecha fF);
    string getNombre();
    fecha getFecha_ini();
    fecha getFecha_fin();
    void setNombre(string sN);
    void setFecha_ini(fecha fI);
    void setFecha_fin(fecha fF);
    void print();
    int calculaDias();
    
    private:
    int diasMes(int iM);
    string sNombre;
    fecha fFecha_ini;
    fecha fFecha_fin;
    
};
    
evento::evento()
{
    sNombre = "SIN NOMBRE DE EVENTO";
    fecha fIni, fFin; //se crean objetos de clase fecha con valores del constructor default de clase fecha
    fFecha_ini = fIni;
    fFecha_fin = fFin;
}

evento::evento(string sN, fecha fI, fecha fF)
{
    sNombre = sN;
    fFecha_ini = fI; //los objetos deben ser declarados antes en el main para pasarlos como parametros
    fFecha_fin = fF;
}

string evento::getNombre()
{
    return sNombre;
}
    
fecha evento::getFecha_ini()
{
    return fFecha_ini;
}
    
fecha evento::getFecha_fin()
{
    return fFecha_fin;
}
    
void evento::setNombre(string sN)
{
    sNombre = sN;
}
    
void evento::setFecha_ini(fecha fI)
{
    fFecha_ini = fI;
}
    
void evento::setFecha_fin(fecha fF)
{
    fFecha_fin = fF;
}
    
void evento::print()
{
    cout<<sNombre<<endl;
    fFecha_ini.print(); //tengo que llamar a una funcion de su clase, porque es un objetos y sus variables son privadas
    fFecha_fin.print();
}

int evento::diasMes(int iM)
{
    if(iM==2)
        return 28;
    else if(iM==4 || iM==6 || iM==9 || iM==11)
        return 30;
    else
        return 31;
}

int evento::calculaDias()
{
    if(fFecha_ini.getMes() == fFecha_fin.getMes())
        return fFecha_fin.getDia() - fFecha_ini.getDia()+1;
    else
    {
        int iDiasTotales = fFecha_fin.getDia();
        iDiasTotales += (diasMes(fFecha_fin.getMes()-fFecha_ini.getDia()+1)); //sumar dias del ultimo mes
        for(int iA= fFecha_ini.getMes()+1; iA<fFecha_fin.getMes(); iA++) //sumas dias de meses intermedios
            {
                iDiasTotales += diasMes(iA);
            }
            
            return iDiasTotales;
    }
        
}

#endif /* evento_h */
