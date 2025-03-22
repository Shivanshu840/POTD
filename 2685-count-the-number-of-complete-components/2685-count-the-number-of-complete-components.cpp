class Solution {
public:
    unordered_map<int,list<int>>adjList;

    void dfs(int src, unordered_map<int,bool>&visited, int &edges, int &node){

        visited[src] = true;
        node++;
        edges += adjList[src].size();
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){

                dfs(nbr,visited,edges,node);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        for(int i = 0;i<edges.size();i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int,bool>visited;
        int count = 0;
        for(int i = 0;i<n;i++){
            
            if(!visited[i]){
                int edges = 0;
                int node = 0;
                dfs(i,visited,edges,node);

                int no_of_edges = node* (node-1)/2;
                if(no_of_edges == edges/2) count++;

            }
        }

        return count;
        
    }
};