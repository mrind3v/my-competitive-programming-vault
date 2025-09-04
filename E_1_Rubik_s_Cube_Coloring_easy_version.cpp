#include <bits/stdc++.h>
using namespace std;

#define int long long
#define space " "
#define endl "\n"

const int p = 1e9 + 7;

int binExp(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if ((b & 1) == 1)
        {
            ans = ((ans % p) * (a % p)) % p;
        }
        a = ((a % p) * (a % p)) % p;
        b = b >> 1;
    }
    return ans;
}

void solve()
{
    int k;
    cin >> k;
    int twoPowerK = binExp(2,k,p-1);
    int fullExp = ((twoPowerK-2)+(p-1))+(p-1);
    cout << 6 * binExp(4, fullExp, p)%p;
}

signed main()
{
    // fast io
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--) {
    //   solve();
    // }
    solve();
}