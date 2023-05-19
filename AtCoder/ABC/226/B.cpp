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
set<vector<int>> st ;

int main(){
cin >> n ;
    rep(i,n){
        int L ;
        cin >> L ;
        vector<int> A ;
        rep(j,L){
            int a;
            cin >> a;
            A.push_back(a);
        }
        st.insert(A);
    }
    cout << st.size() << endl ;
}