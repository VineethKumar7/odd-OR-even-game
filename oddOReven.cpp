//C++ program to write and read values using variables in/from file.
#include <iostream>
#include <fstream>

using namespace std;

int isOddNumber(int userChoise, int systemChoise){
  int oddNum=1;
  return (userChoise + systemChoise)%2 != 0;
}
int isEvenNumber(int userChoise, int systemChoise){
  int evenNum=2;
  return (userChoise + systemChoise)%2 == 0;
}

int main()
{
    char player1[30], oddEven[4];
    fstream file;
    int age;
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
    cout<<"\n Choose option \n 1. ODD \n 2.EVEN \n"; //Choise
    cin>>oddEven;
    if('ODD' == oddEven || 'odd' == oddEven || '1' == oddEven){
      userChoise=1;
      systemChoise = rand() % 2 + 1; //random number between 1 and 2
      /*
        odd(userChoise + systemChoise) or eveb similar to the player oddEven then he won.
      */
      if((userChoise+systemChoise)%2 == 0){//

      }else{

      }
    }else if('EVEN' == oddEven || 'even' == oddEven || '2' == oddEven){
      userChoise=1;
      systemChoise = rand() % 2 + 1; //random number between 1 and 2
      if(isOddNumber(userChoise,systemChoise)){

      }else{

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
