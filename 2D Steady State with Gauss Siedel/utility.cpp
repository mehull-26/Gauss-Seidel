#include "utility.h"

vector<float> GS_solution(int dimension, MATRIX Left_Matrix, MATRIX Right_Matrix, float threshold)
{
	vector<float> solution(dimension, 1.0f);

	float convergence_CKR = 1000;
	float convergence_threshold = threshold;

	while (abs(solution[0] - convergence_CKR) > convergence_threshold)
	{
		convergence_CKR = solution[0];

		for (int i = 0; i < dimension; i++)
		{
			float sigma = 0;
			for (int j = 0; j < dimension; j++)
			{
				if (i != j)
				{
					sigma += Left_Matrix[i][j] * solution[j];
				}
			}
			solution[i] = (Right_Matrix[i][0] - sigma) / Left_Matrix[i][i];
		}
	}

	return solution;
}