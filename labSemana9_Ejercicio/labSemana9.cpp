#include <iostream>
#include <vector>

using namespace std;

//Ejercicio 1 Definicion de Rectangle
class Rectangle{
	public:
		Rectangle();
		Rectangle(int h, int a);
		
		void calcularArea();
	
	private:
		int altura;
		int ancho;
};

Rectangle::Rectangle(){
	altura = 0;
	ancho = 0;
	//contructor por sin nada, valores por definicion
}
Rectangle::Rectangle(int h, int a){
	altura = h;
	ancho = a;
	//contructr con valores, valores por entrada
}
void Rectangle::calcularArea(){
	int area;
	area = altura * ancho;
	cout << "El area de rectangulo es: " << area; 
}

//Ejercicio 2 Definicion de point
class Point{
	public: 
		Point();
		Point(int num1_, int num2_);
		
		void printClass(int cont);
	
	private:
		int largo;
		int angulo;
};
Point::Point(){
	largo = 0;
	angulo = 0;
	cout << "Se ha creado la clase point con los datos: \n\t>> largo: " << largo << "\n\t>> angulo: " << angulo;
}
Point::Point(int num1_, int num2_){
	largo = num1_;
	angulo = num2_;
	cout << "Se ha creado la clase point con los datos: \n\t>> largo: " << largo << "\n\t>> angulo: " << angulo;

}
void Point::printClass(int cont){
	cout << "\tLado numero "<< cont <<": \n\t\t>> largo: " << largo << "\n \t\t>> angulo: " << angulo << endl;
}

//Ejercicio 4 definicion de LinkedList y list
class LinkedList{
	public: 
		LinkedList();
		
		void insertar(int valor);
		void buscar(int valor);
		void eliminar(int valor);
		void imprimir();
		
	private:
		typedef struct Nodo{
			int dato;
			Nodo *sig;
		}*Lista;
		
		Nodo* cabeza;
};

LinkedList::LinkedList(){
	cabeza = NULL;
}

void LinkedList::insertar(int valor){
	Nodo* newNodo = new Nodo;
	newNodo->dato = valor;
	newNodo->sig = NULL;
	if(cabeza == NULL){
		cabeza = newNodo;
	}else{
		Nodo* nodoActual = cabeza;
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		nodoActual->sig = newNodo;
	}
	cout << "Se ha añadido el valor "<< valor << " a la lista..." <<endl;
}
void LinkedList::imprimir(){
	Nodo* actual = cabeza; 
	cout << "Lista: "<<endl;
	while(actual != NULL){
		cout << "\t>> "<<actual->dato<<endl;
		actual = actual->sig;
	}
}
void LinkedList::eliminar(int valor){
	if(cabeza == NULL){
		return;//La lista esta vacia
		cout << "La lista se encontraba vacia.."<<endl;
	}
	Nodo* nodoActual = cabeza;
	Nodo* nodoAnterior = NULL; 
	
	while(nodoActual != NULL && nodoActual->dato != valor){
		nodoAnterior = nodoActual;
		nodoActual = nodoActual->sig;
	}
	if(nodoActual != NULL){
		if(nodoAnterior== NULL){
			cabeza = nodoActual->sig;
		}else{
			nodoAnterior->sig = nodoActual->sig;
		}
		delete nodoActual;
	}
	cout << endl<<"Se ha eliminado el valor "<< valor << " se la lista.." <<endl;
}
void LinkedList::buscar(int valor){
	Nodo* nodoActual = new Nodo;
	nodoActual = cabeza;
	bool valorVerdad = false;
	
	while(nodoActual != NULL){
		if(nodoActual->dato == valor){
			//Si se encontro
			valorVerdad = true;
		}
		nodoActual = nodoActual->sig;
	}	
	if(valorVerdad){
		cout <<endl << "Se ha encontrado el valor "<< valor << " en la lista"<< endl;
	}else{
		cout <<endl<< "NO se ha encontrado el valor "<< valor << " en la lista"<< endl;
	}
}

//Ejercicio 5 definicion de BinaryTree
struct Nodo{
    int dato;
    Nodo* der;
    Nodo* iz;
};
class BinaryTree{
	public:
		BinaryTree();
		
		Nodo* crearNodo(int valor);
		void insertar(Nodo *&raiz, int valor);
		bool buscar(Nodo* raiz, int valor);
		void buscarRes(int valorBuscar);
		void imprimir(Nodo* raiz);
		Nodo* raiz; 
};

BinaryTree::BinaryTree(){
	raiz = NULL;
}
Nodo* BinaryTree::crearNodo(int valor){
	Nodo* newNodo = new Nodo; 
    
    newNodo->dato = valor;
    newNodo->der = NULL;
    newNodo->iz = NULL;
    
    return newNodo;
}
void BinaryTree::insertar(Nodo *&raiz, int valor){
	Nodo *newNodo = new Nodo;
    if(raiz == NULL){
            newNodo = crearNodo(valor);
            raiz = newNodo;
            cout<< "Se ha añadido e valor " << valor << " al arbol binario..."<<endl;
	}else{
		if(valor > raiz->dato){//derecha mayor
			insertar(raiz->der, valor);
        }else{//derecha menor
            insertar(raiz->iz, valor);
        }
	}
}
void BinaryTree::imprimir(Nodo* raiz){
	if(raiz == NULL){
        return; 
    }
    imprimir(raiz->iz);
    cout << raiz->dato << " ";
    imprimir(raiz->der);
}
bool BinaryTree::buscar(Nodo* raiz, int valor){
	if(raiz == NULL){
        return false; 
    }else if(valor == raiz->dato){//Si es igual retornar true
        return true;
    }else if(valor > raiz->dato){//Si es mayor ir por el lado derecho
        buscar(raiz->der, valor);
    }else if(valor < raiz->dato){//Si es menor ir por el lado izquierdo
        buscar(raiz->iz, valor);
    }
}
void BinaryTree::buscarRes(int valorBuscar){
	
	if(buscar(raiz, valorBuscar)){
		cout <<endl << "El valor " << valorBuscar << " se encontro en el arbol binario"<<endl;
	}else{
		cout <<endl << "El valor " << valorBuscar << " NO se encontro en el arbol binario"<<endl;
	}
}

int main(){
	//Ejercicio 1
	cout << "|========| Ejercicio 1 |========|" << endl;
	int altura;
	int ancho; 
	cout << "Ingrese la atura de su rectangulo: ";
	cin >> altura;
	cout << "Ingrese el ancho de su rectangulo: ";
	cin >> ancho;
	Rectangle rec1(altura, ancho);
	rec1.calcularArea();
	
	//Ejrcicio 2
	cout << endl << endl << "|========| Ejercicio 2 |========|" << endl;
	int num1;
	int num2; 
	cout << "Ingrese un numero: ";
	cin >> num1;
	cout << "Ingrese otro numero: ";
	cin >> num2;
	Point point1(num1, num2);
	
	//Ejrcicio 3
	cout << endl << endl << "|========| Ejercicio 3 |========|" << endl;
	vector <Point> vectorPoligono;
	Point point2(2, 45);
	vectorPoligono.push_back(point2);
	vectorPoligono.push_back(point2);
	vectorPoligono.push_back(point2);
	vectorPoligono.push_back(point2);
	vectorPoligono.push_back(point2);
	vectorPoligono.push_back(point2);
	
	cout << endl<< endl << "DATOS DEL POLIGONO: \n\tCantidad de lados: "<< vectorPoligono.size() << endl;
	for(int i = 0; i < vectorPoligono.size(); i++){
		vectorPoligono[i].printClass(i+1);
	}
	
	//Ejercicio 4
	cout << endl << endl << "|========| Ejercicio 4 |========|" << endl;
	LinkedList list;
	//Añadir elementos
	list.insertar(1);
	list.insertar(2);
	list.insertar(3);
	list.insertar(4);
	//Imipirmir la lista
	cout << endl;
	list.imprimir();
	//Eliminar elemento
	list.eliminar(3);
	list.imprimir();
	//Buscar elemento
	list.buscar(4);
	list.buscar(3);
	
	//Ejercicio 5
	cout << endl << endl << "|========| Ejercicio 5 |========|" << endl;
	BinaryTree arbol1;
	//Añadir elementos
	arbol1.insertar(arbol1.raiz, 3);
	arbol1.insertar(arbol1.raiz, 5);
	arbol1.insertar(arbol1.raiz, 4);
	//Imprimir
	cout << endl << "Arbol binario: " << endl;
	arbol1.imprimir(arbol1.raiz);
	cout << endl;
	//buscar
	arbol1.buscarRes(5);
	arbol1.buscarRes(7);
}
