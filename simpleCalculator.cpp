#include <iostream>

using namespace std;

int main()
{
    cout<<"----------SIMPLE CALCULATOR----------"<<endl;
    double a,b;
    char op;
    while(true){
    cout<<"Enter the first number:"<<endl;
    cin>>a;
    cout<<"Enter the second number:"<<endl;
    cin>>b;
    cout<<"Enter the operation('+,-,*,/') :"<<endl;
    cin>>op;
    double ans;
    switch(op){
    case '+':
        ans=a+b;
        break;
    case '-':
        ans=a-b;
        break;
    case '*':
        ans=a*b;
        break;
    case '/':
        if(b==0){
            cout<<"Error : Number not divisible by 0 "<<endl;
            continue;
        }
        ans=a/b;
        break;
    default:
        cout<<"Error: Please enter a valid operation('+,-,*,/') "<<endl;
        //'continue;
    }
     cout << "Result: " << ans << endl;
        char choice;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        if(choice=='y'||choice=='Y'){
            cout<<"Let's do it again!!"<<endl;
        }
        else if (choice == 'n' || choice == 'N') {
            cout<<"THANK YOU!!"<<endl;
            break;
        }
    }
    return 0;
}
