#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<stdio.h> 
#include<algorithm>
#include <stdlib.h>

using namespace std;

class Graph {
	long long int V;
	vector<vector<long long int>> adj;

public:
	Graph(long long int V);
	void addEdge(long long int a, long long int b);
	void printGraph();
	Graph reverse_Graph();
	void first_DFS(vector<long long int> &explored, vector<long long int> &finishing_time, long long int i);
	void second_DFS(vector<long long int> &explored, long long int i, long long int &size_of_scc);
	vector <long long int> count_SCC(int n, Graph &G_rev);

};

Graph::Graph(long long int V) {
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(long long int a, long long int b) {
	adj[a - 1].push_back(b);
}

void Graph::printGraph() {
	for (size_t i = 0; i < V; i++)
	{
		for (size_t j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}

		cout << "\n";
	}
}

Graph Graph::reverse_Graph() {
	Graph G_rev(V);
	for (size_t i = 0; i < V; i++)
	{
		for (size_t j = 0; j < adj[i].size(); j++) {
			G_rev.addEdge(adj[i][j],i+1);
		}
	}

	
	return G_rev;
}

void Graph::first_DFS(vector<long long int> &explored, vector<long long int> &finishing_time, long long int i) {
	
	explored[i] = 1;

	cout << i << endl;
	
	for (size_t j = 0; j < adj[i].size(); j++)
	{
		if (explored[adj[i][j]-1] == 0)
		{
			first_DFS(explored, finishing_time, adj[i][j]-1);
		}
				
	}
			
	finishing_time.push_back(i);
}

void Graph::second_DFS(vector<long long int> &explored, long long int i, long long int &size_of_scc) {
	
	explored[i] = 1;
	size_of_scc++;

	for (size_t j = 0; j < adj[i].size(); j++)
	{
		if (explored[adj[i][j] - 1] == 0) {

			second_DFS(explored, adj[i][j] - 1, size_of_scc);

		}
	}
}

vector <long long int> Graph::count_SCC(int n, Graph &G_rev) {

	vector <long long int> size_scc;

	cout << "count_SCC is started" << '\n';
	
	for (size_t i = 0; i < n; i++)
	{
		size_scc.push_back(0);
	}

	vector<long long int> finishing_time;
	
	vector<long long int> explored;

	for (size_t i = 0; i < V; i++)
	{
		explored.push_back(0);
	}
		
	//First DFS search

	//Graph G_rev = reverse_Graph();

	cout << "First DFS has started" << '\n';

	for (long long int i = V-1; i >= 0; i--)
	{
		
		if (explored[i] == 0)
		{
			G_rev.first_DFS(explored, finishing_time, i);
		}
				
	}

	cout << "First DFS has finished" << '\n';

	for (size_t i = 0; i < V; i++)
	{
		explored[i] = 0;
	}

	//Second DFS Search

	cout << "Second DFS has started" << '\n';

	long long int size_of_scc = 0;
	long long int counter = 0;

	for (long long int i = V - 1; i >= 0; i--)
	{

		size_of_scc = 0;

		if (explored[finishing_time[i]] == 0)
		{
			second_DFS(explored, finishing_time[i], size_of_scc);

			//cout << size_of_scc << endl;

			if (counter < n)
			{
				size_scc[counter] = size_of_scc;
				counter++;
			}
			else
			{
				if (size_of_scc > size_scc[0])
				{
					sort(size_scc.begin(), size_scc.end());
					size_scc[0] = size_of_scc;
					
				}
			}

			
		}

	}

	cout << "Second DFS has finished" << '\n';

	return size_scc;

}



int main()
{
	ifstream in("D:\\Desktop\\DSA\\Stanford Algos\\Part 2\\Week 1\\final.txt");

	string line;

	int vertex_1 = 0;
	int vertex_2 = 0;

	long long int vertex = 875714;

	Graph G(vertex);
	Graph G_rev(vertex);

	cout << "Graph Intialization Started" << endl;

	while (in >> vertex_1 >> vertex_2) {
		G.addEdge(vertex_1, vertex_2);
		G_rev.addEdge(vertex_2, vertex_1);
	}

	cout << "Graph Intialization Finished" << endl;

	in.close();

    vector<long long int> count_n_scc = G.count_SCC(5, G_rev);
	
	cout << "Size of SCCs are:" << '\n';

	for (size_t i = 0; i < count_n_scc.size(); i++)
	{
		cout << count_n_scc[i] << '\n';
	}
	
	int exit;

	cin >> exit;


	
	return 0;
}