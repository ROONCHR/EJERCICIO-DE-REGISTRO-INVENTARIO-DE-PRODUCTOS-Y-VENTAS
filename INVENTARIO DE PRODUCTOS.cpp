#include <iostream>
#include <string>
#include <string.h>

using namespace std;
struct Producto{
	string nombre;
	float precio;
};
struct Venta{
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
};
void registrar_producto(Producto PROD[],int &CDP){
	cout<<endl<<"-----AGREGAR PRODUCTO------"<<endl;
	int resp=1;
	while(resp==1){
		fflush(stdin);
		cout<<endl<<"NOMBRE: ";
		getline(cin, PROD[CDP].nombre);
		cout<<"PRECIO: ";
		cin>>PROD[CDP].precio;
		CDP++;
		cout<<endl<<"Quiere agregar otro producto? Digite (si= 1 , no= 0): ";
		cin>>resp;
		
	}
	cout<<endl<<"------------------------------------------"<<endl;
}	

int main(){
	Producto PROD[100];
	Venta VENT[100];
	int cantidad_de_productos=0;
	int CDP=cantidad_de_productos;
	char opcion;
	do{
	fflush(stdin);
	cout<<"--------INVENTARIO DE PRODUCTOS Y VENTAS-----------"<<endl;
    cout <<endl<< "--- MENU PRINCIPAL ---" << endl;
    cout << "a) Registrar un nuevo producto" << endl;
    cout << "b) Listar los productos registrados" << endl;
    cout << "c) Buscar un producto por nombre" << endl;
    cout << "d) Actualizar los datos de un producto" << endl;
    cout << "e) Eliminar un producto" << endl;
    cout << "f) Registrar una venta" << endl;
    cout << "g) Listar las ventas realizadas" << endl;
    cout << "h) Calcular el total de ventas realizadas" << endl;
    cout << "s) Salir" << endl;
    cout << "Ingrese su opcion: ";
	
    
    cin >> opcion;
    if(opcion=='a'){
    	registrar_producto(PROD,CDP);
	}
	if(opcion=='b'){
    //	LISTAR_PRODUCTOS(PROD,CDP);
	}
	if(opcion=='c'){
    	
	}
	if(opcion=='d'){
    	
	}
	if(opcion=='e'){
    	
	}
	if(opcion=='f'){
    	
	}
	if(opcion=='g'){
    	
	}
	if(opcion=='h'){
    	
	}
    
    }while(opcion!='s');
	
	return 0;
}
