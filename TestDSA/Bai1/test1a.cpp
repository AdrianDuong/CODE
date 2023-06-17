#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream infile("C:\\Users\\thaeanh\\OneDrive\\Desktop\\CODEPTIT\\TestDSA/datain.txt");
    vector<int> A;
    if (infile.is_open())
    {
        int x;
        while (infile>>x)
        {
            A.push_back(x);
        }
        infile.close();
    }
    else
    {
        cout << "!" << endl;
    }
    for (int i=0; i<A.size(); i++)
    {
        cout<< A[i]<< " ";
    }
    return 0;
}
