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


// Time complexity for all the problems below:
// Since we are visiting all nodes exactly nodes. Assuming, we have n nodes in the tree. 
// Time complexity: O(n)
// And space complexity: O(h) where h is the height of the tree (balanced) or O(log(n))  
// For skewed tree, space complexity: O(n)

struct Node {
    int val;
    Node *left, *right;
}

int cntNodes(Node *root){
    if (root == NULL) return 0; 
    int leftCnt = cntNodes(root->left); 
    int rightCnt = cntNodes(root->right); 
    return leftCnt + rightCnt + 1;
}

bool isMirror(Node n1, Node n2) {
    // we did a pre-order traversal here. We failed fast! - checked if root nodes are equal or not first 
    // that saved us from lot of computation in case trees are not mirrors because root nodes are diff 
    // However, in post order traversal, we still need to do a lot of computation because root nodes will
    // be checked at last
    // base case 
    if (n1 == NULL and n2 == NULL) return true;
    if (n1 == NULL or n2 == NULL) return false;
    // recursive code 
   if (n1.val != n2.val) return false;
   return isMirror(n1.left, n2.right) and isMirror(n1.right, n2.left);
}


int heightOfBinaryTree(Node *root){
    // calculating height with respect to number of edges 
    // if (root == NULL) return 0; 
    // int leftHeight = heightOfBinaryTree(root->left); 
    // int rightHeight = heightOfBinaryTree(root->right); 
    // return max(leftHeight, rightHeight) + 1;

    // with respect to number of nodes 
    if (root == NULL) return 0; 
    int leftHeight = heightOfBinaryTree(root->left); 
    int rightHeight = heightOfBinaryTree(root->right); 
    return max(leftHeight, rightHeight)+1;
}

int diameterOfBinaryTree(Node *root){ // longest path between any two nodes - usually two leaf nodes
    // in skewed tree, not between leaf nodes but between the root and the leaf node 
    // here diameter is calculated with respect to number of edges
    if (root == NULL) return 0; 

    int leftHeight = heightOfBinaryTree(root->left); 
    int rightHeight = heightOfBinaryTree(root->right); 
    return leftHeight + rightHeight + 2;

    // but the above code is wrong if root node is not part of diameter
}

int diameterCorrected(Node *root){
    if (root == NULL) return -1; 
    int diamLeft = diameterCorrected(root->left); // using diameterCorrected fn here
    int diamRight = diameterCorrected(root->right);  
    int leftHeight = heightOfBinaryTree(root->left); 
    int rightHeight = heightOfBinaryTree(root->right); // using heighOfBinaryTree fn here
    return max(diamLeft, diamRight, leftHeight + rightHeight + 2);

    // time complexity - O(n^2) --> not optimal
}

struct Data {
    // constructor 
    int diam;
    int height;
    Data(int diam, int height){
        this->diam = diam;
        this->height = height;
    }
}

Data diameterOptimised(Node *root){
    // will return a class/struct containing both diameter and height
    if (root == NULL) return Data(-1, 0); 
    Data leftData = diameterOptimised(root->left); 
    Data rightData = diameterOptimised(root->right); 
    return Data(max(leftData.diam, rightData.diam, leftData.height + rightData.height + 2), max(leftData.height, rightData.height) + 1);
}

// New Q -> You are given traversals of a tree - preorder and inorder traversals. Construct the binary tree 
// (assume that there are no duplicates in the tree)

void solve() {

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