struct Node {
    int count = 0;
    Node* list[26] = {nullptr};  // Array for 26 lowercase English letters
};

class Solution {
private:
    Node* root;
public:
    Solution() {
        root = new Node();
    }

    // Insertion function to add words to the Trie
    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            // If the current character's node doesn't exist, create a new one
            if (node->list[ch - 'a'] == nullptr) {
                node->list[ch - 'a'] = new Node();
            }
            // Increment the count of the current node for this character
            node->list[ch - 'a']->count++;
            // Move to the next node (child)
            node = node->list[ch - 'a'];
        }
    }

    // Search function to calculate prefix score
    int search(const string& word) {
        Node* node = root;
        int preCount = 0;
        for (char ch : word) {
            // Add the count of the current character's node to prefix score
            preCount += node->list[ch - 'a']->count;
            // Move to the next node (child)
            node = node->list[ch - 'a'];
        }
        return preCount;
    }

    // Function to compute the sum of prefix scores for all words
    vector<int> sumPrefixScores(vector<string>& words) {
        // Insert all words into the Trie
        for (auto& word : words) {
            insert(word);
        }

        int n = words.size();
        vector<int> res(n);

        // Calculate prefix score for each word
        for (int i = 0; i < n; i++) {
            int preCount = search(words[i]);
            res[i] = preCount;
        }

        return res;
    }
};