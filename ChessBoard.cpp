#include "ChessBoard.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

ChessBoard::ChessBoard(void)
{
    piece=nullptr;
}
ChessBoard::ChessBoard(Piece *p)
{
    piece=p;
}

ChessBoard::~ChessBoard(void)
{
    //delete gameBoard;
}


/*
for(int i=1;i<=18;i++){
    if((counter==2)||(counter==4)||(counter==6)||(counter==8)||(counter==10)||(counter==12)||(counter==14)||(counter==16)){
        cout<<boardIndicator[index];
        index++;
    }
    else{
    cout<<" ";}
    counter++;
}
char vL='|';
char hL='_';
cout<<endl;
for(int j=1;j<=18;j++){
 if(j==1){
    cout<<boardIndicator[index];
    index++;
 }
 else if((j==2)||(j==4)||(j==6)||(j==8)||(j==10)||(j==12)||(j==14)||(j==16)||(j==18)){
    cout<<vL;
 }
 else if((j==3)||(j==5)||(j==7)||(j==9)||(j==11)||(j==13)||(j==15)||(j==17)||(j==1)){cout<<hL;}
}
cout<<endl;
cout<<endl;
;*/

