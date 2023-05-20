#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Nodo{
    int dato;
    Nodo* der;
    Nodo* iz;
};
class Arbol{
	public:
		Arbol();

		Nodo* crearNodo(int valor);
		void insertarBinaryTree(Nodo *&raiz, int valor);
		void insertarNodos(Nodo* &arbol, int valores[], int indice, int longitud);
		bool buscar(Nodo* raiz, int valor);
		void buscarRes(int valorBuscar);
		void imprimirPreOrden(Nodo* raiz);
		void imprimirInOden(Nodo* raiz);
		void imprimirPostOrden(Nodo* raiz);
		bool buscarPorProfundidadRecursivo(Nodo* raiz, int valor);
		void buscarPorProfundidad(Arbol arbol, int valor);
		bool buscarPorAmplitudBool(Nodo* raiz, int valor);
		void buscarPorAmplitud(Arbol arbol, int valor);
		Nodo* raiz; 
};

Arbol::Arbol(){
	raiz = NULL;
}
Nodo* Arbol::crearNodo(int valor){
	Nodo* newNodo = new Nodo; 

    newNodo->dato = valor;
    newNodo->der = NULL;
    newNodo->iz = NULL;

    return newNodo;
}
//ejercicio 1, definicion incertar nodos de forma ordenada;
void Arbol::insertarNodos(Nodo* &arbol, int valores[], int indice, int longitud) {
    if (indice < longitud) {
        Nodo* nodo = crearNodo(valores[indice]);
        arbol = nodo;
        
        insertarNodos(arbol->iz, valores, 2 * indice + 1, longitud);
        insertarNodos(arbol->der, valores, 2 * indice + 2, longitud);
    }
}
//Ejercicio 5, definicion de creacion del arbol binario;
void Arbol::insertarBinaryTree(Nodo *&raiz, int valor){
	Nodo *newNodo = new Nodo;
    if(raiz == NULL){
            newNodo = crearNodo(valor);
            raiz = newNodo;
            cout<< "Se ha añadido e valor " << valor << " al arbol binario..."<<endl;
	}else{
		if(valor > raiz->dato){//derecha mayor
			insertarBinaryTree(raiz->der, valor);
        }else{//derecha menor
            insertarBinaryTree(raiz->iz, valor);
        }
	}
}

//Ejericio 2, definicion imprimir preOrden
void Arbol::imprimirPreOrden(Nodo* raiz){
	if (raiz != NULL) {
        cout << raiz->dato << " ";
        imprimirPreOrden(raiz->iz);
        imprimirPreOrden(raiz->der);
    }
}
//Ejercicio 3, definicion imprimir inOrden
void Arbol::imprimirInOden(Nodo* raiz){
	if (raiz != NULL) {
        imprimirInOden(raiz->iz);
        cout << raiz->dato << " ";
        imprimirInOden(raiz->der);
    }
}
//Ejericicio 4, definicion imprimir postOrden
void Arbol::imprimirPostOrden(Nodo* raiz){
	if (raiz != NULL) {
        imprimirPostOrden(raiz->iz);
        imprimirPostOrden(raiz->der);
        cout << raiz->dato << " ";
    }
}

//Ejercicio 6, definicion busqueda por profundidad
bool Arbol::buscarPorProfundidadRecursivo(Nodo* raiz, int valor){
	if (raiz == NULL) {
        return false;
    }

    if (raiz->dato == valor) {
        return true;
    }

    bool encontradoIzquierda = buscarPorProfundidadRecursivo(raiz->iz, valor);
    if (encontradoIzquierda) {
        return true;
    }

    bool encontradoDerecha = buscarPorProfundidadRecursivo(raiz->der, valor);
    if (encontradoDerecha) {
        return true;
    }

    return false;
}
void Arbol::buscarPorProfundidad(Arbol arbol, int valor){
    cout << "Buscar valor " << valor << " utilizando buscar por profundidad: ";
    if(arbol.buscarPorProfundidadRecursivo(arbol.raiz, valor)){
        cout << "El numero "<< valor << " fue encontrado en el arbol" << endl;
    } else {
        cout << "El numero "<< valor << " NO fue encontrado en el arbol" << endl;
    }
}

//Ejercicio 7, definicion buscar por amplitud
bool Arbol::buscarPorAmplitudBool(Nodo *raiz, int valor){
	if (raiz == NULL) {
        return false;
    }

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* nodoActual = cola.front();
        cola.pop();

        if (nodoActual->dato == valor) {
            return true;
        }

        if (nodoActual->iz != NULL) {
            cola.push(nodoActual->iz);
        }

        if (nodoActual->der != NULL) {
            cola.push(nodoActual->der);
        }
    }

    return false;
}

void Arbol::buscarPorAmplitud(Arbol arbol, int valor){
	cout << "Buscar valor " << valor << " utilizando buscar por amplitud: ";
    if(arbol.buscarPorAmplitudBool(arbol.raiz, valor)){
        cout << "El numero "<< valor << " fue encontrado en el arbol" << endl;
    } else {
        cout << "El numero "<< valor << " NO fue encontrado en el arbol" << endl;
    }
}

int main(){
	//Ejercicio 1
	cout << "|========| Ejercicio 1 |========|" << endl;
	Arbol arbol_ejercicio1;
	cout << "se a creado el arbol: "<<endl;
	cout << "       1		"<<endl;
	cout << "  2         3	"<<endl;
	cout << "4   5	   6   7"<<endl;
	
	//valores para agregar y su longitud
	int valores_Ej1[] = {1, 2, 3, 4, 5, 6, 7};
    int longitud = sizeof(valores_Ej1) / sizeof(valores_Ej1[0]);
    arbol_ejercicio1.insertarNodos(arbol_ejercicio1.raiz, valores_Ej1, 0, longitud);
    
    //Ejercicio 2
	cout << endl << endl << "|========| Ejercicio 2 |========|" << endl;
	cout << "Imprimir en pre-orden: " << endl;
	arbol_ejercicio1.imprimirPreOrden(arbol_ejercicio1.raiz);
	
	//Ejercicio 3
	cout << endl << endl << "|========| Ejercicio 3 |========|" << endl;
	cout << "Imprimir en in-orden: " << endl;
	arbol_ejercicio1.imprimirInOden(arbol_ejercicio1.raiz);
	
	//Ejercicio 4
	cout << endl << endl << "|========| Ejercicio 4 |========|" << endl;
	cout << "Imprimir en post-orden: " << endl;
	arbol_ejercicio1.imprimirPostOrden(arbol_ejercicio1.raiz);
	
	//Ejercicio 5
	cout << endl << endl << "|========| Ejercicio 5 |========|" << endl;
	Arbol arbolBinario;
	int valores_ej5[] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
	int longitud_ej5 = sizeof(valores_ej5) / sizeof(valores_ej5[0]);
	for(int i; i < longitud_ej5; i++){
		arbolBinario.insertarBinaryTree(arbolBinario.raiz, valores_ej5[i]);
	}
	cout << "Imprimir en in-orden: " << endl;
	arbolBinario.imprimirInOden(arbolBinario.raiz);
	
	//Ejercicio 6
	cout << endl << endl << "|========| Ejercicio 6 |========|" << endl;
	arbolBinario.buscarPorProfundidad(arbolBinario, 18);
	arbolBinario.buscarPorProfundidad(arbolBinario, 3);
	
	//Ejercicio 7
    cout << endl << endl << "|========| Ejercicio 6 |========|" << endl;
    arbolBinario.buscarPorAmplitud(arbolBinario, 18);
	arbolBinario.buscarPorAmplitud(arbolBinario, 3);
}
