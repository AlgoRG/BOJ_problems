#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void){
    int n, x;
    string str;
    queue<int> q;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        if(str=="push"){
            cin >> x;
            q.push(x);
        }
        else if(str == "front"){
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if(str == "back"){
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
        else if(str == "size"){
            cout << q.size() << '\n';
        }
        else if(str == "pop"){
            if(q.empty())
                cout << -1 << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "empty"){
            if(q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}