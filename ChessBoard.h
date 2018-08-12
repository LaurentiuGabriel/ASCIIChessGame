#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <string>
#include <string.h>
#include "Piece.h"

using namespace std;


class ChessBoard
{
public:
    ChessBoard(void);
    virtual ~ChessBoard(void);
    Piece *piece;
    ChessBoard(Piece *);
    // protected:

    string drawGameBoard();

};

#endif // CHESSBOARD_H
