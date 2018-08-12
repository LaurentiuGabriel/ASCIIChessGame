#include <iostream>
#include "ChessBoard.h"
#include <cmath>
#include <windows.h>
#include <sstream>
#include "Piece.h"
#include <stdlib.h>


using namespace std;
void playChess();
int secondTurn=0;
int playerTurn=0;
int moveIntegrity=0;
char interfaceBoard[9][18]=
{
    {' ',' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H'},
    {'8','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'7','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'6','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'5','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'4','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'3','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'2','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
    {'1','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|'},
};
string move1;



int checkCheckMate() {};
//must add boolean reset and console clearing after Sleep function

//draw the gameBoard without any pieces
ChessBoard Board[8][8];
//declaring the variables that store the movement
stringstream stream; //declares a stream for transforming the variable that stores the move from const char to int later on in the game
int r1=0;
int c1=0;
int r2=0;
int c2=0;
int temp=0;
int temp1=0;
int tempCol=0;
int tempCol1=0;


//setting the Board elements to nullptr
int s=0;


//initializing the pieces for the first player:
Piece p11("Pawn", 1, 'p');
Piece p21("Pawn", 1, 'p');
Piece p31("Pawn", 1, 'p');
Piece p41("Pawn", 1, 'p');
Piece p51("Pawn", 1, 'p');
Piece p61("Pawn", 1, 'p');
Piece p71("Pawn", 1, 'p');
Piece p81("Pawn", 1, 'p');
Piece ra1("Rook", 1, 'R');
Piece nb1("Knight", 1, 'N');
Piece bc1("Bishop", 1, 'B');
Piece q1("Queen", 1, 'Q');
Piece k1("King", 1, 'K');
Piece bf1("Bishop", 1, 'B');
Piece ng1("Knight", 1, 'N');
Piece rh1("Rook", 1, 'R');
//booleans to identify pieces across the Board (to be used in move validation)
bool isP11;
bool isP21;
bool isP31;
bool isP41;
bool isP51;
bool isP61;
bool isP71;
bool isP81;
bool isRA1;
bool isNB1;
bool isBC1;
bool isQ1;
bool isK1;
bool isBF1;
bool isNG1;
bool isRH1;

//initializing the pieces for the second player:
Piece p12("Pawn12", 2, 'p');
Piece p22("Pawn22", 2, 'p');
Piece p32("Pawn32", 2, 'p');
Piece p42("Pawn42", 2, 'p');
Piece p52("Pawn52", 2, 'p');
Piece p62("Pawn62", 2, 'p');
Piece p72("Pawn72", 2, 'p');
Piece p82("Pawn82", 2, 'p');
Piece ra2("Rook92", 2, 'R');
Piece nb2("Knight", 2, 'N');
Piece bc2("Bishop", 2, 'B');
Piece q2("Queen", 2, 'Q');
Piece k2("King", 2, 'K');
Piece bf2("Bishop", 2, 'B');
Piece ng2("Knight", 2, 'N');
Piece rh2("Rook", 2, 'R');

//booleans to identify pieces across the Board (to be used in move validation)
bool isP12;
bool isP22;
bool isP32;
bool isP42;
bool isP52;
bool isP62;
bool isP72;
bool isP82;
bool isRA2;
bool isNB2;
bool isBC2;
bool isQ2;
bool isK2;
bool isBF2;
bool isNG2;
bool isRH2;

//Arranging the pieces on the "official" Board for player 1
void drawGameTable()
{
    for(int s=0; s<=8; s++)
    {
        for(int j=0; j<=8; j++)
        {
            //  if(Board[s][j]!=nullptr){
            Board[s][j]=nullptr;
            //   }
        }
    }

    Board[1][0]=&p11;
    Board[1][1]=&p21;
    Board[1][2]=&p31;
    Board[1][3]=&p41;
    Board[1][4]=&p51;
    Board[1][5]=&p61;
    Board[1][6]=&p71;
    Board[1][7]=&p81;
    Board[0][0]=&ra1;
    Board[0][1]=&nb1;
    Board[0][2]=&bc1;
    Board[0][3]=&q1;
    Board[0][4]=&k1;
    Board[0][5]=&bf1;
    Board[0][6]=&ng1;
    Board[0][7]=&rh1;

//Arranging the pieces on the "official" Board for player 2
    Board[6][0]=&p12;
    Board[6][1]=&p22;
    Board[6][2]=&p32;
    Board[6][3]=&p42;
    Board[6][4]=&p52;
    Board[6][5]=&p62;
    Board[6][6]=&p72;
    Board[6][7]=&p82;
    Board[7][0]=&ra2;
    Board[7][1]=&nb2;
    Board[7][2]=&bc2;
    Board[7][3]=&q2;
    Board[7][4]=&k2;
    Board[7][5]=&bf2;
    Board[7][6]=&ng2;
    Board[7][7]=&rh2;
}
//Arranging the pieces on the "interface" Board for player 1
void drawGUITable()
{


    interfaceBoard[7][2]=p11.initial;
    interfaceBoard[7][4]=p21.initial;
    interfaceBoard[7][6]=p31.initial;
    interfaceBoard[7][8]=p41.initial;
    interfaceBoard[7][10]=p51.initial;
    interfaceBoard[7][12]=p61.initial;
    interfaceBoard[7][14]=p71.initial;
    interfaceBoard[7][16]=p81.initial;
    interfaceBoard[8][2]=ra1.initial;
    interfaceBoard[8][4]=nb1.initial;
    interfaceBoard[8][6]=bc1.initial;
    interfaceBoard[8][8]=q1.initial;
    interfaceBoard[8][10]=k1.initial;
    interfaceBoard[8][12]=bf1.initial;
    interfaceBoard[8][14]=ng1.initial;
    interfaceBoard[8][16]=rh1.initial;

    interfaceBoard[2][2]=p12.initial;
    interfaceBoard[2][4]=p22.initial;
    interfaceBoard[2][6]=p32.initial;
    interfaceBoard[2][8]=p42.initial;
    interfaceBoard[2][10]=p52.initial;
    interfaceBoard[2][12]=p62.initial;
    interfaceBoard[2][14]=p72.initial;
    interfaceBoard[2][16]=p82.initial;
    interfaceBoard[1][2]=ra2.initial;
    interfaceBoard[1][4]=nb2.initial;
    interfaceBoard[1][6]=bc2.initial;
    interfaceBoard[1][8]=q2.initial;
    interfaceBoard[1][10]=k2.initial;
    interfaceBoard[1][12]=bf2.initial;
    interfaceBoard[1][14]=ng2.initial;
    interfaceBoard[1][16]=rh2.initial;
    for(int i=0; i<=8 ; i++)
    {
        cout<<endl;
        for(int j=0; j<=17; j++)
        {
            cout<<interfaceBoard[i][j];
        }
    }
}
int checkCheck()
{
    //check done by p1 pawn on k2
    if((Board[r1][c1].piece==&p11)||(Board[r1][c1].piece==&p21)||(Board[r1][c1].piece==&p31)||(Board[r1][c1].piece==&p41)||(Board[r1][c1].piece==&p51)||(Board[r1][c1].piece==&p61)||(Board[r1][c1].piece==&p71)||(Board[r1][c1].piece==&p81))
    {
        if((Board[r2][c2+1].piece==&k2)||(Board[r2][c2-1].piece==&k2))
        {
            return 1;
            if((Board[r2][c2+2].piece!=nullptr)||(Board[r2+1][c2+1].piece!=nullptr)||(Board[r2+1][c2+2].piece!=nullptr)||(Board[r2][c2-1].piece!=nullptr)||(Board[r2][c2-2].piece!=nullptr))
            {
                return 2;
            }
        }
    }
//check done by p1 rooks on k2
    if((Board[r1][c1].piece==&ra1)||(Board[r1][c1].piece==&rh1))
    {
        int row=0;
        int col=0;
        //col=c2;
        for(row=r2; row<=7; row++)
        {

            if(Board[row][c2].piece==nullptr)
            {
                if(Board[row][col].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }

        for(row=r2; row<=0; row--)
        {

            if(Board[row][c2].piece==nullptr)
            {
                if(Board[row][col].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }

        for(col=c2; col<=7; col++)
        {

            if(Board[r2][col].piece==nullptr)
            {
                if(Board[r2][col].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }
        for(col=c2; col<=0; col--)
        {

            if(Board[r2][col].piece==nullptr)
            {
                if(Board[r2][col].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }
    }




//check done by p1 knights on k2
    if((Board[r1][c1].piece==&nb1)||(Board[r1][c1].piece==&ng1))
    {
        if((Board[r2+2][c2+1].piece==&k2)||(Board[r2+2][c2-1].piece==&k2)||(Board[r2-2][c2+1].piece==&k2)||(Board[r2-2][c2-1].piece==&k2)||(Board[r2+1][c2+2].piece==&k2)||(Board[r2+1][c2-2].piece==&k2)||(Board[r2-1][c2+2].piece==&k2)||(Board[r2-1][c2-2].piece==&k2))
            return 1;

    }
//check done by p1 bishops on k2
    if((Board[r1][c1].piece==&bc1)||(Board[r1][c1].piece==&bf1))
    {
        int rowB=0;
        int colB=0;
        for(rowB=r2; rowB<=7; rowB++)
        {
            for(colB=c2; colB<=7; colB++)
            {
                if(Board[rowB][colB].piece==nullptr)
                {
                    if(Board[rowB][colB].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        for(rowB=r2; rowB<=7; rowB++)
        {
            for(colB=c2; colB<=0; colB--)
            {
                if(Board[rowB][colB].piece==nullptr)
                {
                    if(Board[rowB][colB].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        for(rowB=r2; rowB<=0; rowB--)
        {
            for(colB=c2; colB<=7; colB++)
            {
                if(Board[rowB][colB].piece==nullptr)
                {
                    if(Board[rowB][colB].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        for(rowB=r2; rowB<=0; rowB--)
        {
            for(colB=c2; colB<=0; colB--)
            {
                if(Board[rowB][colB].piece==nullptr)
                {
                    if(Board[rowB][colB].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
//check done by the p1 queen on k2
    if(Board[r1][c1].piece==&q1)
    {
        int rowQ=0;
        int colQ=0;
        for(rowQ=r2; rowQ<=7; rowQ++)
        {
            for(colQ=c2; colQ<=7; colQ++)
            {
                if(Board[rowQ][colQ].piece==nullptr)
                {
                    if(Board[rowQ][colQ].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        for(rowQ=r2; rowQ<=7; rowQ++)
        {
            for(colQ=c2; colQ<=0; colQ--)
            {
                if(Board[rowQ][colQ].piece==nullptr)
                {
                    if(Board[rowQ][colQ].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        for(rowQ=r2; rowQ<=0; rowQ--)
        {
            for(colQ=c2; colQ<=7; colQ++)
            {
                if(Board[rowQ][colQ].piece==nullptr)
                {
                    if(Board[rowQ][colQ].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }

        }
        for(rowQ=r2; rowQ<=0; rowQ--)
        {
            for(colQ=c2; colQ<=0; colQ--)
            {
                if(Board[rowQ][colQ].piece==nullptr)
                {
                    if(Board[rowQ][colQ].piece==&k2)
                    {
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for(rowQ=r2; rowQ<=7; rowQ++)
        {

            if(Board[rowQ][c2].piece==nullptr)
            {
                if(Board[rowQ][c2].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }

        for(rowQ=r2; rowQ<=0; rowQ--)
        {

            if(Board[rowQ][c2].piece==nullptr)
            {
                if(Board[rowQ][c2].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }

        for(colQ=c2; colQ<=7; colQ++)
        {

            if(Board[r2][colQ].piece==nullptr)
            {
                if(Board[r2][colQ].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }
        for(colQ=c2; colQ<=0; colQ--)
        {

            if(Board[r2][colQ].piece==nullptr)
            {
                if(Board[r2][colQ].piece==&k2)
                    return 1;
            }
            else
            {
                break;
            }
        }
    }
    //check done by p2 pawn on k1
    if((Board[r1][c1].piece==&p12)||(Board[r1][c1].piece==&p22)||(Board[r1][c1].piece==&p32)||(Board[r1][c1].piece==&p42)||(Board[r1][c1].piece==&p52)||(Board[r1][c1].piece==&p62)||(Board[r1][c1].piece==&p72)||(Board[r1][c1].piece==&p82))
    {
        if((Board[r2][c2+1].piece==&k1)||(Board[r2][c2-1].piece==&k1))
        {
            return 1;
            if((Board[r2][c2+2].piece!=nullptr)||(Board[r2+1][c2+1].piece!=nullptr)||(Board[r2+1][c2+2].piece!=nullptr)||(Board[r2][c2-1].piece!=nullptr)||(Board[r2][c2-2].piece!=nullptr))
            {
                return 2;
            }
        }
//check done by p2 rooks on k1
        if((Board[r1][c1].piece==&ra2)||(Board[r1][c1].piece==&rh2))
        {
            int rowP2=0;
            int colP2=0;
            //col=c2;
            for(rowP2=r2; rowP2<=7; rowP2++)
            {

                if(Board[rowP2][c2].piece==nullptr)
                {
                    if(Board[rowP2][c2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }

            for(rowP2=r2; rowP2<=0; rowP2--)
            {

                if(Board[rowP2][c2].piece==nullptr)
                {
                    if(Board[rowP2][c2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }

            for(colP2=c2; colP2<=7; colP2++)
            {

                if(Board[r2][colP2].piece==nullptr)
                {
                    if(Board[r2][colP2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }
            for(colP2=c2; colP2<=0; colP2--)
            {

                if(Board[r2][colP2].piece==nullptr)
                {
                    if(Board[r2][colP2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }
        }
//check done by p2 knights on k1
        if((Board[r1][c1].piece==&nb2)||(Board[r1][c1].piece==&ng2))
        {
            if((Board[r2+2][c2+1].piece==&k1)||(Board[r2+2][c2-1].piece==&k1)||(Board[r2-2][c2+1].piece==&k1)||(Board[r2-2][c2-1].piece==&k1)||(Board[r2+1][c2+2].piece==&k1)||(Board[r2+1][c2-2].piece==&k1)||(Board[r2-1][c2+2].piece==&k1)||(Board[r2-1][c2-2].piece==&k1))
                return 1;

        }
//check done by p2 bishops on k1
        if((Board[r1][c1].piece==&bc2)||(Board[r1][c1].piece==&bf2))
        {
            int rowBP2=0;
            int colBP2=0;
            for(rowBP2=r2; rowBP2<=7; rowBP2++)
            {
                for(colBP2=c2; colBP2<=7; colBP2++)
                {
                    if(Board[rowBP2][colBP2].piece==nullptr)
                    {
                        if(Board[rowBP2][colBP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

            }
            for(rowBP2=r2; rowBP2<=7; rowBP2++)
            {
                for(colBP2=c2; colBP2<=0; colBP2--)
                {
                    if(Board[rowBP2][colBP2].piece==nullptr)
                    {
                        if(Board[rowBP2][colBP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

            }
            for(rowBP2=r2; rowBP2<=0; rowBP2--)
            {
                for(colBP2=c2; colBP2<=7; colBP2++)
                {
                    if(Board[rowBP2][colBP2].piece==nullptr)
                    {
                        if(Board[rowBP2][colBP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

            }
            for(rowBP2=r2; rowBP2<=0; rowBP2--)
            {
                for(colBP2=c2; colBP2<=0; colBP2--)
                {
                    if(Board[rowBP2][colBP2].piece==nullptr)
                    {
                        if(Board[rowBP2][colBP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
//check done by the p2 queen on k1
        if(Board[r1][c1].piece==&q2)
        {
            int rowQP2=0;
            int colQP2=0;
            for(rowQP2=r2; rowQP2<=7; rowQP2++)
            {
                for(colQP2=c2; colQP2<=7; colQP2++)
                {
                    if(Board[rowQP2][colQP2].piece==nullptr)
                    {
                        if(Board[rowQP2][colQP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

            }
            for(rowQP2=r2; rowQP2<=7; rowQP2++)
            {
                for(colQP2=c2; colQP2<=0; colQP2--)
                {
                    if(Board[rowQP2][colQP2].piece==nullptr)
                    {
                        if(Board[rowQP2][colQP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

            }
            for(rowQP2=r2; rowQP2<=0; rowQP2--)
            {
                for(colQP2=c2; colQP2<=7; colQP2++)
                {
                    if(Board[rowQP2][colQP2].piece==nullptr)
                    {
                        if(Board[rowQP2][colQP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

            }
            for(rowQP2=r2; rowQP2<=0; rowQP2--)
            {
                for(colQP2=c2; colQP2<=0; colQP2--)
                {
                    if(Board[rowQP2][colQP2].piece==nullptr)
                    {
                        if(Board[rowQP2][colQP2].piece==&k1)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for(rowQP2=r2; rowQP2<=7; rowQP2++)
            {

                if(Board[rowQP2][c2].piece==nullptr)
                {
                    if(Board[rowQP2][c2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }

            for(rowQP2=r2; rowQP2<=0; rowQP2--)
            {

                if(Board[rowQP2][c2].piece==nullptr)
                {
                    if(Board[rowQP2][c2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }

            for(colQP2=c2; colQP2<=7; colQP2++)
            {

                if(Board[r2][colQP2].piece==nullptr)
                {
                    if(Board[r2][colQP2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }
            for(colQP2=c2; colQP2<=0; colQP2--)
            {

                if(Board[r2][colQP2].piece==nullptr)
                {
                    if(Board[r2][colQP2].piece==&k1)
                        return 1;
                }
                else
                {
                    break;
                }
            }


        }


        return 0;
    };
}
void checkRules()
{
    cout<<endl<<"second turn is "<<secondTurn<<endl;

    if(secondTurn==1)
    {
        stream.clear();
    }

    stream<<move1[1];
    stream>>r1;
    r1=r1-1;
    if(move1[0]=='a')
        c1=0;
    else if(move1[0]=='b')
        c1=1;
    else if(move1[0]=='c')
        c1=2;
    else if(move1[0]=='d')
        c1=3;
    else if(move1[0]=='e')
        c1=4;
    else if(move1[0]=='f')
        c1=5;
    else if(move1[0]=='g')
        c1=6;
    else if(move1[0]=='h')
        c1=7;
    //Evaluate where the piece is going
    stream.clear();
    stream<<move1[5];
    stream>>r2;
    r2=r2-1;

    if(move1[4]=='a')
        c2=0;
    else if(move1[4]=='b')
        c2=1;
    else if(move1[4]=='c')
        c2=2;
    else if(move1[4]=='d')
        c2=3;
    else if(move1[4]=='e')
        c2=4;
    else if(move1[4]=='f')
        c2=5;
    else if(move1[4]=='g')
        c2=6;
    else if(move1[4]=='h')
        c2=7;
    stream.clear();

    {
        if((Board[r1][c1].piece==&p11)||(Board[r1][c1].piece==&p21)||(Board[r1][c1].piece==&p31)||(Board[r1][c1].piece==&p41)||(Board[r1][c1].piece==&p51)||(Board[r1][c1].piece==&p61)||(Board[r1][c1].piece==&p71))
        {
            //not allowed to move two squares
            if((r1!=1)&&(r2!=r1+2))
            {
                moveIntegrity=0;
            }
            //though you can if at your opening move
            if((r1==1)&&(r2==3)&&(c1==c2))
            {
                moveIntegrity=1;
            }

            //taking a piece
            if((r2==r1+1)&&((Board[r2][c2+1].piece!=nullptr)&&(c2+1<=7))||((Board[r2][c2-1].piece!=nullptr)&&(c2-1>=0)))
            {
                moveIntegrity=1;
            }
            //allowed to go one square at a time
            if((Board[r2][c2].piece==nullptr)&&(r2==r1+1)&&(c1==c2))
            {
                moveIntegrity=1;
            }
            //not allowed to take the piece in front of him
            if((Board[r2][c2].piece!=nullptr)&&(c2==0))
            {
                moveIntegrity=0;
            }

        };
        secondTurn=1;
    }
    {



        if((Board[r1][c1].piece==&p12)||(Board[r1][c1].piece==&p22)||(Board[r1][c1].piece==&p32)||(Board[r1][c1].piece==&p42)||(Board[r1][c1].piece==&p52)||(Board[r1][c1].piece==&p62)||(Board[r1][c1].piece==&p72))
        {

            //not allowed to move two squares
            if((r1!=6)&&(r2>=r1-2))
            {
                moveIntegrity=0;
            }
            //though you can if you are at your opening move
            if((r1==6)&&(r2==4)&&(c1==c2))
            {
                moveIntegrity=1;
            }

            //taking a piece
            if((r2==r1+1)&&((Board[r2][c2].piece!=nullptr)&&(c2<=6))||((Board[r2][c2].piece!=nullptr)&&(c2>=0)))
            {
                moveIntegrity=1;
            }
            //allowed to go one square at a time
            if((Board[r2][c2].piece==nullptr)&&(r2==r1-1)&&(c1==c2))
            {
                moveIntegrity=1;
            }
            //not allowed to take the piece in front of him
            if((Board[r2][c2].piece!=nullptr)&&(c2==c1))
            {
                moveIntegrity=0;
            }
            ;//secondTurn=0;
        }
    }
    {
//move for rooks
        if(((Board[r1][c1].piece==&ra1)||(Board[r1][c1].piece==&rh1))&&(playerTurn==0))
        {

            if((c1==c2)||(r1==r2))
            {
                moveIntegrity=1;
                if(c1!=c2)
                {
                    int c3=0;
                    c3=(c2-c1)-1;
                    for(int o=1; o<=c3; o++)
                    {
                        if(Board[r1][c1+o].piece==nullptr)
                        {
                            moveIntegrity=1;
                        }
                        else
                        {
                            moveIntegrity=0;
                            break;
                        }

                    }
                }
                if(r1!=r2)
                {
                    int r3=0;
                    r3=(r2-r1)-1;
                    for(int o=0; o<=r3; o++)
                    {
                        if(Board[r1+o][c1].piece==nullptr)
                        {
                            moveIntegrity=1;
                        }
                        else
                        {
                            moveIntegrity=0;
                        }

                    }
                }
                if((Board[r2][c2].piece==&p11)&&(Board[r2][c2].piece==&p21)&&(Board[r2][c2].piece==&p31)&&(Board[r2][c2].piece==&p41)&&(Board[r2][c2].piece==&p51)&&(Board[r2][c2].piece==&p61)&&(Board[r2][c2].piece==&p71)&&(Board[r2][c2].piece==&p81)&&(Board[r2][c2].piece==&nb1)&&(Board[r2][c2].piece==&bc1)&&(Board[r2][c2].piece==&q1)&&(Board[r2][c2].piece==&k1)&&(Board[r2][c2].piece==&bf1)&&(Board[r2][c2].piece==&ng1)&&(Board[r2][c2].piece==&k2))
                {
                    moveIntegrity=0;
                }
            }
        }
    }
//move for knights, player 1
    if((Board[r1][c1].piece==&nb1)||(Board[r1][c1].piece==&ng1))
    {
        if(((r2==r1+2)&&((c2==c1+1)||(c2==c1-1)))||(c2==c1+2)&&((r2==r1+1)||(r2==r1-1))||((r2==r1-2)&&((c2==c1+1)||(c2==c1-1)))||(c2==c1-2)&&((r2==r1+1)||(r2==r1-1)))
        {
            moveIntegrity=1;
        }
        if((Board[r2][c2].piece==&p11)&&(Board[r2][c2].piece==&p21)&&(Board[r2][c2].piece==&p31)&&(Board[r2][c2].piece==&p41)&&(Board[r2][c2].piece==&p51)&&(Board[r2][c2].piece==&p61)&&(Board[r2][c2].piece==&p71)&&(Board[r2][c2].piece==&p81)&&(Board[r2][c2].piece==&ra1)&&(Board[r2][c2].piece==&bc1)&&(Board[r2][c2].piece==&q1)&&(Board[r2][c2].piece==&k1)&&(Board[r2][c2].piece==&bf1)&&(Board[r2][c2].piece==&rh1)&&(Board[r2][c2].piece==&k2))
        {
            moveIntegrity=0;
        }


    }

    if((Board[r1][c1].piece==&bc1)||(Board[r1][c1].piece==&bf1))
    {
        if(((r2==r1+1)&&(c2==c1+1))||((r2==r1+2)&&(c2==c1+2))||((r2==r1+3)&&(c2==c1+3))||((r2==r1+4)&&(c2==c1+4))||((r2==r1+5)&&(c2==c1+5))||((r2==r1+6)&&(c2==c1+6))||((r2==r1+7)&&(c2==c1+7))||((r2==r1+8)&&(c2==c1+8)))
        {
            for(int i=r1+1; i<r2; i++)
            {
                for(int s=c1+1; s<c2; s++)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                        i++;
                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }

                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }

        }
        if(((r2==r1-1)&&(c2==c1-1))||((r2==r1-2)&&(c2==c1-2))||((r2==r1-3)&&(c2==c1-3))||((r2==r1-4)&&(c2==c1-4))||((r2==r1-5)&&(c2-c1-5))||((r2==r1-6)&&(c2==c1-6))||((r2==r1-7)&&(c2==c1-7))||((r2==r1-8)&&(c2==c1-8)))
        {

            for(int i=r2-1; i>r1; i--)
            {
                for(int s=c2-1; s>c1; s--)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                    }
                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }
            //moveIntegrity=1;
        }
        if(((r2==r1-1)&&(c2==c1+1))||((r2==r1-2)&&(c2==c1+2))||((r2==r1-3)&&(c2==c1+3))||((r2==r1-4)&&(c2==c1+4))||((r2==r1-5)&&(c2-c1+5))||((r2==r1-6)&&(c2==c1+6))||((r2==r1-7)&&(c2==c1+7))||((r2==r1-8)&&(c2==c1+8)))
        {
            for(int i=r2-1; i>r1; i--)
            {
                for(int s=c1+1; s<c2; s++)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                    }

                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }



        }
        if(((r2==r1+1)&&(c2==c1-1))||((r2==r1+2)&&(c2==c1-2))||((r2==r1+3)&&(c2==c1-3))||((r2==r1+4)&&(c2==c1-4))||((r2==r1+5)&&(c2-c1-5))||((r2==r1+6)&&(c2==c1-6))||((r2==r1+7)&&(c2==c1-7))||((r2==r1+8)&&(c2==c1-18)))
        {
            for(int i=r1+1; i<r2; i++)
            {
                for(int s=c2-1; s>c1; s--)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                    }
                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }



            // moveIntegrity=1;
        }
        if(((c2==c1+1)&&(r2==r1+1))||((c2==c1-1)&&(r2==r2-1))||((c2==c1+1)&&(r2==r1-1))||((c2==c1-1)&&(r2==r1+1)))
        {
            if((Board[r2][c2].piece!=&p11)&&(Board[r2][c2].piece!=&p21)&&(Board[r2][c2].piece!=&p31)&&(Board[r2][c2].piece!=&p41)&&(Board[r2][c2].piece!=&p51)&&(Board[r2][c2].piece!=&p61)&&(Board[r2][c2].piece!=&p71)&&(Board[r2][c2].piece!=&p81)&&(Board[r2][c2].piece!=&ra1)&&(Board[r2][c2].piece!=&nb1)&&(Board[r2][c2].piece!=&q1)&&(Board[r2][c2].piece!=&k1)&&(Board[r2][c2].piece!=&ng1)&&(Board[r2][c2].piece!=&rh1)&&(Board[r2][c2].piece!=&k2))

            {
                moveIntegrity=1;
            }
        }
    }
//move for queen player 1
    {
        if((Board[r1][c1].piece==&q1)&&(playerTurn==0))
        {

            if((c1==c2)||(r1==r2))
            {
                moveIntegrity=1;
                if(c1!=c2)
                {
                    int c3=0;
                    c3=(c2-c1)-1;
                    for(int o=1; o<=c3; o++)
                    {
                        if(Board[r1][c1+o].piece==nullptr)
                        {
                            moveIntegrity=1;
                        }
                        else
                        {
                            moveIntegrity=0;
                            break;
                        }

                    }
                }
                if(r1!=r2)
                {
                    int r3=0;
                    r3=(r2-r1)-1;
                    for(int o=1; o<=r3; o++)
                    {
                        if(Board[r1+o][c1].piece==nullptr)
                        {
                            moveIntegrity=1;
                        }
                        else
                        {
                            moveIntegrity=0;
                            break;
                        }

                    }
                }
                if((Board[r2][c2].piece==&p11)&&(Board[r2][c2].piece==&p21)&&(Board[r2][c2].piece==&p31)&&(Board[r2][c2].piece==&p41)&&(Board[r2][c2].piece==&p51)&&(Board[r2][c2].piece==&p61)&&(Board[r2][c2].piece==&p71)&&(Board[r2][c2].piece==&p81)&&(Board[r2][c2].piece==&nb1)&&(Board[r2][c2].piece==&bc1)&&(Board[r2][c2].piece==&ra1)&&(Board[r2][c2].piece==&k1)&&(Board[r2][c2].piece==&bf1)&&(Board[r2][c2].piece==&ng1)&&(Board[r2][c2].piece==&k2)&&(Board[r2][c2].piece==&rh1))
                {
                    moveIntegrity=0;
                }
            }
            if(((r2==r1+1)&&(c2==c1+1))||((r2==r1+2)&&(c2==c1+2))||((r2==r1+3)&&(c2==c1+3))||((r2==r1+4)&&(c2==c1+4))||((r2==r1+5)&&(c2==c1+5))||((r2==r1+6)&&(c2==c1+6))||((r2==r1+7)&&(c2==c1+7))||((r2==r1+8)&&(c2==c1+8)))
            {
                for(int i=r1+1; i<r2; i++)
                {
                    for(int s=c1+1; s<c2; s++)
                    {
                        if(Board[i][s].piece!=nullptr)
                        {
                            moveIntegrity=0;
                            break;
                        }
                        else
                        {
                            moveIntegrity=1;
                            i++;
                        }
                        if(moveIntegrity==0)
                        {
                            break;
                        }

                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }
                }

            }
            if(((r2==r1-1)&&(c2==c1-1))||((r2==r1-2)&&(c2==c1-2))||((r2==r1-3)&&(c2==c1-3))||((r2==r1-4)&&(c2==c1-4))||((r2==r1-5)&&(c2-c1-5))||((r2==r1-6)&&(c2==c1-6))||((r2==r1-7)&&(c2==c1-7))||((r2==r1-8)&&(c2==c1-8)))
            {

                for(int i=r2-1; i>r1; i--)
                {
                    for(int s=c2-1; s>c1; s--)
                    {
                        if(Board[i][s].piece!=nullptr)
                        {
                            moveIntegrity=0;
                            break;
                        }
                        else
                        {
                            moveIntegrity=1;
                        }
                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }
                }
                //moveIntegrity=1;
            }
            if(((r2==r1-1)&&(c2==c1+1))||((r2==r1-2)&&(c2==c1+2))||((r2==r1-3)&&(c2==c1+3))||((r2==r1-4)&&(c2==c1+4))||((r2==r1-5)&&(c2-c1+5))||((r2==r1-6)&&(c2==c1+6))||((r2==r1-7)&&(c2==c1+7))||((r2==r1-8)&&(c2==c1+8)))
            {
                for(int i=r2-1; i>r1; i--)
                {
                    for(int s=c1+1; s<c2; s++)
                    {
                        if(Board[i][s].piece!=nullptr)
                        {
                            moveIntegrity=0;
                            break;
                        }
                        else
                        {
                            moveIntegrity=1;
                        }

                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }
                }



            }
            if(((r2==r1+1)&&(c2==c1-1))||((r2==r1+2)&&(c2==c1-2))||((r2==r1+3)&&(c2==c1-3))||((r2==r1+4)&&(c2==c1-4))||((r2==r1+5)&&(c2-c1-5))||((r2==r1+6)&&(c2==c1-6))||((r2==r1+7)&&(c2==c1-7))||((r2==r1+8)&&(c2==c1-18)))
            {
                for(int i=r1+1; i<r2; i++)
                {
                    for(int s=c2-1; s>c1; s--)
                    {
                        if(Board[i][s].piece!=nullptr)
                        {
                            moveIntegrity=0;
                            break;
                        }
                        else
                        {
                            moveIntegrity=1;
                        }
                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }
                }



                // moveIntegrity=1;
            }
            if(((c2==c1+1)&&(r2==r1+1))||((c2==c1-1)&&(r2==r2-1))||((c2==c1+1)&&(r2==r1-1))||((c2==c1-1)&&(r2==r1+1)))
            {

            }
        }

        {

//move for queen player 2
            {
                if((Board[r1][c1].piece==&q2)&&(playerTurn==0))
                {

                    if((c1==c2)||(r1==r2))
                    {
                        moveIntegrity=1;
                        if(c1!=c2)
                        {
                            int c3=0;
                            c3=(c2-c1)-1;
                            for(int o=1; o<=c3; o++)
                            {
                                if(Board[r1][c1+o].piece==nullptr)
                                {
                                    moveIntegrity=1;
                                }
                                else
                                {
                                    moveIntegrity=0;
                                    break;
                                }

                            }
                        }
                        if(r1!=r2)
                        {
                            int r3=0;
                            r3=(r2-r1)-1;
                            for(int o=1; o<=r3; o++)
                            {
                                if(Board[r1+o][c1].piece==nullptr)
                                {
                                    moveIntegrity=1;
                                }
                                else
                                {
                                    moveIntegrity=0;
                                    break;
                                }

                            }
                        }
                        if((Board[r2][c2].piece==&p12)&&(Board[r2][c2].piece==&p22)&&(Board[r2][c2].piece==&p32)&&(Board[r2][c2].piece==&p42)&&(Board[r2][c2].piece==&p52)&&(Board[r2][c2].piece==&p62)&&(Board[r2][c2].piece==&p72)&&(Board[r2][c2].piece==&p82)&&(Board[r2][c2].piece==&nb2)&&(Board[r2][c2].piece==&bc2)&&(Board[r2][c2].piece==&ra2)&&(Board[r2][c2].piece==&k2)&&(Board[r2][c2].piece==&bf2)&&(Board[r2][c2].piece==&ng2)&&(Board[r2][c2].piece==&k1)&&(Board[r2][c2].piece==&rh2))
                        {
                            moveIntegrity=0;
                        }
                    }
                    if(((r2==r1+1)&&(c2==c1+1))||((r2==r1+2)&&(c2==c1+2))||((r2==r1+3)&&(c2==c1+3))||((r2==r1+4)&&(c2==c1+4))||((r2==r1+5)&&(c2==c1+5))||((r2==r1+6)&&(c2==c1+6))||((r2==r1+7)&&(c2==c1+7))||((r2==r1+8)&&(c2==c1+8)))
                    {
                        for(int i=r1+1; i<r2; i++)
                        {
                            for(int s=c1+1; s<c2; s++)
                            {
                                if(Board[i][s].piece!=nullptr)
                                {
                                    moveIntegrity=0;
                                    break;
                                }
                                else
                                {
                                    moveIntegrity=1;
                                    i++;
                                }
                                if(moveIntegrity==0)
                                {
                                    break;
                                }

                            }
                            if(moveIntegrity==0)
                            {
                                break;
                            }
                        }

                    }
                    if(((r2==r1-1)&&(c2==c1-1))||((r2==r1-2)&&(c2==c1-2))||((r2==r1-3)&&(c2==c1-3))||((r2==r1-4)&&(c2==c1-4))||((r2==r1-5)&&(c2-c1-5))||((r2==r1-6)&&(c2==c1-6))||((r2==r1-7)&&(c2==c1-7))||((r2==r1-8)&&(c2==c1-8)))
                    {

                        for(int i=r2-1; i>r1; i--)
                        {
                            for(int s=c2-1; s>c1; s--)
                            {
                                if(Board[i][s].piece!=nullptr)
                                {
                                    moveIntegrity=0;
                                    break;
                                }
                                else
                                {
                                    moveIntegrity=1;
                                }
                            }
                            if(moveIntegrity==0)
                            {
                                break;
                            }
                        }
                        //moveIntegrity=1;
                    }
                    if(((r2==r1-1)&&(c2==c1+1))||((r2==r1-2)&&(c2==c1+2))||((r2==r1-3)&&(c2==c1+3))||((r2==r1-4)&&(c2==c1+4))||((r2==r1-5)&&(c2-c1+5))||((r2==r1-6)&&(c2==c1+6))||((r2==r1-7)&&(c2==c1+7))||((r2==r1-8)&&(c2==c1+8)))
                    {
                        for(int i=r2-1; i>r1; i--)
                        {
                            for(int s=c1+1; s<c2; s++)
                            {
                                if(Board[i][s].piece!=nullptr)
                                {
                                    moveIntegrity=0;
                                    break;
                                }
                                else
                                {
                                    moveIntegrity=1;
                                }

                            }
                            if(moveIntegrity==0)
                            {
                                break;
                            }
                        }



                    }
                }
            }
            if(((r2==r1+1)&&(c2==c1-1))||((r2==r1+2)&&(c2==c1-2))||((r2==r1+3)&&(c2==c1-3))||((r2==r1+4)&&(c2==c1-4))||((r2==r1+5)&&(c2-c1-5))||((r2==r1+6)&&(c2==c1-6))||((r2==r1+7)&&(c2==c1-7))||((r2==r1+8)&&(c2==c1-18)))
            {
                for(int i=r1+1; i<r2; i++)
                {
                    for(int s=c2-1; s>c1; s--)
                    {
                        if(Board[i][s].piece!=nullptr)
                        {
                            moveIntegrity=0;
                            break;
                        }
                        else
                        {
                            moveIntegrity=1;
                        }
                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }
                }



                // moveIntegrity=1;
            }
            if(((c2==c1+1)&&(r2==r1+1))||((c2==c1-1)&&(r2==r2-1))||((c2==c1+1)&&(r2==r1-1))||((c2==c1-1)&&(r2==r1+1)))
            {

            }
        }
        //move for rooks, player 2
//move for rooks, player 2
        if(((Board[r1][c1].piece==&ra2)||(Board[r1][c1].piece==&rh2))&&(playerTurn==0))
        {

            if((c1==c2)||(r1==r2))
            {
                moveIntegrity=1;
                if(c1!=c2)
                {
                    int c3=0;
                    c3=(c2-c1)-1;
                    for(int o=1; o<=c3; o++)
                    {
                        if(Board[r1][c1+o].piece==nullptr)
                        {
                            moveIntegrity=1;

                        }
                        else
                        {
                            moveIntegrity=0;
                            break;
                        }

                    }
                }
                if(r1!=r2)
                {
                    int r3=0;
                    r3=(r1-r2)-1;
                    for(int o=0; o<=r3; o++)
                    {
                        if(Board[r2+o][c1].piece==nullptr)
                        {
                            moveIntegrity=1;
                        }
                        else
                        {
                            moveIntegrity=0;
                        }

                    }
                }
                if((Board[r2][c2].piece==&p12)&&(Board[r2][c2].piece==&p22)&&(Board[r2][c2].piece==&p32)&&(Board[r2][c2].piece==&p42)&&(Board[r2][c2].piece==&p52)&&(Board[r2][c2].piece==&p62)&&(Board[r2][c2].piece==&p72)&&(Board[r2][c2].piece==&p82)&&(Board[r2][c2].piece==&nb2)&&(Board[r2][c2].piece==&bc2)&&(Board[r2][c2].piece==&q2)&&(Board[r2][c2].piece==&k2)&&(Board[r2][c2].piece==&bf2)&&(Board[r2][c2].piece==&ng2)&&(Board[r2][c2].piece==&k1))
                {
                    moveIntegrity=0;
                }
            }
        }
    }
    {
        //checking validity of knight moves, player 2
        if((Board[r1][c1].piece==&nb2)||(Board[r1][c1].piece==&ng2))
        {
            if(((r2==r1+2)&&((c2=c1+1)||(c2==c1-1)))||(c2==c1+2)&&((r2==r1+1)||(r2==r1-1))||((r2==r1-2)&&((c2==c1+1)||(c2==c1-1)))||(c2==c1-2)&&((r2==r1+1)||(r2==r1-1)))
            {
                moveIntegrity=1;
            }
            if((Board[r2][c2].piece==&p12)&&(Board[r2][c2].piece==&p22)&&(Board[r2][c2].piece==&p32)&&(Board[r2][c2].piece==&p42)&&(Board[r2][c2].piece==&p52)&&(Board[r2][c2].piece==&p62)&&(Board[r2][c2].piece==&p72)&&(Board[r2][c2].piece==&p82)&&(Board[r2][c2].piece==&ra2)&&(Board[r2][c2].piece==&bc2)&&(Board[r2][c2].piece==&q2)&&(Board[r2][c2].piece==&k2)&&(Board[r2][c2].piece==&bf2)&&(Board[r2][c2].piece==&rh2)&&(Board[r2][c2].piece==&k2))
            {
                moveIntegrity=0;
            }


        }


    }
    //move for bishops, player 2
    if((Board[r1][c1].piece==&bc2)||(Board[r1][c1].piece==&bf2))
    {
        if(((r2==r1+1)&&(c2==c1+1))||((r2==r1+2)&&(c2==c1+2))||((r2==r1+3)&&(c2==c1+3))||((r2==r1+4)&&(c2==c1+4))||((r2==r1+5)&&(c2==c1+5))||((r2==r1+6)&&(c2==c1+6))||((r2==r1+7)&&(c2==c1+7))||((r2==r1+8)&&(c2==c1+8)))
        {
            for(int i=r1+1; i<r2; i++)
            {
                for(int s=c1+1; s<c2; s++)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;

                    }
                    else
                    {
                        moveIntegrity=1;
                    }
                    if(moveIntegrity==0)
                    {
                        break;
                    }
                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }


        }
        if(((r2==r1-1)&&(c2==c1-1))||((r2==r1-2)&&(c2==c1-2))||((r2==r1-3)&&(c2==c1-3))||((r2==r1-4)&&(c2==c1-4))||((r2==r1-5)&&(c2-c1-5))||((r2==r1-6)&&(c2==c1-6))||((r2==r1-7)&&(c2==c1-7))||((r2==r1-8)&&(c2==c1-8)))
        {

            for(int i=r2-1; i>r1; i--)
            {
                for(int s=c2-1; s>c1; s--)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                    }
                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }
            //moveIntegrity=1;
        }
        if(((r2==r1-1)&&(c2==c1+1))||((r2==r1-2)&&(c2==c1+2))||((r2==r1-3)&&(c2==c1+3))||((r2==r1-4)&&(c2==c1+4))||((r2==r1-5)&&(c2-c1+5))||((r2==r1-6)&&(c2==c1+6))||((r2==r1-7)&&(c2==c1+7))||((r2==r1-8)&&(c2==c1+8)))
        {
            for(int i=r2-1; i>r1; i--)
            {
                for(int s=c1+1; s<c2; s++)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                    }

                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }



        }
        if(((r2==r1+1)&&(c2==c1-1))||((r2==r1+2)&&(c2==c1-2))||((r2==r1+3)&&(c2==c1-3))||((r2==r1+4)&&(c2==c1-4))||((r2==r1+5)&&(c2-c1-5))||((r2==r1+6)&&(c2==c1-6))||((r2==r1+7)&&(c2==c1-7))||((r2==r1+8)&&(c2==c1-8)))
        {
            for(int i=r1+1; i<r2; i++)
            {
                for(int s=c2-1; s>c1; s--)
                {
                    if(Board[i][s].piece!=nullptr)
                    {
                        moveIntegrity=0;
                        break;
                    }
                    else
                    {
                        moveIntegrity=1;
                    }
                }
                if(moveIntegrity==0)
                {
                    break;
                }
            }



            // moveIntegrity=1;
        }
        if(((c2==c1+1)&&(r2==r1+1))||((c2==c1-1)&&(r2==r2-1))||((c2==c1+1)&&(r2==r1-1))||((c2==c1-1)&&(r2==r1+1)))
        {
            if((Board[r2][c2].piece!=&p12)&&(Board[r2][c2].piece!=&p22)&&(Board[r2][c2].piece!=&p32)&&(Board[r2][c2].piece!=&p42)&&(Board[r2][c2].piece!=&p52)&&(Board[r2][c2].piece!=&p62)&&(Board[r2][c2].piece!=&p72)&&(Board[r2][c2].piece!=&p82)&&(Board[r2][c2].piece!=&ra2)&&(Board[r2][c2].piece!=&nb2)&&(Board[r2][c2].piece!=&q2)&&(Board[r2][c2].piece!=&k2)&&(Board[r2][c2].piece!=&ng2)&&(Board[r2][c2].piece!=&rh2)&&(Board[r2][c2].piece!=&k2))

            {
                moveIntegrity=1;
            }
        }
    }
}


int main()
{
    system("cls");
    drawGameTable();
    drawGUITable();



    while(1!=0)
    {
        cout<<endl;
        if(playerTurn==0)
        {
            cout<<"Player 1, please enter your move: "<<endl;

            cin>>move1;
            moveIntegrity=0;

            //Verify move integrity


            while(moveIntegrity!=1)
            {


                checkRules();

                if(move1[0]!='a'&&move1[0]!='b'&&move1[0]!='c'&&move1[0]!='d'&&move1[0]!='e'&&move1[0]!='f'&&move1[0]!='g'&&move1[0]!='h')
                {
                    cout<<"The reference of the table column is unknown"<<endl;
                    cout<<"Player 1, please re-enter your move: "<<endl;
                    cin>>move1;
                }
                if(move1[4]!='a'&&move1[4]!='b'&&move1[4]!='c'&&move1[4]!='d'&&move1[4]!='e'&&move1[4]!='f'&&move1[4]!='g'&&move1[4]!='h')
                {
                    cout<<"The reference of the table column where you want to move your piece is unknown"<<endl;
                    cout<<"Player 1, please re-enter your move: "<<endl;
                    cin>>move1;
                }
                if(move1[1]!='1'&&move1[1]!='2'&&move1[1]!='3'&&move1[1]!='4'&&move1[1]!='5'&&move1[1]!='6'&&move1[1]!='7'&&move1[1]!='8')
                {
                    cout<<"The reference of the table row where you want to move your piece is unknown"<<endl;
                    cout<<"Player 1, please re-enter your move: "<<endl;
                    cin>>move1;
                }
                if(move1.length()!=6)
                {
                    {
                        cout<<"The move input parameter has more or less than 6 characters"<<endl;
                        cout<<"Player 1, please re-enter your move: "<<endl;
                        cin>>move1;
                    }
                }

                if(checkCheck()>0)
                {
                    moveIntegrity=0;
                }

                if(moveIntegrity==1) //Basically processing the move by first identifying the row where the piece that you want to move is placed
                {
                    //moveIntegrity=1;
                    stream.clear();
                    stream<<move1[1];
                    stream>>r1;
                    r1=r1-1;
                    if(move1[0]=='a')
                        c1=0;
                    else if(move1[0]=='b')
                        c1=1;
                    else if(move1[0]=='c')
                        c1=2;
                    else if(move1[0]=='d')
                        c1=3;
                    else if(move1[0]=='e')
                        c1=4;
                    else if(move1[0]=='f')
                        c1=5;
                    else if(move1[0]=='g')
                        c1=6;
                    else if(move1[0]=='h')
                        c1=7;
                    //Evaluate where the piece is going
                    stream.clear();
                    stream<<move1[5];
                    stream>>r2;
                    r2=r2-1;
                    if(move1[4]=='a')
                        c2=0;
                    else if(move1[4]=='b')
                        c2=1;
                    else if(move1[4]=='c')
                        c2=2;
                    else if(move1[4]=='d')
                        c2=3;
                    else if(move1[4]=='e')
                        c2=4;
                    else if(move1[4]=='f')
                        c2=5;
                    else if(move1[4]=='g')
                        c2=6;
                    else if(move1[4]=='h')
                        c2=7;

                    if(moveIntegrity==1)
                    {
                        cout<<"Your move has been processed"<<endl;

                        playerTurn=1;
                    }
                }

                else
                {
                    cout<<"Your move is against the rules or you are in check!"<<endl;
                    cout<<"Player 1, please re-enter your move: "<<endl;
                    cin>>move1;
                }
            }






//move for first pawn, player 1
            if(Board[r1][c1].piece==&p11)
            {
                isP11=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p11;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }
//move for second pawn, player 1
            if(Board[r1][c1].piece==&p21)
            {
                isP21=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p21;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }


            }
//move for third pawn, player 1
            if(Board[r1][c1].piece==&p31)
            {
                isP31=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p31;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }

            }

//move for fourth pawn, player 1
            if(Board[r1][c1].piece==&p41)
            {
                isP41=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }

                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p41;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

//move for fifth pawn, player 1
            if(Board[r1][c1].piece==&p51)
            {
                isP51=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p51;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }
//move for sixth pawn, player 1
            if(Board[r1][c1].piece==&p61)
            {
                isP61=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p61;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

//move for seventh pawn, player 1
            if(Board[r1][c1].piece==&p71)
            {
                isP71=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p71;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }
//move for eighth pawn, player 1
            if(Board[r1][c1].piece==&p81)
            {
                isP81=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&p81;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='p';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

//move for the A rook, player 1
            if(Board[r1][c1].piece==&ra1)
            {
                isRA1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&ra1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='R';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

//move for B knight, player 1
            if(Board[r1][c1].piece==&nb1)
            {
                isNB1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&nb1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='N';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }
//move for C bishop, player 1
            if(Board[r1][c1].piece==&bc1)
            {
                isBC1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&bc1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='B';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }
            //move for king, player 1
            if(Board[r1][c1].piece==&k1)
            {
                isK1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&k1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='K';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

            //move for queen, player 1
            if(Board[r1][c1].piece==&q1)
            {
                isQ1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&q1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='Q';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

            //move for f bishop, player 1
            if(Board[r1][c1].piece==&bf1)
            {
                isBF1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&bf1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='B';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

            //move for G knight, player 1
            if(Board[r1][c1].piece==&ng1)
            {
                isNG1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&ng1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='N';
                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }

//move for H rook, player 1
            if(Board[r1][c1].piece==&rh1)
            {
                isRH1=1;
                Board[r1][c1]=nullptr;
                if(r1==7)
                {
                    temp1=1;
                }
                if(r1==6)
                {
                    temp1=2;
                }
                if(r1==5)
                {
                    temp1=3;
                }
                if(r1==4)
                {
                    temp1=4;
                }
                if(r1==3)
                {
                    temp1=5;
                }
                if(r1==2)
                {
                    temp1=6;
                }
                if(r1==1)
                {
                    temp1=7;
                }
                if(r1==0)
                {
                    temp1=8;
                }
                if(r2==7)
                {
                    temp=1;
                }
                if(r2==6)
                {
                    temp=2;
                }
                if(r2==5)
                {
                    temp=3;
                }
                if(r2==4)
                {
                    temp=4;
                }
                if(r2==3)
                {
                    temp=5;
                }
                if(r2==2)
                {
                    temp=6;
                }
                if(r2==1)
                {
                    temp=7;
                }
                if(r2==0)
                {
                    temp=8;
                }
                if(c1==0)
                {
                    tempCol=2;
                }
                if(c1==1)
                {
                    tempCol=4;
                }
                if(c1==2)
                {
                    tempCol=6;
                }
                if(c1==3)
                {
                    tempCol=8;
                }
                if(c1==4)
                {
                    tempCol=10;
                }
                if(c1==5)
                {
                    tempCol=12;
                }
                if(c1==6)
                {
                    tempCol=14;
                }
                if(c1==7)
                {
                    tempCol=16;
                }
                if(c2==0)
                {
                    tempCol1=2;
                }
                if(c2==1)
                {
                    tempCol1=4;
                }
                if(c2==2)
                {
                    tempCol1=6;
                }
                if(c2==3)
                {
                    tempCol1=8;
                }
                if(c2==4)
                {
                    tempCol1=10;
                }
                if(c2==5)
                {
                    tempCol1=12;
                }
                if(c2==6)
                {
                    tempCol1=14;
                }
                if(c2==7)
                {
                    tempCol1=16;
                }
                Board[r2][c2]=&rh1;
                interfaceBoard[temp1][tempCol]=' ';
                interfaceBoard[temp][tempCol1]='R';

                Sleep(2000);
                for(int i=0; i<=8 ; i++)
                {
                    cout<<endl;
                    for(int j=0; j<=17; j++)
                    {
                        cout<<interfaceBoard[i][j];
                    }
                }
            }



        }

        if(playerTurn==1)
        {
            cout<<"Player 2, please enter your move: "<<endl;

            cin>>move1;
            moveIntegrity=0;

            //Verify move integrity


            while(moveIntegrity!=1)
            {


                checkRules();

                if(move1[0]!='a'&&move1[0]!='b'&&move1[0]!='c'&&move1[0]!='d'&&move1[0]!='e'&&move1[0]!='f'&&move1[0]!='g'&&move1[0]!='h')
                {
                    cout<<"The reference of the table column is unknown"<<endl;
                    cout<<"Player 2, please re-enter your move: "<<endl;
                    cin>>move1;
                }
                if(move1[4]!='a'&&move1[4]!='b'&&move1[4]!='c'&&move1[4]!='d'&&move1[4]!='e'&&move1[4]!='f'&&move1[4]!='g'&&move1[4]!='h')
                {
                    cout<<"The reference of the table column where you want to move your piece is unknown"<<endl;
                    cout<<"Player 2, please re-enter your move: "<<endl;
                    cin>>move1;
                }
                if(move1[1]!='1'&&move1[1]!='2'&&move1[1]!='3'&&move1[1]!='4'&&move1[1]!='5'&&move1[1]!='6'&&move1[1]!='7'&&move1[1]!='8')
                {
                    cout<<"The reference of the table row where you want to move your piece is unknown"<<endl;
                    cout<<"Player 2, please re-enter your move: "<<endl;
                    cin>>move1;
                }
                if(move1.length()!=6)
                {
                    {
                        cout<<"The move input parameter has more or less than 6 characters"<<endl;
                        cout<<"Player 2, please re-enter your move: "<<endl;
                        cin>>move1;
                    }
                }

                if(checkCheck()>0)
                {
                    moveIntegrity=0;
                }

                if(moveIntegrity==1) //Basically processing the move by first identifying the row where the piece that you want to move is placed
                {
                    //moveIntegrity=1;

                    stream<<move1[1];
                    stream>>r1;
                    r1=r1-1;
                    if(move1[0]=='a')
                        c1=0;
                    else if(move1[0]=='b')
                        c1=1;
                    else if(move1[0]=='c')
                        c1=2;
                    else if(move1[0]=='d')
                        c1=3;
                    else if(move1[0]=='e')
                        c1=4;
                    else if(move1[0]=='f')
                        c1=5;
                    else if(move1[0]=='g')
                        c1=6;
                    else if(move1[0]=='h')
                        c1=7;
                    //Evaluate where the piece is going
                    stream.clear();
                    stream<<move1[5];
                    stream>>r2;
                    r2=r2-1;
                    if(move1[4]=='a')
                        c2=0;
                    else if(move1[4]=='b')
                        c2=1;
                    else if(move1[4]=='c')
                        c2=2;
                    else if(move1[4]=='d')
                        c2=3;
                    else if(move1[4]=='e')
                        c2=4;
                    else if(move1[4]=='f')
                        c2=5;
                    else if(move1[4]=='g')
                        c2=6;
                    else if(move1[4]=='h')
                        c2=7;



                    if(moveIntegrity==1)
                    {
                        cout<<"Your move has been processed"<<endl;



                        playerTurn=0;
                    }
                }

                else
                {
                    cout<<"Your move is against the rules!"<<endl;
                    cout<<"Player 2, please re-enter your move: "<<endl;
                    cin>>move1;
                    stream.clear();
                }

//move for first pawn, player 2
                if(Board[r1][c1].piece==&p12)
                {
                    isP12=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p12;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }
//move for second pawn, player 2
                if(Board[r1][c1].piece==&p22)
                {
                    isP22=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p22;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }


                }
//move for third pawn, player 2
                if(Board[r1][c1].piece==&p32)
                {
                    isP32=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p32;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }

                }

//move for fourth pawn, player 1
                if(Board[r1][c1].piece==&p42)
                {
                    isP42=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }

                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p42;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

//move for fifth pawn, player 1
                if(Board[r1][c1].piece==&p52)
                {
                    isP52=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p52;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }
//move for sixth pawn, player 1
                if(Board[r1][c1].piece==&p62)
                {
                    isP62=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p62;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

//move for seventh pawn, player 2
                if(Board[r1][c1].piece==&p72)
                {
                    isP72=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p72;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }
//move for eighth pawn, player 2
                if(Board[r1][c1].piece==&p82)
                {
                    isP82=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&p82;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='p';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

//move for the A rook, player 2
                if(Board[r1][c1].piece==&ra2)
                {
                    isRA2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&ra2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='R';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

//move for B knight, player 1
                if(Board[r1][c1].piece==&nb2)
                {
                    isNB2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&nb2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='N';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }
//move for C bishop, player 1
                if(Board[r1][c1].piece==&bc2)
                {
                    isBC2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&bc2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='B';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }
                //move for king, player 2
                if(Board[r1][c1].piece==&k2)
                {
                    isK2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&k2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='K';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

                //move for queen, player 1
                if(Board[r1][c1].piece==&q2)
                {
                    isQ2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&q2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='Q';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

                //move for f bishop, player 1
                if(Board[r1][c1].piece==&bf2)
                {
                    isBF2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&bf2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='B';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

                //move for G knight, player 1
                if(Board[r1][c1].piece==&ng2)
                {
                    isNG2=1;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&ng2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='N';
                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }

//move for H rook, player 2
                if(Board[r1][c1].piece==&rh2)
                {
                    isRH1=2;
                    Board[r1][c1]=nullptr;
                    if(r1==7)
                    {
                        temp1=1;
                    }
                    if(r1==6)
                    {
                        temp1=2;
                    }
                    if(r1==5)
                    {
                        temp1=3;
                    }
                    if(r1==4)
                    {
                        temp1=4;
                    }
                    if(r1==3)
                    {
                        temp1=5;
                    }
                    if(r1==2)
                    {
                        temp1=6;
                    }
                    if(r1==1)
                    {
                        temp1=7;
                    }
                    if(r1==0)
                    {
                        temp1=8;
                    }
                    if(r2==7)
                    {
                        temp=1;
                    }
                    if(r2==6)
                    {
                        temp=2;
                    }
                    if(r2==5)
                    {
                        temp=3;
                    }
                    if(r2==4)
                    {
                        temp=4;
                    }
                    if(r2==3)
                    {
                        temp=5;
                    }
                    if(r2==2)
                    {
                        temp=6;
                    }
                    if(r2==1)
                    {
                        temp=7;
                    }
                    if(r2==0)
                    {
                        temp=8;
                    }
                    if(c1==0)
                    {
                        tempCol=2;
                    }
                    if(c1==1)
                    {
                        tempCol=4;
                    }
                    if(c1==2)
                    {
                        tempCol=6;
                    }
                    if(c1==3)
                    {
                        tempCol=8;
                    }
                    if(c1==4)
                    {
                        tempCol=10;
                    }
                    if(c1==5)
                    {
                        tempCol=12;
                    }
                    if(c1==6)
                    {
                        tempCol=14;
                    }
                    if(c1==7)
                    {
                        tempCol=16;
                    }
                    if(c2==0)
                    {
                        tempCol1=2;
                    }
                    if(c2==1)
                    {
                        tempCol1=4;
                    }
                    if(c2==2)
                    {
                        tempCol1=6;
                    }
                    if(c2==3)
                    {
                        tempCol1=8;
                    }
                    if(c2==4)
                    {
                        tempCol1=10;
                    }
                    if(c2==5)
                    {
                        tempCol1=12;
                    }
                    if(c2==6)
                    {
                        tempCol1=14;
                    }
                    if(c2==7)
                    {
                        tempCol1=16;
                    }
                    Board[r2][c2]=&rh2;
                    interfaceBoard[temp1][tempCol]=' ';
                    interfaceBoard[temp][tempCol1]='R';

                    Sleep(2000);
                    for(int i=0; i<=8 ; i++)
                    {
                        cout<<endl;
                        for(int j=0; j<=17; j++)
                        {
                            cout<<interfaceBoard[i][j];
                        }
                    }
                }
            }
        }
    }
}
