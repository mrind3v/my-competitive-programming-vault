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

struct TreeNode{
    string val;
    TreeNode* left;
    TreeNode* right;
};


// Q1. Given a postfix array, make a Binary tree representing the expression in the postfix array
bool isOperand(string str){
    if (str=="+" || str=="-" || str=="/" || str=="*") return true;
    return false;
}

TreeNode* makeTree(v<string> postfix) {
    stack<TreeNode*> st;
    for (string str : postfix){
        if (isOperand(str)){
            TreeNode* root = new TreeNode;
            root->val = str;
            root->right = st.top(); st.pop();
            root->left = st.top(); st.pop();
            st.push(root);
        }
        else {
            st.push(new TreeNode{str,nullptr,nullptr}); 

        }
    }
    return st.empty() ? nullptr : st.top();
}


// Q2. Given a postfix array, evaluate the expression
int handleOp(int& left, int& right, string& op) {
    if (op=="+") return left+right;
    else if (op=="-") return left-right;
    else if (op=="*") return left*right;
    return left/right;
}

int evalPostfix(v<string> postfix, stack<int> st){
    for (string str : postfix) {
        if (isOperand(str)) {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            st.push(handleOp(left, right, str));
        } else {
            st.push(stoi(str));
        }
    }
    return st.top();
}


// Q3. Given a tree that represents an expression -> make a postfix array out of it
void makePostfixArrayFromTree(TreeNode* root, v<string>& postfix) {
    if (root==nullptr) return;
    makePostfixArrayFromTree(root->left, postfix);
    makePostfixArrayFromTree(root->right, postfix);
    postfix.pb(root->val);

}


// Q4. Given the postfix array, get the infix array 
void helper(TreeNode* root, v<string>& infix) {
    if (root==nullptr) return;
    helper(root->left,infix);
    infix.pb(root->val);
    helper(root->right,infix);
}

void makeInfixFromPostfix(v<string>& postfix, v<string>& infix){
    // will use the functions previously made!
    stack<TreeNode*> st;
    TreeNode* root = makeTree(postfix);
    // now that we have the tree of the expression, we can construct the infix array 
    helper(root,infix);
}

// END

void solve() {
    // Q1. Given a postfix array, make a Binary tree representing the expression in the postfix array
    v<string> postfix = {"3","2","+","6","3","/","-3","-", "*"};
    makeTree(postfix);

    // Q2. Given a postfix array, evaluate the expression
    stack<int> st2;
    int result = evalPostfix(postfix,st2);

    // Q3. Given a tree that represents an expression -> make a postfix array out of it
    v<string> postfix;
    TreeNode* root; 
    makePostfixArrayFromTree(root,postfix);

    // Q4. Given the postfix array, get the infix array 
    v<string> postfix2 = {"4","2","+","6","3","/","-3","-", "*"};
    v<string> infix; 
    makeInfixFromPostfix(postfix2,infix);

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