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

using state = pair<int, int>;
const bool multipleTestCases = true;

// Type-1 of implicit problem is where we will be given grid with start and end states and we will need to
// find the shortest path start and end. Also, that grid will have obstacles, through which you cannot pass
// and you can movie in specific direction in each step

/*
1. Input can be taken in two ways - i) vector of strings (where each row is a string) OR ii) vector of vector
of characters (where each row is a vector of characters)(used mostly when there are spaces in betn grid posns)

We will take a grid with spaces for this example 

S . # . . .
. . # . . .
. . . . # .
# # # # . .
F . . . . .

*/

// 2. defining the global variables
int n,m;
v<v<char>> grid;
vvi dist;
vvi visited;

// 3. creating some macros and an alias for type pair<int,int> (can also use macro)
// we already have it - using pii = pair<int,int> and also #define ff first and #define ff second
// but we shale replace pii as state - because state will represent our current configuration/node we are currently
// in


// 9. is_valid function to check if a coord is a valid neighbour
bool isValid(int x, int y) {
    if (x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#'){
        return true;
    }
    else return false;
}

// 10. dx, dy arrays for moving around
int dx[] = {1,0,-1,0}; // down, right, up, left 
int dy[] = {0,1,0,-1};

// 8. neighbours function - need to output valid {i,j} neighbouring pairs in the form of a vector 
v<state> neighbours(state node) {
    v<state> neighs; 
    for (int k=0; k<4; k++){ // to give neighbours in all four directions!
        int x = node.ff + dx[k];
        int y = node.ss + dy[k];
        if (isValid(x,y)){
            neighs.pb({x,y});
        }
    }
    return neighs;
}

// 7. bfs function
void bfs(state stNode) {
    dist.assign(n, vi(m,0));
    visited.assign(n,vi(m,0));

    queue<state> q;
    visited[stNode.ff][stNode.ss] = 1;
    dist[stNode.ff][stNode.ss] = 0;
    q.push(stNode);

    while (!q.empty()){
        state node = q.front();
        q.pop();
        for (auto child : neighbours(node)) {
            if (!visited[child.ff][child.ss]){
                visited[child.ff][child.ss]=1;
                dist[child.ff][child.ss]=dist[node.ff][node.ss]+1;
                q.push(child);
            }
        }
    }
}

void solve() {

    // 4. taking the grid as input
    cin>>n>>m;
    // before - [[]] (empty 2d vector); after - [[],[],...[]] (vector with n rows). But each row is empty
    grid.resize(n);
    state st,en; // st and en both are (i,j) pairs in the grid
    for (int i=0; i<n; i++){
        // for each row, we make the grid contain m columns - now the columns will be uninitialised characters
        // before - [[],...,[]]; after - [[.,...,.], [.,...,.],...,[.,...,.]] (n rows with m columns)
        grid[i].resize(m);
        for (int j=0; j<m; j++){
            cin>>grid[i][j];
            if (grid[i][j]=='S'){
                st = {i,j};
            }
            else if (grid[i][j]=='F') {
                en = {i,j};
            }
        }
    }


    // 5. next, we will do a bfs from starting to the ending state
    bfs(st); // will find the distance to each point in grid

    // 6. finally, we shall just print the shortest distance to final state with indices {en.ff,en.ss}
    // edge case - final state is not reachable!
    if (!visited[en.ff][en.ss]){
        cout<<"Final state is not reachable!"<<endl;
    } else {
        cout<<dist[en.ff][en.ss]<<endl;
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