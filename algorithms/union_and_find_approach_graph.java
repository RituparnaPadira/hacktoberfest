//Detects cycle in O(n) amortized time complexity.

import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{
    //Function to detect cycle in an undirected graph.
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj)
    {       

        //Union find

        int[] parent=new int[V];

        Arrays.fill(parent,-1);   

        for(int src=0;src<V;src++){

            for(int des:adj.get(src)){

                if(src<des){

                    int x=find(parent,src);
                    int y=find(parent,des);

                    if(x==y) return true;

                    union(parent,x,y);

                }

            }

        }
        return false;
    }

    private int find(int[] parent,int i){

        if(parent[i]==-1){
            return i;
        }
        int idx=find(parent,parent[i]);
        parent[i]=idx;
        return idx;
    }

    private void union(int[] parent,int x,int y){

        parent[x]=y;

    }

}
