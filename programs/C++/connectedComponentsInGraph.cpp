/* This program uses DFS to find number of connected components in a undirected graph.
Time complexity - O(n), where n is number of vertices in a graph
Assumption: In a graph of n vertices, vertices are numbered from 0 to n-1
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> graph,vector<bool>& visited,int curr){
	visited[curr]=true;
	for(int i=0;i<graph[curr].size();i++){
		if(!visited[graph[curr][i]])
			dfs(graph,visited,graph[curr][i]);
	}
}

int main(){
	cout<<"Enter number of vertices in a graph"<<endl;
	int vertices;
	cin>>vertices;
	cout<<"Enter number of edges in a graph"<<endl;
	int edges;
	cin>>edges;
	vector<vector<int>> graph(vertices);
	vector<bool> visited(vertices,false);

	cout<<"Enter edges in format X Y, which means there is a bidirectional edge between X and Y"<<endl;

	while(edges--){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	int connectedComponents = 0;
	for(int i=0;i<vertices;i++){
		if(!visited[i]){
			connectedComponents++;
			dfs(graph,visited,i);
		}
	}

	cout<<"Number of connected components in a graph are:	"<<connectedComponents<<endl;

	return 0;
}