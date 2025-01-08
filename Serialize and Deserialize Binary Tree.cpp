/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        string ans;

        if (root == NULL)
            return ans;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front == NULL)
                ans += "#,";
            else
                ans += to_string(front->val) + ',';

            if (front != NULL && front->left)
                q.push(front->left);
            else if (front != NULL)
                q.push(NULL);

            if (front != NULL && front->right != NULL)
                q.push(front->right);
            else if (front != NULL)
                q.push(NULL);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stack<TreeNode *> st;

        if (data.length() == 0)
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
                front->left = NULL;
            else
            {
                TreeNode *temp = new TreeNode(stoi(str));
                front->left = temp;
                q.push(temp);
            }

            getline(s, str, ',');
            if (str == "#")
                front->right = NULL;
            else
            {
                TreeNode *temp = new TreeNode(stoi(str));
                front->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));