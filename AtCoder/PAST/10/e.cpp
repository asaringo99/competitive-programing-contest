#include <bits/stdc++.h>
using namespace std ;
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
#define endl "\n"

const int dd[] = {0,1,2} ;

string S ;

int main(){
    cin >> S ;
    int val = 0 ;
    rep(i,4){
        val *= 10 ;
        val += S[i] - '0' ;
    }
    rrep(i,5,7){
        val *= 10 ;
        val += S[i] - '0' ;
    }
    rrep(i,8,10){
        val *= 10 ;
        val += S[i] - '0' ;
    }
    bool ok = false ;

    ll ans = 1e16 ;
    rep(i,3) rep(j,3) rep(k,3) {
        rep(a,3) rep(b,3){
            rep(s,3) rep(t,3) {
                if(s == 0 && t == 0) continue;
                if(a == 0 && b == 0) continue;
                if(a == 2) continue;
                set<int> st ;
                st.insert(2) ;
                st.insert(dd[a]) ;
                st.insert(dd[b]) ;
                st.insert(dd[s]) ;
                st.insert(dd[t]) ;
                st.insert(dd[i]) ;
                st.insert(dd[j]) ;
                st.insert(dd[k]) ;
                if(st.size() > 2) continue;
                ll y = 2 * 10000000 + dd[i] * 1000000 + dd[j] * 100000 + dd[k] * 10000 ;
                ll m = dd[a] * 1000 + dd[b] * 100 ;
                ll d = dd[s] * 10 + dd[t] ;
                ll res = y + m + d ;
                if(res >= val){
                    chmin(ans,res) ;
                    ok = true ;
                }
            }
        }
    }
    if(ok){
        string T = to_string(ans) ;
        rep(i,4){
            cout << T[i] ;
        }
        cout << '/' ;
        rrep(i,4,6){
            cout << T[i] ;
        }
        cout << '/' ;
        rrep(i,6,8){
            cout << T[i] ;
        }
        cout << endl ;
    }
    else cout << "3000/03/03" << endl ;
}