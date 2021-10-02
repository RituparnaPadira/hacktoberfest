#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class edge{
    public:
        int source, dest, weight;
};

bool comp(const edge & a, const edge & b){
    return a.weight < b.weight;
}

void kruskals(edge *inp, int n, int e){
    sort(inp, inp + e, comp);

    edge output[n - 1];
    int parent[n];
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int count = 0, i = 0;

    while(count < n - 1 && i < e){
        edge container = inp[i];
        int sourceVertex = inp[i].source;
        int destVertex = inp[i].dest;
        while(parent[sourceVertex] != sourceVertex){
            sourceVertex = parent[sourceVertex];
        }
        while(parent[destVertex] != destVertex){
            destVertex = parent[destVertex];
        }
        if(parent[sourceVertex] != parent[destVertex]){
            parent[sourceVertex] = destVertex;
            output[count] = container;
            count++;
        }
        i++;

    }

    for(int i = 0; i < n - 1; i++){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }
}

void prims(int **input, int n, int e){
    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    int parent[n], weight[n];
    weight[0] = 0;
    parent[0] = -1;
    for(int i = 1; i < n; i++){
        weight[i] = INT_MAX;
        parent[i] = -1; 
    }
    int count = 0;
    while(count < n - 1){
        int mini = -1;
        int minWeight = INT_MAX;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                if(minWeight > weight[i]){
                    mini = i;
                    minWeight = weight[i];
                }
            }
        }
        if(mini == -1){
            break;
        }
        visited[mini] = true;
        for(int i = 0 ; i < n ; i++){
            if(input[mini][i] && !visited[i]){
                if(weight[i] > input[mini][i]){
                    weight[i] = input[mini][i];
                    parent[i] = mini;
                }
            }
        }
        count++;
    }

    for(int i = 1 ; i < n; i++) {
        if(parent[i] > i){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else{
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }
}

int main(){

    int n, e;
    cin>>n>>e;
    // edge *inp = new edge[e];
    // for(int i = 0; i < e; i++){
    //     int source, dest, weight;
    //     cin>>source>>dest>>weight;
    //     inp[i].source = source;
    //     inp[i].dest = dest;
    //     inp[i].weight = weight;
    // }

    // kruskals(inp, n, e);

    int **input = new int*[n];
    for(int i = 0 ; i < n; i++){
        input[i] = new int[n];
        for(int j = 0 ; j < n; j++){
            input[i][j] = 0;
        }
    }
    for(int i = 0 ; i < e; i++){
        int v1, v2, weight;
        cin>>v1>>v2>>weight;
        input[v1][v2] = weight;
        input[v2][v1] = weight;
    }

    prims(input, n, e);

    for(int i = 0; i < n; i++){
        delete []input[i];
    }

    delete []input;

    return 0;
}