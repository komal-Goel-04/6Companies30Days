class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {

        int size1 = arr1.size();
        int size2 = arr2.size();
        int count = 0;

        for (int i = size1 - 1; i >= 0; i--)
        {
            bool flag = false;
            for (int j = 0; j < size2; j++)
            {
                if (abs(arr1[i] - arr2[j]) <= d)
                    break;
                if (j == size2 - 1)
                    flag = true;
            }
            if (flag)
            {
                // cout<<arr1[i]<<"  ";
                count++;
                // break;
            }
        }
        return count;
    }
};