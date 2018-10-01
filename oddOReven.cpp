//C++ program to write and read values using variables in/from file.
#include <iostream>
#include <fstream>

using namespace std;
int userOddEven(int num){
  return num%2!=0;
}
void current_game(int game_Array[]){

}

int main()
{
    char player1[30], oddEven[4];
    fstream file;
    int Number,flag=1,batting,game_Array[1];
    int Check,systemChoise,won;
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
    while(flag !=0){
      cout<<"\n Enter a number between 1-6 \n"; //Choise
      cin>>Number;

      check1= userOddEven(Number);
      systemChoise = rand() % 6 + 1; //random number between 1 and 6
      check2=userOddEven(systemChoise);

      // This will check whether both the inputs are equal or not.
      if(check1 != check2){
        flag =1;
      }
    }
    check3 = (Number + systemChoise) % 2;
  if(check1 == check3){
    cout<<"\n Player Won the toss \n";
    cout<<"\n Choose 1 for batting and 0 for bowling \n";
    cin>>batting;
    if(batting==1){
      cout<<"Player Won the toss and coose to batting";
      file<<"player1 Won the toss and"<<"choose batting"<<endl;
      game_Array={1,0};
      current_game(game_Array);
    }else{
      cout<<"Player Won the toss and choose to bowiling";
      file<<"player1 Won the toss and"<<"choose bowling"<<endl;
      game_Array={0,1};
      current_game(game_Array);
    }

  }else{
    cout<<"\n System won the choise \n";
    batting= rand()%1;
    if(batting==1){
      cout<<"System Won the toss and choose batting";
      file<<"System Won the toss and "<<"choose batting"<<endl;
      game_Array={0,1};
      current_game(game_Array);
  }else{
    file<<"System Won the toss and choose bowling"<<endl;
    file<<"System Won the toss and"<<"choose bowling"<<endl;
    game_Array={1,0};
    current_game(game_Array);
  }

}
