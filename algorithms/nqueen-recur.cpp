#include<iostream>
#include<vector>
#include<array>
using std::array;
using std::vector;
using std::cout;
constexpr int N = 4;
void printSoln(array<array<int, N>, N> &board)
{
    for(auto &row : board)
    {
        for(auto &col : row)
        {
            std::cout << col << "  ";
        }
        std::cout << " \n";
    }
    
}


bool is_attacked( array<array<int, N>, N> &board, int x, int y)
{

        int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < y; i++) 
        if (board[x][i]) 
            return true; 
  
    /* Check upper diagonal on left side */
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return true; 
  
    /* Check lower diagonal on left side */
    for (i = x, j = y; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return true; 
  
    return false; 

}

bool NQUtil(array<array<int, N>, N> &board, int y)
{
    if (y >= N) return true;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //the parameter y there is trying to avoid trying forever
           //if it can place all the queens it should stop
            if (is_attacked(board, i, y)) continue;
            board[i][y] = 1;
            if (NQUtil(board, y+1)) return true;

            board[i][y] = 0;
        }
    }
    return false;
}

bool solveNQ()
{
    array<array<int, N>, N> board = {{{ 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }}}; 
    if (NQUtil(board, 0) == false)
    {
        cout << "Solution does not exist" << " \n";
        return false;
    }
    printSoln(board);
    return true;

}
int main()
{
   solveNQ();
   return 0;

}
  
