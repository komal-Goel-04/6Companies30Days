/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution {
public:
    int  sum = 0;
    bool isbst(TreeNode* root, int small, int large, int &tempsum)
    {
        if(root == NULL)
            return true;

        if(root->val <= small || root->val >= large)
            return false;

        tempsum += root->val;
        bool left = isbst(root->left, small, root->val, tempsum);
        bool right = isbst(root->right, root->val, large, tempsum);

        return left && right;

    }
    void solve(TreeNode* root)
    {
        if(root == 0)
            return ;

        solve(root->left);
        int tempsum = 0;
        if(isbst(root, INT_MIN, INT_MAX, tempsum))
            sum = max(sum, tempsum);
        solve(root->right);
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return sum;
    }
};*/

/*class Solution {
public:
    struct TreeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    int maxSum = 0;

    TreeInfo postOrder(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN}; // An empty tree is a BST
        }

        // Postorder traversal: calculate for left and right subtrees
        TreeInfo left = postOrder(root->left);
        TreeInfo right = postOrder(root->right);

        // Check if the current tree is a BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSum = root->val + left.sum + right.sum;

            // Update the maximum sum
            maxSum = max(maxSum, currentSum);

            // Return info about the current subtree
            return {true, currentSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        // If it's not a BST, return false with dummy values
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        postOrder(root);
        return maxSum;
    }
};*/

/*class Solution {
public:
    int sum = 0;
    unordered_map<TreeNode*, bool> bstCache;
    unordered_map<TreeNode*, int> sumCache;

    bool isbst(TreeNode* root, int small, int large, int& tempsum) {
        if (root == NULL)
            return true;

        // Check if the result is already cached
        if (bstCache.find(root) != bstCache.end()) {
            tempsum = sumCache[root];
            return bstCache[root];
        }

        if (root->val <= small || root->val >= large) {
            bstCache[root] = false;
            sumCache[root] = root->val;
            return false;
        }

        int leftSum = 0, rightSum = 0;
        bool left = isbst(root->left, small, root->val, leftSum);
        bool right = isbst(root->right, root->val, large, rightSum);

        // If both left and right subtrees are BSTs
        if (left && right) {
            tempsum = root->val + leftSum + rightSum;
            bstCache[root] = true;
            sumCache[root] = tempsum;
            return true;
        }

        // Otherwise, this subtree is not a BST
        bstCache[root] = false;
        sumCache[root] = root->val;
        return false;
    }

    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        solve(root->left);
        int tempsum = 0;
        if (isbst(root, INT_MIN, INT_MAX, tempsum))
            sum = max(sum, tempsum);
        solve(root->right);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return sum;
    }
};*/

class Solution
{
public:
    int sum = 0;
    unordered_map<TreeNode *, bool> bstCache;
    unordered_map<TreeNode *, int> sumCache;

    bool isBST(TreeNode *root, int low, int high, int &currentSum)
    {
        if (!root)
        {
            currentSum = 0;
            return true;
        }

        if (root->val <= low || root->val >= high)
        {
            return false;
        }

        int leftSum = 0, rightSum = 0;
        bool leftIsBST = isBST(root->left, low, root->val, leftSum);
        bool rightIsBST = isBST(root->right, root->val, high, rightSum);

        if (leftIsBST && rightIsBST)
        {
            currentSum = root->val + leftSum + rightSum;
            return true;
        }

        currentSum = 0;
        return false;
    }

    void traverse(TreeNode *root)
    {
        if (!root)
            return;

        traverse(root->left);
        int currentSum = 0;
        if (isBST(root, INT_MIN, INT_MAX, currentSum))
        {
            sum = max(sum, currentSum);
        }
        traverse(root->right);
    }

    int maxSumBST(TreeNode *root)
    {
        traverse(root);
        return sum;
    }
};
