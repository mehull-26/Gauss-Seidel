#pragma once
#include <vector>
using namespace std;

class MATRIX
{
private:
	vector<vector<float>> data;

public:
	MATRIX(int rows , int columns) : data(rows, vector<float>(columns)) {}

	MATRIX(int rows, int columns, vector<vector<float>> matrix) : data(rows, vector<float>(columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				data[i][j] = matrix[i][j];
			}
		}
	}

	vector<float>& operator[](int i) { return data[i]; }
	const vector<float>& operator[](int i) const { return data[i]; }
};

vector<float> GS_solution(int dimension, MATRIX Left_Matrix, MATRIX Right_Matrix, float threshold);
