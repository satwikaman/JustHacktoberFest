#include<bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
typedef long long int ll;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD (ll)(1000000000+7)
#define MAXN 100000+1 
#define pb push_back
#define mp make_pair
#define TEST_CASES  ll t;cin >> t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,b,a) for(ll i=(b-1);i>=a;i--)
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b){ return (a.second < b.second) ; }
ll max(ll a, ll b){ if(a>b) return a ; return b; }
ll min(ll a, ll b){ if(a<b) return a ; return b; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);  }
bool func(const vector<int> &A , int l , int h , int x){
    while(l<=h){
        int m = l + (h-l)/2 ;
        if(A[m]==x)
            return true;
        else if(A[m]>x)
            h=m-1;
        else{
            l=m+1;
        }
    }
    return false;
}

int main(){
    fio;
    int n,k;cin>>n>>k;
    vector<int>A(n);
    rep(i,0,n){
        cin>>A[i];
    }

    while(k--){
        int q;cin>>q;
        bool f = false; 
        f = func(A,0,n-1,q);
        if(f==0)
            cout<<"NO"<<endl;
        else 
            cout<<"YES"<<endl;
        
    }
    return 0;
}