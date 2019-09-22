#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(void){
    stack<int> s;
    int n, x;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str == "push"){
            cin >> x;
            s.push(x);
        } 
        else if(str == "pop"){
            if(s.empty())
                cout<<-1<<'\n';
            else{
                cout<<s.top()<<'\n';
                s.pop();
            }
        }
        else if(str == "size"){
            cout<<s.size()<<'\n';
        }
        else if(str == "empty"){
            cout<<(s.empty()? 1:0)<<'\n';
        }
        else if(str == "top"){
            if(s.empty())
                cout<<-1<<'\n';
            else
                cout<<s.top()<<'\n';
        }
    }
    return 0;
}