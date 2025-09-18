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

/*
Idea:

initilly color[all nodes]=1 

dfs(starting_node):
    color[starting_node]=2
    for (for all x which is a neighbour node of starting_node):
        if color[x]==2:
            dfs(x)
    // after visiting starting_node and all its neighbours
    dfs[starting_node]=3


                forward edge
node1 (color=2) -----------> node2 (color=1) - exploring the neighbour of node1 for the first time - will be
                                               visited by dfs

                back edge
node1 (color=2) -----------> node2 (color=2) - we do have a cycle - not visited by dfs
There lookout for back edges in the graph!

                cross edge
node1 (color=2) -----------> node2 (color=3) - looks like a cycle, but no! - not visited by dfs
*/

vvi g;
vi color;
bool isCycle = 0;
vi parent;
vi anyCycle;
void dfsDetectCycle(int node, int par){
    color[node]=1;
    parent[node]=par; // this will store the parent of each node
    for (auto neigh : g[node]){
        if (color[neigh]==1) {
            // forward edge - call dfs

            // passing the parent of a neighbour, which would be assigned later in the recursive call
            dfsDetectCycle(neigh, node); 
        }
        else if (color[neigh]==2) {
            // back edge (temp -> neigh) - a cycle!
            
            // storing the cycle path logic 
            if (isCycle==0){ // the first time we see a cycle - since we output the first cycle we see!
                int temp = node;
                while (temp!=neigh){ 
                    // push the node (the neigh of which forms a back edge) 
                    anyCycle.pb(temp);
                    // keep going to parent
                    temp = parent[temp]
                }
                anyCycle.pb(temp); // storing neigh as well once reached
            }
            isCycle=1;
        }
        else if (color[neigh]==3) {
            // cross edge - do nothing!
        }
    }
}

void solve() {
    int n,m; cin>>n>>m;
    g.resize(n+1);
    color.assign(n+1,1);
    for (int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        // we are inputting directed graph
        g[a].pb(b);
    }

    // we shall run dfs for each node. We cannot directly start dfs from a random node as the graph may
    // not be fully connected, so we might not explore a cycle even if there is if we start dfs from a node
    // which belongs to a component that doesn't have a cycle
    for (int i=1; i<=n; i++){
        // if not visited - meaning color=1
        if (color[i]==1){
            dfsDetectCycle(i,0); // let parent of node 1 be 0
        }
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