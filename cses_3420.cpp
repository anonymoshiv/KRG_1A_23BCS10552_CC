#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>nums;
    for(int i = 0;i<n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int res = 0;
    for(int i = 1;i<=32;i++){
        int set = 0,unset = 0;
        for(auto x : nums){
            int bit = (1<<i) & x;
            if(bit!=0) set++;
            else unset++;
        }
        res+=set*unset;
    }
    cout << res*2;
    return 0;
}