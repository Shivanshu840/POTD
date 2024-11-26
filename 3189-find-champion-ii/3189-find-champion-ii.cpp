class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int>Indegree(n,0);

        for(int i = 0;i<edges.size();i++){

            int u = edges[i][0];
            int v = edges[i][1];

            Indegree[v]++;

        }
        

        int champ = -1;
        int count = 0;

        for(int i = 0;i<n;i++){

            if(Indegree[i]==0){
                champ = i;
                count++;
                if(count>1) return -1;
            }
        }

        return champ;
    }
};