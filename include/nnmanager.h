//Batch class header file

#include <neural-network.h>

class NNManager{

public:
	void setBatchInput();
	void setBatchOutput();
	

private:
	int* input;
	int* output;


};
