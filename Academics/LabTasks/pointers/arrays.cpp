// (1)
// #include<iostream>
// using namespace std;
// int main()
// {
//     int r,c;cout<<"Enter the number of rows and columns of the 2D array : ";cin>>r>>c;

//     int *arr = new int[r*c];

//     for(int i=0;i<r;i++)
//     {
//         cout<<"Enter "<<c<<" elements in the "<<i+1<<" row : ";
//         for(int j=0;j<c;j++)
//         {
//             cin>>*(arr + r*i + j);
//         }
//     }

//     cout<<endl<<endl<<"****** YOur 2D array ******"<<endl;
//     for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//             cout<<*(arr + r*i + j)<<"  ";
//         }
//         cout<<endl;
//     }

//     delete[] arr;
//     return 0;
// }





// (2)

// #include<iostream>
// using namespace std;
// int main()
// {
//     int *ptr[2];
//     *(ptr + 0) = new int[4]{45,57,23,12};
//     *(ptr + 1) = new int[4]{78,89,23,19};

//     for(int i=0;i<2;i++)
//     {
//         for(int j=0;j<4;j++)
//         cout<<*(*(ptr+i)+j)<<"  ";
//         cout<<endl;
//     }

//     for(int i=0;i<2;i++)
//     {
//         delete[] *(ptr+i);
//     }
// }

// int main()
// {
//     int **ptr = new int*[2];

//     *(ptr + 0) = new int[3]{67,34,78};
//     *(ptr + 1) = new int[3]{23,56,59};

    
//     for(int i=0;i<2;i++)
//     {
//         delete[] *(ptr+i);
//     }

//     delete ptr;
// }


