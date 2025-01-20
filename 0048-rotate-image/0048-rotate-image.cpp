class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //pehle transpose nikalenge 
        for(int i=0;i<n;i++){
            for(int j = i; j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // fir sare row ko reverse kardenge tab ho jayega 
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};