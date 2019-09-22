#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int n,a,b;
    vector<pair<int,int>> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back(pair<int, int>(a,b));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
    return 0;
}