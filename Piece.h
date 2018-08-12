#ifndef PIECE_H
#define PIECE_H
#include <string.h>
#include <string>
#include <iostream>
//#include "ChessBoard.h"

using namespace std;
// : public ChessBoard
class Piece
{
public:
    Piece(void);
    virtual ~Piece(void);
    Piece(string x, int y, char z);

    string name;
    int player;
    char initial;

};

#endif // PIECE_H
