//------------------------------------------------------------------------
//PROGRAMA DE FACTURACION
//POR: GIAME CARLOS FAJARDO SANTOS
//20-04-2016
//------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
	//ARCHIVO
FILE *archivoFacturas;
FILE *archivoDetalles;
FILE *archivoClientes;
FILE *archivoProductos;
	//ESTRUCTURAS
typedef struct{//estrunctura FACTURA eFactura
		 char fecha[17];
		 int codigo, codigoCliente;
	 } eFactura;
typedef struct{//estrunctura DETALLE eDetalle
		 int codigoFactura, codigoProducto, cantidad;
		 float precioProducto;
	 } eDetalle;
typedef struct{//estrunctura CLIENTE eCliente
		 char nombre[30], cedula[13];
		 int codigo;
	 } eCliente;
typedef struct{//estrunctura PRODUCTO eProducto
		//variables
		char nombre[20];
		int codigo;
		float precio;
		//funciones
		
		void Grabar(){
			fprintf(archivoProductos,"%5d %20s %8.2f\n",codigo, nombre, precio);
		}
		
	 } eProducto;
	//VARIABLES
eFactura factura;
eDetalle detalle;
eCliente cliente;
eProducto producto;
	//AUXILIARES
char lecturaPrecioProducto[8];
char lecturaPrecioDetalle[8];
char lecturaCodigoProducto[5];
char lecturaCodigoProductoDetalle[5];
char lecturaCedula[13];
char lecturaCantidad[3];
char lecturaCodigoCliente[5];
char lecturaCodigoClienteFactura[5];
char lecturaCodigoFactura[5];
	//CREACION DE ARCHIVOS
void AbrirOCrearArchivoFactura(){//CREACION DEL ARCHIVO DE FACTURA
	archivoFacturas = fopen("facturas.txt","a+");

   if(archivoFacturas == NULL)
   {
      fprintf(stderr,"El archivo no se pudo crear o abrir");
      getch();
      exit(1);
   } 
}
void AbrirOCrearArchivoDetalle(){//CREACION DEL ARCHIVO DE DETALLE
	archivoDetalles = fopen("detalles.txt","a+");

   if(archivoDetalles == NULL)
   {
      fprintf(stderr,"El archivo no se pudo crear o abrir");
      getch();
      exit(1);
   } 
}
void AbrirOCrearArchivoCliente(){//CREACION DEL ARCHIVO DE CLIENTE
	archivoClientes = fopen("clientes.txt","a+");

   if(archivoClientes == NULL)
   {
      fprintf(stderr,"El archivo no se pudo crear o abrir");
      getch();
      exit(1);
   } 
}
void AbrirOCrearArchivoProducto(){//CREACION DEL ARCHIVO DE PRODUCTOS
	archivoProductos = fopen("productos.txt","a+");

   if(archivoProductos == NULL)
   {
      fprintf(stderr,"El archivo no se pudo crear o abrir");
      getch();
      exit(1);
   } 
}
	//BUSCAR
eProducto BuscarProducto(int codigo){
	eProducto product;
	fclose(archivoProductos);
	archivoProductos =  fopen("productos.txt","r");
	while(feof(archivoProductos)==NULL){
		fscanf(archivoProductos,"%5s %20s %8s\n",lecturaCodigoProducto, producto.nombre, lecturaPrecioProducto);
			if(atoi(lecturaCodigoProducto)==codigo){
				product.codigo = atoi(lecturaCodigoProducto);
				for(int i=0;i<20;i++)
					product.nombre[i] = producto.nombre[i];
				product.precio = atof(lecturaPrecioProducto);
			}	  
				
			fflush(stdin);
	}
	 	
	fclose(archivoProductos);
    return product;
}	
eCliente BuscarCliente(int codigo){
	eCliente client;
	fclose(archivoClientes);
	archivoClientes =  fopen("clientes.txt","r");
	while(feof(archivoClientes)==NULL){
		fscanf(archivoClientes,"%5s %13s %30s\n",lecturaCodigoCliente, cliente.cedula, cliente.nombre);
				
			if(atoi(lecturaCodigoCliente)==codigo){
				client.codigo = atoi(lecturaCodigoCliente);
				for(int i=0;i<30;i++)
					client.nombre[i] = cliente.nombre[i];
				for(int i=0;i<13;i++)
					client.cedula[i] = cliente.cedula[i];
			}
				
			fflush(stdin);
	}
	 	
	fclose(archivoProductos);
    getch();
    return client;
}	
eFactura BuscarFactura(int codigo){
	eFactura fact;
	fclose(archivoFacturas);
	archivoFacturas =  fopen("facturas.txt","r");
	while(feof(archivoFacturas)==NULL){
		fscanf(archivoFacturas,"%5s %5s %17s\n",lecturaCodigoFactura, lecturaCodigoClienteFactura, factura.fecha);
				
			if(atoi(lecturaCodigoFactura)==codigo){
				fact.codigo = atoi(lecturaCodigoFactura);
				fact.codigoCliente = atoi(lecturaCodigoClienteFactura);
				for(int i=0;i<17;i++)
				fact.fecha[i] = factura.fecha[i];
			}	  
				
			fflush(stdin);
	}
	 	
	fclose(archivoFacturas);
    getch();
    return fact;
}	
eDetalle BuscarDetalles(int codigo){
	eDetalle det;
	eProducto pro;
	
	fclose(archivoDetalles);
	archivoDetalles =  fopen("detalles.txt","r");
	while(feof(archivoDetalles)==NULL){
		fscanf(archivoDetalles,"%5s %5s %3s %6s\n", lecturaCodigoFactura, 
													lecturaCodigoProductoDetalle, 
													lecturaCantidad ,
													lecturaPrecioDetalle);
					
			if(atoi(lecturaCodigoFactura)==codigo){
				pro = BuscarProducto(atoi(lecturaCodigoProductoDetalle));		
				printf("%s",pro.nombre);
				printf("%5d       %3d        %6.2f\t\t\t|\n", atoi(lecturaCodigoProductoDetalle), 
															  atoi(lecturaCantidad),	
														      atof(lecturaPrecioDetalle));
				
			}	  
				
			fflush(stdin);
	}
	 	
	fclose(archivoDetalles);
    getch();
    return det;
}
	//MAYOR
int MayorProducto(){
	int mayor = 0;
	fclose(archivoProductos);
	archivoProductos =  fopen("productos.txt","r");
	while(feof(archivoProductos)==NULL){
		fscanf(archivoProductos,"%5s %20s %8s\n",lecturaCodigoProducto, producto.nombre, lecturaPrecioProducto);
			if(mayor<atoi(lecturaCodigoProducto)){
				mayor=atoi(lecturaCodigoProducto);
			}	  
				
			//fflush(stdin);
	}
	 	
	fclose(archivoProductos);
    //getch();
    return mayor;
}
	//SIGUIENTE	
int SiguienteProducto(){
	return MayorProducto()+1;
}	
	//GUARDAR y ESCANEAR

void GrabarDetalle(){
	fprintf(archivoDetalles,"%5d %5d %3d %6.2f\n",detalle.codigoFactura, detalle.codigoProducto, detalle.cantidad, detalle.precioProducto);
}
void EscanearDetalle(int codigoFactura){//ESCANEA LOS DATOS DEL DETALLE
	detalle.codigoFactura=codigoFactura;
	int codigoProducto;
	
	printf("Digite el codigo del producto: ");
	scanf("%d",&detalle.codigoProducto);
	codigoProducto=detalle.codigoProducto;
	printf("Digite la cantidad: ");
	scanf("%d",&detalle.cantidad);
//	printf("Digite el precio: ");
//	scanf("%f",&detalle.precioProducto);
//	printf("precio: %6.2f\n/n",BuscarProducto(codigoProducto).precio);
	detalle.precioProducto = BuscarProducto(codigoProducto).precio;
	GrabarDetalle();
}
void GrabarFactura(){
	printf("%d",factura.codigo);
	fprintf(archivoFacturas,"%5d %5d %17s\n",factura.codigo, factura.codigoCliente, factura.fecha);
}
void EscanearFactura(){//ESCANEA LOS DATOS DEL FACTURA
	char optDetalle;
	int codigo;
	printf("Digite el codigo: ");
	scanf("%d",&factura.codigo);
	codigo=factura.codigo;
	printf("Digite el codigo del cliente: ");
	scanf("%d",&factura.codigoCliente);
	//efectuar un bucle para los detalles
    
	do{
    	EscanearDetalle(factura.codigo);
    	printf("Deseas agregar otro producto?(S|N)\n");
    	optDetalle=getch();
    	if(optDetalle=='n'||optDetalle=='N')
    		break;
	}while(optDetalle=='s'||optDetalle=='S');
		
	
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y-%H:%M:%S",tlocal);
    
    for(int i=0;i<17;i++)
    	factura.fecha[i]=output[i];
    	
    factura.codigo=codigo;	
	GrabarFactura();
}
void GrabarCliente(){
	printf("-------%d-------",cliente.codigo);
	fprintf(archivoClientes,"%5d %13s %30s\n",cliente.codigo, cliente.cedula, cliente.nombre);
}
void EscanearCliente(){//ESCANEA LOS DATOS DEL CLIENTE
	printf("Digite el codigo: ");
	scanf("%d",&cliente.codigo);
	printf("Digite el nombre: ");
	scanf("%s",cliente.nombre);
	printf("Digite la cedula: ");
	scanf("%s",cliente.cedula);
	
	GrabarCliente();
}
void GrabarProducto(){
	fprintf(archivoProductos,"%5d %20s %8.2f\n",producto.codigo, producto.nombre, producto.precio);
}
void EscanearProducto(){//ESCANEA LOS DATOS DEL PRODUCTO
//	int codigo = SiguienteProducto();
//	printf("%d",SiguienteProducto());
//	producto.codigo = codigo;
	printf("Digite el codigo: ");
	scanf("%d",&producto.codigo);
	printf("Digite el nombre: ");
	scanf("%s",producto.nombre);
	printf("Digite el precio: ");
	scanf("%f",&producto.precio);
	
	producto.Grabar();
	//GrabarProducto();
}
void InsertarDetalle(){
	int codigo;
	printf("Digite el codigo de la factura: ");
	scanf("%d",&codigo);
	EscanearDetalle(codigo);
}	
	//MOSTRAR
void MostrarDetalles(){
	
	printf("\n");	 
	 		printf("+-------------------------------------+\n");	 
	 		printf("|Factura  Producto  Cantidad    Precio|\n");
	 		printf("+-------------------------------------+\n");	 
	 		fclose(archivoDetalles);
	 		
	 		archivoDetalles = fopen("detalles.txt","r");
	 		while(feof(archivoDetalles)==NULL){
				fscanf(archivoDetalles,"%5s %5s %3s %6s\n",lecturaCodigoFactura, lecturaCodigoProducto, lecturaCantidad ,lecturaPrecioProducto);
				
				printf("%5d    %5d       %3d        %6.2f|\n",atoi(lecturaCodigoFactura), atoi(lecturaCodigoProducto), atoi(lecturaCantidad),atof(lecturaPrecioProducto));
				
				fflush(stdin);
				
			}
	 		printf("+-------------------------------------+\n");	 
			
	 		fclose(archivoDetalles);
     		getch();
}
void MostrarFacturas(){
	
	printf("\n");	 
	 		printf("+--------------------------------------+\n");	 
	 		printf("|Código  Cliente                  Fecha|\n");
	 		printf("+--------------------------------------+\n");	 
	 		fclose(archivoFacturas);
	 		
	 		archivoFacturas =  fopen("facturas.txt","r");
	 		while(feof(archivoFacturas)==NULL){
				fscanf(archivoFacturas,"%5s %5s %17s\n",lecturaCodigoFactura, lecturaCodigoCliente, factura.fecha);
				
				printf("%5d    %5d        %17s|\n",atoi(lecturaCodigoFactura), atoi(lecturaCodigoCliente), factura.fecha);
				
				fflush(stdin);
			}
	 		printf("+--------------------------------------+\n");		 
			
	 		fclose(archivoFacturas);
     		getch();
}	
void MostrarClientes(){
	
	printf("\n");	 
	 		printf("+----------------------------------------------------+\n");	 
	 		printf("|Código        Cédula                          Nombre|\n");
	 		printf("+----------------------------------------------------+\n");	 
	 		fclose(archivoClientes);
	 		
	 		archivoClientes =  fopen("clientes.txt","r");
	 		while(feof(archivoClientes)==NULL){
				fscanf(archivoClientes,"%5s %13s %30s\n",lecturaCodigoCliente, cliente.cedula, cliente.nombre);
				
				printf("%5d    %13s %30s|\n",atoi(lecturaCodigoCliente), cliente.cedula, cliente.nombre);
				
				fflush(stdin);
			}
	 		printf("+----------------------------------------------------+\n");	 
			
	 		fclose(archivoClientes);
     		getch();
}	
void MostrarProductos(){
	
	printf("\n");	 
	 		printf("+-------------------------------------+\n");	 
	 		printf("|Código  Nombre                 Precio|\n");
	 		printf("+-------------------------------------+\n");	 
	 		fclose(archivoProductos);
	 		
	 		archivoProductos =  fopen("productos.txt","r");
	 		while(feof(archivoProductos)==NULL){
				fscanf(archivoProductos,"%5s %20s %8s\n",lecturaCodigoProducto, producto.nombre, lecturaPrecioProducto);
				  
				printf("%5d    %20s %8.2f|\n",atoi(lecturaCodigoProducto), producto.nombre, atof(lecturaPrecioProducto));
				
				fflush(stdin);
			}
	 		printf("+-------------------------------------+\n");
			
	 		fclose(archivoProductos);
     		getch();
}
void ImprimirFactura(int codigo){
	eFactura factur;
	eCliente client;
	eDetalle detall;
		
	factur = BuscarFactura(codigo);
	client = BuscarCliente(factur.codigoCliente);
	
	printf("+----------------------------------------------+\n");
	printf("|Codigo: %d\t\t\t\tFac#:%d|\n",client.codigo,factur.codigo);
	printf("|Cliente: %s\t\t  %s|\n",client.nombre,factur.fecha);
	printf("|Cedula: %s\t\t\t\t       |\n",client.cedula);
	printf("+----------------------------------------------+\n");
	
	//BuscarDetalles(factur.codigo);
	
	//printf("%s",BuscarCliente(6).nombre);
}
	//CONTROLES
void Salir(){
	exit(1);
}	
	//MENUES
void MenuDetalle(){
	char opcionMenu;
	
	do{
		system("cls");
		printf("+--------------------------------------+\n");
		printf("|--------- DIGITE UNA OPCION. ---------|\n");
		printf("+--------------------------------------+");
		printf("\n|                                      |");
		printf("\n|   'V' para volver                    |");
		printf("\n|   'I' para insertar                  |");
		printf("\n|   'L' para listar.                   |");
		printf("\n|                                      |");
		printf("\n+--------------------------------------+\n");
		opcionMenu=getch();
		switch(opcionMenu){
			case 'V':
			case 'v': system("cls");break;
			case 'I':
			case 'i': system("cls");InsertarDetalle();break;
			case 'L':
			case 'l': system("cls");MostrarDetalles();break;
		}
	}while(opcionMenu!='V'&&opcionMenu!='v');
}	
void MenuFactura(){
	char opcionMenu;
	
	do{
		system("cls");
		printf("+--------------------------------------+\n");
		printf("|--------- DIGITE UNA OPCION. ---------|\n");
		printf("+--------------------------------------+");
		printf("\n|                                      |");
		printf("\n|   'V' para volver                    |");
		printf("\n|   'A' para agregar.                  |");
		printf("\n|   'L' para listar.                   |");
		printf("\n|                                      |");
		printf("\n+--------------------------------------+\n");
		opcionMenu=getch();
		switch(opcionMenu){
			case 'V':
			case 'v': system("cls");break;
			case 'A':
			case 'a': system("cls");EscanearFactura();break;
			case 'L':
			case 'l': system("cls");MostrarFacturas();break;
		}
	}while(opcionMenu!='V'&&opcionMenu!='v');
}	
void MenuCliente(){
	char opcionMenu;
	
	do{
		system("cls");
		printf("+--------------------------------------+\n");
		printf("|--------- DIGITE UNA OPCION. ---------|\n");
		printf("+--------------------------------------+");
		printf("\n|                                      |");
		printf("\n|   'V' para volver                    |");
		printf("\n|   'A' para agregar.                  |");
		printf("\n|   'L' para listar.                   |");
		printf("\n|                                      |");
		printf("\n+--------------------------------------+\n");
		opcionMenu=getch();
		switch(opcionMenu){
			case 'V':
			case 'v': system("cls");break;
			case 'A':
			case 'a': system("cls");EscanearCliente();break;
			case 'L':
			case 'l': system("cls");MostrarClientes();break;
		}
	}while(opcionMenu!='V'&&opcionMenu!='v');
}	
void MenuProducto(){
	char opcionMenu;
	
	do{
		system("cls");
		printf("+--------------------------------------+\n");
		printf("|--------- DIGITE UNA OPCION. ---------|\n");
		printf("+--------------------------------------+");
		printf("\n|                                      |");
		printf("\n|   'V' para volver                    |");
		printf("\n|   'A' para agregar.                  |");
		printf("\n|   'L' para listar.                   |");
		printf("\n|                                      |");
		printf("\n+--------------------------------------+\n");
		opcionMenu=getch();
		switch(opcionMenu){
			case 'V':
			case 'v': system("cls");break;
			case 'A':
			case 'a': system("cls");EscanearProducto();break;
			case 'L':
			case 'l': system("cls");MostrarProductos();break;
		}
	}while(opcionMenu!='V'||opcionMenu!='v');
}	
void MenuPrincipal(){
	char opcionMenu;
	
	do{
		system("cls");
		printf("+--------------------------------------+\n");
		printf("|--------- DIGITE UNA OPCION. ---------|\n");
		printf("+--------------------------------------+");
		printf("\n|                                      |");
		printf("\n|   'F' menu facturas                  |");
		printf("\n|   'D' menu detalles                  |");
		printf("\n|   'C' menu clientes                  |");
		printf("\n|   'P' menu productos                 |");
		printf("\n|                                      |");
		printf("\n+--------------------------------------+\n");
		opcionMenu=getch();
		switch(opcionMenu){
			case 'F':
			case 'f': system("cls");MenuFactura();break;
			case 'D':
			case 'd': system("cls");MenuDetalle();break;
			case 'C':
			case 'c': system("cls");MenuCliente();break;
			case 'P':
			case 'p': system("cls");MenuProducto();break;
			case 'S':
			case 's': system("cls");Salir();break;
		}
	}while(true);
}

int main(){
	AbrirOCrearArchivoProducto();
	AbrirOCrearArchivoFactura();
	AbrirOCrearArchivoDetalle();
	AbrirOCrearArchivoCliente();
//	ImprimirFactura(83);
//	BuscarDetalles(83);
//	printf("%s",BuscarProducto(2).nombre);
	MenuPrincipal();
//	EscanearProducto();
//	EscanearFactura();
//	printf("%d",SiguienteProducto());
//	EscanearCliente();
//	MostrarProductos();
//	MostrarClientes();
//	MostrarDetalles();
//	MostrarFacturas();
	return 0;
}
