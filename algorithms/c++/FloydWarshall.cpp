//Floyd-Warshall is a DP algorithm that gives shortest path between each pair of vertices in directed graph in O(n^3) time complexity
/**
Input constraints:
In a graph of n vertices. Vertices are numbered from o to n-1
**/
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX


void printShortestDistance(vector<vector<int>> shortestDist,int vertices){
    cout<<"Following are shortestDist between each pair of vertices"<< endl;
    cout<<"SourceVertex"<<"	"<<"TargetVertex"<<"	"<<"shortestDistance"<<endl;
    for (int i=0;i<vertices;i++)
    {
    	for(int j=0;j<vertices;j++){
    		if(shortestDist[i][j] == INF){
    			cout<<i<<"	"<<j<<"	"<<"INF"<<endl;
    		}
    		else{
    			cout<<i<<"	"<<j<<"	"<<shortestDist[i][j]<<endl;    		}
    	}
    }
}

void applyFloydWarshall(vector<vector<int>> graph,int vertices){
	vector<vector<int>> shortestDist (vertices,vector<int>(vertices,INF));

	for(int i=0;i<vertices;i++)
		for(int j=0;j<vertices;j++)
			if(i==j)
				shortestDist[i][j]=0;
			else
				shortestDist[i][j]=graph[i][j];

	for(int k=0;k<vertices;k++){
		for(int i=0;i<vertices;i++){
			for(int j=0;j<vertices;j++){

				if(shortestDist[i][j]>(shortestDist[i][k]+shortestDist[k][j]) && (shortestDist[i][k]!=INF) && (shortestDist[k][j]!=INF)){
					shortestDist[i][j] = shortestDist[i][k] + shortestDist[k][j];
				}
			}
		}
	}

	printShortestDistance(shortestDist,vertices);
}

int main(){
	int vertices;
	cout<<"Enter number of vertices in a graph"<<endl;
	cin>>vertices;

	int edges;
	cout<<"Enter number of edges in the graph"<<endl;
	cin>>edges;

	cout<<"Enter edges in following format X Y Z, where Z is weight of edge from X to Y"<<endl;

	vector<vector<int>> graph (vertices,vector<int>(vertices,INF));

	while(edges--){
		int x,y,z;
		cin>>x>>y>>z;
		graph[x][y]=z;
	}

	applyFloydWarshall(graph,vertices);

	return 0;

}