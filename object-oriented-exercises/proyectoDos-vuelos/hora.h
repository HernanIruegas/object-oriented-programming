class hora
{
    public:
    
        hora();
        hora(int iHora, int iMinu);
        int getHora();
        int getMinu();
        void setHora(int iHora);
        void setMinu(int iMinu);
        void print();
    
    private:

        int iHora, iMinu;
};


hora::hora()
{
    iHora = 0;
    iMinu = 0;
}

hora::hora(int iHora, int iMinu)
{
    this->iHora = iHora;
    this->iMinu = iMinu;
}

int hora::getHora()
{
    return iHora;
}

int hora::getMinu()
{
    return iMinu;
}

void hora::setHora(int iHora)
{
    this->iHora= iHora;
}

void hora::setMinu(int iMinu)
{
    this->iMinu= iMinu;
}

void hora::print()
{
   if(iHora<10)
   		cout<<"0";
   
   cout<<iHora<<":";

   if(iMinu<10)
   		cout<<"0";
   
   cout<<iMinu<<endl;

   
}