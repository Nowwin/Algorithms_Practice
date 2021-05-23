#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h> 
#include<algorithm> 
#include <vector> 

using namespace std;

long long int count_of_inv = 0;

void merge(vector<int> &A, int l, int m, int r) {

	int n1 = m + 1 - l;
	int n2 = r - m;

	vector<int> left_side;
	vector<int> right_side;

	for (size_t i = 0; i < n1; i++)
	{
		left_side.push_back(A[l+i]);
	}

	for (size_t i = 0; i < n2; i++)
	{
		right_side.push_back(A[m+1+i]);
	}

	int j = 0, k = 0, index = l;

	while (j < n1 && k < n2)
	{
		if (left_side[j] <= right_side[k]) {
			A[index] = left_side[j];
			j++;
		}
		else
		{
			A[index] = right_side[k];
			k++;
			count_of_inv = count_of_inv + n1 - j;
			
		}
		index++;
	}

	while (j < n1)
	{
		A[index] = left_side[j];
		index++;
		j++;
	}

	while (k < n2)
	{
		A[index] = right_side[k];
		index++;
		k++;
	}

}

void merge_sort(vector<int> &A, int l, int r) {
	
	if (l<r)
	{
		int m = l + (r - l) / 2;

		merge_sort(A, l, m);
		merge_sort(A, m + 1, r);

		merge(A, l, m, r);
	}

}

int main() {

	vector<int> input;
	int x = 0;

	ifstream inFile;

	inFile.open("D:\\Desktop\\DSA\\Stanford Algos\\Week 2\\test.txt");

	if (!inFile) {
		cerr << "Unable to open file test.txt";
		exit(1);   // call system to stop
	}

	while (inFile >> x) {
		input.push_back(x);
	}

	inFile.close();

	/*for (size_t i = 0; i < input.size(); i++)
	{
		cout << input[i] << endl;
	}
*/
	merge_sort(input, 0, input.size() - 1);

	/*for (size_t i = 0; i < input.size(); i++)
	{
		cout << input[i] << endl;
	}*/


	cout << count_of_inv << endl;

	int exit = 0;

	cin >> exit;

	return 0;
}
