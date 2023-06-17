#include <bits/stdc++.h>
using namespace std;

int timkiem(int arr[], int n, int x) {
    int left=0, right=n - 1;
    while(left<=right) {
        int mid=left + (right-left)/2;
        if (arr[mid]==x) {
        return mid;
        }
        else if (arr[mid]<x) {
            left = mid+1;
        }
        else {
            right =mid-1;
        }
    }
    return -1;
}
int main() {
    int n, x;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    cin >> x;
    int index = timkiem(A, n, x);
    if (index == -1) {
        cout<<"Khong tim thay"<<endl;
    }
    else {
        cout<<index<<endl;
    }
    return 0;
}