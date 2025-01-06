class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        if (k == 1)
            return arr;
        vector<int> ans;
        int maxi = INT_MIN;

        int l = 0, r = 0;
        while (r < arr.size())
        {
            maxi = max(maxi, arr[r]);

            if (r - l + 1 > k)
            {
                if (arr[l] != maxi)
                    l++;
                else
                {
                    maxi = INT_MIN;
                    r = l + 1;
                    l = r;
                    continue;
                }
            }

            if (r - l + 1 == k)
                ans.push_back(maxi);

            r++;
        }
        return ans;
    }
};