#include "Piece.h"
#include <iostream>
#include <string>
#include <string.h>

Piece::Piece(void){

}

Piece::Piece(string x, int y, char z)
{
    name=x;
    player=y;
    initial=z;
}

Piece::~Piece()
{}
