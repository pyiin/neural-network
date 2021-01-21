#pragma once
#include <cstdio>
#include <stdlib.h>
#include "nnmanager.h"
#define max(a,b) (a>b?a:b)

NNManager::NNManager(int n_layers, int* layers){
	NN.generateNew(n_layers, layers);
	in_size = *layers;
	out_size = *(layers + n_layers - 1);
	batch_size = 1;
}

void NNManager::learnBatch(int size){
	batch_size = size <= 0 ? batch_size : size; //avilable_IO
	for(int i=0; i < size && IO_index < avilable_IO; i++, IO_index++){
		NN.evaluate(input + IO_index*in_size, output + IO_index*out_size);
		NN.gradient();
	}
	NN.applyGradient(1.0/size);
}

int NNManager::genIO(int n_tests){
	if(in_size != out_size)
		return 0;
	avilable_IO = n_tests;
	IO_index = 0;
	input = new double[n_tests * in_size];
	output = new double[n_tests * out_size];
	for(int i = 0; i < n_tests; i++){
		double m = 0.0;
		for(int j = 0; j < in_size; j++){
			input[i*in_size + j] = 0.0001 * (rand()%10000);
			m = max(m, input[i*in_size + j]);
		}
		for(int j = 0; j < in_size; j++){
			output[i*in_size + j] = input[i*in_size + j] == m;
		}
	}
	return 1;
}

void NNManager::testNN(int test_num){
	printf("%d\n", NN.evaluate(input + in_size*test_num, output + out_size*test_num));
}
