#pragma once

class NeuralNetwork {

    private:
    struct node {
        double value;
        double baias;// bias is only in vertices, not nodes
    };
    int layers_num;
    int edges_num;
    int nodes_num;
    int* layers_sizes;
    node* nodes;
    double* edges_weight;

    public:
    void generateNew(int, int*);
    double getNodeValue(int, int);
    void setNodeBaias(int, int, double);
    void setEdgeWeight(int, int, int, double);

};