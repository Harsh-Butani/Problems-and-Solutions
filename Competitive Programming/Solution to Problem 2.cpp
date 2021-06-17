#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define test           \
    ll t;              \
    scanf("%lld", &t); \
    while (t--)

bool good(ll a[], ll n, ll k, ll sum)
{
    ll c = 0, s = 0;
    for (ll i = 0; i < n; i++)
    {
        s += a[i];
        if (s >= sum)
        {
            c++;
            s = 0;
        }
    }
    return c >= k;
}

int main()
{
    test
    {
        ll n, k;
        cin >> n >> k;
        ll a[n], sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        ll lo = 0, hi = sum, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            bool b1 = good(a, n, k, mid);
            bool b2 = good(a, n, k, mid + 1);
            if (b1 && !b2)
            {
                cout << mid << '\n';
                break;
            }
            else if (!b1)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
    }
    return 0;
}