class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> tempnum = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> ans;
        map<int, int> m;

        for (int i = n - k; i < n; i++)
            m[nums[i]]++;

        for (int i = 0; i < n; i++)
        {
            if (m[tempnum[i]] > 0)
            {
                ans.push_back(tempnum[i]);
                m[tempnum[i]]--;
            }
        }

        return ans;
    }
};