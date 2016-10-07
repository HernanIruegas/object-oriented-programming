//
//  Header.h
//  composicion
//
//  Created by Hernán Iruegas Villarreal on 23/09/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#ifndef Header_h
#define Header_h

class fecha
{
    public:
    
        fecha();
        fecha(int iD, int iM, int iA);
        int getDia();
        int getMes();
        int getAño();
        void setDia(int iD);
        void setMes(int iM);
        void setAño(int iA);
        void print();
    
    private:

        int iDia, iMes, iAño;
    
};


fecha::fecha()
{
    iDia=1;
    iMes=1;
    iAño=2015;
}

fecha::fecha(int iD, int iM, int iA)
{
    iDia=iD;
    iMes=iM;
    iAño=iA;
}

int fecha::getDia()
{
    return iDia;
}

int fecha::getMes()
{
    return iMes;
}

int fecha::getAño()
{
    return iAño;
}

void fecha::setDia(int iD)
{
    iDia= iD;
}

void fecha::setMes(int iM)
{
    iDia= iM;
}

void fecha::setAño(int iA)
{
    iDia= iA;
}

void fecha::print()
{
    if(iDia<10)
        cout<<"0";
    
    cout<<iDia<<"/";
    
    if(iMes<10)
        cout<<"0";
    
    cout<<iMes<<"/"<<iAño<<endl;
}

#endif /* Header_h */
