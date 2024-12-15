class Solution {
public:
    unordered_map<int,list<pair<int,int>>>adjList;
     void solve(int n,int dest,int src,int k,vector<int>&dist){
        dist[src] = 0;
        queue<pair<int,pair<int,int>>>st;
        st.push({0,{src,0}}); // queue ke andr stop and src or distance ko push kar denge

        while(!st.empty()){

            auto frontNode = st.front();
            st.pop();
            int stop = frontNode.first;
            int node = frontNode.second.first;
            int distance = frontNode.second.second;

            if(stop>k) continue;

            for(auto nbr:adjList[node]){
                if(distance+nbr.second<dist[nbr.first] && stop<=k){ //yja pe bs ek extra condition lga lenge stop<=k hoga tabhi update karenge warna nhii kerenge
                    dist[nbr.first] = nbr.second + distance;
                    st.push({stop+1,{nbr.first,dist[nbr.first]}});
                }
            }
            
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9) dist[i] = -1;
        }

    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int dist = flights[i][2];

            adjList[u].push_back({v,dist});
        }

      vector<int>dist(n,1e9);
      solve(n,dst,src,k,dist);

        for(auto itr:dist){
            cout<<itr<<" ";
        }


        return dist[dst];

        
    }
};