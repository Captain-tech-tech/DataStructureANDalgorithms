
// Students and Sandwiches
// #include <iostream>
// #include <queue>
// #include <stack>
// #include <vector>

// using namespace std;

// int main() {
//     int n;
//     if (!(cin >> n)) return 0;

//     vector<int> students_input(n);
//     for (int i = 0; i < n; i++) {
//         cin >> students_input[i];
//     }

//     vector<int> sandwiches_input(n);
//     for (int i = 0; i < n; i++) {
//         cin >> sandwiches_input[i];
//     }

//     queue<int> q;
//     for (int i = 0; i < n; i++) {
//         q.push(students_input[i]);
//     }

//     stack<int> s;
//     for (int i = n - 1; i >= 0; i--) {
//         s.push(sandwiches_input[i]);
//     }

//     int attempts = 0;

//     while (!q.empty() && attempts < q.size()) {
//         if (q.front() == s.top()) {
//             q.pop();
//             s.pop();
//             attempts = 0;
//         } else {
//             int current_student = q.front();
//             q.pop();
//             q.push(current_student);
//             attempts++;
//         }
//     }

//     cout << q.size() << endl;

//     return 0;
// }








// Hot potato game
// #include<iostream>
// #include<queue>
// using namespace std;

// int main()

// {
//     queue<string>st;
//     while(true)
//     {
//         string s;
//         char choice;
//         cout<<"do you wanna enter a name (y/n): ";cin>>choice;
//         if(choice=='y')
//         {
//             cin>>s;
//             st.push(s);
//         }
//         else
//             break;
//     }

//     int k;cout<<"enter k value : ";cin>>k;

//     while(st.size()>1)
//     {
//         for(int i=0;i<k-1;i++)
//         {
//             string t = st.front();
//             st.pop();
//             st.push(t);
//         }
//         string t = st.front();
//         st.pop();
//         cout<<"Eliminated : "<<t<<endl;
//     }

//     cout<<"Winner: "<<st.front()<<endl;

//     return 0;
// }




















// #include <iostream>
// #include <string>
// using namespace std;

// struct Stack {
//     string data[1000];
//     int top = -1;

//     void push(string val) {
//         if (top < 999) {
//             top++;
//             data[top] = val;
//         }
//     }

//     string pop() {
//         if (top >= 0) {
//             string val = data[top];
//             top--;
//             return val;
//         }
//         return "";
//     }

//     bool isEmpty() {
//         return top == -1;
//     }

//     void clear() {
//         top = -1;
//     }
// };

// int main() {
//     Stack undoStack;
//     Stack redoStack;
//     char choice;

//     while (true) {
//         cout << "Car Control Menu" << endl;
//         cout << "1. Accelerate" << endl;
//         cout << "2. Brake" << endl;
//         cout << "3. Decelerate" << endl;
//         cout << "4. Turn Left" << endl;
//         cout << "5. Turn Right" << endl;
//         cout << "Z. Undo" << endl;
//         cout << "Y. Redo" << endl;
//         cout << "Q. Quit" << endl;
//         cout << "Choice: ";
//         cin >> choice;

//         if (choice == '1') {
//             cout << "Action: Accelerate" << endl;
//             undoStack.push("Accelerate");
//             redoStack.clear();
//         } else if (choice == '2') {
//             cout << "Action: Brake" << endl;
//             undoStack.push("Brake");
//             redoStack.clear();
//         } else if (choice == '3') {
//             cout << "Action: Decelerate" << endl;
//             undoStack.push("Decelerate");
//             redoStack.clear();
//         } else if (choice == '4') {
//             cout << "Action: Turn Left" << endl;
//             undoStack.push("Turn Left");
//             redoStack.clear();
//         } else if (choice == '5') {
//             cout << "Action: Turn Right" << endl;
//             undoStack.push("Turn Right");
//             redoStack.clear();
//         } else if (choice == 'Z' || choice == 'z') {
//             if (!undoStack.isEmpty()) {
//                 string current = undoStack.pop();
//                 cout << "Undo: " << current << endl;
//                 redoStack.push(current);
//             } else {
//                 cout << "Nothing to undo" << endl;
//             }
//         } else if (choice == 'Y' || choice == 'y') {
//             if (!redoStack.isEmpty()) {
//                 string current = redoStack.pop();
//                 cout << "Redo: " << current << endl;
//                 undoStack.push(current);
//             } else {
//                 cout << "Nothing to redo" << endl;
//             }
//         } else if (choice == 'Q' || choice == 'q') {
//             break;
//         } else {
//             cout << "Invalid choice" << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }











// insert position
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
    
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
    
//     int target;
//     cin>>target;

//     int st = 0, end = n-1, ans = -1;

//     while(st<=end)
//     {
//         int mid = st + (end-st)/2;

//         if(arr[mid] == target)
//         {
//             ans = mid;
//             break;
//         }
//         else if(arr[mid] > target)
//             end = mid-1;
//         else
//             st = mid+1;
//     }

//     if(ans == -1)
//         ans = st;
//     cout<<ans<<endl;
//     return 0;
// }
















// plus one 
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];

//     bool carry = true;

//     for(int i=n-1;i>=0;i--)
//     {
//         if(arr[i]<9)
//         {
//             arr[i]++;
//             carry = false;
//             break;
//         }
//         else
//         {
//             arr[i] = 0;
//         }
//     }

//     if(carry)
//     {
//         n++;
//         int *new_arr = new int[n];
//         new_arr[0] = 1;
//         for(int i=1;i<n;i++)
//             new_arr[i] = 0;
        
//         for(int i=0;i<n;i++)
//             cout<<new_arr[i]<<"  ";
//         cout<<endl;
//     }
//     else
//     {
//         cout<<endl<<"Printing new array"<<endl;
//         for(int i=0;i<n;i++)
//             cout<<arr[i]<<"  ";
//         cout<<endl;
//     }

//     return 0;
// }








