#include<iostream> 
#include<stdio.h> 
#include<algorithm> 
#include <vector> 

using namespace std;


vector<int> highest_element(vector<int> a, int l, int r) {

	vector<int> compared1, compared2;

	if (l == r)
	{
		compared1.push_back(a[l]);
		return compared1;
	}

	int mid = l + (r - l) / 2;

	compared1 = highest_element(a, l, mid);
	compared2 = highest_element(a, mid + 1, r);
	

	if (compared1[0] >= compared2[0])
	{
		compared1.push_back(compared2[0]);
		return compared1;
	}
	else
	{
		compared2.push_back(compared1[0]);
		return compared2;
	}

	
}

int second_largest(vector<int> a, int l, int r) {

	vector<int> highest_compared_w = highest_element(a, l, r);
	vector<int> second_highest = highest_element(highest_compared_w, 1, highest_compared_w.size()-1);

	return second_highest[0];
}



int main() {
	
	vector<int> input;

	int n = 0;
	int element = 0;

	cout << "Enter the size of input: "<< endl;
	cin >> n;

	cout << "Enter the elements: " << endl;

	for (size_t i = 0; i < n; i++)
	{
		cin >> element;
		input.push_back(element);
	}

	cout << second_largest(input, 0, n-1) << endl;

	int exit = 0;

	cin >> exit;

	return 0;
}