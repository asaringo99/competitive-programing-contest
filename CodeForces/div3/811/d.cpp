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
typedef tuple<ll,ll,ll> TP ;
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

const int inf = 1e9;

// kmp をやるための前計算
vector<int> makeTable(const string& s) {
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while(j >= 0 && s[i] != s[j]) j = ret[j] ;
        j++ ;
        ret[i+1] = j ;
    }
    return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const string& str, const string& word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m+i < n) {
        if (word[i] == str[m+i]) {
            if (++i == (int)(word.size())) {
                ret.push_back(m);
                m = m+i-table[i];
                i = table[i];
            }
        }
        else {
            m = m+i-table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}

int t;

void solve(){
    int n, m;
    string S;
    cin >> S;
    n = S.size();
    cin >> m;
    vector<string> A(m);
    vector<P> vec(n,P(0,-1));
    rep(i,m) cin >> A[i];
    rep(i,m){
        vector<int> ret = kmp(S,A[i]);
        for(int u : ret) chmax(vec[u],P(A[i].size(), i));
    }
    vector<int> dp(n+1,inf);
    vector<int> sp(n+1,-1);
    dp[0] = 0;
    rrep(i,1,n+1){
        auto[s, id] = vec[i-1];
        rep(j,s) {
            if(dp[i+j] > dp[i-1] + 1){
                dp[i+j] = dp[i-1] + 1;
                sp[i+j] = i-1;
            }
        }
    }
    if(dp[n] == inf) pt(-1);
    else {
        pt(dp[n]);
        int x = sp[n];
        while(x != -1){
            cout << vec[x].second + 1 << " " << x + 1 << endl;
            x = sp[x];
        }
    }
}

int main(){
    cin >> t ;
    rep(i,t) solve();
}