class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {

        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par) {

            return;
        }

        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        } else if (rank[x_par] < rank[y_par]) {
            parent[x_par] = y_par;
        } else {
            parent[x_par] = y_par;
            rank[y_par] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {

        rank.resize(26, 0);
        parent.resize(26);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < equations.size(); i++) {

            string str = equations[i];
            char x = str[0] - 'a';
            char y = str[str.size() - 1] - 'a';

            if (str[1] == '=') { // if char are equal then union them

                Union(x, y);
            }
        }

        for (int i = 0; i < equations.size(); i++) {

            string str = equations[i];
            char x = str[0] - 'a';
            char y = str[str.size() - 1] - 'a';

            if (str[1] == '!') { // if char are not equal then union them

                int x_par = find(x);
                int y_par = find(y);

                if (x_par == y_par) {

                    return false;
                }
            }
        }

        return true;
    }
};