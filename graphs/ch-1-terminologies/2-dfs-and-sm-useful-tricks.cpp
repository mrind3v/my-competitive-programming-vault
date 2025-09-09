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

// adjacency list (global)
vvi g;


// 2. pure dfs with the ability to calc size of component
void dfs(int node, int &numNodes, vi &visited) {
    if (visited[node]) return;
    visited[node]=1;
    numNodes++;
    for (auto neighbour : g[node]){
        if (!visited[neighbour]){
            dfs(neighbour,numNodes,visited);
        }
    }
    
}

// 4.1. dfs for coloring components
// color is not passed by refernce as its value is not changed inside dfs
void dfsColor(int node, int color, vi &visitedCol) {
    if (visitedCol[node]) return;
    visitedCol[node]=color; // visited array will hold color (also a number) instead of 1
    for (auto neighbour : g[node]){
        if (!visitedCol[neighbour]){
            dfsColor(neighbour,color,visitedCol);
        }
    }
}


void solve() {
    // 1. building the adjacency list
    int n,m; cin>>n>>m; // n - number of nodes, m - number of edges

    // visited array
    vi visited(n+1,0);
    // visited color
    vi visitedCol(n+1,0);
    // component size/number of nodes
    int numNodes;

    g.resize(n+1); // this will modify g to have n+1 empty vectors inside a vector
    /*
        [
        [],  
        [],
        .     
        .    n+1 empty vectors inside
        .
        []
        ]
    */
    for (int i=0; i<m; i++){ // for the next m lines, we will be given the exact edges betn two nodes
        int a,b; cin>>a>>b;
        g[a].pb(b);
        // if undirected, we also do..
        g[b].pb(a);
    }

    // 3. calculate the number of components of graph
    int numComp = 0;
    // dummy variable as we don't need size of each componenet but we still need to pass an second arg
    int dummy = 0;
    // go thru each node
    for (int i=1; i<=n; i++){
        // check if it's visited
        if (!visited[i]){
            // run dfs on the node
            dfs(i,dummy,visited);
            // all nodes in the component have been marked. So increase numComp 
            numComp++;
        }
    }
    cout<<"Number of componenets in the graph: "<<numComp<<endl;

    // resetting the visited array, because we gonna run dfs later in count size of component
    fill(visited.begin(), visited.end(), 0);


    // 4. Color each component with a different color (use visited array) 
    int color = 1;
    for (int i=1; i<=n; i++){
        if (!visitedCol[i]){
            dfsColor(i,color,visitedCol);
            color++;
        }
    }
    cout<<visitedCol<<endl;

    // 5. calculate size each component of graph
    int compNumber = 0;
    unordered_map<int,int> compToSize;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            // before starting dfs on a node, set numNodes calculated = 0. Only after dfs, when we have
            // visited all the nodes, we get the final numNodes (which would hv been incremented inside dfs)
            numNodes = 0;
            // our dfs fn has the ability to count size
            dfs(i,numNodes,visited);
            compNumber++;
            compToSize[compNumber]=numNodes;
        }
    }
    for (auto it : compToSize){
        cout<<it.first<<":"<<it.second<<endl;
    }

    // 6. check if two nodes belong to the same component
    int node1, node2; cin>>node1>>node2;
    // if colors of node1 and node2 are different -> they belong to different components
    // since, a while back, we colored each component with a different color
    if (visitedCol[node1]==visitedCol[node2]){
        cout<<"Same"<<endl;
    }
    else {
        cout<<"Different"<<endl;
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