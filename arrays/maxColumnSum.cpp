#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int arr[][3] = {{456,34,46},{23,89,56},{89,23,67},{98,533,674}};
    int maxColSum = INT_MIN;

    for(int i=0;i<3;i++)
    {
        int colSum = 0;
        for(int j=0;j<4;j++)
        {
            colSum += arr[j][i];
        }

        maxColSum = max(maxColSum, colSum);
    }
    cout<<"The highest sum of the column is "<<maxColSum<<endl;
    return 0;
}


