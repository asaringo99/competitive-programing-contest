#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int z ;
bool A[26][26], B[26][26][26];

map<vector<int>, TP> mp;

void solve(){
    int n, m;
    cin >> n >> m;
    rep(i,26) rep(j,26) A[i][j] = false;
    rep(i,26) rep(j,26) rep(k,26) B[i][j][k] = false;
    rep(i,n){
        string s;
        cin >> s;
        rep(j,m){
            vector<int> a, b;
            if(j + 1 < m) rep(k,2) a.push_back(s[j+k]-'0');
            if(j + 2 < m) rep(k,3) b.push_back(s[j+k]-'0');
            if(a.size() == 2) A[a[0]][a[1]] = true;
            if(b.size() == 3) B[b[0]][b[1]][b[2]] = true;
            mp[a] = {j+1,j+2,i+1};
            mp[b] = {j+1,j+3,i+1};
        }
    }
    string S;
    cin >> S;
    vector<int> s;
    for(char u : S) s.push_back(u-'0');
    vector<bool> dp(m+1,false);
    vector<int> sp(m+1,-1);
    dp[0] = true;
    rrep(i,1,m){
        if(!dp[i-1]) continue;
        if(A[s[i-1]][s[i]]){
            dp[i+1] = true;
            sp[i+1] = i-1;
        }
        if(i + 1 < m  && B[s[i-1]][s[i]][s[i+1]]){
            dp[i+2] = true;
            sp[i+2] = i-1;
        }
    }
    if(!dp[m]){
        cout << -1 << endl;
        return;
    }
    vector<int> vec;
    int t = m;
    while(t != -1){
        vec.push_back(t);
        t = sp[t];
    }
    reverse(vec.begin(),vec.end());
    int k = vec.size();
    cout << k - 1 << endl;
    rep(i,k-1){
        int d = vec[i+1] - vec[i];
        vector<int> res;
        rrep(j,vec[i],vec[i]+d) res.push_back(s[j]);
        auto[l,r,id] = mp[res];
        cout << l << " " << r << " " << id << endl;
    }
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}