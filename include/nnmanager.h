//NN manager class header file

#pragma once
#include "neural-network.h"

class NNManager{

public:
	NNManager(int n_layers, int* layers);
	void learnBatch(int size = -1);
	void testNN(int test_num);
	int genIO(int n_tests);

private:
	NeuralNetwork NN;
	double* input;
	double* output;
	int batch_size;
	int in_size;
	int out_size;
	int avilable_IO;
	int IO_index;
};
