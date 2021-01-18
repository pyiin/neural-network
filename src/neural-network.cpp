#include "neural-network.h"

// This is obsolete
   /*
    private:
    struct node {
        double value;
        double baias;
    };
    int layers_num;
    int edges_num;
    int nodes_num;
    int* layers_sizes;
    node* nodes;
    double* edges_weight;

    public:
    */
    void NeuralNetwork::generateNew(int new_layers_num, int* new_layers_sizes) {
        layers_num = new_layers_num;
        layers_sizes = new int[layers_num];
        for(int layer = 0; layer < layers_num; layer++) {
            layers_sizes[layer] = new_layers_sizes[layer];
            nodes_num += layers_sizes[layer];
            if(layer > 0) {
                edges_num += layers_sizes[layer] * layers_sizes[layer - 1];
            }
        }
        nodes = new node[nodes_num];
        edges_weight = new double[edges_num];
    }
/*    double NeuralNetwork::getNodeValue(int, int);
    void NeuralNetwork::setNodeBaias(int, int, double);
    void NeuralNetwork::setEdgeWeight(int, int, int, double);
*/
