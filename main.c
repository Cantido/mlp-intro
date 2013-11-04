#include <stdio.h>
#include <math.h>

#define LEARNING_RATE (0.5)

/* START neural network computational functions */

double func(double x){
	return (1 / (1 + pow(x, M_E)));
}

double func_p(double x){
	return func(x)*(1-func(x));
}


/* END neural network computational functions */

int main(){

	/* net:
	 * 	[0] weighted sum input to input node
	 * 	[1,2] weighted sum input to hidden nodes
	 * 	[3] weighted sum input to output node (NOT FINAL OUTPUT OF NETWORK)
	 */

	double n[4];

	/* weights w:
	 * 	[0,1] = connection between input & first hidden node
	 * 	[2,3] = connection between input & second hidden node
	 */

	double w[4];
	
	/* output array:
	 * 	[0] sigmoid output of input node
	 * 	[1,2] sigmoid output of hidden nodes
	 * 	[3] sigmoid output of output node (final output of network)
	 */

	double y[4];
	
	/* error array:
	 *  [0] dummy variable for index. or the result of messy code. DO NOT USE.
	 *  [1,2] local error of hidden layer nodes
	 *  [3] local error of output layer
	 *
	 * This array -will- be filled backwards, from 3 to 0
	 */
	 
	double l_e[4];

	/* create input/output array */

	double desired[21];
	double input[21];

	input[0] = -1.0;
	desired[0] = pow(input[0], 2) + 1;

	for(short i = 1; i < 21; i++){
		input[i] = input[i-1] + 0.1;
		desired[i] = pow(input[i], 2) + 1;
	}

	/* done creating input/output array */

	double iteration_error = 0;

	for(int i = 0; i < 500; i++){ // Completion of one loop: one full iteration through dataset
		for(int j = 0; j < 21; j++){ // Completion of one loop: presentation & propagation of one data point
			
			/* input layer computation */

			n[0] = input[j];
			y[0] = func(n[0]);

			/* hidden layer computation */

			n[1] = w[0] * y[0];
			n[2] = w[1] * y[0];

			y[1] = func(n[1]);
			y[2] = func(n[2]);

			/* output layer computation */

			n[3] = (w[2] * y[1]) + (w[3] * y[2]);

			y[3] = func(n[3]);

			/* the output of the network is now stored in y[3] */

			/* back propagating now */

			/* compute error of output layer */

			l_e[3] = (desired[j] - y[3]) * func_p(n[3]);

			/* compute local error of hidden layer */

			l_e[1] = y[1] * (1 - y[1]) * l_e[3] * w[2];
			l_e[2] = y[2] * (1 - y[1]) * l_e[3] * w[3];

			/* there is no input layer local error term */

			/* weight updates */

			/* input-hidden connection weights */

			w[0] = w[0] + LEARNING_RATE * l_e[1] * y[0];
			w[1] = w[1] + LEARNING_RATE * l_e[2] * y[0];

			/* hidden-output connection weights */

			w[2] = w[2] + LEARNING_RATE * l_e[3] * y[1];
			w[3] = w[3] + LEARNING_RATE * l_e[3] * y[2];
			
			
			iteration_error += pow((desired[j] - y[3]), 2);
		}

		printf("%i \t%f", i, iteration_error);

	}


	return 0;
}
