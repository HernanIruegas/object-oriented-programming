class aeropuerto
{
	public:

		aeropuerto();
		aeropuerto(string sClave, string sCiudad);
		string getClave();
		string getCiudad();
		void setClave(string sClave);
		void setCiudad(string sCiudad);
		void print();

	private:

		string sClave, sCiudad;

};

aeropuerto::aeropuerto()
{
	sClave = "2222";
	sCiudad = "Monterrey";
}

aeropuerto::aeropuerto(string sClave, string sCiudad)
{
	this->sClave = sClave;
	this->sCiudad = sCiudad;
}

string aeropuerto::getClave()
{
	return sClave;
}

string aeropuerto::getCiudad()
{
	return sCiudad;
}

void aeropuerto::setClave(string sClave)
{
	this->sClave = sClave;
}

void aeropuerto::setCiudad(string sCiudad)
{
	this->sCiudad = sCiudad;
}

void aeropuerto::print()
{
	cout<<sClave<<"\n";
	cout<<sCiudad<<endl;
}