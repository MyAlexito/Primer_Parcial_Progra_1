#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Empleado{
	int codigo_empleado;
	char nombre[50];
	char apellido[50];
	char puesto[50];
	int sueldo;
	int bonificacion;
};
 void ingresar_empleado();
void abrir_empleado();
 void modificar_empleado();
 
int main (){
	abrir_empleado();
 ingresar_empleado();
	modificar_empleado();

	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO EMPLEADO: ";
	cin>>cod;
    Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo_empleado == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo de Empleado: \n" << empleado.codigo_empleado << endl;
        cout << "\nNombre: \n" << empleado.nombre << endl;
        cout << "\nApellido: \n" << empleado.apellido << endl;
        cout << "\nPuesto: \n" << empleado.puesto << endl;
        cout << "\nSueldo Base: \n" << empleado.sueldo << endl;
        cout << "\nBonificacion: \n" << empleado.bonificacion << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo Empleado: \n" << empleado.codigo_empleado << endl;
        cout << "Nombre: \n" << empleado.nombre << endl;
        cout << "Apellido: \n" << empleado.apellido << endl;
        cout << "Puesto: \n" << empleado.apellido << endl;
        cout << "Sueldo Base: \n" << empleado.sueldo << endl;
        cout << "Bonificacion: \n" << empleado.bonificacion << endl;
        cout << endl;
	fclose(archivo);
}

void abrir_empleado(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<" _______________________________________________________________________"<<endl;
	cout<<"|"<< "id" <<"|"<< "CODIGO DE EMPLEADO" <<"|"<< "NOMBRE"<<"|"<<"APELLIDO"<<"|"<<"PUESTO"<<"|"<<"SUELDO BASE "<<"|"<<"BONIFICACION"<<" |"<<endl;	
	cout<<" -----------------------------------------------------------------------"<<endl;
		do{
		cout<<"________________________________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo_empleado <<" | "<< empleado.nombre<<" | "<<empleado.apellido<<" | "<<empleado.puesto<<" | "<<empleado.sueldo<<" | "<<endl;
        cout<<"------------------------------------------------"<<endl;
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"       Ingrese el Codigo de Empleado:\n";
		cin>>empleado.codigo_empleado;
        cin.ignore();
        
		cout<<"       Ingrese el Nombre:\n";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"       Ingrese el Apellido:\n";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"       Ingrese el Puesto:\n";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
		cout<<"       Ingrese el Sueldo Base:\n";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"       Ingrese la Bonificacion:\n";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"       Desea Agregar otro Nombre s/n :\n ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();
		
	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido, puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el Codigo que desea Modificar: \n";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );
		cout<<"\nIngrese el Codigo de Empleado:\n";
		cin>>empleado.codigo_empleado;
        cin.ignore();
        
		cout<<"\nIngrese el Nombre:\n";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"\nIngrese el Apellido:\n";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"\nIngrese el Puesto:\n";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
		cout<<"\nIngrese el Sueldo Base:\n";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"\nIngrese la Bonificacion:\n";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}
