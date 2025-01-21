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
class Solution
{
public:
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    unordered_set<TreeNode *> leaf;
    int ans = 0;

    void BFS(TreeNode *leafnode, int dist)
    {
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited;

        q.push(leafnode);
        int distance = 0;
        visited[leafnode] = true;

        while (distance <= dist)
        {
            int size = q.size();

            while (size--)
            {
                TreeNode *front = q.front();
                q.pop();

                if (leafnode != front && leaf.count(front))
                    ans++;

                for (auto i : adj[front])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }

                    // if(leaf.count(i) )
                    //     ans++;
                }
            }
            distance++;
        }
    }

    void makegraph(TreeNode *root, TreeNode *prev)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            leaf.insert(root);
        if (prev != NULL)
        {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makegraph(root->left, root);
        makegraph(root->right, root);
    }
    int countPairs(TreeNode *root, int distance)
    {
        makegraph(root, NULL);

        for (auto i : leaf)
        {
            BFS(i, distance);
        }

        return ans / 2;
    }
};