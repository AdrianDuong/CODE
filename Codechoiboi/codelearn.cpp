#include<iostream>

using namespace std;

int main() {
    int a[100],sum=0;
    for(int i=0; i<100;i++) {
        cin>a[i];
    }
    for(int i=0;i<100;i++) {
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
