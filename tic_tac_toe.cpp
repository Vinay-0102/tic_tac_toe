#include<iostream>

using namespace std;

char board[3][3];
char current_marker ;
int current_player ;

void fill_table()
{
     char k = '1' ;

    for(int i =0 ;i<3; i++)
    {
        for(int j =0 ; j<3 ;j++)
            {
               board[i][j] = k;
                 k++;
            }

    }

}

bool placeMark(int slot)
{
    int row;
    if(slot%3) row = slot/3 ;
    else row = (slot/3) -1 ;

    int col;
    if(slot%3) col = (slot%3)-1;
    else col = 2;
//    cout<< row <<" " <<col << endl;
   if(board[row][col]!='x' && board[row][col]!='x')
   {
      board[row][col] = current_marker;
      return true;
   }
   return false ;
}

void drawBoard()
{
    for(int i =0 ;i<3; i++)
    {
        for(int j =0 ; j<3 ;j++)
            {
                cout<<board[i][j]<<" | " ;
            }
         if(i<2)  cout<<"\n ----------"<<endl;
    }
}

int winner()
{
    for(int i=0 ; i<3;  i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return current_player;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return current_player;
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return current_player;
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return current_player;

    }
      return 0 ;
}
void swap_player_and_Marker()
{
    if(current_marker=='x')current_marker = 'o';
    else current_marker ='x';

    if(current_player==1)current_player = 2;
    else current_player = 1;
}
void game()
{
    cout<<"player one , choose your marker : ";
    char marker_pl ;
    cin>>marker_pl;
    current_player  = 1;
    current_marker = marker_pl ;
      int player_won;

    drawBoard();
    for(int i=0 ;i<9 ; i++)
    {
        cout<<"\n it's player " <<current_player<<"'s turn . Enter your slot : ";
        int slot ;
        cin>>slot ;
        if(slot < 1 || slot> 9)
        {
           cout<<"\n that slot is invalid ! try another slot : ";
           i--  ;
        cout<<endl;
           continue;
        }
       if(!placeMark(slot))
       {
           cout<<"\n that slot is already occupied ! try another slot  ";
           i--  ;
           cout<<endl;
           continue;
       }
        player_won = winner();

        if(player_won ==1)
        {
            drawBoard();
            cout<<"\n player one won ! Congratulations"<<endl ;
            break;
        }
          if(player_won ==2)
        {
            drawBoard();
            cout<<"\n player two won ! Congratulations"<<endl ;
            break;
        }
      swap_player_and_Marker();
        drawBoard();
    }
  if(player_won == 0) cout<<"that's a tie game !! "<<endl;
}

int main()
{
    fill_table();

     game();


}
