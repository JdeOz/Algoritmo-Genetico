#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;
random_device rd;
mt19937 mt(rd());
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
vector<int> MBP( vector<int> individual) {
    uniform_int_distribution<int> randNode(0, individual.size());
    cout << individual.size() << endl;
    int pos1;
    do {
        pos1 = randNode(mt);
    } while (pos1 == 0 || pos1 >= individual.size()-1);
    cout << pos1 << endl;
    int pos2;
    do {
        pos2 = randNode(mt);
    } while (pos2 == 0 || pos2 >= individual.size()-1 || pos2==pos1);
    cout << pos2 << endl;
    swap(individual[pos1], individual[pos2]);
    return individual;

}

// TODO: Mutación Basada en Orden
vector<int> MBO( vector<int> individual) {
    uniform_int_distribution<int> randNode(0, individual.size());
    int pos1;
    do {
        pos1 = randNode(mt);
    } while (pos1 == 0 || pos1 >= individual.size()-1);
    cout << pos1 << endl;
    int pos2;
    do {
        pos2 = randNode(mt);
    } while (pos2 == 0 || pos2>= individual.size() - 1 || pos2 == pos1);
    cout << pos2 << endl;
    int minval, maxval;
    if (pos1 < pos2) {
        minval = pos1;
        maxval = pos2;
    }
    else {
        minval = pos2;
        maxval = pos1;
    }
    individual.insert(individual.begin()+minval,individual[maxval]);
    individual.erase(individual.begin() + maxval + 1);
    return individual;
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
