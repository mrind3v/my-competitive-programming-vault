#ifdef TOWRIST
#define debug(...) cout << "[" << #_VA_ARGS_ << "]:", debug_out(_VA_ARGS_);
#else
#define debug(...) ;
#endif

#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        stream << vec[i];
        if (i != vec.size() - 1)
            stream << ' ';
    };
    return stream;
}
template <typename T>
std::istream &operator>>(std::istream &stream, vector<T> &vec)
{
    for (T &x : vec)
        stream >> x;
    return stream;
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr)
{
    stream << pr.first << ' ' << pr.second;
    return stream;
}
template <typename T, typename U>
std::istream &operator>>(std::istream &stream, pair<T, U> &pr)
{
    stream >> pr.first >> pr.second;
    return stream;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(char c)
{
    string s;
    s += c;
    return s;
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "1" : "0"); }
string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cout << " " << to_string(H);
    debug_out(T...);
}

#define int long long
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sorta(a) sort(a.begin(), a.end())
#define sortar(a) sort(a.rbegin(), a.rend())
#define reva(a) reverse(a.begin(), a.end())
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define v vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define setn(n) cout << fixed << setprecision(n)
#define pi pair<int, int>
#define double long double
#define ff first
#define ss second
#define pb push_back
#define bit(num, i) (num & (1ll << i))
#define no cout << "NO" << "\n"
#define yes cout << "YES" << "\n"
#define space " "

using pii = pair<int, int>;
const bool multipleTestCases = false;

// Q. Do prime factorization of a number N and also print them;

// thought - we can find all primes till sqrt(N). There can't be primes larger than sqrt(N) that
// multiply together and give prime

void primeFactorization(int n)
{
    vector<int> primes;
    int limit = sqrt(n);
    // generate all primes upto sqrt(n); -- SIEVE (TC - O(nlog(logn)) for input n)
    // here TC - O(sqrt(n)loglogsqrt(n))
    vector<bool> isPrime(limit+1, true);
    for (int i=2; i<=limit; i++){
        if (isPrime[i]){
            primes.pb(i);
            for (int j=i*i; j<=limit; j+=i){
                isPrime[j]=false;
            }
        }
    }
    // keep dividing n by prime p till n becomes 1
    // TC - by prime number theorem - no. of primes of a number n is n/logn
    // here TC - sqrt(n)/logsqrt(n)
    for (auto it : primes){ // "it" will represent each element in the primes array
        while (n%it==0){
            cout<<it<<space; 
            n/=it;
        }
        // overall we divide n by p logn number of times
        // so TC - O(logsqrt(n)+sqrt(n)/logsqrt(n))
    }
    if (n>1) cout<<n<<space;
    // overall TC = max(O(sqrt(n)loglogsqrt(n)) + (sqrt(n)/logsqrt(n)))
}

void solve()
{
    int n=12;
    primeFactorization(n);
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    multipleTestCases and cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}