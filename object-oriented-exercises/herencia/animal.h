using namespace std;
class animal
{
	public:

		animal();
		animal(int cantPatas, string comida, char tipo);
		int getCantPatas();
		string getComida();
		char getTipo();
		void setCantPatas(int cantPatas);
		void setComida(string comida);
		void setTipo(char tipo);
		void muestraDatos();

	protected:

		int cantPatas;
		string comida;
		char tipo;

};

animal::animal()
{
	cantPatas = 0;
	comida = "croquetas";
	tipo = 'M';
}

animal::animal(int cantPatas, string comida, char tipo)
{
	this->cantPatas = cantPatas;
	this->comida = comida;
	this->tipo = tipo;
}

int animal::getCantPatas()
{
	return cantPatas;
}

string animal::getComida()
{
	return comida;
}

char animal::getTipo()
{
	return tipo;
}

void animal::setCantPatas(int cantPatas)
{
	this->cantPatas = cantPatas;
}

void animal::setComida(string comida)
{
	this->comida = comida;
}

void animal::setTipo(char tipo)
{
	this->tipo = tipo;
}

void animal::muestraDatos()
{
	cout<<"Cantidad de Patas: "<<cantPatas<<" "
	<<"Comida: "<<comida<<" "
	<<"Tipo: "<<tipo<<endl;
}











