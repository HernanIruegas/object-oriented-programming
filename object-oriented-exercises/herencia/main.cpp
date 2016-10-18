#include <iostream>
using namespace std;

#include "Beagle.h"

int main(){
	int p1, p2, p3,p4;
	string c1, c2, c3, c4;
	string n2, n3, n4;
	char col3, col4;
	char t1,t2,t3,t4;
	
	cin >> p1>>c1>>t1;
	cin >> p2>>c2>>t2>>n2;
	cin >> p3>>c3>>t3>>n3>>col3;
	cin >> p4>>c4>>t4>>n4>>col4;
	
	animal pato(p1,c1,t1);
	perro chihuahua(p2,c2,t2,n2);
	beagle snoopy(p3,c3,t3,n3,col3);
	beagle superCan;
	
	pato.muestraDatos();
	chihuahua.muestraDatos();
	snoopy.muestraDatos();
	
	superCan.setCantPatas(p4);
	superCan.setComida(c4);
	superCan.setNombre(n4);
	superCan.setTipo(t4);
	superCan.setColor(col4);
	cout<<superCan.getCantPatas()<<"-"<<superCan.getComida()<<"-"
		<<(superCan.getTipo()=='S'?"SALVAJE":"DOMESTICO")<<"-"
		<<superCan.getNombre()<<"-"
		<<(superCan.getColor()=='B'?"BICOLOR":"TRICOLOR")<<"-"
		<<superCan.habla()<<endl;
}

