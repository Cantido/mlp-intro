#include <stdio.h>
#include <math.h>

#define MAX_NODES 10  /* maximum nodes -per layer- */

/* START data structure functions */

typedef struct neuron{
	struct neuron* incoming[MAX_NODES];
	struct neuron* outgoing[MAX_NODES];
	float weight[MAX_NODES];
	float net;
} neuron;

void link_neuron(neuron* high, neuron* low, int highs_depth, int lows_depth){
	high.outgoing[lows_depth] = low;
	low.incoming[highs_depth] = high;
}

void link_layer(neuron* high, neuron* low, int n_high, int n_low){

	/* Links each node in high with every node in low */

	for(short i = 0; i < MAX_NODES; i++){
		for(short j = 0; j < MAX_NODES; j++){
			if(i < n_high && j < n_low){
				link_neuron(high[i], low[j], i, j);
			}
			else{
				high[i].outgoing[j] = NULL;
				low[j].incoming[i] = NULL;
			}
		}
	}
}

neuron* build_network(int n_input_nodes, int n_hidden_nodes, int n_output_nodes){
	if(n_input_nodes > MAX_NODES || n_hidden_nodes > MAX_NODES || n_output_nodes > MAX_NODES){
		return NULL;
	}

	static neuron input[MAX_NODES];
	static neuron hidden[MAX_NODES];
	static neuron output[MAX_NODES];

	static neuron* layer[3] = {input, hidden, output};

	link_layer(input, hidden, n_input_nodes, n_hidden_nodes);

	link_layer(hidden, output, n_hidden_nodes, n_output_nodes);

	return layer;
}

/* END data structure functions */

/* START neural network computational functions */

float sigmoid(float x){
	return (1 / (1 + pow(x, M_E)));
}

/* END neural network computational functions */

int main(){
	return 0;
}
