class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int sum = 0, f = 0, ans = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            f += i * nums[i];
        }
        ans = max(ans, f);

        for (int i = 1; i < nums.size(); i++)
        {
            f = f + sum - (n * nums[n - i]);
            ans = max(ans, f);
        }

        return ans;
    }
};