#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<double,double> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
P A[101010] ;
double tot ;

double f(double x){
    double sum = 0 , t = 0 ;
    rep(i,n){
        if(sum + A[i].first > x){
            t += (x - sum) / A[i].second ;
            break ;
        }
        else{
            t += A[i].first / A[i].second ;
            sum += A[i].first ;
        }
    }
    double y = tot - x ;
    double cnt = 0 , s = 0 ;
    rep(i,n){
        if(cnt + A[n - 1 - i].first > y){
            s += (y - cnt) / A[n - 1 - i].second ;
            break ;
        }
        else{
            s += A[n - 1 - i].first / A[n - 1 - i].second ;
            cnt += A[n - 1 - i].first ;
        }
    }
    return abs(s - t) ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i].first >> A[i].second , tot += A[i].first ;
    double lef = 0 , rig = tot + 10 ;
    int count = 0 ;
    while(count < 500){
        double mid1 = (2 * lef + rig) / 3 , mid2 = (lef + 2 * rig) / 3 ;
        if(f(mid1) > f(mid2)) lef = mid1 ;
        else rig = mid2 ;
        count++ ;
    }
    cout << fixed << setprecision(10) << rig << endl ;
}