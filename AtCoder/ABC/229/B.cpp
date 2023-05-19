#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string A , B ;

int main(){
    cin >> A >> B ;
    reverse(A.begin(),A.end()) ;
    reverse(B.begin(),B.end()) ;
    rep(i,min(A.size(),B.size())){
        int a = A[i]-'0' ;
        int b = B[i]-'0' ;
        if(a + b > 9){
            cout << "Hard" << endl ;
            return 0 ;
        }
    }
    cout << "Easy" << endl ;

}