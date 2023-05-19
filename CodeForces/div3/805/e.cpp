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

int z ;

void solve(){
    int n;
    cin >> n;
    multiset<P> A, B;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(a > b) swap(a,b);
        A.insert({a,b});
        B.insert({b,a});
    }
    set<int> X, Y;
    rep(i,n) X.insert(i), Y.insert(i);
    int x = 0;
    rep(i,n){
        auto at = A.lower_bound({x,-1});
        auto bt = B.lower_bound({x,-1});
        auto ct = A.begin();
        if(at != A.end() && (*at).first == x){
            auto[s,t] = *at;
            if(i % 2 == 0){
                if(X.count(s)) X.erase(s);
                else{
                    cout << "NO" << endl;
                    return;
                }
                if(X.count(t)) X.erase(t);
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            else{
                if(Y.count(s)) Y.erase(s);
                else{
                    cout << "NO" << endl;
                    return;
                }
                if(Y.count(t)) Y.erase(t);
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            A.erase(A.find({s,t}));
            B.erase(B.find({t,s}));
            x = t;
        }
        else if(bt != B.end() && (*bt).first == x){
            auto[s,t] = *bt;
            if(i % 2 == 0){
                if(X.count(s)) X.erase(s);
                else{
                    cout << "NO" << endl;
                    return;
                }
                if(X.count(t)) X.erase(t);
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            else{
                if(Y.count(s)) Y.erase(s);
                else{
                    cout << "NO" << endl;
                    return;
                }
                if(Y.count(t)) Y.erase(t);
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            B.erase(B.find({s,t}));
            A.erase(A.find({t,s}));
            x = t;
        }
        else{
            auto[s,t] = *ct;
            if(i % 2 == 0){
                if(X.count(s)) X.erase(s);
                else{
                    cout << "NO" << endl;
                    return;
                }
                if(X.count(t)) X.erase(t);
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            else{
                if(Y.count(s)) Y.erase(s);
                else{
                    cout << "NO" << endl;
                    return;
                }
                if(Y.count(t)) Y.erase(t);
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            A.erase(A.find({s,t}));
            B.erase(B.find({t,s}));
            x = t;
        }
    }
    if(X.size() || Y.size()) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    cin >> z ;
    rep(i,z) solve();
}