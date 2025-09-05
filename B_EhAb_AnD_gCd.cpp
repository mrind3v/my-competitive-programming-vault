#ifdef TOWRIST
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...);
#endif

#include <bits/stdc++.h>
using namespace std;

// ---------------- Debug Utilities ----------------
template <typename T> ostream &operator<<(ostream &stream, const vector<T> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        stream << vec[i]; if (i + 1 < vec.size()) stream << " ";
    }
    return stream;
}
template <typename T> istream &operator>>(istream &stream, vector<T> &vec) {
    for (T &x : vec) stream >> x;
    return stream;
}
template <typename T, typename U> ostream &operator<<(ostream &stream, const pair<T,U> &p) {
    return stream << p.first << " " << p.second;
}
template <typename T, typename U> istream &operator>>(istream &stream, pair<T,U> &p) {
    return stream >> p.first >> p.second;
}

string to_string(const string &s) { return '"' + s + '"'; }
string to_string(char c) { return string(1, c); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return b ? "1" : "0"; }
template <typename A> string to_string(A v) {
    bool first = true; string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false; res += to_string(x);
    }
    res += "}"; return res;
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H); debug_out(T...);
}

// ---------------- Shortcuts ----------------
#define int long long
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sorta(a) sort(a.begin(), a.end())
#define sortar(a) sort(a.rbegin(), a.rend())
#define reva(a) reverse(a.begin(), a.end())
#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"

// =======================================================
//                NUMBER THEORY UTILITIES
// =======================================================
namespace number_theory {
    using ll = long long;
    const ll MOD = 1e9 + 7;

    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

    bool isprime(ll n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (ll i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    vector<bool> prime;
    void sieve(int n) {
        prime.assign(n+1, true);
        prime[0] = prime[1] = false;
        for (ll p = 2; p * p <= n; p++) if (prime[p])
            for (ll i = p*p; i <= n; i += p) prime[i] = false;
    }

    vector<ll> primelist;
    bool __primes_generated__ = 0;
    void genprimes(int n) {
        sieve(n);
        primelist.clear();
        for (int i = 2; i <= n; i++) if (prime[i]) primelist.pb(i);
        __primes_generated__ = 1;
    }

    vector<ll> factors(ll n) {
        if (!__primes_generated__) {
            cerr << "Call genprimes first!\n"; exit(1);
        }
        vector<ll> facs;
        for (ll p : primelist) {
            if (p*p > n) break;
            while (n % p == 0) {
                facs.pb(p); n /= p;
            }
        }
        if (n > 1) facs.pb(n);
        sort(all(facs));
        return facs;
    }

    vector<ll> getdivs(ll n) {
        vector<ll> divs;
        for (ll i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                divs.pb(i);
                if (i != n/i) divs.pb(n/i);
            }
        }
        sort(all(divs));
        return divs;
    }

    ll modpow(ll a, ll b, ll m = MOD) {
        ll res = 1; a %= m;
        while (b) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    ll modinv(ll a, ll m = MOD) {
        return modpow(a, m - 2, m);
    }

    vector<ll> fact, invfact;
    void init_factorials(int n, ll m = MOD) {
        fact.assign(n+1, 1);
        invfact.assign(n+1, 1);
        for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % m;
        invfact[n] = modinv(fact[n], m);
        for (int i = n-1; i >= 0; i--) invfact[i] = (invfact[i+1] * (i+1)) % m;
    }

    ll nCr(int n, int r, ll m = MOD) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % m * invfact[n-r] % m;
    }
}

using namespace number_theory;

const bool multipleTestCases = true;

void solve() {
    // Your solution here
    int x; cin>>x;
    cout<<1<<" "<<x-1<<endl;

}

signed main() {
    fastIO;
    int t = 1;
    if (multipleTestCases) cin >> t;
    while (t--) solve();
    return 0;
}