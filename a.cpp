#include<bits/stdc++.h>
using namespace std;

void cp(){
    string s;cin>>s;
    if(s=="??????????"){
        cout<<6<<endl;return;
    }
    else if(s=="0000000000" || s=="1111111111"){
        cout<<10<<endl;return;
    }
    else{
        int a=0,b=0;
        int ans=9;
        for(int i=0;i<10;i++){
            if(i%2==0 && (s[i]=='1' || s[i]=='?'))a++;
            if(i%2==1 && (s[i]=='1'))b++;
            if((a-b>(10-i)/2) || ((b-a)>(9-i)/2))ans=min(ans,i);
        }
    
        a=0,b=0;
        for(int i=0;i<10;i++){
            if(i%2==0 && (s[i]=='1'))a++;
            if(i%2==1 && (s[i]=='1' || s[i]=='?'))b++;
            if((a-b>(10-i)/2) || ((b-a)>(9-i)/2))ans=min(ans,i);
        }
        cout<<ans+1<<endl;return;    
    }
}





int main(){
    int t;cin>>t;
    while(t--){
        cp();
    }
    return 0;
}