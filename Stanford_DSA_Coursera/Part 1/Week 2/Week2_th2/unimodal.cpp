#include<iostream> 
#include<stdio.h> 
#include<algorithm> 
#include <vector> 

using namespace std;

int find_max(vector<int> A, int l, int r) {

	if (l >= r) {
		return A[l];
	}

	int highest = 0;

	int mid = l + (r - l) / 2;
	

	
	if (A[mid] > A[mid+1])
	{
		highest = find_max(A, l, mid);
	}
	else
	{
		highest = find_max(A, mid+1, r);
	}

	return highest;
}


int main() {

	vector<int> input;

	int n = 0;
	int element = 0;

	cout << "Enter the size of input: " << endl;
	cin >> n;

	cout << "Enter the elements in unimodal fashion: " << endl;

	for (size_t i = 0; i < n; i++)
	{
		cin >> element;
		input.push_back(element);
	}

	cout << "The highest element is: " << find_max(input, 0, n - 1) << endl;

	int exit = 0;

	cin >> exit;

	return 0;
}