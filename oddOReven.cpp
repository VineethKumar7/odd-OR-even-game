//C++ program to write and read values using variables in/from file.
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>

int userOddEven(int num){
  return num%2!=0;
}
int verifySix(int number){
  if(number>=1 && number<=6){
    return 1;
  }else{
  cout<<"\n Wrong Value";
  }
  return 0;
}
int verifyOne(int number){
  if(number==0 || number==1){
    return 1;
  }else{
  cout<<"\n Wrong Value";
  }
  return 0;
}
void current_game(int game_Array[1],int result[1]);

int main(){
  char player1[30], oddEven[4];
  fstream file;
  int result[1];
  int Number,flag1=0,flag2=0,flag3=0,batting,game_Array[1];
  int check1,check2,check3,systemChoise,won;
  file.open("GAMESCOR.txt",ios::out|ios::app);
  if(!file)
  {
    cout<<"Error in creating file.."<<endl;
    return 0;
  }
  //Terminal instructions
  cout<<"\n \t------ODD OR EVEN GAME------\t"<<endl;

  //read values from User
  cout<<"Enter the player name : ";
  cin.getline(player1,30);
  while(flag1==0){
    flag2=0;
    while (flag2==0) {
      cout<<"\n Enter a number between 1-6 : "; //Choise
      cin>>Number;
      if(verifySix(Number)){
        flag2=1;
      }
    }
    check1= userOddEven(Number);
    systemChoise = rand() % 6 + 1; //random number between 1 and 6
    cout<<"\n The system choise is : "<<systemChoise;
    check2=userOddEven(systemChoise);

    // This will check whether both the inputs are equal or not.
    if(check1 != check2){
      flag1 =1;
    }
  }
  check3 = (Number + systemChoise) % 2;
/*
game_Array[0] is for User
game_Array[1] is for System
*/

  if(check1 == check3){
    cout<<"\n Player Won the toss";
    while(flag3==0){
      cout<<"\n Choose 1 for batting and 0 for bowling \n";
      cin>>batting;
      if(verifyOne(batting)){
        flag3=1;
      }
    }

    if(batting==1){
      cout<<"Player Won the toss and coose to batting";
      file<<"player1 Won the toss and"<<"choose batting"<<endl;
      file<<"player1: is "<<player1<<endl;
      file<<"player2: is System"<<endl;
      game_Array[0]=1;
      game_Array[1]=0;
      current_game(game_Array,result);
    }else{
      cout<<"Player Won the toss and choose to bowiling";
      file<<"player1 Won the toss and"<<"choose bowling"<<endl;
      file<<"player1: is System"<<endl;
      file<<"player12: is "<<player1<<endl;
      game_Array[0]=0;
      game_Array[1]=1;
      current_game(game_Array,result);
    }
  }else{
    cout<<"\n System won the choise \n";
    batting= rand()%1;
    if(batting==1){
      cout<<"System Won the toss and choose batting";
      file<<"System Won the toss and "<<"choose batting"<<endl;
      file<<"player1: is System"<<endl;
      file<<"player12: is "<<player1<<endl;
      game_Array[0]=0;
      game_Array[1]=1;
      current_game(game_Array,result);
  }else{
    cout<<"System Won the toss and choose bowling";
    file<<"System Won the toss and "<<"choose bowling"<<endl;
    file<<"player1: is "<<player1<<endl;
    file<<"player2: is System"<<endl;
    game_Array[0]=1;
    game_Array[1]=0;
    current_game(game_Array,result);
    }
  }
  //closing the file
  file.close();
  getch();
  return 0;
}

void current_game(int game_Array[1],int result[1]){
  fstream file2; //object of fstream class
  int value,flag=0,systemChoise,totalScore1=0,totalScore2=0,out=0;
  //opening file "sample.txt" in out(write) mode
  file2.open("GAMESCOR.txt",ios::out|ios::app);

  if(!file2)
  {
      cout<<"Error in creating file!!!";
  }else{
    cout<<"\n Game starts here..... \n";

    //-----------------First Game -----------------------
    out=0;
    file2<<"------SCORE CARD 1------"<<endl;
    while(!out){
      flag=0;
      while (flag==0) {
        cout<<"\n Enter a number between 1-6 : ";
        cin>>value;
        if(verifySix(value)){
          flag=1;
          totalScore1+=value;
        }
      }
      systemChoise = rand() % 6 + 1; //random number between 1 and 6
      cout<<"\n The system choise is : "<<systemChoise;
      if(value == systemChoise)
      {
        out =1;
        file2<<"OUT"<<endl;
      }else{
        file2<<value<<endl;
      }
    }
    file2<<" The Total Score for palyer 1 : "<<totalScore1<<endl;
    cout<<"\n The total score of player 1 is "<<totalScore1;
    if(game_Array[1] == 1){
      cout<<"\n The second player is Computer";
      file2<<" The second player is Computer"<<endl;
    }else{
      cout<<"\n The second player is Player";
      file2<<" The second player is Player"<<endl;
    }
    // -------------Second GAME-----------------
    out=0;
    file2<<"------SCORE CARD 2------"<<endl;
    while(!out){
      flag=0;
      while (flag==0) {
        cout<<"\n Enter a number between 1-6: ";
        cin>>value;
        if(verifySix(value)){
          flag=1;
          totalScore2+=value;
          if(totalScore2>totalScore1){ // Stop bolling when the second payer wins.
            out=1;//Here the out is just a flag it does not indicate he is out.
          }
        }
      }
      systemChoise = rand() % 6 + 1; //random number between 1 and 6
      cout<<"\n The system choise is : "<<systemChoise;
      if(value == systemChoise)
      {
        out =1;
        file2<<"OUT"<<endl;
      }else{
        file2<<value<<endl;
      }
    }
    file2<<"The Total Score for palyer 2 : "<<totalScore2<<endl;
    cout<<"\n The total score of player 2 is "<<totalScore2;
    if(game_Array[0]==1){//If user is batting and have high score then
      if(totalScore1>totalScore2 ){
        result[0]=1;
      }else {
        result[1]=1;
      }
    }else{
      if(totalScore1>totalScore2 ){
        result[1]=1;
      }else{
        result[0]=1;
    }
  }
    if(result[0]==1){
      cout<<"\n User Won the match";
      file2<<"User Won the match"<<endl;
    }else{
      cout<<"\n System Won the match";
      file2<<"System Won the match"<<endl;
    }
    //closing the file
    file2.close();
  }

}
