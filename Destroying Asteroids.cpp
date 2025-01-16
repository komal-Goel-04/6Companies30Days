class Solution
{
public:
    bool asteroidsDestroyed(long long mass, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > mass)
                return false;
            else
                mass += arr[i];
        }

        return true;
    }
};