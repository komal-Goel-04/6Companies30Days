class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size(), length = 0, ans = 0;

        for (int i = 1; i <= n - 2; i++)
        {
            length = 0;
            if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
            {
                int j = i - 1;
                while (j >= 0)
                {
                    if (arr[j] < arr[j + 1])
                        length++;
                    else
                        break;
                    j--;
                }
                j = i + 1;
                while (j < n)
                {
                    if (arr[j] < arr[j - 1])
                        length++;
                    else
                        break;
                    j++;
                }
                ans = max(ans, length + 1);
                // cout<<arr[i]<<"  "<<length+1<<endl;
            }
        }
        return ans;
    }
};