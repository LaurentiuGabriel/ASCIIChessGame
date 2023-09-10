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
{}
