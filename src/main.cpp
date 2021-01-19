#include "neural-network.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	NeuralNetwork NNN;
	int layers[3] = {3, 5, 3};
	double input[3] = {3, 5, 3};
	double output[3] = {3, 5, 3};
	NNN.generateNew(3, layers);
	cout << NNN.evaluate(input, output) << endl;
	
	return 0;
}