#include <iostream>
#include <string>
#include <string.h>

using namespace std;
struct Producto{
	string nombre;
	float precio;
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
void LISTAR_PRODUCTOS(Producto PROD[],int CDP){
	cout<<endl<<"---------LISTA DE PRODUCTOS-------- "<<endl<<endl;
	
	for(int i=0;i<CDP;i++){
		
		cout<<" "<<i+1<<"."<<PROD[i].nombre<<"          "<<"Precio: "<<PROD[i].precio<<" soles "<<endl;
	}
	cout<<endl<<"--------------------------------------------"<<endl;
}	
void BUCAR_PRODUCTO(Producto PROD[],int CDP){
	cout<<"-----------BUSCAR PRODUCTO------------"<<endl<<endl;
	string nom_p;
	int flag;
	fflush(stdin);
	cout<<"Ingrese el nombre del producto que quiere buscar: ";
	getline(cin, nom_p);
	for(int i=0; i<CDP;i++){
		if(nom_p==PROD[i].nombre){
			cout<<"NOMBRE: "<<PROD[i].nombre<<endl;
			cout<<"PRECIO: "<<PROD[i].precio<<endl;
			flag=1;
		}
	}
	if(flag!=1){
		cout<<endl;
		cout<<"!!! Producto no registrado.";
		cout<<endl<<"--------------------------------------------"<<endl;
	}
	cout<<endl<<"--------------------------------------------"<<endl;
}	
void ACTUALIZAR_PRODUCTO(Producto PROD[],int CDP){
	cout<<endl<<"--------------ACTUALIZAR PRODUCTO-----------"<<endl<<endl;
	string nom_p;
	int flag;
	fflush(stdin);
	cout<<"Ingrese el nombre del producto que quiere actualizar: ";
	getline(cin, nom_p);
	for(int i=0; i<CDP;i++){
		if(nom_p==PROD[i].nombre){
			cout<<endl<<"--------------------------------------------"<<endl;
			cout<<"__VIGENTE ---> Nombre:"<<PROD[i].nombre<<" |"<<"Precio: "<<PROD[i].precio<<" soles___"<<endl<<endl;
			cout<<"---NUEVO---"<<endl<<endl<<"NOMBRE: ";
			getline(cin, PROD[i].nombre);
			cout<<"PRECIO: ";
			cin>>PROD[i].precio;
			flag=1;
		}
	}
	if(flag!=1){
		cout<<endl;
		cout<<"!!! Producto no registrado.";
		cout<<endl<<"--------------------------------------------"<<endl;
	}else{
	
		cout<<"Actualizado EXITOSAMENTE."<<endl<<"--------------------------------------------"<<endl;
	}
}
void ELIMINAR_PRODUCTO(Producto PROD[],int &CDP){
	cout<<endl<<"--------------ELIMINAR PRODUCTO-----------"<<endl<<endl;
	string nom_p;
	int flag;
	fflush(stdin);
	cout<<"Ingrese el nombre del producto que quiere eliminar: ";
	getline(cin, nom_p);
	for(int i=0;i<CDP;i++){
		if(PROD[i].nombre==nom_p){
			PROD[CDP-1].nombre=PROD[i].nombre;
			cout<<endl<<"Se elimino el producto: "<<PROD[i].nombre<<endl;
			CDP--;
			flag=1;
		}
		
	}
	if(flag!=1){
		cout<<endl;
		cout<<"!!! Producto no registrado.";
		cout<<endl<<"--------------------------------------------"<<endl;
	}else{
	
		cout<<"ELIMINADO EXITOSAMENTE."<<endl<<"--------------------------------------------"<<endl;
	}
}
struct Venta{
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
};
void REGISTRAR_VENTA(Venta VENT[],Producto PROD[],int CDP,int &n_ventas){
	cout<<endl<<"-------------REGISTRAR UNA VENTA----------"<<endl<<endl;

	int resp=1,flag;
	float precio_uni;
	while(resp==1){
		fflush(stdin);
		cout<<endl<<"Producto: ";
		getline(cin, VENT[n_ventas].producto);
		for(int i=0; i<CDP;i++){
			if(VENT[n_ventas].producto==PROD[i].nombre){
				precio_uni=PROD[i].precio;
				flag=1;
			}
					
		}
		cout<<"Cantidad: ";
		cin>>VENT[n_ventas].cantidad;
		
		VENT[n_ventas].precioTotal=precio_uni*VENT[n_ventas].cantidad;
		VENT[n_ventas].idVenta=n_ventas+1;
		
		n_ventas++;
		cout<<endl<<"Quiere agregar otra venta? Digite (si= 1 , no= 0): ";
		cin>>resp;
		
	}
	cout<<endl<<"---------------"<<flag<<"---------------------------"<<endl;
}
void LISTAR_VENTAS(Venta VENT[],int n_ventas){
	cout<<endl<<"---------LISTA DE VENTAS-------- "<<endl<<endl;
	
	for(int i=0;i<n_ventas;i++){
		
		cout<<"ID: "<<VENT[i].idVenta<<"|Producto: "<<VENT[i].producto<<"|Cantidad: "<<VENT[i].cantidad<<"|Precio Total: "<<VENT[i].precioTotal<<endl;
	}
	cout<<endl<<"--------------------------------------------"<<endl;
}	
void CALCULAR_TOTAL_DE_VENTAS(Venta VENT[],int n_ventas){
	cout<<endl<<"-------------CALCULAR TOTAL DE VENTAS----------"<<endl<<endl;
	float suma=0;
	for(int i=0;i<n_ventas;i++){
		
		cout<<"ID: "<<VENT[i].idVenta<<"|Recaudacion: "<<VENT[i].precioTotal<<" soles "<<endl;
		suma=suma+VENT[i].precioTotal;
	}
	cout<<endl<<"Recaudacion total por ventas: "<<suma<<endl;
	cout<<endl<<"------------------------------------------"<<endl;
	
}



int main(){
	Producto PROD[100];
	Venta VENT[100];
	int cantidad_de_productos=0;
	int CDP=cantidad_de_productos;
	int n_ventas=0;
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
    	LISTAR_PRODUCTOS(PROD,CDP);
	}
	if(opcion=='c'){
    	BUCAR_PRODUCTO(PROD,CDP);
	}
	if(opcion=='d'){
   		ACTUALIZAR_PRODUCTO(PROD,CDP);
	}
	if(opcion=='e'){
    	ELIMINAR_PRODUCTO(PROD,CDP);
	}
	if(opcion=='f'){
    	REGISTRAR_VENTA(VENT,PROD,CDP,n_ventas);
	}
	if(opcion=='g'){
    	LISTAR_VENTAS(VENT,n_ventas);
	}
	if(opcion=='h'){
    	CALCULAR_TOTAL_DE_VENTAS(VENT,n_ventas);
	}
    
    }while(opcion!='s');
	
	return 0;
}
