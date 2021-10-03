/*
This program is used to detect cycle in a undirected graph of n vertices numbered from 0 to n-1 using union-find algorithm.
Assumption: Edges given in input are non repetitive
*/

#include<bits/stdc++.h>
using namespace std;

int findParent(int x,vector<int> parents){
	if(parents[x]==x)
		return x;
	return findParent(parents[x],parents);
}

int main(){
	cout<<"Enter number of vertices in a graph"<<endl;
	int vertices;
	cin>>vertices;
	cout<<"Enter number of edges in a graph"<<endl;
	int edges;
	cin>>edges;
	vector<pair<int,int>> edgeList;

	cout<<"Enter edges in format X Y, which means there is a bidirectional edge between X and Y"<<endl;
	while(edges--){
		int x,y;
		cin>>x>>y;
		edgeList.push_back({x,y});
	}

	vector<int> parent(vertices);
	for(int i=0;i<vertices;i++)
		parent[i]=i;

	for(int i=0;i<edgeList.size();i++){
		int px = findParent(edgeList[i].first,parent);
		int py = findParent(edgeList[i].second,parent);

		if(px==py){
			cout<<"Given graph has a cycle"<<endl;
			return 0;
		}
		else{
			parent[edgeList[i].second] = edgeList[i].first;
		}
	}
 
	cout<<"Given graph does not have cycle"<<endl;

	return 0;


}