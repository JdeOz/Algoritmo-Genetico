#include <iostream>
#include <vector>
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
    int k = 10; // Tamaños de la población
    int g = 100; // Número de generaciones

    createRandom(n);
    vector<vector<int>> generation;

    // Generación Población Inicial
    generation.reserve(k);
    for (int i = 0; i < k; i++) {
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
            fitnessValues[i] = 1/fitness(generation[i]);
        }

        // Selección: Calcular valor esperado y valor Actual
        float media = average(fitnessValues, (int) generation.size());
        int VA[generation.size()];//Valor Actual
        for (int ind = 0; i < generation.size(); ind++) {
            VA[i] = (int) round(fitnessValues[i] / media);
        }

        vector<vector<int>> newGen;
        // TODO: Operadores genéticos

        generation = newGen;
    }

}
