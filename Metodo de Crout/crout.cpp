#include <iostream>

int main (void){
	float Y[3][3] = {{3.0, 2.0, 4.0}, {1.0, 1.0, 2.0}, {4.0, 3.0, 2.0}};
	float sum;
	float L[3][3] = {0.0}, U[3][3] = {0.0};

	for(int j = 0; j < 3; j++){
		for(int i = 0; i < 3; i++){
			sum = 0.0;

			for(int k = 0; k < j ; k++){
				sum = sum + L[i][k]*U[k][j];
			}

			if(i == j)
				U[i][j] = 1; 

			if(i >= j){
				L[i][j] = Y[i][j] - sum;
			}
			else
				U[i][j] = ((Y[i][j] - sum)/(L[i][i]));
		}
	}


	for(int j = 0; j < 3; j++){
		for(int i = 0; i < 3; i++){
			std::cout << L[j][i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for(int j = 0; j < 3; j++){
		for(int i = 0; i < 3; i++){
			std::cout << U[j][i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}