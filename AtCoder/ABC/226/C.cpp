#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll T[202020];
vector<int> A[202020];

int main(){
    cin >> n;
    rep(i,n){
        int t , k;
        cin >> t >> k;
        T[i] = t;
        rep(j,k) {
            int a ;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }
    set<int> st;
    set<int> vec ;
    vec.insert(n-1);
    while(!vec.empty()){
        set<int> check;
        for(int u: vec){
            rep(i,A[u].size()) if(st.count(A[u][i]) != 1) {
                check.insert(A[u][i]);
                st.insert(A[u][i]);
            }
        }
        vec = {};
        for(int u: check) vec.insert(u);
    }
    ll res = T[n-1];
    for(int u: st) res += T[u];
    cout << res << endl;
}