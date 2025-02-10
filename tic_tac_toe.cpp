#include<iostream>
#include<vector>
using namespace std;
class tictactoe{
    vector<vector<char>>board;
    char currentPlayer;
    public:
       tictactoe(){
        board={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        currentPlayer='X';
       }
       void printboard(){
       cout<<endl<<endl;
        for(int i=0;i<3;i++){
            cout<<"                ";
            for(int j=0;j<3;j++){      
                cout<<" "<<board[i][j]<<" ";
                if(j<2){
                    cout<<"|";
                }
            }
        cout<<endl;
        if(i<2){
            cout<<"                "<<"---+---+---"<<endl;
        }
           
        }
        cout<<endl<<endl;  
       }
       bool makemove(int in){
          int row=(in-1)/3;
          int col=(in-1)%3;
          if(board[row][col]!='X' && board[row][col]!='O' ){
               board[row][col]=currentPlayer;
               return true;
          }
          return false;
          
       }
       bool checkwinner(){
         if(board[0][0]==board[0][1] && board[0][1] ==board[0][2]  ){
             return true;
         }
       else  if(board[1][0]==board[1][1] && board[1][1] ==board[1][2]  ){
             return true;
         }
      else  if(board[2][0]==board[2][1] && board[2][1] ==board[2][2]  ){
             return true;
         }
      else  if(board[0][0]==board[1][0] && board[1][0] ==board[2][0]  ){
             return true;
         }
     else  if(board[0][1]==board[1][1] && board[1][1] ==board[2][1]  ){
             return true;
         }
     else  if(board[0][2]==board[1][2] && board[1][2] ==board[2][2]  ){
             return true;
         }
    else  if(board[0][0]==board[1][1] && board[1][1] ==board[2][2]  ){
             return true;
         }
     else  if(board[0][2]==board[1][1] && board[1][1] ==board[2][0]  ){
             return true;
         }  
         else{
            return false;
         }
     }
     bool fullboard(){
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){      
              if(board[i][j]!='X' && board[i][j]!='O'){
                     return false;
              }  
              
            }
       
           
        }
  
        return true;
     }

       char changeplayer(char currentPlayer){
        if(currentPlayer=='X'){
            return 'O';
        }
        else{
            return 'X';
        }

    }
    void play(){
        int input;
         cout<<endl<<endl<<endl;
        cout<<"  -------|  WELCOME TO TIC_TAC_TOE |-------"<<endl;
         while(true){
            printboard();
            cout<<currentPlayer<<" enter your input between(1 to 9):";
            cin>>input;
            if(input <0 && input >9){
                cout<<" INVALID INPUT";
                continue;
            }
            if(!makemove(input)){
               cout<<" POSITION OCCUPIED TRY ANOTHER POSITION";
               continue;
               
            }
            if(checkwinner()){
                printboard();
                cout<<"WINNER IS "<<currentPlayer<<endl<<endl;
                break;
            }
            if( fullboard() ){
                printboard();
                cout<<endl<<endl;
                cout<<"-----IT IS A DRAW-----";
                break;
            }
           currentPlayer=  changeplayer(currentPlayer);
            
         }
        

    }


};
int main(){
    tictactoe game;
    game.play();
    return 0;
}