#include<iostream> 
#include<stdio.h> 
#include<algorithm> 
#include <vector> 

using namespace std;

int findColMin(vector<vector<int>> A, int col) {

	
	int min = A[0][col], min_index = 0;

	for (size_t i = 0; i < A[0].size(); i++)
	{
		if (A[i][col] < min) {
			min = A[i][col];
			min_index = i;
		}
	}

	//cout << "min_index: " << min_index << endl;

	return min_index;
}

int find_minima(vector<vector<int>> A, int row, int column_start, int column_last) {

	int mid = column_start + (column_last - column_start) / 2;

	//cout << "Mid: "<< mid << endl;
	
	int min = findColMin(A, mid);

	if (mid == 0 || mid == A[0].size()-1)
	{
		return A[min][mid];
	}

	if (A[min][mid-1] > A[min][mid] && A[min][mid + 1] > A[min][mid])
	{
		return A[min][mid];
	}

	if (A[min][mid - 1] < A[min][mid])
	{
		return find_minima(A, row, column_start, mid-1);
	}
	else
	{
		return find_minima(A, row, mid+1, column_last);
	}
}


int main() {

	

	int n = 0;
	int element = 0;

	cout << "Enter the size of matrix: " << endl;
	cin >> n;

	vector<vector<int>> input(n);
	

	cout << "Enter the elements: " << endl;

	for (size_t i = 0; i < n; i++)
	{
		

		for (size_t j = 0; j < n; j++) {
			cin >> element;
			
			input[i].push_back(element);
			
		}

		
	}

	

	cout << find_minima(input, n - 1, 0, n - 1);

	int exit = 0;

	cin >> exit;
	

	return 0;
}