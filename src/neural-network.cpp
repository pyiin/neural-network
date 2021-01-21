#pragma once
#include "neural-network.h"
#include <math.h>
#include <cstring>


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
    for(int i=0; i<edges_num; i++){
	edges[i].derivative = 0;
    }
    for(int i=0; i<nodes_num; i++){
	nodes[i].derivative = 0;
    }
}

double NeuralNetwork::evaluate(double* input, double* output) {
    for(int i = 0; i<layers_sizes[layers_num-1]; i++){
        expected_out[i] = output[i];
    }
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

void NeuralNetwork::gradient() { // don't f**king touch it PJ
    int offset = 0;
    int edge_offset = 0;
    int L = 0;
    for(; L < layers_num - 1; offset += layers_sizes[L], edge_offset+=layers_sizes[L]*layers_sizes[++L]); // L = layers_num - 1
    for(int k = 0; k<layers_sizes[L]; k++){ // last layer is special
        nodes[offset + k].derivative += 2*(nodes[offset + k].value - expected_out[k]); //derivative - magic
    }

    for(L--; L>=0; L++){ //every other layer
        offset -= layers_sizes[L];
        edge_offset -= layers_sizes[L]*layers_sizes[L+1];
        for(int k = 0; k<layers_sizes[L]; k++){ // loop over a^(L)_k
            for(int k_next = 0; k < layers_sizes[L + 1]; k_next++){
                int node_next = offset + layers_sizes[L] + k_next;
                nodes[offset + k].derivative += nodes[node_next].derivative * nodes[node_next].value * (nodes[node_next].value - 1)* edges[edge_offset + k*layers_sizes[L+1] + k_next].weight;
                edges[edge_offset + k*layers_sizes[L+1] + k_next].derivative += nodes[node_next].derivative * nodes[k+offset].value;
            }
        }
    }
}

void NeuralNetwork::applyGradient(double constant) {
    int offset = 0;
    int edge_offset = 0;
    for(int L = 0; L < layers_num - 1; offset += layers_sizes[L], edge_offset+=layers_sizes[L]*layers_sizes[++L]); // L = layers_num - 1
    offset += layers_sizes[layers_num-1];
    for(;offset>=0;--offset){
        nodes[offset].bias += nodes[offset].derivative;
        nodes[offset].derivative = 0;
    }
    for(;edge_offset>=0;--edge_offset){
        edges[edge_offset].weight += edges[edge_offset].derivative;
        edges[edge_offset].derivative = 0;
    }
}

// {{{
//void NeuralNetwork::batch(int n, double** inputs, double** outputs) { //remember to use safely -> inputs[n][layers_num[0]]; output[n][layers_num[layers_sizes-1]];
//    for(int i=0; i<n; i++){
//        evaluate(*(inputs+i), *(outputs+i));
//        gradient();
//    }
//    applyGradient(1);//to change
//}
//
//double NeuralNetwork::getNodeValue(int layer_n, int layer_k) {
//    return 69;
//}
//void NeuralNetwork::setNodeBaias(int, int, double) {
//
//}
//void NeuralNetwork::setEdgeWeight(int, int, int, double) {
//
//}
//}}}
