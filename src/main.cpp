#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <cmath>

using namespace std;

struct Node {
    int x, y;

    Node(int x, int y) : x(x), y(y) {}
};

vector<Node> nodes;
int inicial;

// TODO: Crear nodos random
void createRandom(int n) {

}

// TODO: Generar población inicial
vector<int> generateRandomIndividual() {
    //No tomar en cuenta al nodo inicial
}

// TODO: Distancia Euclidiana
float Euclidean(Node a, Node b) {
    
}

// TODO: Cálculo aptitud(sumar distancias)
float fitness(const vector<int> &individual) {
    //Tomar en cuenta que inicia y termina en el nodo inicial
}

// TODO: Media
float average(float fitnessValues[], int n) {

}

// TODO: Mutación Basada en Posición
vector<int> MBP(const vector<int> &individual) {

}

// TODO: Mutación Basada en Orden
vector<int> MBO(const vector<int> &individual) {

}

// TODO: Mutación Basada en Desorden
vector<int> MBD(const vector<int> &individual) {

}

// TODO: Crossover de Orden
vector<int> Crossover(const vector<int> &individual) {

}

int main() {
    int n = 10; // Número de nodos

    int p = 10; // Tamaños de la población
    int g = 100; // Número de generaciones
    int cantEli = 2; // Cantidad Elitismo
    int probCru = 70; // Probabilidad Cruzamiento
    int probMut = 100 - probCru; // Probabilidad Mutación

    createRandom(n);

    // Generación Población Inicial
    vector<vector<int>> generation;
    generation.reserve(p);
    for (int i = 0; i < p; i++) {
        generation.push_back(generateRandomIndividual());
    }

    // Seleccionar nodo Inicial aleatorio
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> randNode(0, n);
    inicial = randNode(mt);

    // Algoritmo genético
    for (int i = 0; i < g; i++) {

        // Calcular la aptitud de cada individuo
        float fitnessValues[generation.size()];
        for (int ind = 0; i < generation.size(); ind++) {
            fitnessValues[i] = 1 / fitness(generation[i]);
        }

        // Selección: Calcular valor esperado y valor Actual
        float media = average(fitnessValues, (int) generation.size());
        multimap<int, vector<int>> VA;
        for (int ind = 0; i < generation.size(); ind++) {
            VA.insert(pair<int, vector<int>>((int) round(fitnessValues[i] / media), generation[i]));
        }

        // Crear la nueva generación
        vector<pair<int, vector<int>>> ordenados;
        for(const auto& indi:VA){
            if(indi.first>0){
                ordenados.push_back(indi);
            }
        }

        vector<vector<int>> newGen;
        for (int j = 0; j < cantEli; j++) {
            if (ordenados[j].first > 0) {
                newGen.push_back(ordenados[j].second);
                ordenados[j].first-=1;
            }
        }

        int iter=0;
        int crias=0;
        while(iter<ordenados.size() and crias<probCru){

        }











        // Aplicar operadores lógicos a options

        // TODO: Operadores genéticos

        generation = newGen;
    }

}
