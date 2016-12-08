using namespace std;//noc si sea necesario para sobrecarga operador cout

class hora{
	
	private:

		int hh,mm;

	public:

		hora();
		hora(int hh, int mm);
		int getHora();
		int getMinu();
		void setHora(int hh);
		void setMinu(int mm);
		hora operator+(int minu);
		bool operator>=(hora h);
		bool operator<=(hora h);
		bool operator==(hora h);
		friend istream& operator>>(istream& is, hora& horaCreada);
		friend ostream& operator<<(ostream& os, hora& horaCreada);
};

hora::hora()
{
	hh = 0;
	mm = 0;
}

hora::hora(int hh, int mm)
{
	this->hh = hh;
	this->mm = mm;
}

int hora::getHora()
{
	return hh;
}

int hora::getMinu()
{
	return mm;
}

void hora::setHora(int hh)
{
	this->hh = hh;
}

void hora::setMinu(int mm)
{
	this->mm = mm;
}

hora hora::operator+(int minu)
{
	int minHora = hh*60 + mm;//minutos de la hora actual

	int minTotales = minu + minHora; //se suman los minutos del parametro

	int hhNuevo = (minTotales/60)%24;
	int mmNuevo = minTotales%60;

	hora horaNueva(hhNuevo, mmNuevo); //se crea la nueva hora

	return horaNueva;
}

bool hora::operator>=(hora hComparar)
{
	if(hh > hComparar.hh)
		return true;
	else 
	{
		if (hh == hComparar.hh)
		{
			if(mm >= hComparar.mm)
				return true;
			else 
				return false;
		}
		else 
			return false;
	}
}

bool hora::operator<=(hora hComparar)
{
	if(hh < hComparar.hh)
		return true;
	else 
	{
		if (hh == hComparar.hh)
		{
			if(mm <= hComparar.mm)
				return true;
			else 
				return false;
		}
		else 
			return false;
	}
}

bool hora::operator==(hora hComparar)
{
	if(hh == hComparar.hh && mm == hComparar.mm)
		return true;
	else
		return false;
}

//tengo que asegurarme que estan bien implementadas estas ultimas dos funciones
istream& operator>>(istream &is, hora &horaEntra)
{
	is>>horaEntra.hh;
	is>>horaEntra.mm;

	return is;
}

ostream& operator<<(ostream& os, hora& horaSale)
{
	if(horaSale.getHora()<10)
		os<<"0"<<horaSale.getHora()<<":";
    else
        os<<horaSale.getHora()<<":";

	if(horaSale.getMinu()<10)
		os<<"0"<<horaSale.getMinu()<<endl;
    else
        os<<horaSale.getMinu()<<endl;

	return os;
}


















