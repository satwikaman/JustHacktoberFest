#include<bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
typedef long long int ll;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD (ll)(1000000000+7)
#define MAXN 1000000000+1 
#define pb push_back
#define mp make_pair
#define TEST_CASES  ll t;cin >> t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,b,a) for(ll i=(b-1);i>=a;i--)
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b){ return (a.second < b.second) ; }
ll max(ll a, ll b){ if(a>b) return a ; return b; }
ll min(ll a, ll b){ if(a<b) return a ; return b; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);  }
void cp(){
    ll n;cin>>n;
    vector<ll> v(n);
    ll su(0), cnt(0);
    set<ll>s;
    s.insert(0);
    for(auto  &it: v){
        cin>>it;
        su+=it;
        if(s.count(su)){
            cnt++;
            s.clear();
            s.insert(0);
            s.insert(it);
            su=it;
        }
        else{
            s.insert(su);
        }
    }
    cout<<cnt<<endl;
    return;
}

int main(){
fio ;
//TEST_CASES{
cp();
//}
return 0;
}