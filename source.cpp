#include<iostream>
using namespace std;

/* global variables */
const int width = 80;
const int height = 20;
int x, y; // snake head coordinates(x axis and y axis)
int playerScore;
bool isGameOver;


/*functions */

void GameInit(){
    isGameOver = false;
    playerScore = 0;
    x = width /2;
    y = height /2;
}

void GameBoard(string playerName){
    system("cls");

    cout<<playerName<<"'s score : "<<playerScore<<endl;

    for(int i=0; i< width+1; i++){
        cout<<"-";
    }
    cout<<endl;

    for(int i=0; i< height; i++){
        for(int j=0; j <=width; j++){
            if(j == 0 || j == width)
                cout<<"|";
            else
                cout<<" ";

            if(i == y && j == x)
                cout<<"O";
        }
        cout<<endl;
    }

    for(int i=0; i<width+1; i++){
        cout<<"-";
    }
    cout<<endl;

}


int main(){
    string playerName;
    cout<<"Enter Players Name :";
    cin>>playerName;
    GameInit();
    GameBoard(playerName);

    return 0;
}
