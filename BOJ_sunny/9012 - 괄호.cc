#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str){
    int len = str.length();
    stack<char> st;
    for(int i=0;i<len;i++){
        char c = str[i];
        if(c=='('){
            st.push(str[i]);
        } else{
            if(!st.empty()){
                st.pop();
            } else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(void){
    int n;
    stack<int> s;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>str;
        if(check(str))
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}