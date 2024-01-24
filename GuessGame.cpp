#include <iostream>
#include<ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int num;char need;
    int random=rand()%100+1;
    cout << "----------WELCOME TO NUMBER GUESSING GAME----------" << endl;
    cout<<"Guess a number between 1 to 100 "<<endl;
    cout<<"Let's Go!!!"<<endl;
    do{
    cout<<"Enter a number to guess:"<<endl;
    cin>>num;
    if(num==random){
        cout<<"Congratulation!!!\n";
        cout<<"You Win!!!"<<endl;
    }
    else if(num<random){
            cout<<"The guessed number is too low.Try again!"<<endl;
            }
    else{
        cout<<"The guessed number is too high.Try again!"<<endl;
    }
    cout<<"Do want play again?(y/n): "<<endl;
    cin>>need;
    if(need=='y'|| need=='Y'){
        random=rand()%100+1;
    }
    else{
        cout<<"Thank you for playing!"<<endl;
    }


}
while(need=='Y'||need=='y');
    return 0;
}
