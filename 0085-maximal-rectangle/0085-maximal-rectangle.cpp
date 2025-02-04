class Solution {
public:
    void NSR(vector<int>& nsr, vector<int>& heights) {

        stack<pair<int, int>> st;
        int pseudoIndx = heights.size();

        for (int i = heights.size() - 1; i >= 0; i--) {

            if (st.empty())
                nsr.push_back(pseudoIndx);
            else if (!st.empty() && st.top().first < heights[i])
                nsr.push_back(st.top().second);
            else if (!st.empty() && st.top().first >= heights[i]) {

                while (!st.empty() && st.top().first >= heights[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    nsr.push_back(pseudoIndx);
                } else
                    nsr.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
    }
    void NSL(vector<int>& nsl, vector<int>& heights) {

        stack<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {

            if (st.empty())
                nsl.push_back(-1);
            else if (!st.empty() && st.top().first < heights[i])
                nsl.push_back(st.top().second);
            else if (!st.empty() && st.top().first >= heights[i]) {

                while (!st.empty() && st.top().first >= heights[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    nsl.push_back(-1);
                } else
                    nsl.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr;
        vector<int> nsl;

        NSL(nsl, heights);
        NSR(nsr, heights);
        reverse(nsr.begin(), nsr.end());

        vector<int> width;
        int maxArea = INT_MIN;

        for (int i = 0; i < nsr.size(); i++) {

            int diff = nsr[i] - nsl[i] - 1;
            width.push_back(diff);
        }

        for (int i = 0; i < heights.size(); i++) {

            int mul = heights[i] * width[i];
            maxArea = max(maxArea, mul);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>v;

        for(int i = 0; i<m; i++){
            v.push_back(matrix[0][i] - '0');
        }
        int maxArea = largestRectangleArea(v);

        for(int i = 1; i<n;i++){

            for(int j = 0;j<m;j++){

                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }else{

                    v[j] = v[j] + matrix[i][j]-'0';
                }
            }

            maxArea = max(maxArea,largestRectangleArea(v));
        }

        return maxArea;
    }
};