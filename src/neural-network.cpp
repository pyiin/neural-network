#include <math.h>
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
    double* edges; //12, 13, 14, 15, ..., 21, 22, 23, 24

    public:
    */
double sigmoid(double x){
    return 1/(1 + exp(x));
}
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
    edges = new edge[edges_num];
}

double NeuralNetwork::evaluate(double* input, double* output) {
    for(int node = 0; node < layers_sizes[0]; node++){
        nodes[node].value = input[node];
    }

    int node_offset = 0;
    int edge_offset = 0;
    for(int layer = 0; layer < layers_num - 1; layer++) {
        for(int node = node_offset; node < node_offset + layers_sizes[layer]; node++) {
            for(int edge = 0; edge < layers_sizes[layer + 1]; edge++) {
                nodes[node_offset + layers_sizes[layer] + edge].value += edges[edge_offset + edge].weight * nodes[node].value;
            }
            edge_offset += layers_sizes[layer + 1];
        }
        node_offset += layers_sizes[layer];
        for(int node = node_offset; node < node_offset + layers_sizes[layer + 1]; node++) {
            nodes[node].value += nodes[node].bias;
            nodes[node].value = sigmoid(nodes[node].value);
        }
    }
    double ans = 0;
    node_offset = nodes_num - layers_sizes[layers_num - 1];
    for(int node = 0; node < layers_sizes[layers_num - 1]; node++){
        ans += pow(nodes[node_offset + node].value - output[node], 2);
    }
    return ans;
}

double NeuralNetwork::getNodeValue(int layer_n, int layer_k) {

}
void NeuralNetwork::setNodeBaias(int, int, double) {

}
void NeuralNetwork::setEdgeWeight(int, int, int, double) {

}

void NeuralNetwork::gradient() {

}
