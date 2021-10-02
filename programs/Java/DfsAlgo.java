import java.util.*;
import java.lang.*;
public class DfsAlgo {
    static void dfsTraversal(int v,ArrayList<ArrayList<Integer>> Graph,boolean vis[]){
        vis[v] = true;
        System.out.print(v+" ");
        for(int i:Graph.get(v)){
            if(!vis[i]){
                dfsTraversal(i,Graph,vis);
            }
        }
    }
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> Graph = new ArrayList<ArrayList<Integer>>();
        int NumberOfvertices = 5;
        for(int i=0; i<NumberOfvertices; i++) {
            Graph.add(new ArrayList<Integer>());
        }
        Graph.get(0).add(2);
        Graph.get(0).add(3);
        Graph.get(2).add(0);
        Graph.get(3).add(0);
        Graph.get(4).add(3);
        Graph.get(3).add(4);
        Graph.get(2).add(3);
        Graph.get(3).add(2);

        boolean vis[] = new boolean[NumberOfvertices];
        
        //for all the components
        for(int i=0; i<NumberOfvertices;i++){
            if(!vis[i]){
                dfsTraversal(i,Graph,vis);
            }
        }
    }
}
