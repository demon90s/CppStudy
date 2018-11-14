/*
    (a) 棋盘的每个角上可能会有一个棋子，即兵、士、相、车、皇后或国王，也可能为空。每个棋子可能为
        黑色的也可能是白色的。请定义两个枚举类型 Piece 用来包含7种可能的值（其中一种为"空"），
        Color 用来表示两种颜色。
    (b) 利用(a)中的类型，定义名为 Square 的结构类型，使此类型可以存储棋子的类型和颜色。
    (c) 利用(b)中的类型 Square ，声明一个名为 board 的8*8的数组，此数组可以用来存储棋盘上的全部内容。
    (d) 给(c)中的声明添加初始值，使 board 的初始值对应日常国际象棋比赛开始时的棋子布置。
*/

typedef enum piece {
    NonePiece,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
} Piece;

typedef enum color {
    NoneColor,
    White,
    Black
} Color;

typedef struct square {
    Piece piece;
    Color color;
} Square;

Square board[8][8] = {
    { {Rook, Black}, {Knight, Black}, {Bishop, Black}, {King, Black}, {Queen, Black}, {Bishop, Black}, {Knight, Black}, {Rook, Black} },
    { {Pawn, Black}, {Pawn, Black}, {Pawn, Black}, {Pawn, Black}, {Pawn, Black}, {Pawn, Black}, {Pawn, Black}, {Pawn, Black} },
    { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
    { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
    { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
    { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
    { {Pawn, White}, {Pawn, White}, {Pawn, White}, {Pawn, White}, {Pawn, White}, {Pawn, White}, {Pawn, White}, {Pawn, White} },
    { {Rook, White}, {Knight, White}, {Bishop, White}, {King, White}, {Queen, White}, {Bishop, White}, {Knight, White}, {Rook, White} },
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
