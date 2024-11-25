class Solution {
public:


    void dfs(int src,map<int,bool>&visited,unordered_map<int,list<int>>&adjList){

        visited[src] = true;

        for(auto nbr:adjList[src]){

            if(!visited[nbr]){
                dfs(nbr,visited,adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>>adjList;
        map<int,bool>visited;
        int count = 0;
        // construction of the graph
        for(int i = 0;i<isConnected.size();i++){

            for(int j = 0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){

                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }


        for(int i=0;i<adjList.size();i++){

            if(!visited[i]){
                count++;
                dfs(i,visited,adjList);
            }
        }

        return count;
        
    }
};