class pasajero
{
	public:

		pasajero();
		pasajero(int iId, string sNombre);
		int getId();
		string getNombre();
		void setId(int iId);
		void setNombre(string sNombre);
		void print();

	private:

		int iId;
		string sNombre;	
};

pasajero::pasajero()
{
	iId = 1;
	sNombre = "Hernan";
}

pasajero::pasajero(int iId, string sNombre)
{
	this->iId = iId;
	this->sNombre = sNombre;
}

int pasajero::getId()
{
	return iId;
}

string pasajero::getNombre()
{
	return sNombre;
}

void pasajero::setId(int iId)
{
	this->iId = iId;
}

void pasajero::setNombre(string sNombre)
{
	this->sNombre = sNombre;
}

void pasajero::print()
{
	cout<<iId<<"\n";
	cout<<sNombre<<endl;
}