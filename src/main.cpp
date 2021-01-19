#include "neural-network.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	NeuralNetwork NNN;
	int layers[2] = {3, 3};
	double input[3] = {1, 1, 1};
	double output[3] = {1, 1, 1};
	NNN.generateNew(2, layers);
	cout << NNN.evaluate(input, output) << endl;
	
	return 0;
}