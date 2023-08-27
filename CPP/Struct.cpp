#include <iostream>
#include <algorithm>

using namespace std;

struct xemay{
    int mahang;
    float giaban;
};
bool sosanhgiaban(const xemay &a, const xemay &b) {
    return a.giaban < b.giaban;
}
int main(){
    const int MAX_SIZE=100;
    xemay Xe[MAX_SIZE];
    int n = 0;
    char over;
    do {
        cout << "Nhap ma hang: ";
        cin >> Xe[n].mahang;
        cout << "Nhap gia ban: ";
        cin >> Xe[n].giaban;
        n++;
        cout << "Nhap n de ket thuc, neu khong hay nhap mot so: ";
        cin >> over;
    } while (over != 'n' && n < MAX_SIZE);
    cout << "Danh sach xe may:\n";
    for (int i = 0; i < n; i++){
        cout << "Ma hang: " << Xe[i].mahang << ", Gia ban: " << Xe[i].giaban << endl;
    }
    sort(Xe, Xe+n, sosanhgiaban);
    cout << "\nDanh sach xe may da sap xep:\n";
    for (int i = 0; i < n; i++){
        cout << "Ma hang: " << Xe[i].mahang << ", Gia ban: " << Xe[i].giaban << endl;
    }
    return 0;
}

