// primary diagonal elements have i==j
// secondry diagonal elements have i+j == number_of_rows or number_of_columns    or  j = n-i-1


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> v = {{45,57,45},{78,45,235,6786,489},{231,45,4864,238},{89,456,345}};

    //  rows = v.size();
    // columns = v[i].size();

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
}


