#pragma once

class NeuralNetwork {
    
    private:
    struct node {
        double value;
        double baias;
    };
    int* layers_size;
    node* nodes;
    double* edges_weight;

    public:
    void generateNew();
    double getNodeValue(int, int);
    void setNodeBaias(int, int, double);
    void setEdgeWeight(int, int, int, double);

};