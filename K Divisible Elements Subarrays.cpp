class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<vector<int>> s;
        int n = nums.size(), ans = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> curr;
            count = 0;
            for (int j = i; j < n; j++)
            {
                curr.push_back(nums[j]);
                if (nums[j] % p == 0)
                    count++;

                if (count <= k)
                    s.insert(curr);
                else
                    break;
            }
        }
        return s.size();
    }
};