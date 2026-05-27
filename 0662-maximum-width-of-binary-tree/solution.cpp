class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Use unsigned long long to safeguard against large indices before normalization
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // Start indexing from 0
        
        unsigned long long max_width = 0;

        while (!q.empty()) {
            int n = q.size();
            // The index of the first node in the current level
            unsigned long long level_min = q.front().second; 
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                // Subtract level_min to normalize indices to 0 and prevent overflow
                unsigned long long idx = q.front().second - level_min; 
                q.pop();

                if (i == 0) first = idx;   // First node of the current level
                if (i == n - 1) last = idx; // Last node of the current level

                if (node->left != nullptr) {
                    q.push({node->left, 2 * idx + 1});
                }
                if (node->right != nullptr) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
            // Calculate width using the current level's nodes
            max_width = max(max_width, last - first + 1);
        }
        
        return max_width;
    }
};
