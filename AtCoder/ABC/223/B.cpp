#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S ;
vector<string> vec ;

int main(){
    cin >> S ;
    int n = S.size() ;
    rep(i,n){
        string T = "" ;
        rep(j,n){
            T += S[(j+i)%n] ;
        }
        vec.push_back(T) ;
    }
    sort(vec.begin(),vec.end()) ;
    cout << vec[0] << endl ;
    cout << vec[vec.size()-1] << endl ;
}