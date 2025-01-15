class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;

        set<pair<int, int>> s;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i] + k;
            if (x == nums[i] && m[x] > 1)
                s.insert({nums[i], x});
            else if (x != nums[i] && m[x] >= 1)
                s.insert({nums[i], x});
        }
        return s.size();
    }
};