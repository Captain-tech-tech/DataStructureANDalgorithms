// array store data of same data type, data is stored in contigous memory + linear


// code of array of marks of a student and finding the highest and smallest marks of a student
// #include<iostream>
// using namespace std;
// int main()
// {
//     string stu;cout<<"Enter the student name : ";getline(cin>>ws,stu);
//     int a;cout<<"Enter the number of papers for the student : ";cin>>a;
//     double marks[a];
//     cout<<"Enter "<<a<<" papers marks for "<<stu<<" : ";
//     for(int i=0;i<a;i++)
//     cin>>marks[i];

//     cout<<endl<<"Your marks are : ";
//     for(int i=0;i<a;i++)
//     cout<<marks[i]<<" ";
//     cout<<endl;

//     // finding the largest and smallest marks in the array
//     int smallest=marks[0],largest=marks[0];
//     for(int i=0;i<a;i++)
//     {
//         if(smallest>marks[i])
//         smallest=marks[i];

//         if(largest<marks[i])
//         largest=marks[i];
//     }
//     cout<<endl<<"The highest marks : "<<largest<<". And the lowest marks : "<<smallest<<endl<<endl;
//     return 0;
// }






// code for pass by reference
// #include<iostream>
// using namespace std;
// void changearr(int arr[],int size)
// {
//     for(int i=0;i<size;i++)
//     {
//         arr[i]=(2*i)+arr[i];
//     }
// }
// int main()
// {
//     int size;cout<<"Enter the size of the array : ";cin>>size;
//     int arr[size];

//     cout<<"Enter "<<size<<" number for your array : ";
//     for(int i=0;i<size;i++)
//     cin>>arr[i];

//     cout<<"Original array : ";
//     for(int i=0;i<size;i++)
//     cout<<arr[i]<<" ";
//     cout<<endl;

//     changearr(arr,size);
    
//     cout<<"New modified array : ";
//     for(int i=0;i<size;i++)
//     cout<<arr[i]<<" ";
//     cout<<endl;
//     return 0;
// }



// code for linear search algorithm
// #include<iostream>
// using namespace std;

// int linearsearch(double arr[],int size,double search_for_num)
// {
//     for(int i=0;i<size;i++)
//     {
//         if(arr[i]==search_for_num)
//         return i;
//     }
//     return -1;
// }

// int main()
// {
//     int size;cout<<"Enter the size of your array : ";cin>>size;
    
//     double arr[size];
//     cout<<"Enter "<<size<<" numbers in your array : ";
//     for(int i=0;i<size;i++)
//     cin>>arr[i];
    
//     double num;cout<<"Enter the number for which your are searching : ";cin>>num;

//     int n=linearsearch(arr,size,num);

//     if(n!=(-1))
//     cout<<"The required number is find at index "<<n<<endl;
//     else
//     cout<<"The number is not found in the array!"<<endl;

//     return 0;
// }




//reversing an array without making a second copy array
// arrray reversal algorithm
// #include<iostream>
// using namespace std;
// void reverse_array(int arr[],int size)
// {
//     for(int i=0;i<size/2;i++)
//     {
//         int temp=arr[i];
//         arr[i]=arr[size-i-1];
//         arr[size-i-1]=temp;
//     }
// }

// int main()
// {
//     int s;cout<<"Enter the size of your array : ";cin>>s;

//     int arr[s];
//     cout<<"Enter "<<s<<" integer numbers for your array : ";
//     for(int i=0;i<s;i++)
//     cin>>arr[i];

//     cout<<"Your Original Array : ";
//     for(int i=0;i<s;i++)
//     cout<<arr[i]<<" ";
//     cout<<endl;

//     reverse_array(arr,s);

//     cout<<"Your Reversed Array : ";
//     for(int i=0;i<s;i++)
//     cout<<arr[i]<<" ";
//     cout<<endl;
    
//     return 0;
// }




