#include <bits/stdc++.h>
using namespace std;

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

struct TrieNode {
    unordered_map<char, TrieNode*> mp;
    bool isEnd=false;
    TrieNode(unordered_map<char,TrieNode*> mp = {}){
        this->mp = mp;
    }
};

TrieNode* insertNode(TrieNode* root, string word){ // TC: O(l)
    if (root==nullptr){
        root = new TrieNode();
    }
    TrieNode* curr = root;
    for (char c : word) {
        if (curr->mp.find(c)==curr->mp.end()) {
            curr->mp[c] = new TrieNode();
        }
        curr = curr->mp[c]; // if c is present or not -> either way we are going to move ahead
    }
    curr->isEnd = true;
    return root;
}

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