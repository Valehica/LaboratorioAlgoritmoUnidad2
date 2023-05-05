#include <iostream>
#define N 100

using namespace std; 

struct Nodo{
    int dato;
    Nodo* der;
    Nodo* iz;
    Nodo* padre;
};

Nodo* crearNodo(int dat, Nodo *padre){

    Nodo* newNodo = new Nodo; 
    
    newNodo->dato = dat;

    newNodo->der = NULL;
    newNodo->iz = NULL;
    newNodo->padre = padre;
    
    return newNodo;
}
void agregarNuevoNodo(Nodo *&raiz, int dat, Nodo *padre){
    Nodo *newNodo = new Nodo;
    if(raiz == NULL){
            newNodo = crearNodo(dat, padre);
            raiz = newNodo;
	}else{
		if(dat > raiz->dato){//derecha mayor
			agregarNuevoNodo(raiz->der, dat, raiz);
        }else{//derecha menor
            agregarNuevoNodo(raiz->iz, dat, raiz);
        }
	} 
}

void printTree(Nodo* raiz){
    if(raiz == NULL){
        return; 
    }
    printTree(raiz->iz);
    cout << raiz->dato << " ";
    printTree(raiz->der);
}
bool buscarTree(Nodo* raiz, int dato){
    if(raiz == NULL){
        return false; 
    }else if(dato == raiz->dato){//Si es igual retornar true
        return true;
    }else if(dato > raiz->dato){//Si es mayor ir por el lado derecho
        buscarTree(raiz->der, dato);
    }else if(dato < raiz->dato){//Si es menor ir por el lado izquierdo
        buscarTree(raiz->iz, dato);
    }
    
}
int valorMaximo(Nodo* raiz){
    if(raiz == NULL){
        return 0; 
    }
    while (raiz->der != NULL) {
        raiz = raiz->der;
    }
    return raiz->dato;
}
int valorMinimo(Nodo* raiz){
    if(raiz == NULL){
        return 0; 
    }
    while (raiz->iz != NULL) {
        raiz = raiz->iz;
    }
    return raiz->dato;
}

/*|===============================|
	FUNCIONES PARA ELIMINAR NODOS 
  |===============================|*/

//Encontrar el valor minimo desde el nodo a eliminar
Nodo *minimo(Nodo *raiz){
	if(raiz == NULL){//Si esta vacio retorarnar vacio
		return NULL;
	}else if(raiz->iz){//Si existe un nodo izquierdo volver a buscar
		return minimo(raiz->iz);
	}else{
		return raiz;//Retornar el nodo ya encontrado
	}
}
void destruirNodo(Nodo *nodo){
	nodo->iz = NULL;
	nodo->der = NULL;
	delete nodo;
}
void remplazar(Nodo *raiz, Nodo *nuevoNodo){
	if(raiz->padre){
		//al padre hay que asignarle eel nuevo hijo
		if(raiz->dato == raiz->padre->iz->dato){//Si es por la izquierda
			raiz->padre->iz = nuevoNodo;
		}else if(raiz->dato == raiz->padre->der->dato){//Si es por la derecha
			raiz->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		//al hijo hay que asignarle el nuevo padre
		nuevoNodo->padre = raiz->padre;
	}
}
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->iz && nodoEliminar->der){//Para cuando tenga 2 hijos
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}else if(nodoEliminar->iz){//Cuando solo tiene 1 hijo izquierdo
		remplazar(nodoEliminar, nodoEliminar->iz);
		destruirNodo(nodoEliminar);
	}else if(nodoEliminar->der){//Cuando tiene 1 hijo derecho
		remplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}else{//Cuando no tiene hijos
		remplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
	
	
}
void eliminar(Nodo *raiz, int n){
	if(raiz == NULL){//Si el arbol esta vacio no hac nada
		return; 		
	}else if(n < raiz->dato){//Si es menor buscar en la izquierda
		eliminar(raiz->iz, n);
	}else if(n > raiz->dato){//se es mayor buscar en la derecha 
		eliminar(raiz->der, n); 
	}else{//si ya se encontro el valor
		eliminarNodo(raiz);
	}
	
}

/*|===============|
	FUNCION MAIN
  |===============|*/
int main(){
	bool valor = true;
    Nodo* nodo = NULL;
    int dat;
    //Ejercicio 1
    cout << "|========| Ejercicio 1 |========|" << endl;
    cout << "Ingrese un valor para el dato: ";
    cin >> dat;
    nodo = crearNodo(dat,NULL);
    cout << endl;

    //Ejercicio 2
    int opcion; 
    
    cout << "|========| Ejercicio 2 |========|" << endl;
    while(valor){
    	cout << "Ingrese una opcion: \n\t>> 1 para agregar un valor \n\t>> Otro valor para salir" << endl;
    	cin >> opcion;
    	if(opcion == 1){
	    	cout << "Ingrese un valor para el nuevo dato: ";
		    cin >> dat;
		    agregarNuevoNodo(nodo, dat, NULL);
		    cout << endl;	
		}else{
			valor = false; 	
		}
	    	
	}

    //Ejercicio 3
    cout << "|========| Ejercicio 3 |========|" << endl;
    printTree(nodo);
    cout << endl;

    //Ejercicio 4
    valor = false;
    valor = buscarTree(nodo, dat);
    cout << "|========| Ejercicio 4 |========|" << endl;

    cout << "Ingrese un valor para buscar en el arbol: ";
    cin >> dat;
    if (	valor){
        cout << "Se ha encontrado el valor " << dat << " en el arbol" << endl;
    }else{
        cout << "No se ha encontrado el valor " << dat << " en el arbol" << endl;
    }
    
    //Ejercicio 5
    cout << "|========| Ejercicio 5 |========|" << endl;
    int mayor;
    mayor = valorMaximo(nodo);
    cout << "El numero mayor es: " << mayor << endl; 
    system("pause");
    cout << endl;
    
	//Ejercicio 6
    cout << "|========| Ejercicio 6 |========|" << endl;
    int menor;
    menor = valorMinimo(nodo);
    cout << "El numero menor es: " << menor << endl;
	system("pause");
    cout << endl; 
    
    //Ejercicio 7
    cout << "|========| Ejercicio 7 |========|" << endl;
    cout << "Ingrese el numero que quiere eliminar: ";
    cin >> dat;
    eliminar(nodo, dat);
    cout << "Se ha eliminado el dato " << dat << endl; 
    cout << "NUEVO ARBOL: "<< endl;
    printTree(nodo);

}
