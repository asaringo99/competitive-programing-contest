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

void solve(){
    int a, b, c, d;
    string S;
    cin >> a >> b >> c >> d >> S;
    int n = S.size();
    vector<int> odda, oddb, evea, eveb;
    int id = 0, bd = 0;
    while(id < n){
        bd = id;
        while(id < n - 1 && S[id] != S[id + 1]){
            id++;
        }
        if(bd != id) {
            // cout << bd << " " << id << endl;
            if((id - bd) % 2 == 0 && S[bd] == 'A') odda.push_back(id - bd);
            if((id - bd) % 2 == 0 && S[bd] == 'B') oddb.push_back(id - bd);
            if((id - bd) % 2 == 1 && S[bd] == 'A') evea.push_back(id - bd + 1);
            if((id - bd) % 2 == 1 && S[bd] == 'B') eveb.push_back(id - bd + 1);
        }
        id++;
        while(id < n && S[id] == S[id + 1]){
            if(S[id] == 'A') a--;
            if(S[id] == 'B') b--;
            id++;
        }
        if(id == n - 1){
            if(S[id] == 'A') a--;
            if(S[id] == 'B') b--;
            id++;
        }
    }
    a -= odda.size();
    b -= oddb.size();
    // cout << a << " " << b << " " << c << " " << d << endl;
    sort(evea.begin(),evea.end());
    sort(eveb.begin(),eveb.end());
    for(int u : evea){
        int x = u / 2;
        if(c >= x) c -= x;
        else{
            x -= c;
            x--;
            a--;
            b--;
            c = 0;
            if(d >= x){
                d -= x;
                x = 0;
            }
            else{
                x -= d;
                d = 0;
            }
            a -= x;
            b -= x;
        }
    }
    // cout << a << " " << b << " " << c << " " << d << endl;
    for(int u : eveb){
        int x = u / 2;
        if(d > x) d -= x;
        else{
            x -= d;
            x--;
            a--;
            b--;
            d = 0;
            if(c >= x){
                c -= x;
                x = 0;
            }
            else{
                x -= c;
                c = 0;
            }
            a -= x;
            b -= x;
        }
    }
    // cout << a << " " << b << " " << c << " " << d << endl;
    int r = c + d;
    for(int u : odda){
        int x = u / 2;
        r -= x;
    }
    for(int u : oddb){
        int x = u / 2;
        r -= x;
    }
    if(r == 0 && a == 0 && b == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    // for(int u : odda) cout << u << " "; cout << endl;
    // for(int u : oddb) cout << u << " "; cout << endl;
    // for(int u : evea) cout << u << " "; cout << endl;
    // for(int u : eveb) cout << u << " "; cout << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}