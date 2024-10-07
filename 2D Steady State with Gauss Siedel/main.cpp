#include <fstream>
#include <iostream>
#include "utility.h"

int main()
{
	vector <vector<float>> lol = { {2.25,-1, 0, 0}, {-1, 2.25, -1, 0}, { 0, -1, 2.25, -1}, {0, 0, -2, 2.25} };
	MATRIX a(4,4, lol);
	
	vector <vector<float>> lol2 = { {1}, {0}, {0}, {0} };
	MATRIX b(4, 1, lol2);
	vector<float> ans = GS_solution(4, a, b, 0.0001f);
	for (int i = 0; i < 4; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
