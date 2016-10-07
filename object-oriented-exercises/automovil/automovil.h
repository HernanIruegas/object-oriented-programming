//
//  automovil.h
//  automovil
//
//  Created by Hernán Iruegas Villarreal on 08/09/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#ifndef automovil_h
#define automovil_h

class automovil
{
    
public:
    
    automovil();
    int getKilometros();
    int getCapTanque();
    int getRendimiento();
    double getGasolina();
    void setKilometros(int iKm);
    void setCapTanque(int iCapTanque);
    void setRendimiento(int iKmxLitro);
    void setGasolina(double dGasolina);
    bool avanza(int iKmAvanzar);
    void llenaTanque();
    
private:
    
    int iKm, iCapTanque, iKmxLitro;
    double dGasolina;
};

automovil::automovil()
{
    this->iKm = 0;
    this->iCapTanque= rand()%(71-40)+40;
    this->iKmxLitro=rand()%(21-8)+8;
}

int automovil::getKilometros()
{
    return this->iKm;
}

int automovil::getCapTanque()
{
    return this->iCapTanque;
}

int automovil::getRendimiento()
{
    return this->iKmxLitro;
}

double automovil::getGasolina()
{
    return this->dGasolina;
}

void automovil::setKilometros(int iKm)
{
    this->iKm = iKm;
}

void automovil::setCapTanque(int iCapTanque)
{
    this->iCapTanque = iCapTanque;
}

void automovil::setRendimiento(int iKmxLitro)
{
    this->iKmxLitro = iKmxLitro;
}

void automovil::setGasolina(double dGasolina)
{
    this->dGasolina=dGasolina;
}

bool automovil::avanza(int iKmAvanzar)
{
    if(iKmAvanzar<=(this->dGasolina * this->iKmxLitro))
        return true;
    else
        return false;
    
}

void automovil::llenaTanque()
{
    this->dGasolina= this->iCapTanque;
}

#endif /* automovil_h */
