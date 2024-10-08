#include <fstream>
#include <iostream>
#include "utility.h"

int main()
{

	MATRIX left_matrix(16, 16);
	MATRIX right_matrix(16, 1);

	vector<float> r1 =  { 4, -2,  0,  0, -2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	vector<float> r2 =  {-1,  4, -1,  0,  0, -2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	vector<float> r3 =  { 0, -1,  4, -1,  0,  0, -2,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	vector<float> r4 =  { 0,  0, -1,  4,  0,  0,  0, -2,  0,  0,  0,  0,  0,  0,  0 , 0 };
	vector<float> r5 =  {-1,  0,  0,  0,  4, -2,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0 };
	vector<float> r6 =  { 0, -1,  0,  0,  1,  4, -1,  0,  0, -1,  0,  0,  0,  0,  0,  0 };
	vector<float> r7 =  { 0,  0, -1,  0,  0, -1,  4, -1,  0,  0, -1,  0,  0,  0,  0,  0 };
	vector<float> r8 =  { 0,  0,  0, -1,  0,  0, -1,  4,  0,  0,  0, -1,  0,  0,  0,  0 };
	vector<float> r9 =  { 0,  0,  0,  0, -1,  0,  0,  0,  4, -2,  0,  0, -1,  0,  0,  0 };
	vector<float> r10 = { 0,  0,  0,  0,  0, -1,  0,  0, -1,  4, -1,  0,  0, -1,  0,  0 };
	vector<float> r11 = { 0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  4, -1,  0,  0, -1,  0 };
	vector<float> r12 = { 0,  0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  4,  0,  0,  0, -1 };
	vector<float> r13 = { 0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  4, -2,  0,  0 };
	vector<float> r14 = { 0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  4, -1,  0 };
	vector<float> r15 = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  4, -1 };
	vector<float> r16 = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  4 };
	left_matrix[0] = r1;
	left_matrix[1] = r2;
	left_matrix[2] = r3;
	left_matrix[3] = r4;
	left_matrix[4] = r5;
	left_matrix[5] = r6;
	left_matrix[6] = r7;
	left_matrix[7] = r8;
	left_matrix[8] = r9;
	left_matrix[9] = r10;
	left_matrix[10] = r11;
	left_matrix[11] = r12;
	left_matrix[12] = r13;
	left_matrix[13] = r14;
	left_matrix[14] = r15;
	left_matrix[15] = r16;

	for (int i = 0; i < 16; i++)
	{
		right_matrix[i][0] = 1 / 16;
	}
	
	vector<float> solution = GS_solution(16, left_matrix, right_matrix, 0.00001);

	for (int i = 0; i < 4; i++)
	{
		cout << solution[4 - i - 1] << "\t\t";
		cout << solution[8 - i - 1] << "\t\t";
		cout << solution[12 - i - 1] << "\t\t";
		cout << solution[16 - i - 1] << "\t\n";
	}
	return 0;
}
