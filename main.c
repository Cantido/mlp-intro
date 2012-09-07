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

	/* net array:
	 * 	[0] weighted sum input to input node
	 * 	[1,2] weighted sum input to hidden nodes
	 * 	[3] weighted sum input to output node
	 */

	double net[4] = 0;
	
	
	/* output array:
	 * 	[0] sigmoid output of input node
	 * 	[1,2] sigmoid output of hidden nodes
	 * 	[3] sigmoid output of output node (final output of network)
	 */

	double net[4] = 0;
	
	/* error array:
	 *  [0] local error of input layer
	 *  [1,2] local error of hidden layer nodes
	 *  [3] local error of output layer
	 *
	 * This array -will- be filled backwards, from 3 to 0
	 */
	 
	 double error[4] = 0;

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

			net[0] = input[j] * weight[0];
			results[0] = sigmoid(net[0]);

			/* for two nodes: input vector x weight -> sigmoid */

			net[1] = results[0] * weight[1];
			net[2] = results[0] * weight[2];
			
			results[1] = sigmoid(net[1]);
			results[2] = sigmoid(net[2]);

			/* for final node: weight * sum both outputs -> sigmoid */

			net[3] = results[2] * weight[3] + 
			
			/* back-propagate */
			/* compute output layer local error */
			
			error[3] = (desired[j] - results[3]) * sigmoid_deriv(results[3]);
			
			/* compute hidden layer local error */
			
			error[1] = sigmoid_deriv(net[1]) * error [3] * weight[3];
			error[2] = sigmoid_deriv(net[2]) * error [3] * weight[4];
			
			/* compute input layer local error */
			
			error[0] = sigmoid_deriv(net[0]) * ((error[1] * weight[1]) + (error[2] * weight[2]));
			
			/* update weights (i'll go from input layer to output layer) */
			
			

		}

	}


	return 0;
}
