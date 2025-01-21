/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int peakindex(MountainArray &mountainArr, int n)
    {
        int l = 0, r = n - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int binarySearch(MountainArray &mountainArr, int target, int start, int end, bool ascending)
    {
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal == target)
                return mid;

            if (ascending)
            {
                if (midVal > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (midVal < target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int pivot = peakindex(mountainArr, n);

        int index = binarySearch(mountainArr, target, 0, pivot, true);
        if (index != -1)
            return index;

        return binarySearch(mountainArr, target, pivot + 1, n - 1, false);
    }
};