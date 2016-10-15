#include <iostream>

using namespace std;

class Reloj{
	private:
		int hora;
		int minu;
	public:
		Reloj();
		Reloj(int h);
		Reloj(int h, int m);
		void setHora(int h);
		void setMin(int m);
		int getHora();
		int getMin();
		void muestra();
		void operator++();
		void operator--();
		Reloj operator+(int m);
		Reloj operator+(Reloj r);
		Reloj operator-(int m);
		Reloj operator-(Reloj r);
		bool operator>(Reloj r);
		bool operator<(Reloj r);
		bool operator==(Reloj r);
};

// Aquí va tu codigo

Reloj::Reloj()
{
	hora = 0;
	minu = 0;
}

Reloj::Reloj(int h)
{
	hora = h;
	minu = 0;
}

Reloj::Reloj(int h, int m)
{
	hora = h;
	minu = m;
}

void Reloj::setHora(int h)
{
	hora = h;
}

void Reloj::setMin(int m)
{
	minu = m;
}

int Reloj::getHora()
{
	return hora;
}

int Reloj::getMin()
{
	return minu;
}

void Reloj::muestra()
{
	if (hora < 10)
    	cout << "0";

    cout << hora <<":";
    if (minu < 10)
        cout << "0";
    cout << minu << endl;		
}

void Reloj::operator++()
{
	if(minu == 59)
	{
		minu = 00;
		if(hora ==23)
			hora = 00;
		else 
			hora++;
	}
	else
		minu++;
}

void Reloj::operator--()
{
	if(minu==00)
	{
		minu = 59;
		if(hora==00)
			hora = 23;
		else
			hora--;
	}
	else
		minu--;
}

Reloj Reloj::operator+(int m)
{
	int iMinTotales = hora * 60 + minu + m;
	hora = (iMinTotales / 60) % 24;
	minu = iMinTotales % 60;
	Reloj rUno(hora, minu);
	return rUno;
}

Reloj Reloj::operator+(Reloj r)
{
	int iMinTotales = (this->hora * 60 + r.hora * 60) + this->minu + r.minu;
	int nuevaHora = (iMinTotales / 60) % 24;
	int nuevoMinu = iMinTotales % 60;
	Reloj rUno(nuevaHora, nuevoMinu);
	return rUno;
}

Reloj Reloj::operator-(int m)
{
	int iMinTotales = hora * 60 + minu - m;
	hora = (iMinTotales / 60) % 24;
	minu = iMinTotales % 60;
	Reloj rUno(hora, minu);
	return rUno;
} 

Reloj Reloj::operator-(Reloj r)
{
	int iMinutosTotales = (hora - r.getHora()) * 60 + (minu - r.getMin());
    if (iMinutosTotales < 1440)
    {
        iMinutosTotales+=1440;
        iMinutosTotales = iMinutosTotales % 1440;
    }

        int iH = iMinutosTotales / 60;
        int iM = iMinutosTotales - iH * 60;

    return Reloj(iH, iM);
} 

bool Reloj::operator>(Reloj r)
{
	if(this->hora > r.hora)
		return true;
	else 
	{
		if(this->hora == r.hora)
		{
			if(this->minu > r.minu)
				return true;
			else
				return false;
		}
		else
			return false;
	}
} 


bool Reloj::operator<(Reloj r)
{
	if(this->hora < r.hora)
		return true;
	else 
	{
		if(this->hora == r.hora)
		{
			if(this->minu < r.minu)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

bool Reloj::operator==(Reloj r)
{
	if(this->hora == r.hora && this->minu == r.minu)
		return true;
	else
		return false;
}


int main(){
	int a1, a2, b2, a3, b3, op;
	cin >> op;
	cin >> a1 >> a2 >> b2 >> a3 >> b3;
	Reloj r1(a1), r2(a2,b2), r3(a3,b3), r4, r5, r6;
	
	switch (op){
		case 1:{
			++r1;
			++r2;
			++r3;
			r1.muestra();
			r2.muestra();
			r3.muestra();
			break;
		}
		case 2:{
			--r1;
			--r2;
			--r3;
			r1.muestra();
			r2.muestra();
			r3.muestra();
			break;
		}
		case 3:{
			r4=r1+r2;
			r5=r1+r3;
			r6=r2+r3;
			r4.muestra();
			r5.muestra();
			r6.muestra();
			break;
		}
		case 4:{
			r4=r1+20;
			r5=r2+60;
			r6=r3+100;
			r4.muestra();
			r5.muestra();
			r6.muestra();
			break;
		}
		case 5:{
			r4=r1-r2;
			r5=r1-r3;
			r6=r2-r3;
			r4.muestra();
			r5.muestra();
			r6.muestra();
			break;
		}
		case 6:{
			r4=r1-20;
			r5=r2-60;
			r6=r3-100;
			r4.muestra();
			r5.muestra();
			r6.muestra();
			break;
		}
		case 7:{
			if (r1>r2)
				cout << "r1 SI es mayor a r2"<<endl;
			else 
				cout << "r1 NO es mayor a r2" <<endl;
			if (r1>r3)
				cout << "r1 SI es mayor a r3"<<endl;
			else 
				cout << "r1 NO es mayor a r3" <<endl;
			if (r2>r3)
				cout << "r2 SI es mayor a r3"<<endl;
			else 
				cout << "r2 NO es mayor a r3" <<endl;
			break;
		}
		case 8:{
			if (r1<r2)
				cout << "r1 SI es menor a r2"<<endl;
			else 
				cout << "r1 NO es menor a r2" <<endl;
			if (r1<r3)
				cout << "r1 SI es menor a r3"<<endl;
			else 
				cout << "r1 NO es mayor a r3" <<endl;
			if (r2<r3)
				cout << "r2 SI es menor a r3"<<endl;
			else 
				cout << "r2 NO es menor a r3" <<endl;
			break;
		}
		case 9:{
			if (r1==r2)
				cout << "r1 SI es igual a r2"<<endl;
			else
				cout << "r1 NO es igual a r2"<<endl;
			if (r1==r3)
				cout << "r1 SI es igual a r3"<<endl;
			else
				cout << "r1 NO es igual a r3"<<endl;
			if (r2==r3)
				cout << "r2 SI es igual a r3"<<endl;
			else
				cout << "r2 NO es igual a r3"<<endl;
			break;
		}
	}
}