class carro
{
	public:

		carro();
		carro(int iClave, string sMarca, int iModelo, int iKm);
		int getClave();
		string getMarca();
		int getModelo();
		int getKm();
		void setClave(int iClave);
		void setModelo(int iModelo);
		void setKm(int iKm);
		void setMarca(string sMarca);
		void print();

	private:

		int iClave, iModelo, iKm;
		string sMarca;
};

carro::carro()
{
	iClave = 2;
	sMarca = "Jetta";
	iModelo = 2016;
	iKm = 0;
}

carro::carro(int iClave, string sMarca, int iModelo, int iKm)
{
	this->iClave = iClave;
	this->sMarca = sMarca;
	this->iModelo = iModelo;
	this->iKm = iKm;
}

int carro::getClave()
{
	return iClave;
}

string carro::getMarca()
{
	return sMarca;
}

int carro::getModelo()
{
	return iModelo;
}

int carro::getKm()
{
	return iKm;
}

void carro::setClave(int iClave)
{
	this->iClave = iClave;
}

void carro::setMarca(string sMarca)
{
	this->sMarca = sMarca;
}

void carro::setModelo(int iModelo)
{
	this->iModelo = iModelo;
}

void carro::setKm(int iKm)
{
	this->iKm = iKm;
}

void carro::print()
{
	cout<<"La clave es: "<<iClave
	<<"\nLa marca es: "<<sMarca
	<<"\nEl modelo es: "<<iModelo
	<<"\nLos kilometros son: "<<iKm<<endl;
}

















