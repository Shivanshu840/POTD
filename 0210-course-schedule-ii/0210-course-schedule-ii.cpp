class Solution {
public:

    unordered_map<int,list<int>>adjList;
    void topoSort(int n, vector<int>&ans){

        unordered_map<int,int>indeg;
        queue<int>q;

        for(auto itr:adjList){
            for(auto nbr:itr.second){
                indeg[nbr]++;
            }
        }

        for(int i = 0; i < n; i++){

            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            
            for(auto itr:adjList[frontNode]){
                
                indeg[itr]--;

                if(indeg[itr] == 0){
                    q.push(itr);
                }
            }
        }


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();

        for(int i = 0; i < n; i++){

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        vector<int>ans;
        
        topoSort(numCourses,ans);

        if(ans.size() == numCourses){
            return ans;
        }

        return {};
        
    }
};