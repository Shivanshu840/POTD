#include <vector>
#include <unordered_map>

using namespace std;

class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> locked;

    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        children.resize(n);
        locked.assign(n, -1);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (locked[num] == -1) {
            locked[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (locked[num] != -1) return false;  // The node must be unlocked
        if (hasLockedAncestor(num)) return false; // Must not have locked ancestors
        if (!hasLockedDescendant(num)) return false; // Must have at least one locked descendant

        unlockDescendants(num);
        locked[num] = user; // Lock the node
        return true;
    }

private:
    bool hasLockedAncestor(int num) {
        while (num != -1) {
            if (locked[num] != -1) return true;
            num = parent[num];
        }
        return false;
    }

    bool hasLockedDescendant(int num) {
        for (int child : children[num]) {
            if (locked[child] != -1 || hasLockedDescendant(child)) {
                return true;
            }
        }
        return false;
    }

    void unlockDescendants(int num) {
        for (int child : children[num]) {
            locked[child] = -1;
            unlockDescendants(child);
        }
    }
};
