#include <iostream>
using namespace std;

bool ishuiwen(int& x){
    if(x<0) return false;
    int high = x;
    int low = 1;
    while(high/10){
        low = low*10;
        high = high/10;
    }
    while(x) {
        if (x / low != x % 10) return false;
        x = x%low;
        x = x/10;
        low = low/100;
    }
    return true;
}

int main() {
    int x = 0;
    while(cin>>x){
        bool res = ishuiwen(x);
        cout<<res<<endl;
    }
    return 0;
}