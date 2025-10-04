#ifdef TOWRIST
    #define debug(...) cout << "[" << #_VA_ARGS_ << "]:", debug_out(_VA_ARGS_);
#else
    #define debug(...);
#endif

#include <bits/stdc++.h>
using namespace std;

template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }

#define int long long
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sorta(a) sort(a.begin(), a.end())
#define sortar(a) sort(a.rbegin(), a.rend())
#define reva(a) reverse(a.begin(), a.end())
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define v vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define setn(n) cout << fixed << setprecision(n)
#define pi pair<int, int>
#define double          long double
#define ff              first
#define ss              second
#define pb              push_back
#define bit(num, i)     (num & (1ll << i))
#define no cout<<"NO"<<"\n"
#define space " "
#define ovi optional<vi>
#define yes cout<<"YES"<<"\n"

using pii = pair<int, int>;
const bool multipleTestCases = true;

vi vis;
vvi g;
v<v<pii>> g_weighted; 
int n,m;
const int INF = 1e9;

void bfs(int node) {
    queue<int> q;
    vis.assign(n+1,0);
    vis[node] = 1;
    q.push(node);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : g[node]){
            if (!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

vi dijkstra(int node) {
    priority_queue<pii> pq; 
    vi dist(n+1,INF);
    vis.assign(n+1,0);      
    dist[node] = 0;
    pq.push({0,node});
    while (!pq.empty()) {
        auto [node,d] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = 1;
        for (auto it : g_weighted[node]){
            auto [child,wt] = it;
            if (dist[child] > dist[node] + wt){ 
                dist[child] = dist[node] + wt;
                pq.push({child,-dist[child]});
            }
        }
    }
    return dist;
}


/*
bellman ford algo relaxes 1 edge in 1st iteration, 2 edges in 2nd iteration --> to V-1 edges in the V-1th itern
And since there can only be at max V-1 edges (V - number of vertices in graph) --> we will be able to relax all
edges to find the shortest path even with negative edges.

But the vanilla algo of bellman ford still fails for the presence of negative cycle (but will work in positive
cycle - as we won't visit already visited nodes in cycle due to increasing weight - distance) because in a neg
cycle - the distance/weight keep reducing - we will keep getting shorter distances! Therefore, any node that
is reachable from -ve cycle -> we won't get a true shortest distance from them -> because all of em will have
edge weights as -infinity
*/
void bellman_ford(int src) {
    vi dist(n+1,INF);
    dist[src] = 0;
    for (int i=1; i<=n-1; i++){ // V-1 iterations
        for (int u=1; u<=n; u++){ // go through each node
            for (auto it : g_weighted[u]){
                auto [v,wt] = it;
                if (dist[u] != INF and dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    /*
    How check for negative weight cycle? After running the bellman ford algo V-1 times if i run the algo and we
    find that one of the edges is being relaxed -> we got a cycle! Because the algo says thatwe need at max V-1
    iterations to relax all edges. But if i find any edge being relaxed even after running the algo V-1 times, it
    can only happen in the case of -ve cycle!
    */ 
    for (int u=1; u<=n; u++){
        for (auto it : g_weighted[u]){
            auto [v,wt] = it;
            if (dist[u] != INF and dist[v] > dist[u] + wt){
                cout<<"Negative weight cycle exists\n";
                return;
            }
        }
    }
}

void solve() {
    cin>>n>>m;
    g.resize(n+1);
    for (int i=0; i<m; i++){
        int a,b; cin>>a>>b; 
        g[b].pb(a);
        g[a].pb(b);
    }
    // inputting g_weighted
    for (int i=0; i<m; i++){
         int a,b,w; cin>>a>>b>>w; 
         g_weighted[b].pb({a,w});
         g_weighted[a].pb({b,w});
    }        

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