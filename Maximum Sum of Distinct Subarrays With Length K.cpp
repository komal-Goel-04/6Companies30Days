class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans = 0;
        unordered_map<int, int> m;
        long long sum = 0;

        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            m[nums[r]]++;
            sum += nums[r];

            if (r - l + 1 > k)
            {
                sum -= nums[l];
                m[nums[l]]--;

                if (m[nums[l]] == 0)
                    m.erase(nums[l]);

                l++;
            }

            if (m.size() == k && (r - l + 1) == k)
                ans = max(ans, sum);
        }
        return ans;
    }
};