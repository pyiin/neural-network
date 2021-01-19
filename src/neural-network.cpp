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
    double* edges_weight; //12, 13, 14, 15, ..., 21, 22, 23, 24

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
    edges_weight = new double[edges_num];
}

double NeuralNetwork::evaluate(double* input, double* output) {
    int k = 0;
    for(i = 1; i < layers_num; i++){
        k += layers_sizes[i-1];
        for(int j=0; j < layers_sizes[i]; j++){
            for(int l=0; l < layers_sizes[i-1]; l++){
                nodes[k+j].value += edges_weight[l*layers_sizes[i-1] + i] * nodes[k - layers_sizes[i-1] + l].value;
            }
            nodes[k+j].value += nodes[k+j].bias;
            nodes[k+j].value = sigmoid(nodes[k+j].value);
        }
    }
    double ans = 0;
    for(int i = 0; i < layers_sizes[layers_num]){
        ans += (nodes[k + i] - output[i])*(nodes[k + i] - output[i]);
    }
    return ans;
}

double NeuralNetwork::getNodeValue(int layer_n, int layer_k) {

}
void NeuralNetwork::setNodeBaias(int, int, double) {

}
void NeuralNetwork::setEdgeWeight(int, int, int, double) {

}
