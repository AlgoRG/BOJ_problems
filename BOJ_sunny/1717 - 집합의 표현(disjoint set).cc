#include<iostream>
using namespace std;
int p[1000001];
int find(int a){
    if(p[a]==a)    return a;
    return p[a]=find(p[a]);
}
void union_(int a, int b){
    a=find(a);
    b=find(b);
    p[a]=b;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,x,a,b;
    cin >> n >> m;
    for(int i=0;i<=n;i++)
        p[i]=i;
    for(int i=0;i<m;i++){
        cin >> x >> a >> b;
        if(x==0)
            union_(a,b);
        else if(x==1){
            if(find(a)==find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}