class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size(), mid = 0;

        // for(int i=0;i<n;i++)
        //     cout<<nums[i]<<"  ";

        mid = ((n - 1) / 2) + 1;

        // while(nums[mid] == nums[0])
        // {
        //     mid++;
        //     if(mid >= n)
        //         break;
        // }
        int i = 0, maxi = mid;

        // cout<<mid<<endl;
        // if(mid < n)
        //     cout<<"mid = "<<nums[mid]<<endl;

        while (i < maxi)
        {
            ans.push_back(nums[i]);
            if (mid < nums.size())
                ans.push_back(nums[mid]);
            i++;
            mid++;
        }

        while (i < maxi)
        {
            ans.push_back(nums[i]);
            i++;
        }
        nums = ans;
    }
};