#include<iostream>
using namespace std;

char boxes[3][3]={{'1','2','3'} , {'4','5','6'} , {'7','8','9'}};
bool gamedone=false;
void Draw();
void Place_XO(int box);
void Logic();
int check_winner();

int main()
{
    cout<<"$ Welcome to game $"<<endl;
    Draw();
    while(gamedone==false )
    {
        Logic();
        Draw();
    }
    return 0;
}

void Draw()
{
    // used only to draw the game contents
    cout<<endl;
    cout<<" "<<boxes[0][0]<<" | "<<boxes[0][1]<<" | "<<boxes[0][2]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<boxes[1][0]<<" | "<<boxes[1][1]<<" | "<<boxes[1][2]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<boxes[2][0]<<" | "<<boxes[2][1]<<" | "<<boxes[2][2]<<" "<<endl;

}
void Place_XO(int box,char mark)
{
    // take the position where player want to mark X or O
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(boxes[i][j]==box)
                boxes[i][j]=mark;
        }
    }
}

void Logic()
{
    static int rounds=0;
    char box;
    int winnerplayer;
    ++rounds;
    if(rounds%2!=0)
    {
        cout<<"payer 1 choose the wanted box number to put X: ";
        cin>>box;
        Place_XO(box,'X');
    }
    else
    {
        cout<<"payer 2 choose the wanted box number to put O: ";
        cin>>box;
        Place_XO(box,'O');
    }
    if(rounds>4)  // only need to check if matching happened after 5 rounds
    {
        winnerplayer=check_winner();
        if(winnerplayer==1)
            {
                cout<<"---congrats player 1---"<<endl;
                gamedone=true;
            }
        else if(winnerplayer==2)
            {
                cout<<"---congrats player 2---"<<endl;
                gamedone=true;
            }
        else
        {
            if(rounds==9) // no one win here
            {
                cout<<"----Game Over----"<<endl;
                gamedone=true;
            }
        }
    }

}

int check_winner()  // check for matching and return who win if any
{
    int winnerplayer=0;
    int i=0;
    for(i=0;i<3;i++)
    {
        if( boxes[i][0]=='X' && boxes[i][1]=='X' && boxes[i][2]=='X' || boxes[0][i]=='X' && boxes[1][i]=='X' && boxes[2][i]=='X' )
        {
            winnerplayer=1;   break;
        }
        else if( boxes[i][0]=='O' && boxes[i][1]=='O' && boxes[i][2]=='O' || boxes[0][i]=='O' && boxes[1][i]=='O' && boxes[2][i]=='O' )
        {
            winnerplayer=2;   break;
        }
    }
    if( boxes[0][0]=='X' && boxes[1][1]=='X' && boxes[2][2]=='X' || boxes[1][1]=='X' && boxes[0][2]=='X' && boxes[2][0]=='X' )
    {
        winnerplayer=1;
    }
    else if(boxes[0][0]=='O' && boxes[1][1]=='O' && boxes[2][2]=='O' || boxes[1][1]=='O' && boxes[0][2]=='O' && boxes[2][0]=='O')
    {
        winnerplayer=2;
    }

    return winnerplayer;
}
