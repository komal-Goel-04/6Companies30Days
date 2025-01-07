class Solution
{
public:
    bool isinc(int i, int j, vector<int> &nums)
    {
        int temp = INT_MIN;
        for (int k = 0; k < nums.size(); k++)
        {
            if (k >= i && k <= j)
                continue;

            if (temp == INT_MIN)
                temp = nums[k];
            else if (nums[k] <= temp)
                return false;
            else
                temp = nums[k];
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (isinc(i, j, nums))
                {
                    // cout<<i<<"  "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};