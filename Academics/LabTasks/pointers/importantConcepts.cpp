
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




