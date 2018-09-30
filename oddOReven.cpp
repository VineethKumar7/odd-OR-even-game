//C++ program to write and read values using variables in/from file.
#include <iostream>
#include <fstream>

using namespace std;

int oddOREven(int Number, int systemChoise){
  int Num=2; // By default it is even number
  if((userChoise + systemChoise)%2 != 0){
    Num=1;
  }
  return Num;
}

int main()
{
    char player1[30], oddEven[4];
    fstream file;
    int Number;
    int userChoise,systemChoise,won;
    file.open("Game Score Card.txt",ios::out);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
      return 0;
    }
    //Terminal instructions
    cout<<"\n \t------ODD OR EVEN GAME------\t"<<endl;

    //read values from User
    cout<<"Enter the player name ";
    cin.getline(player1,30);
    cout<<"\n Enter a number between 1-6 \n"; //Choise
    cin>>Number;
    //For ODD number
    if(Number % 2 != 0 ){
      userChoise=1; // Note here 1 indicates it is a odd Number
      systemChoise = rand() % 2 + 1; //random number between 1 and 2

      if(oddOREven(Number) == userChoise){//
        cout<<"\n Player Won the choise \n";
      }else{
        cout<<"\n System Won the choise \n";
      }
    }

    //write into file
    file<<player1<<" "<<age<<endl;
    file<<player1<<" "<<age<<endl;

    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;

    //re open file in input mode and read data
    //open file
    file.open("Game Score Card.txt",ios::in);
    if(!file){
        cout<<"Error in opening file..";
        return 0;
    }
    file>>player1;
    file>>age;
    cout<<"Name: "<<player1<<",Age:"<<age<<endl;
    file>>player1;
    file>>age;
    cout<<"Name: "<<player1<<",Age:"<<age<<endl;
    return 0;
}
