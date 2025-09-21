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

// MSSP idea (Monsters problem):
/*
For "every" node, find the min dist (shortest path) to "any" of the source nodes

How to solve this problem?

Create a super source node, connect it to each of the source node and run BFS from it. Result? we will get
min distance between all nodes (of interest, say S) and the super node. Say source node is E and super source
is E_super. Then min_dist(E_super, a particular S) will be equal to 1+min_dist( any E,particular S) since
all Es (source nodes) are just 1 distance away from the super source node E_super.

More intuitively, after running the mssp algo (tweaked bfs), we get, for each node, the distance to the closest
source node in the same time complexity as normal bfs in a grid - i.e. O(N*M)

In person,monster,exit problem. Which is the super node?
Ans - For "every" node (including exit nodes), we want "the one" closest monster. So monster is super here.
So we shall keep all monsters in queue at once with dist 0 instead of keeping super monster with dist 0
About the person, we can do a simple bfs - to know the distance between that person to all nodes in the grid

trick to remember - whichever variable we want the closest/shortest dist to - make that super node - in this case,
we wanted the closest monster for every node, so it is super.

*/
int n,m;
v<char> dir = {'U', 'D', 'L', 'R'}; 
vi dx = {-1,1,0,0}; // U, D, L, R
vi dy = {0,0,-1,1};
v<string> g;
vvi monsterTime;
v<v<bool>> vis;
v<v<pii>> parent; 
queue<pii> q;
vvi dist;


bool isValid(int x, int y) {
    if (x>=1 && x<=n && y>=0 && y<=m && g[x][y]!='#'){
        return true;
    }
    else {
        return false;
    }
}

v<pii> neigh(pii node){
    v<pii> neighbours; 
    for (int k=0; k<4; k++){
        // will go through all neighbouring cells of the given node
        int nx = node.ff + dx[k]; // if this node has coords x,y --> neighbour coords will be nx and ny
        int ny = node.ss + dy[k];
        // check if its valid 
        if (isValid(nx,ny)) {
            neighbours.pb({nx,ny});
        }
    }
}

void bfsMonster() {
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // going thru each cell, wherever we find a monster 'M'
            if (g[i][j]=='M'){
                // we store the coordinate of the monster in the queue
                q.push({i,j}); 
                // and for all monsters we find, we initialise the time/dist for that cell = 0
                // as initially, all monsters in the grid will be at time 0 in their respective cells
                monsterTime[i][j]==0;
            }
        }
    }

    while (!q.empty()){
        pii node = q.front(); // here node is a monster only
        auto [x,y] = node;
        q.pop();
        for (auto child : neigh(node)){
            int nx = child.ff; 
            int ny = child.ss;
            // if the monster time/dist in neigh cell is greater than time/dist of current cell
            if (monsterTime[nx][ny] > monsterTime[x][y]+1){
                // we shall relax that edge and update
                monsterTime[nx][ny] = monsterTime[x][y]+1;
                q.push({nx,ny});
            }
        }

    }
}

void bfsA(pii start, pii end) { // passing starting node as input
    q.push(start);
    vis[start.ff][start.ss] = true;
    bool escaped = false; 
    while (!q.empty() && !escaped){
        pii node = q.front();
        auto [x,y] = node;
        q.pop();
        for (auto child : neigh(node)){
            int nx = child.ff; 
            int ny = child.ss;
            if (!vis[nx][ny] && dist[x][y]+1 < monsterTime[nx][ny]){
                vis[nx][ny] = true; 
                dist[nx][ny] = dist[x][y]+1;
                parent[nx][ny] = node; 
                q.push({nx,ny});
            }
        }
    }

}

void solve() {
    cin>>n>>m;
    monsterTime.assign(n+1, vi(m+1, INT_MAX));
    vis.assign(n+1, v<bool>(m+1, false));
    parent.assign(n+1, v<char>(m+1));
    dist.assign(n+1, vi(m+1,INT_MAX)); // for person A 
    // reading the grid 
    for (int i=1; i<=n; i++){
        cin>>g[i];
    }

    // step1: Multi Source BFS for all monsters
    bfsMonster();


    // step2: start bfs from A avoiding monsters

    // we need to initialise starting coord (from where we will start bfs) and ending coord (for path tracing)
    pii start = {-1,-1};
    pii end = {-1,-1};
    for (int i=1; i<=n; i++){
        for (int j=1; j<m; j++){
            if (g[i][j]=='A') {
                start = {i,j};
            }
        }
    }

    bfsA(start,end);

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