#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h> 
#include<algorithm> 
#include <vector> 

using namespace std;

long long int count_of_comp = 0;

void swap_element(vector<int> &A, int swap1, int swap2) {
	
	int temp = 0;

	temp = A[swap1];
	A[swap1] = A[swap2];
	A[swap2] = temp;
}

int return_pivot(vector<int> &A, int l, int r) {
	//return l;
	//return r;

	int mid = l + (r - l) / 2;

	if ((A[l] < A[mid] && A[mid] < A[r]) || (A[r] < A[mid] && A[mid] < A[l]))
	{
		return mid;
	}

	if ((A[mid] < A[l] && A[l] < A[r]) || (A[r] < A[l] && A[l] < A[mid]))
	{
		return l;
	}

	if ((A[mid] < A[r] && A[r] < A[l]) || (A[l] < A[r] && A[r] < A[mid]))
	{
		return r;
	}

	return l;
}

int partition(vector<int> &A, int l, int r, int pivot) {

	if (l < r)
	{
		count_of_comp = r - l + count_of_comp;

		swap_element(A, l, pivot);

		int i = l + 1;

		for (size_t j = l+1; j < r+1; j++)
		{
			if (A[j] < A[l]) {
				swap_element(A, j, i);
				i++;
			}
		}

		swap_element(A, l, i - 1);

		return i - 1;
	}

	return l;
}

void quick_sort(vector<int> &A, int l, int r) {

	if (l < r)
	{
		int pivot = return_pivot(A, l, r);

		int final_pivot = partition(A, l, r, pivot);

		quick_sort(A, l, final_pivot - 1);
		quick_sort(A, final_pivot + 1, r);

	}

}

int main() {

	vector<int> input;
	int x = 0;

	ifstream inFile;

	inFile.open("D:\\Desktop\\DSA\\Stanford Algos\\Week 3\\test.txt");

	if (!inFile) {
		cerr << "Unable to open file test.txt";
		exit(1);   // call system to stop
	}

	while (inFile >> x) {
		input.push_back(x);
	}

	inFile.close();

	quick_sort(input, 0, input.size() - 1);

	/*for (size_t i = 0; i < input.size(); i++)
	{
		cout << input[i] << endl;
	}
*/
	cout << count_of_comp << endl;

	int exit = 0;

	cin >> exit;

	return 0;
}
