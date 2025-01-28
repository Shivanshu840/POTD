class Solution {
public:
    unordered_map<int,list<int>>adjList;
    vector<int>ans;
    vector<vector<int>>res;

    void dfs(int src,int target){

        ans.push_back(src);
        if(src == target){
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        for(auto nbr: adjList[src]){
            
            
               dfs(nbr,target);
            
        }
        ans.pop_back();
       

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<graph[i].size();j++){

                int u = i;
                int v = graph[i][j];

                adjList[u].push_back(v);
            }
        }

        dfs(0,n-1);

        return res;


        
    }
};