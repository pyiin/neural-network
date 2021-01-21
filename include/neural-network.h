class NeuralNetwork {

    private:
    struct node {
        double value = 0;
        double bias = 0;
	double derivative = 0;
    };
    struct edge {
        double weight = 0;
        double derivative = 0;
    };
    int layers_num = 0;
    int edges_num = 0;
    int nodes_num = 0;
    int* layers_sizes  = 0;
    int* expected_out = 0;
    node* nodes;
    edge* edges;

    public:
    void generateNew(int, int*);
    double evaluate(double* input, double* output);
    //double getNodeValue(int, int);
    //void setNodeBaias(int, int, double);
    //void setEdgeWeight(int, int, int, double);
    void gradient();
    void applyGradient(double constant);
    //void batch(int n, double** inputs, double** outputs);

};
