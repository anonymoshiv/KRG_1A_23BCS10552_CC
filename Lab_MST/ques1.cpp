#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<vector<int>> task(n,vector<int>(2));
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>task[i][0]>>task[i][1];
        sum+=task[i][0];
    }
    
    sort(task.begin(),task.end(),[](const vector<int>& a,const vector<int>& b){
        if(a[1]-a[0] == b[1]-b[0])
            return a[1]>b[1];
        return a[1]-a[0] > b[1]-b[0];
    });
    
    long long temp=sum;
    for(auto el:task){
        if(temp<el[1]){
            sum+=(el[1]-temp);
            temp=el[1];
        }
        temp-=el[0];
    }
    cout<<sum;
    
return 0;
}