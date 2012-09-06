#include <stdio.h>
#include <math.h>

#define LEARNING_RATE .5

/* START neural network computational functions */

double sigmoid(double x){
	return (1 / (1 + pow(x, M_E)));
}

double sigmoid_deriv(double x){
	return ( x * (1 - x));
}


/* END neural network computational functions */

int main(){

	/* weights:
	 * 	[0] = input node's weight on the initial input
	 * 	[1,2] = the two hidden nodes' weights on the input node's output
	 * 	[3,4] = the one output node's weights on the two hidden nodes' output
	 */

	double weight[5] = 0;

	/* results array:
	 * 	[0] result of input node's computation
	 * 	[1,2] result of hidden layer node computation
	 * 	[3] result of output layer's computation
	 */

	double results[4] = 0;

	double desired[21];
	double input[21];

	double x = -1.0;
	for(short i = 0, x = -1.0; i < 21; i++, x + 0.1){
		input[i] = x;
		desired[i] = pow(x, 2) + 1;
	}

	for(int i = 0; i < 500; i++){ // Completion of one loop: full iteration through dataset
		for(int j = 0; j < 21; j++){

			/* first layer: input vector x weight -> sigmoid */

			results[0] = sigmoid(input[j] * weight[0]);

			/* for two nodes: input vector x weight -> sigmoid */

			results[1] = sigmoid(results[0] * weight[1]);
			results[2] = sigmoid(results[0] * weight[2]);

			/* for final node: weight * sum both outputs -> sigmoid */

			results [3] = sigmoid((results[1] * weight[3]) + (results[2] * weight[4]));

			/* back-propagate */



		}

	}


	return 0;
}
