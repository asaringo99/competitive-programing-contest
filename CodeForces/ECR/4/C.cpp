#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define all(a) a.begin(), a.end()
#define endl "\n"

map<char,int> mp;

void solve(){
    string S;
    cin >> S;
    int n = S.size();
    mp['<'] = 0;
    mp['>'] = 1;
    mp['{'] = 2;
    mp['}'] = 3;
    mp['['] = 4;
    mp[']'] = 5;
    mp['('] = 6;
    mp[')'] = 7;
    int res = 0;
    vector<int> vec;
    rep(i,n){
        int u = mp[S[i]];
        if(u % 2 == 0){
            vec.push_back(u);
        }
        else{
            if(vec.empty()){
                cout << "Impossible" << endl;
                return;
            }
            char s = vec.back(); vec.pop_back();
            if(s / 2 != u / 2) {
                res++;
            }
        }
    }
    if(vec.size() > 0){
        cout << "Impossible" << endl;
        return;
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}