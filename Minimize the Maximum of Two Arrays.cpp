typedef long long int ll;
class Solution
{
public:
    ll LCM(ll d1, ll d2)
    {
        return (d1 * d2) / __gcd(d1, d2);
    }
    bool ispossible(ll maxvalue, int d1, int d2, int c1, int c2)
    {
        ll valid = maxvalue;

        ll bothinvalid = maxvalue / LCM(d1, d2);
        ll arr1invalid = (maxvalue / d1) - bothinvalid;
        ll arr2invalid = (maxvalue / d2) - bothinvalid;
        ll canbeinany = maxvalue - arr2invalid - arr1invalid - bothinvalid;

        if (arr2invalid < c1)
            canbeinany -= (c1 - arr2invalid);
        if (arr1invalid < c2)
            canbeinany -= (c2 - arr1invalid);

        // return canbeinany + arr2invalid + arr1invalid >= c1 + c2;
        return canbeinany >= 0;
    }
    int minimizeSet(int d1, int d2, int c1, int c2)
    {
        ll l = 1, r = 2e9;
        while (l < r)
        {
            ll m = (l + r) / 2;

            if (ispossible(m, d1, d2, c1, c2))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};