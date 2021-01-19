class NeuralNetwork {

    private:
    struct node {
        double value;
        double bias;
	double derivative;
    };
    struct edge {
        double weight;
        double derivative;
    };
    int layers_num;
    int edges_num;
    int nodes_num;
    int* layers_sizes;
    int* expected_out;
    node* nodes;
    edge* edges;

    public:
    void generateNew(int, int*);
    double evaluate(double* input, double* output);
    double getNodeValue(int, int);
    void setNodeBaias(int, int, double);
    void setEdgeWeight(int, int, int, double);
    void gradient();

};
