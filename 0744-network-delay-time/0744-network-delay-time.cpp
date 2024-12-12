class Solution {
public:
    unordered_map<int,list<pair<int,int>>>adjList;

    void shortestPath(int src,vector<int>&dist){
        set<pair<int,int>>st;
        st.insert({0,src});

        dist[src] = 0;

        while(!st.empty()){
            auto frontNode = *(st.begin());
            st.erase(st.begin());

            int nodeDist = frontNode.first;
            int node = frontNode.second;

            for(auto nbr: adjList[node]){

                if(nodeDist + nbr.second < dist[nbr.first]){

                    //check kar lenge set mein already present to nhii hai

                    auto result = st.find({dist[nbr.first],nbr.first});

                    //if present then erase this entry
                    if(result != st.end()){

                        st.erase(result);
                    }

                    dist[nbr.first] = nodeDist + nbr.second;
                    st.insert({dist[nbr.first],nbr.first});
                }
            }


        }

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Build the adjList 
        for(int i = 0; i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adjList[u].push_back({v,w});
        }

         vector<int>dist(n+1,1e9);

         shortestPath(k,dist);

         int maxi = INT_MIN;

         for(int i =1;i<=n;i++){

            if(dist[i]==1e9) return -1;

            maxi = max(dist[i],maxi);
         }

         return maxi;



        
    }
};