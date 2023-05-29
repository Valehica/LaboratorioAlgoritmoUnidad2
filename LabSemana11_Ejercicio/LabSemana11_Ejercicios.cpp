#include <iostream>
#include <vector>

using namespace std;

//variable global
int a = 0, b = 1, c = 2, d = 3, e= 4, f = 5, g = 6, h = 7;

//EJERCICIO 1: CREACCION DE CONECCIONES
void addConexion(vector<vector<int>>& graph, int nodo1, int nodo2){
    graph[nodo1][nodo2] = 1;
    graph[nodo2][nodo1] = 1;
}
void addTotalConexion(vector<vector<int>>& grafo){
    //conecciones A
    addConexion(grafo, a,b);
    addConexion(grafo, a,c);
    //coneccionees B
    addConexion(grafo, b,e);
    addConexion(grafo, b,d);
    addConexion(grafo, b,f);
    //conecciones C
    addConexion(grafo, c,d);
    addConexion(grafo, c,f);
    addConexion(grafo, c,g);
    //conecciones d
    addConexion(grafo, d,e);
    //coneccion e  
    addConexion(grafo, e,f);
    addConexion(grafo, e,h);
    //coneccion f
    addConexion(grafo, f,h);
    addConexion(grafo, f,g);
    //coneccion g
    addConexion(grafo, g,h);
    //ya se hicieron las conecciones de h
    cout << "Ya se agregaron todas las conecciones..." << endl << endl;
}

//EJERCICIO 2: IMPRIMIR LA MATRIZ
void printGrafo(const vector<vector<int>>& graph){
    int cont = 0;
    string abecedario = "ABCDEFGH";
    cout << "Matriz adyacencia: "<< endl << endl;
    cout << "    A B C D E F G H" <<endl;
    cout << "    ---------------" <<endl;
    for(const auto& row: graph){
        cout << abecedario[cont] << " | ";
        cont++;
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//EJERCICIO 3: COMPROBAR SI SON ADYACENTES
void comprobarAdyacencia(vector<vector<int>>& grafo, int nodo1, int nodo2){
    string abecedario = "ABCDEFGH";
    if(grafo[nodo1][nodo2] == 1 && grafo[nodo2][nodo1] == 1){
        cout << "Los vectores " << abecedario[nodo1] << " y " << abecedario[nodo2] << " SI son adyacentes" << endl;
    }else{
        cout << "Los vectores " << abecedario[nodo1] << " y " << abecedario[nodo2] << " NO son adyacentes" << endl;
    }
}

//EJERCICIO 4: CAMINO ENTRE DOS VERTICES
bool dfs(vector<vector<int>>& grafo, int nodoInicial, int nodoFinal, vector<bool>& visitado) {
    string abecedario = "ABCDEFGH";
    
    
    if (nodoInicial == nodoFinal)
        return true;
    
    visitado[nodoInicial] = true;

    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[nodoInicial][i] == 1 && !visitado[i]) {
            cout << " -> "  << abecedario[i];
            if (dfs(grafo, i, nodoFinal, visitado)){
                return true;
            }
        }
    }
    
    return false;
}

void buscarCamino(vector<vector<int>>& grafo, int nodoInicial, int nodoFinal){
    string abecedario = "ABCDEFGH";
    cout << "Recorrido: " << endl;
    cout << abecedario[nodoInicial];

    vector<bool> visitado(grafo.size(), false);
    bool valor = dfs(grafo, nodoInicial, nodoFinal, visitado);

    if(valor){
        cout << endl << "Si hay una ruta posible" << endl;
    }else{
        cout<< endl <<  "No hay una ruta posible" << endl;
    }
}
// EJERCICIO 5: TRANSFORMAR EN GRAFO DIRIGIDO
void inicializarGrafo(vector<vector<int>>& grafo){
    for (int i = 0; i < grafo.size(); i++) {
        for (int k = 0; k < grafo.size(); k++) {
            grafo[i][k] = 0;
        }
    }
}
void addConexionDirigido(vector<vector<int>>& graph, int nodo1, int nodo2) {
    graph[nodo1][nodo2] = 1;
}

void addTotalDirijidoEJ5(vector<vector<int>>& graph) {
    // conecciones a
    addConexionDirigido(graph, a, b);
    addConexionDirigido(graph, a, c);
    // conecciones b
    addConexionDirigido(graph, b, d);
    addConexionDirigido(graph, b, e);
    addConexionDirigido(graph, b, f);
    // conecciones c;
    addConexionDirigido(graph, c, d);
    addConexionDirigido(graph, c, f);
    addConexionDirigido(graph, c, g);
    // conecciones d
    addConexionDirigido(graph, d, b);
    addConexionDirigido(graph, d, c);
    addConexionDirigido(graph, d, e);
    // conecciones e
    addConexionDirigido(graph, e, b);
    addConexionDirigido(graph, e, f);
    // conecciones f
    addConexionDirigido(graph, f, b);
    addConexionDirigido(graph, f, c);
    addConexionDirigido(graph, f, e);
    addConexionDirigido(graph, f, g);
    // conecciones g
    addConexionDirigido(graph, g, c);
    addConexionDirigido(graph, g, e);

}

int main(){
    int cantVertices = 8;
    vector<vector<int>> grafo(cantVertices, vector<int>(cantVertices, 0));
    
    //EJERCICIO 1: CREACCION DE CONECCIONES
    cout << "|====| EJERCICIO 1: CREACION DE CONECCIONES |====|" << endl;
    addTotalConexion(grafo);

    //EJERCICIO 2: IMPRIMIR LA MATRIZ
    cout << "|====| EJERCICIO 2: IMPRIMIR LA MATRIZ|====|" << endl;
    printGrafo(grafo);

    //EJERCICIO 3: COMPROBAR SI SON ADYACENTES
    cout << "|====| EJERCICIO 3: COMPROBAR ADYACENCIA |====|" << endl;
    comprobarAdyacencia(grafo, a,b);
    comprobarAdyacencia(grafo, a,h);

    //EJERCICIO 4: CAMINO ENTRE DOS VERTICES
    cout << "|====| EJERCICIO 4: CAMINO ENTRE DOS VERTICES |====|" << endl;
    buscarCamino(grafo, a, h);

    // EJERCICIO 5: TRANSFORMAR EN GRAFO DIFIGIDO
    cout << "|====| EJERCICIO 5: CAMINO ENTRE DOS VERTICES |====|" << endl;
    inicializarGrafo(grafo);
    addTotalDirijidoEJ5(grafo);
    printGrafo(grafo);

    //Ejercicio 6: CREAR UN CICLO
    cout << "|====| EJERCICIO 5: CREAR UN CICLO |====|" << endl;
    addConexionDirigido(grafo,h,h);
    printGrafo(grafo);

    //EJERCICIO 7: 
    //No pude realizar el ejercicio 7

    
    return 0;
}