#include "neural-network.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	NeuralNetwork NNN;
	int layers[2] = {3, 3};
	double input[3] = {1, 1, 1};
	double output[3] = {1, 1, 1};
	NNN.generateNew(2, layers);
	cout << NNN.evaluate(input, output) << endl;
	
	//following might be usefull for Release version
	/*
	int useless;
	cin >> useless;
	return 0;
	//*/
}