#include <iostream>
#include <vector>
#include <map>
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
vector<int> MBD(vector<int> individual) {
    uniform_int_distribution<int> randNode(0, individual.size());
    int pos1;
    do {
        pos1 = randNode(mt);
    } while (pos1 == 0 || pos1 >= individual.size() - 1);
    cout << pos1 << endl;
    int pos2;
    do {
        pos2 = randNode(mt);
    } while (pos2 == 0 || pos2 >= individual.size() - 1 || pos2 == pos1);
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
    uniform_int_distribution<int> rn(0, 2);
    if (rn(mt) == 0) {
        cout << "m" << 0 << endl;
        individual.insert(individual.begin() + minval, individual[maxval]);
        individual.erase(individual.begin() + maxval + 1);
    }
    else {
        cout <<"m"<< 1 << endl;
        individual.insert(individual.begin() + maxval+1, individual[minval]);
        individual.erase(individual.begin() + minval);
    }
    
    return individual;
}

// TODO: Crossover de Orden
vector<int> Crossover(const vector<int> &individual1, const vector<int> &individual2) {

}
void writetxt(string nombre,int nrogen,int amplitud) {
    ofstream myfile;
    myfile.open(nombre+".txt",ios::app);
    myfile << nrogen<<","<<amplitud<<"\n";
    myfile.close();
}

int main() {
    int n = 10; // Número de nodos

    int p = 10; // Tamaños de la población
    int g = 100; // Número de generaciones
    int cantEli = 2; // Cantidad Elitismo
    int probCru = 70 / 100 * (p - cantEli); // Probabilidad Cruzamiento
    int probMut = p - probCru; // Probabilidad Mutación

    createRandom(n);

    // Generación Población Inicial
    vector<vector<int>> generation;
    generation.reserve(p);
    for (int i = 0; i < p; i++) {
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
        for (const auto &indi: VA) {
            if (indi.first > 0) {
                ordenados.push_back(indi);
            }
        }

        vector<vector<int>> newGen;
        //Elitismo
        int elite = 0;
        int iter = 0;
        while (!ordenados.empty() and elite < cantEli) {
            newGen.push_back(ordenados[iter].second);
            ordenados[iter].first--;
            if (ordenados[iter].first == 0) {
                ordenados.erase(ordenados.begin() + iter);
            } else {
                iter++;
            }
            elite++;
        }

        int crias = 0;
        while (!ordenados.empty() and crias < probCru) {
            int iter2 = 0;
            int pares = 0;
            int totalPares = ordenados[0].first;
            while (pares < totalPares and crias < probCru) {
                newGen.push_back(Crossover(ordenados[0].second, ordenados[iter2 + 1].second));
                crias++;
                ordenados[iter2 + 1].first--;
                ordenados[0].first--;
                if (ordenados[iter2 + 1].first == 0) {
                    ordenados.erase(ordenados.begin() + iter);
                } else {
                    iter2++;
                }
                pares++;
            }
            if (ordenados[0].first == 0) {
                ordenados.erase(ordenados.begin());
            }
        }

        int iter3 = 0;
        int mutations = 0;
        while (mutations < probMut) {
            for (int j = 0; j < ordenados[iter3].first; j++) {
                newGen.push_back(MBD(ordenados[iter3].second));
                mutations++;
                if (mutations >= probMut) {
                    break;
                }
            }
        }

        // Aplicar operadores lógicos a options

        // TODO: Operadores genéticos

        generation = newGen;
    }

}
