//C++ program to write and read values using variables in/from file.
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int userOddEven(int num){
  return num%2!=0;
}
int verify(number){
  if(number>=1 && number<=6){
    return 1;
  }
  return 0;
}

int current_game(int game_Array[],int result[]){
  fstream file; //object of fstream class
  int value,flag=0,systemChoise,totalScore1=0,totalScore2=0;
  //opening file "sample.txt" in out(write) mode
  file.open("Game Score Card.txt",ios::app);

  if(!file)
  {
      cout<<"Error in creating file!!!"<<endl;
  }else{
    cout<<"\n Game starts here..... \n"<<endl;
    //write text into file
    /* out = 0 means the player is not out by default the player is not out.
      out = 1 means that the player is out
    */
    //-----------------First Game -----------------------
    while(!out){
      while (flag==0) {
        cout<<"\n Enter a number between 1-6";
        cin>>value;
        if(verify(value)){
          flag=1;
          totalScore1+=value;
        }
      }
      systemChoise = rand() % 6 + 1; //random number between 1 and 6
      cout<<"\n The system choise is : "<<systemChoise;

      if(value == systemChoise)
      {
        out =1;
      }else{
        file<<value<<endl;
      }
    }
    if(game_Array[1] == 1){
      cout<<"The second player is Computer";
      file<<"The second player is Computer"<<endl;
    }else{
      cout<<"The second player is Player";
      file<<"The second player is Player"<<endl;
    }
    // -------------Second GAME-----------------
    while(!out){
      while (flag==0) {
        cout<<"\n Enter a number between 1-6";
        cin>>value;
        if(verify(value)){
          flag=1;
          totalScore2+=value;
        }
      }
      systemChoise = rand() % 6 + 1; //random number between 1 and 6
      cout<<"\n The system choise is : "<<systemChoise;

      if(value == systemChoise)
      {
        out =1;
      }else{
        file<<value<<endl;
      }
    }
    if(game_Array[0]==1){//If user is batting and have high score then
      if(totalScore1>totalScore2 ){
        result[0]=1;
      }else if(totalScore1>totalScore2 && game_Array[0]==1){
        result[1]=1;
      }
    }else{
      if(totalScore1>totalScore2 ){
        result[1]=1;
      }else if(totalScore1>totalScore2 && game_Array[0]==1){
        result[0]=1;
    }

    //closing the file
    file.close();
  }
  return result;
}

int main()
{
  char player1[30], oddEven[4];
  fstream file;
  int result[1]={0,0};
  int Number,flag=0,batting,game_Array[1];
  int check1,check2,check3,systemChoise,won;
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
  while(flag==0){
    cout<<"\n Enter a number between 1-6 \n"; //Choise
    cin>>Number;

    check1= userOddEven(Number);
    systemChoise = rand() % 6 + 1; //random number between 1 and 6
    cout<<"\n The system choise is : "<<systemChoise;
    check2=userOddEven(systemChoise);

    // This will check whether both the inputs are equal or not.
    if(check1 != check2){
      flag =1;
    }
  }
  cout<<"\n Exited the while loop";
  check3 = (Number + systemChoise) % 2;
/*
game_Array[0] is for User
game_Array[1] is for System
*/

  if(check1 == check3){
    cout<<"\n Player Won the toss";
    cout<<"\n Choose 1 for batting and 0 for bowling \n";
    cin>>batting;
    if(batting==1){
      cout<<"Player Won the toss and coose to batting";
      file<<"player1 Won the toss and"<<"choose batting"<<endl;
      game_Array[0]=1;
      game_Array[1]=0;
      result=current_game(game_Array,result);
    }else{
      cout<<"Player Won the toss and choose to bowiling";
      file<<"player1 Won the toss and"<<"choose bowling"<<endl;
      game_Array[0]=0;
      game_Array[1]=1;
      result=current_game(game_Array,result);
    }
  }else{
    cout<<"\n System won the choise \n";
    batting= rand()%1;
    if(batting==1){
      cout<<"System Won the toss and choose batting";
      file<<"System Won the toss and "<<"choose batting"<<endl;
      game_Array[0]=0;
      game_Array[1]=1;
      result=current_game(game_Array,result);
  }else{
    file<<"System Won the toss and choose bowling"<<endl;
    file<<"System Won the toss and"<<"choose bowling"<<endl;
    game_Array[0]=1;
    game_Array[1]=0;
    result=current_game(game_Array,result);
    }
  }
  if(result[0]==1){
    cout<<"User Won the match";
    file<<"User Won the match"<<endl;
  }else{
    cout<<"System Won the match";
    file<<"System Won the match"<<endl;
  }
  //closing the file
  file.close();
}
