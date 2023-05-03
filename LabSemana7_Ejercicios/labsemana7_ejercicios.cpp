#include <iostream>
#include <string>

using namespace std;

struct Numero{
	float number;
};

typedef struct Nodo{
	Numero dato;
	Nodo *sig;
}*Lista;

void cincoutStringInt(){
    int number; 
    string wordl;

    cout << "Ingrese el numero entero: ";
    cin >> number;
	
	cin.ignore();
    cout << "Ingrese el string: ";
    getline(cin, wordl);  

    cout << endl;
    
    if(number != NULL && wordl.length() != 0){
        cout << "El numero ingresado es: " << number << endl;   
        cout << "El string ingresado es: " << wordl<< endl << endl;
    }
}
void promedioNUmeros(){
    float aux;
    float suma = 0;
    float promedio;
    int i; 

    for(i = 0; i < 3; i++){
        cout << "Ingrese el valor para el numero " << i + 1 << ": ";
        cin >> aux;
        suma = suma + aux; 
    }
    promedio = suma/3; 

    cout << "El promedio entre los numeor ingresados es: " << promedio << endl <<endl;

}
void longitudString(){
    string wordl;
    int lenString;
    
    cin.ignore();
    cout << "Ingrese una palaba: ";
    getline(cin, wordl);  
    lenString = wordl.length();

    cout << "La longitud de la palabra ingresada es: " << lenString << endl << endl;
}
void listMath(){
	Lista listaNumeros = NULL; //creacion de la lista vacia
    int valor = true;
	int cont = 1; 
	int opcion; 
	int num;
	
	while(valor == true){
		cout << "Ingrese una opcion \n\t>> 1 para ingresar un numero \n\t>> Otro valor para salir"  << endl;
		cin >> opcion; 
		
		if(opcion == 1){//ingresar un numero
			cout << "Ingrese un valor para el numero " << cont <<": "; 
			cin >> num;
			cin.ignore();
			
			Nodo* nuevoNodo = new Nodo;
			nuevoNodo->dato.number = num;
			nuevoNodo->sig = NULL;
			
			//Se le eagrega el nodo a la lista
			if(listaNumeros == NULL){
				listaNumeros = nuevoNodo;
			}else{
				Nodo* ultimoNodo = listaNumeros;
				while (ultimoNodo->sig != NULL) {
		            ultimoNodo = ultimoNodo->sig;
		        }
		        ultimoNodo->sig = nuevoNodo;	
			}	 
			cont++;
		}else{//salir
			valor = false;
		}
	}
	
	//operaciones matematicas
	if(listaNumeros == NULL){
		cout << "No hay ningun valor en la lista " << endl << endl;
	}else{
		float suma = 0;
		float promedio;
		float producto = 1; 
		int a = 1;//elimianr
		Nodo* nodoActual = listaNumeros;
		while (nodoActual != NULL) {
			//suma
			suma = suma + nodoActual->dato.number;
			//producto
			producto = producto * nodoActual->dato.number;
			
            nodoActual = nodoActual->sig;
        }
        promedio = suma/(cont - 1);
        
        cout << "La suma de los valores de la lista es: " << suma << endl;
        cout << "El promedio de los valores de la lista es: " << promedio << endl;
        cout << "El producto de los valores de la lista es: " << producto << endl << endl;
	}

}
int factorial(int number){
    if(number > 0){
        return (number * factorial(number - 1));
        
    }else{
        return 1;
    }
}
void palindromo() {
    int i = 0;
	int k;
	bool valor = true;
	string wordl;
	
	cin.ignore();
	cout << "Ingrese una fase para verificar si es palindrome: ";
	getline(cin,wordl);
	k = wordl.length() - 1;//Extncion del string
	
    while (i < k) {
        if (wordl[i] != wordl[k]) {
            valor = false;
        }
        i++;
        k--;
    }
    if(valor == true){
    	cout << "La palabra ingresada es palindrome";
	}else{
		cout << "La palabra ingresada no palindrome";
	}
    
}
int main(){
    //Ejercicio 1:
    cout << "|========| Ejercicio numero 1 |========|" << endl;
    cincoutStringInt();

    //Ejercicio 2: 
    cout << "|========| Ejercicio numero 2 |========|" << endl;
    promedioNUmeros();

    //Ejercicio 3: 
    cout << "|========| Ejercicio numero 3 |========|" << endl;
    longitudString();

    //Ejercicio 4:
	cout << "|========| Ejercicio numero 4 |========|" << endl; 
	listMath();
	
    //Ejercicio 5: 
    cout << "|========| Ejercicio numero 5 |========|" << endl;
    int numero;
    cout << "Ingrese un numero para saber su factorial: ";
    cin >> numero;
    int factorialResult;
    if(numero != 0){
        factorialResult = factorial(numero);
    }else{
        factorialResult = 0;
    }
    cout << "El factorial de " << numero << " es : " << factorialResult << endl << endl;

    //Ejercicio 6: 
    cout << "|========| Ejercicio numero 6 |========|" << endl;
	palindromo();
	
	return 0;
}
