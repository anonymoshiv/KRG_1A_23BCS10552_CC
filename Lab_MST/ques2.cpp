#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++)
        cin>>words[i];
    vector<int> bistMask(n,0);
    int i=0;
    for(auto str:words){
        int temp=0;
        for(auto ch:str){
            temp=temp | (1<<(ch-'a'));
        }
        bistMask[i]=temp;
        i++;
    } 
    long long ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((bistMask[i] & bistMask[j])==0){
                ans=max(ans,1LL*words[i].size()*words[j].size());
            }
        }
    }
    cout<<ans;
return 0;
}