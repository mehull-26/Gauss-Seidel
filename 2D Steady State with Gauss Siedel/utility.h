#pragma once
#include <vector>
using namespace std;

class MATRIX
{
private:
	vector<vector<double>> data;

public:
	MATRIX(int rows , int columns) : data(rows, vector<double>(columns)) {}

	MATRIX(int rows, int columns, vector<vector<double>> matrix) : data(rows, vector<double>(columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				data[i][j] = matrix[i][j];
			}
		}
	}

	vector<double>& operator[](int i) { return data[i]; }
	const vector<double>& operator[](int i) const { return data[i]; }
};

vector<double> GS_solution(int dimension, MATRIX Left_Matrix, MATRIX Right_Matrix, double threshold);
