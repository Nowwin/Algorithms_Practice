#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<stdio.h> 
#include<algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<int> find_head(vector<vector<int>> input) {

	vector<int> head;

	for (size_t i = 0; i < input.size(); i++)
	{
		head.push_back(input[i][0]);

	}

	return head;
}

void print_graph(vector<vector<int>> input) {

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++)
			std::cout << input[i][j] << ' ';

		std::cout << '\n';
	}


}

int find_element_in_head(vector<int> head, int element) {

	for (size_t i = 0; i < head.size(); i++)
	{
		if (head[i] == element)
		{
			return i;
		}

	}

	return -1;

}

vector<int> subset_graph(vector<vector<int>> input, int subset_index) {

	vector<int> subset;

	for (size_t i = 1; i < input[subset_index].size(); i++)
	{
		subset.push_back(input[subset_index][i]);

	}

	return subset;
}

void print_vector(vector<int> input) {
	for (size_t i = 0; i < input.size(); i++)
	{
		cout << "Elements in vector are: " << input[i] << endl;
	}
}

int karger_cut(vector<vector<int>> graph) {

	//Set random seed
	srand(time(NULL));

		
	int no_of_vertex = graph.size();

	while (no_of_vertex > 2)
	{
		
		vector<int> head = find_head(graph);
		
		int index_1 = rand() % head.size();

		int index_1_2 = rand() % graph[index_1].size();

		if (index_1_2 == 0)
		{
			index_1_2++;
		}

		//Getting Edge
		int vertex_fused_1 = head[index_1];
		int vertex_fused_2 = graph[index_1][index_1_2];
		
		int index_2 = find_element_in_head(head, vertex_fused_2);
		
		if (index_2 == -1)
		{
			cout << "This vertex was not found in head: " << vertex_fused_2 << endl;
			return -1;
		}

		vector<int> subset_index_2 = subset_graph(graph, index_2);

		//Union the vertexes

		for (size_t i = 0; i < subset_index_2.size(); i++)
		{
			graph[index_1].push_back(subset_index_2[i]);

		}

		
		//Contracting the remaining vertexes

		for (size_t k = 0; k < subset_index_2.size(); k++)
		{
			if (subset_index_2[k] != vertex_fused_1 && subset_index_2[k] != vertex_fused_2)
			{
				int locator = find_element_in_head(head, subset_index_2[k]);

				if (locator == -1)
				{
					cout << "Error in finding element from subset" << endl;
					return -1;
				}

				for (size_t p = 1; p < graph[locator].size(); p++)
				{
					if (graph[locator][p] == vertex_fused_2) {
						graph[locator][p] = vertex_fused_1;
					}
				}


			}
		}

		//Removing Self Loops
				
		for (size_t j = 1; j < graph[index_1].size(); j++)
		{
			if (graph[index_1][j] == vertex_fused_1 || graph[index_1][j] == vertex_fused_2) {

				graph[index_1].erase(graph[index_1].begin() + j);
				j--;
			}
		}

		

		no_of_vertex--;
		graph.erase(graph.begin() + index_2);

		//cout << "The Edge Contracted: " << vertex_fused_1 << "--" << vertex_fused_2 << endl;
		//print_graph(graph);
	}

	return graph[0].size() - 1;
}

int main()
{
	std::ifstream in("D:\\Desktop\\DSA\\Stanford Algos\\Week 4\\test.txt");
	std::vector<std::vector<int> > v;

	if (in) {
		std::string line;

		while (std::getline(in, line)) {
			v.push_back(std::vector<int>());

			// Break down the row into column values
			std::stringstream split(line);
			int value;

			while (split >> value)
				v.back().push_back(value);
		}
	}

	

	//print_graph(v);
	
	int min_cut = karger_cut(v);
	   
	int temp = 0;

	for (size_t i = 0; i < v.size()*v.size(); i++)
	{
		temp = karger_cut(v);

		if (temp < min_cut)
		{
			min_cut = temp;
		}

		cout << i << endl;
		cout << "The minimum cut of this iteration is: " << min_cut << endl;

	}

	cout << min_cut << endl;
	
	
	int exit = 0;

	cin >> exit;

	return 0;
}