#include <bits/stdc++.h>												
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

const int MOD = 1e9+7;
ll gcd(ll a, ll b) {if(b==0) return a; return gcd(b,a%b);}

#define fastAf cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

#define cp int t;cin>>t;while(t--) {solve();}

#define loop(i,n) for(int i = 0; i<n;i++)

#define pb push_back

#define SORT(v) sort(v.begin(),v.end());

ll calc_meave(vector<int>&meave,double t){
    return meave[0]*(t*t*t*t) + meave[1]*(t*t*t) + meave[2]*(t*t) + meave[3]*t;
}

ll calc_otis(vector<int>& otis ,double t){
    return otis[0]*(t*t*t)+otis[1]*(t*t)+otis[2]*t;
}
ll func(vector<int>&meave , vector<int>&otis , double d,double t){
    return meave[0]*pow(t,4) + (meave[1] + otis[0]) * pow(t,3) + (meave[2] + otis[1]) * pow(t,2) + (meave[3]+otis[2])*t - d;
}

double bisection(vector<int>& meave, vector<int>& otis, double d, double root1,double root2){
    double mid;
    while(root2-root1 > 0.0001){

        mid = (root1+root2)/2;
        if(func(meave,otis,d,mid) == 0)
            return mid;
        else{
            if((func(meave,otis,d,mid) < 0  &&  func(meave,otis,d,root1) > 0 ) || (func(meave,otis,d,mid) > 0  &&  func(meave,otis,d,root1) < 0 ) )
                root2 = mid;
            else
                root1 = mid;
        }
    }
    return mid;
}

void solve(){

    int d;
    cin >> d;

    vector<int> otis;
    vector<int> meave;

    for(int i = 0 ; i<3;i++){
        int x;
        cin >> x;
        otis.pb(x);
    }
    for(int i = 0 ; i<4;i++){
        int x;
        cin >> x;
        meave.pb(x);
    }
    double past;
    for(double i = 1; i<128; i*=2){
        if(calc_meave(meave,i)+calc_otis(otis,i) > d){
            past = i;
            break;
        }
        if(calc_meave(meave,i)+calc_otis(otis,i) == d){
            cout << fixed << setprecision(2) << i;
            return;
        }
    }

    double result = bisection(meave,otis,d,past/2,past);

    cout  << fixed << setprecision(2) << result;

    

    

}
	



int main(){

	fastAf
	solve();
	return 0;
}