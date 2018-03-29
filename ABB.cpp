#include<iostream>
#include<conio.h>

using namespace std;

struct nodo{
	
	int dato;
	
	nodo *izquierda;
	nodo *derecha;
	nodo *padre;
};

nodo *arbol = NULL;         //puntero que me permitira almacenar todos los nodos
nodo *crear;                //puntero que me permitira manejar la creacion del nodo raiz
bool band;                  //variable que me permitira determinar que elemnto encontre en el arbol

/*************************************************/
nodo *raiz(int n, nodo *padre){          //funcion externa que me permitira generar el nodo raiz mas facilmente
	
	crear = new nodo();
	
	crear->dato = n;
	crear->derecha = NULL;          
	crear->izquierda = NULL;
	crear->padre = padre;
	
	return crear;
}

void insertar(nodo *&arbol, int n, nodo *padre){
	
	if(arbol == NULL){
		
		arbol = raiz(n, padre);     //le asigno la funcion raiz para generar el nodo raiz y determinar luego quien es el padre y quien va a la izquierda o derecha
		
	}else if(n < arbol->dato){
		
		insertar(arbol->izquierda, n, arbol);     //le asigno arbol como referecia para indicarle quien es el padre de cada elemento
		
	}else if(n > arbol->dato){
		
		insertar(arbol->derecha, n, arbol);       //le asigno arbol como referecia para indicarle quien es el padre de cada elemento
	}
}
/*************************************************/

void mostrar(nodo *arbol, int cont){           //la variable cont me permitira imprimir el arbol de manera un poco grafica
	
	if(arbol == NULL){
		
		return;	
	}
	
	mostrar(arbol->derecha, cont+1);
	
	for(int i = 0; i<cont; i++){               //este ciclo me permitira la impresion de lineas en blanco
	
		cout<<"  ";
	}
	
	cout<<arbol->dato<<endl;
	
	mostrar(arbol->izquierda, cont+1);
}

void buscar(nodo *arbol, int n){
	
	band = false;
	
	if(arbol == NULL){
		
		return;
		
	}else if(n == arbol->dato){
		
		band = true;
		
	}else if(n < arbol->dato){
		
		buscar(arbol->izquierda, n);
		
	}else{
		
		buscar(arbol->derecha, n);
	}
}

/****************************************/
void preorden(nodo *arbol){
	
	if(arbol != NULL){
		
		cout<<arbol->dato<<" ";
		preorden(arbol->izquierda);
		preorden(arbol->derecha);
	}
}

void inorden(nodo *arbol){
	
	if(arbol != NULL){
		
		inorden(arbol->izquierda);
		cout<<arbol->dato<<" ";
		inorden(arbol->derecha);
	}
}

void postorden(nodo *arbol){
	
	if(arbol != NULL){
		
		postorden(arbol->izquierda);
		postorden(arbol->derecha);
		cout<<arbol->dato<<" ";
	}
}
/****************************************/

/*************************************************/
void destruirNodo(nodo *nodo){
	
	nodo->izquierda = NULL;
	nodo->derecha = NULL;
	
	delete nodo;
}

nodo *minimo(nodo *arbol){
	
	if(arbol == NULL){
		
		return NULL;
	}
	
	if(arbol->izquierda){
		
		return minimo(arbol->izquierda);
		
	}else{
		
		return arbol;
	}
}

void reemplazar(nodo *arbol, nodo *nuevo){
	
	if(arbol->padre){
		
		if(arbol->dato = arbol->padre->izquierda->dato){
			
			arbol->padre->izquierda = nuevo;
			
		}else if(arbol->dato = arbol->padre->derecha->dato){
			
			arbol->padre->derecha = nuevo;
		}
		
		if(nuevo){
			
			nuevo->padre = arbol->padre;
		}
	}
}

void eliminarNodo(nodo *nodoEliminar){
	
	if(nodoEliminar->izquierda && nodoEliminar->derecha){
		
		nodo *menor = minimo(nodoEliminar->derecha);
		
		nodoEliminar->dato = menor->dato;
		
		eliminarNodo(menor);
		
	}else if(nodoEliminar->izquierda){
		
		reemplazar(nodoEliminar, nodoEliminar->izquierda);
		
		destruirNodo(nodoEliminar);
		
	}else if(nodoEliminar->derecha){
		
		reemplazar(nodoEliminar, nodoEliminar->derecha);
		
		destruirNodo(nodoEliminar);
		
	}else{
		
		reemplazar(nodoEliminar, NULL);
		
		destruirNodo(nodoEliminar);
	}
}

void eliminar(nodo *arbol, int n){
	
	if(arbol == NULL){
		
		return;
		
	}else if(n < arbol->dato){
		
		eliminar(arbol->izquierda, n);
		
	}else if(n > arbol->dato){
		
		eliminar(arbol->derecha, n);
		
	}else{
		
		eliminarNodo(arbol);
	}
}
/*************************************************/


main(){
	
	int num;
	int sw;
	int rep;
	
	cout<<"\nBIENVENIDO AL PROGRAMA ARBOL...\n\n";
	
	system("pause");
	system("cls");
	
	do{
		
		cout<<"\nQue operacion desea realizar?\n";
		cout<<"\n[1]Insertar en el Arbol\n";
		cout<<"[2]Mostrar Arbol\n";
		cout<<"[3]Recorridos del Arbol\n";		
		cout<<"[4]Buscar en el arbol\n";
		cout<<"[5]Eliminar elementos\n";
		cout<<"[0]Salir\n";
		cout<<"\nopcion: ";
		cin>>sw;
		
		system("cls");
		
		switch(sw){
			
			case 1:
				
				cout<<"\nIngrese en numero de nodos que desea ingresar al arbol: ";
				cin>>rep;
				
				system("cls");
				
				for(int i= 0; i<rep; i++){
					
					cout<<"\nIngrese el nodo numero "<<i+1<<": ";
					cin>>num;
					insertar(arbol,num, NULL);          //le asigno NULL ya que no se cual es el padre del elemento que estoy introduciendo
				}
				
				system("cls");
				
				cout<<"\nCARGA DE NODOS EXITOSA\n";
				
				cout<<"\n";
				
				system("pause");
				
				break;
				
			case 2:
				
				if(arbol == NULL){
					
					cout<<"\nEl arbol se encuentra vacio\n";
					
				}else{
					
					cout<<"\n";
					mostrar(arbol, 0);
				}
				
				cout<<"\n";
				
				system("pause");
				
				break;
				
			case 3:
				
				do{
					
					cout<<"\nSeleccione el tipo de recorrido\n";
					cout<<"\n[1]Recorrer en Preorden\n";
					cout<<"[2]Recorrer en Inorden\n";
					cout<<"[3]Recorrer en Postorden\n";
					cout<<"[4]atras\n";
					cout<<"\nopcion: ";
					cin>>sw;
					
					system("cls");
					
					switch(sw){
						
						case 1:
							if(arbol == NULL){
								cout<<"\nArbol vacio! no se puede recorrer\n";
							}else{
								cout<<"\nRECORRIDO EN PREORDEN\n\n";
								preorden(arbol);
								cout<<"\n";
							}
							cout<<"\n";
							system("pause");
							break;
							
						case 2:
							if(arbol == NULL){
								cout<<"\nArbol vacio! no se puede recorrer\n";
							}else{
								cout<<"\nRECORRIDO EN INORDEN\n\n";
								inorden(arbol);
								cout<<"\n";
							}
							cout<<"\n";
							system("pause");
							break;
							
						case 3:
							if(arbol == NULL){
								cout<<"\nArbol vacio! no se puede recorrer\n";
							}else{
								cout<<"\nRECORRIDO EN POSTORDEN\n\n";
								preorden(arbol);
								cout<<"\n";
							}
							cout<<"\n";
							system("pause");
							break;
					}
					
					system("cls");
					
				}while(sw != 4);
				
			case 4:
				
				if(arbol == NULL){
					
					cout<<"\nArbol vacio! no se puede buscar\n";
					
				}else{
					
					cout<<"\nIngrese el dato que desea buscar: ";
					cin>>num;
					buscar(arbol, num);
					
					if(band == true){
						
						cout<<"\nElemento encontrado\n";
						
					}else{
						
						cout<<"\nElemento no encontrado\n";
					}
				}
				
				cout<<"\n";
				
				system("pause");
				
				break;
				
			case 5:
				
				if(arbol == NULL){
					
					cout<<"\nArbol vacio! no se pueden eliminar elementos\n";
					
				}else{
					
					cout<<"\nIngrese el dato que desea eliminar: ";
					cin>>num;
					eliminar(arbol, num);
					
					cout<<"\nElemento eliminado satisfactoriamente";
				}
				
				cout<<"\n";
				
				system("pause");
				
				break;
		}
		
		system("cls");
		
	}while(sw != 0);
	
	return 0;
}
