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
    unordered_map<int, vector<int>> graph;
    void rootToTree(TreeNode *root, TreeNode *parent = nullptr)
    {
        if (!root)
            return;

        if (parent)
        {
            graph[root->val].push_back(parent->val);
            graph[parent->val].push_back(root->val);
        }

        rootToTree(root->left, root);
        rootToTree(root->right, root);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        rootToTree(root, NULL);

        int time = 0;

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty())
        {
            time++;
            queue<int> temp = q;
            queue<int> emptyQueue;
            swap(q, emptyQueue);

            while (!temp.empty())
            {
                int front = temp.front();
                temp.pop();

                for (auto i : graph[front])
                {
                    if (!visited.count(i))
                    {
                        visited.insert(i);
                        q.push(i);
                    }
                }
            }
        }
        if (time == 0)
            return 0;

        else
            return time - 1;
    }
};