#include<iostream>
#include<vector>
using namespace std;

pair<int,int> linearSearch(int arr[][3],int r, int c, int target)
{
    pair<int,int>p;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j] == target)
            {
                p = {i,j};
                return p;
            }
        }
    }
    return {-1,-1};
}

int main()
{
    // important point
    // while declaration, it is neccessary to assign column numbers at the time of declaration and assignment
    int arr[][3] = {{456,34,46},{23,89,56},{89,23,67},{98,533,674}};

    pair<int,int> p;
    p = linearSearch(arr, 4,3,67);

    cout<<"("<<p.first<<", "<<p.second<<")"<<endl;

}

