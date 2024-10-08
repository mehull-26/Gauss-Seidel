#include <fstream>
#include <iostream>
#include "utility.h"

int main()
{
	int grid_size = 4;
	cout << "Enter the grid size (eg: 10 for grid spacing of 0.1): ";
	cin >> grid_size;

	MATRIX left_matrix(grid_size * grid_size, grid_size * grid_size);

	MATRIX right_matrix(grid_size * grid_size, 1);
	for (int i = 0; i < grid_size * grid_size; i++)
	{
		right_matrix[i][0] = 1.0f / (grid_size * grid_size);
	}
	for (int m = 0; m < grid_size * grid_size; m++)
	{
		int i = int(m / grid_size);
		int j = m % grid_size;

		if (i == 0 && j == 0)
		{
			left_matrix[m][i * (grid_size) + j] = 4;
			left_matrix[m][i * (grid_size) + (j + 1)] = -2;
			left_matrix[m][(i + 1) * (grid_size) + j] = -2;
			continue;
		}
		else if (i == 0)
		{
			left_matrix[m][i * (grid_size) + j] = 4;
			left_matrix[m][(i+1) * (grid_size) + j] = -2;
			left_matrix[m][(i) * (grid_size) + j-1] = -1;
			if (j + 1 < grid_size)
				left_matrix[m][(i) * (grid_size)+ j+1] = -1;
			continue;
		}
		else if (j == 0)
		{
			left_matrix[m][i * (grid_size) + j] = 4;
			left_matrix[m][(i-1) * (grid_size) + j] = -1;
			if (i + 1 < grid_size)
				left_matrix[m][(i + 1) * (grid_size)+j] = -1;
			left_matrix[m][i * (grid_size) + j+1] = -2;
			continue;
		}
			
		left_matrix[m][i * (grid_size) + j] = 4;
		left_matrix[m][(i-1) * (grid_size) + j] = -1;
		if (i + 1 < grid_size)
			left_matrix[m][(i + 1) * (grid_size)+j] = -1;
		left_matrix[m][i * (grid_size) + j-1] = -1;
		if (j + 1 < grid_size)
			left_matrix[m][i * (grid_size) + j+1] = -1;

	}

	
	vector<double> solution = GS_solution( grid_size * grid_size, left_matrix, right_matrix, 0.00001);
	ofstream fout;
	fout.open("solution.txt");
	fout.clear();
	fout << "Grid Size: " << grid_size << "\n";
	fout << "Grid Spacing: " << 1.0f / grid_size << "\n\n";

	for (int i = grid_size -1; i >= 0; i--)
	{
		for (int j = 0; j < grid_size; j++)
		{
			fout <<"T"<< i * grid_size + j + 1 << ": " << solution[i * grid_size + j] << "\t\t";
		}
		fout << "\n";
	}
	cout << "Solution written to solution.txt\n";
	fout.close();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any existing input
	cin.get();
	return 0;
}
