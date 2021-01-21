#include "neural-network.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int layers[3] = {3, 3, 3};
	NNManager NM(3, layers);
	NM.genIO(100);
	NM.learnBatch(100);
	NM.testNN(57);

	//following might be usefull for Release version
	/*
	int useless;
	cin >> useless;
	return 0;
	//*/
}
