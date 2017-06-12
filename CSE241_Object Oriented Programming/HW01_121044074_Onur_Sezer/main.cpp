// HW01_121044074_Onur_Sezer
// main.c
//
// Created on 22/09/2015 by Onur_Sezer
//
// Description
//
// Kullanicidan alinan board size ile ekrana board'i basar ve reversi oyununu oynatir.  

#include <iostream>

using namespace std;

// Boardi ekrana basar.
void printBoard(char board[][20],const int &rows,const int &cols);
// Girilen size'a gore board'i doldurur.
void fillBoard(char board[][20],const int &rows,const int &cols);
// User ve computer icin hamle yapar.
int move(char board[][20],const int &rows,const int &cols,int change,int &numberOfMoves,int x,int y,char char1,char char2);
// Fonksiyonlarin birlestirilmesinde gorev yapar.
void test(char board[][20],const int &rows,const int &cols);
// Userdan hamle yapmasini ister.
void getUser(int &x,int &y);
// Oyunun bitip bitmedigini kontrol eder.
void control(char board[][20],const int &rows,const int &cols,int &cross,int &circular,int &point);

int main(){

    int rows,cols;
    char c;
    char board[20][20];

    cout << "Enter a board size: " << endl;
    cin >> rows;
    cols = rows;
    if(!(((rows%2) == 0) && rows >= 4 && rows <=20))
    {
        cout << "Error Entry!\n";
        return -1;
    }
    test(board,rows,cols);
    return 0;
}
void test(char board[][20],const int &rows,const int &cols)
{
    int status,userCont,computerCont;
    int change,numberOfMoves = 0,max = 0,mX,mY,sum,x,y,cross,circular,point;
    char ch; 

    fillBoard(board,rows,cols);
    printBoard(board,rows,cols);
    control(board,rows,cols,cross,circular,point);
    cout << endl;
    cout << "  YOU : " << circular << "   CPU : " << cross << endl;
    while(1)
    {
        change = 0;
        for (x = 0; x < rows; ++x)
        {
            for (y = 0; y < cols; ++y)
            {
                if(board[x][y] == '.')
                {
                    move(board,rows,cols,change,numberOfMoves,x,y,'O','X');
                    if(max < numberOfMoves)
                    { 
                        max = numberOfMoves;
                        mX = x; mY = y;
                    }
                }
            }
        }
        userCont = max;
        if(userCont == 0){
                cout << endl;
                cout << "User Passes(no move possible)\n";
        }
        max = 0;	
        if(userCont != 0)
        {	
            getUser(x,y);
            change = 1;
            while(!(board[x][y] == '.'))
            {
                cout << "ERROR ENTERY !!!\n";
                getUser(x,y);
            }
            status = move(board,rows,cols,change,numberOfMoves,x,y,'O','X');
            while(status == -1)
            {
                cout << "ERROR ENTERY !!\n";
                getUser(x,y);
                status = move(board,rows,cols,change,numberOfMoves,x,y,'O','X');
            }
            printBoard(board,rows,cols);
            control(board,rows,cols,cross,circular,point);
            cout << endl;
            cout << "  YOU : " << circular << "   CPU : " << cross << endl;
            cout << endl;
            if(point == 0)
            {
                cout << endl;
                if(cross > circular)
                    cout << "*****   COMPUTER WIN!   *****" << endl;
                else if(circular > cross)
                    cout << "*****   YOU WIN!   *****" << endl;
                else if(cross == 0)
                    cout << "*****   YOU WIN!   *****" << endl;
                else if(circular == 0)
                    cout << "*****   COMPUTER WIN!   *****" << endl;		
                else
                    cout << "*****   SCORELESS!   *****" << endl;
                cout << endl;
                break;
            }
        }
        change = 0;
        for (x = 0; x < rows; ++x)
        {
            for (y = 0; y < cols; ++y)
            {
                if(board[x][y] == '.')
                {
                    move(board,rows,cols,change,numberOfMoves,x,y,'X','O');
                    if(max < numberOfMoves)
                    { 
                        max = numberOfMoves;
                        mX = x; mY = y;
                    }
                }
            }
        }	
        computerCont = max;
        if (computerCont == 0){
            cout << endl;
            cout << "Computer Passes(no move possible)\n";
        }
        sum = max; max = 0;
        if(computerCont != 0)
        {
            change = 1;
            //cout << "numberOfMoves : " << sum << endl;
            move(board,rows,cols,change,numberOfMoves,mX,mY,'X','O');		
            cout << "Computer is Playing :" << endl;
            ch = mY + 97;
            cout << mX+1 << ch << endl;
            cout << endl;
            printBoard(board,rows,cols);
            control(board,rows,cols,cross,circular,point);
            cout << endl;
            cout << "  YOU : " << circular << "   CPU : " << cross << endl;
            if(point == 0)
            {
                cout << endl;
                if(cross > circular)
                    cout << "*****   COMPUTER WIN!   *****" << endl;
                else if(circular > cross)
                    cout << "*****   YOU WIN!   *****" << endl;
                else if(cross == 0)
                    cout << "*****   YOU WIN!   *****" << endl;
                else if(circular == 0)
                    cout << "*****   COMPUTER WIN!   *****" << endl;		
                else
                    cout << "*****   SCORELESS!   *****" << endl;
                cout << endl;
                break;
            }	
        }	
        if(userCont == 0 && computerCont == 0)
        {
            cout << endl;
            cout << "No legal move!\n" << endl;
            if(cross > circular)
                cout << "*****   COMPUTER WIN!   *****" << endl;
            else if(circular > cross)
                cout << "*****   YOU WIN!   *****" << endl;
            else if(cross == 0)
                cout << "*****   YOU WIN!   *****" << endl;
            else if(circular == 0)
                cout << "*****   COMPUTER WIN!   *****" << endl;		
            else
                cout << "*****   SCORELESS!   *****" << endl;
            cout << endl;
            break;	
        }
    }	
}
void fillBoard(char board[][20],const int &rows,const int &cols)
{
    int mid;
    mid = rows / 2;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if((i == mid-1) && (j == mid-1))
                board[i][j] = 'X';
            else if((i == mid-1) && (j == mid))
                board[i][j] = 'O';
            else if((i == mid) && (j == mid-1))
                board[i][j] = 'O';
            else if((i == mid) && (j == mid))
                board[i][j] = 'X';
            else												
                board[i][j] = '.';
        }	
    }
}
void printBoard(char board[][20],const int &rows,const int &cols)
{
    char x=97;
    int count=1;


    for (int k = 0; k <= rows; ++k)
    {
        if (k == 0)
            cout << "    ";
        else
        {
            cout << x << "  ";
            x++;
        } 
    }
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        if(i >= 9)
            cout << count << " ";
        else
            cout << " " << count << " ";	
        count++;
        for (int j = 0; j < cols; ++j)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}
// char1 = X char2 = O  computer
// char1 = O char2 = X  user
int move(char board[][20],const int &rows,const int &cols,int change,int &numberOfMoves,int x,int y,char char1,char char2)
{
    int cont,st2=0,st=0;
    char c;
    int status = -1,corX,corY,temp;

    numberOfMoves = 0;
    //cout << "x : " << x << ", y: " << y << endl;
    if((x+1 < rows) && (board[x+1][y] == char2)) //asagi
    {	
            //cout << "deneme\n";
            cont = x;
            while((cont < rows) && (st2 != -1) && (st != 2))
            {
                cont++;
                if(board[cont][y] == char2)
                        st = 1;
                else if(board[cont][y] == char1)
                        st = 2;
                else 
                        st2 = -1;			
            }
            if (st == 2)
            {
                temp = cont - x - 1;
                numberOfMoves += temp;
            }	
            if(st == 2 && change == 1)
            {
                for (int i = x; i < cont; ++i)
                {
                    board[i][y] = char1;
                }
                status = 0;
            }
            st=0;st2=0;
    }
    if((x-1 >= 0) && (board[x-1][y] == char2)) //yukari
    {
            //cout << "deneme2\n";
            cont = x;
            while((cont >= 0) && (st2 != -1) && (st != 2))
            {
                cont--;
                if(board[cont][y] == char2)
                    st = 1;
                else if(board[cont][y] == char1)
                    st = 2;
                else 
                    st2 = -1;			
            }	
            if (st == 2)
            {
                temp = x - cont - 1;
                numberOfMoves += temp;             
            }	
            if(st == 2 && change == 1)
            {
                for (int i = cont; i <= x; ++i)
                {
                    board[i][y] = char1;
                }
                status = 0;
            }		
            st=0;st2=0;
    }
    if((y+1 < cols) && (board[x][y+1] == char2)) //sag
    {
            //cout << "deneme3\n";
            cont = y;
            while((cont < cols) && (st2 != -1) && (st != 2))
            {
                cont++;
                if(board[x][cont] == char2)
                    st = 1;
                else if(board[x][cont] == char1)
                    st = 2;
                else 
                    st2 = -1;			
            }	
            if (st == 2)
            {
                temp = cont - y - 1;
                numberOfMoves += temp;             
            }	
            if(st == 2 && change == 1)
            {
                for (int i = y; i < cont; ++i)
                {
                    board[x][i] = char1;
                }
                status = 0;
            }
            st=0;st2=0;
    }
    if((y-1 >= 0) && (board[x][y-1] == char2)) //sol
    {
            //cout << "deneme4\n";
            cont = y;
            while((cont >= 0) && (st2 != -1) && (st != 2))
            {
                cont--;
                if(board[x][cont] == char2)
                    st = 1;
                else if(board[x][cont] == char1)
                    st = 2;
                else 
                    st2 = -1;			
            }	
            if (st == 2)
            {
                temp = y - cont - 1;
                numberOfMoves += temp;             
            }	
            if(st == 2 && change == 1)
            {
                for (int i = cont; i <= y; ++i)
                {
                    board[x][i] = char1;
                }
                status = 0;
            }
            st=0;st2=0;	
    }
    if((x-1 >= 0) && (y+1 < cols) && (board[x-1][y+1] == char2)) //sag yukari
    {
        //cout << "deneme5\n";
        corY = y;
        corX = x;
        while((corX >= 0) && (corY < cols) && (st2 != -1) && (st != 2))
        {
            corX--;
            corY++;
            if(board[corX][corY] == char2)
                st = 1;
            else if(board[corX][corY] == char1)
                st = 2;
            else 
                st2 = -1;			
        }	
        if (st == 2)
        {
            temp = x - corX - 1;
            numberOfMoves += temp;             
        }	
        if(st == 2 && change == 1)
        {
            while((corX <= x) && (y < corY))
            {
                corX++;
                corY--;
                //cout << "corX : " << corX << ", corY : " << corY << endl << endl;
                if((corX <= x) && (y <= corY))
                    board[corX][corY] = char1;
            }
            status = 0;
        }
        st=0;st2=0;		
    }
    if((x-1 >= 0) && (y-1 >= 0) && (board[x-1][y-1] == char2)) //sol yukari
    {
        //cout << "deneme6\n";
        corY = y;
        corX = x;
        while((corX >= 0) && (corY >= 0) && (st2 != -1) && (st != 2))
        {
            corX--;
            corY--;
            if(board[corX][corY] == char2)
                    st = 1;
            else if(board[corX][corY] == char1)
                    st = 2;
            else 
                    st2 = -1;			
        }	
        if (st == 2)
        {
            temp = x - corX - 1;
            numberOfMoves += temp;             
        }	
        if(st == 2 && change == 1)
        {
            //cout << "corX : " << corX << ", corY : " << corY << endl << endl;
            while((corX <= x) && (corY <= y))
            {
                corX++;
                corY++;
                if((corX <= x) && (corY <= y))
                        board[corX][corY] = char1;
            }
            status = 0;
        }
        st=0;st2=0;	
    }
    if((x+1 < rows) && (y+1 < cols) && (board[x+1][y+1] == char2)) //sag asagi
    {
        //cout << "deneme7\n";
        corY = y;
        corX = x;
        while((corX < rows) && (corY < cols) && (st2 != -1) && (st != 2))
        {
            corX++;
            corY++;
            if(board[corX][corY] == char2)
                    st = 1;
            else if(board[corX][corY] == char1)
                    st = 2;
            else 
                    st2 = -1;			
        }	
        if (st == 2)
        {
            temp = corX - x - 1;
            numberOfMoves += temp;             
        }	
        if(st == 2 && change == 1)
        {
            while((corX >= x) && (corY >= y))
            {
                corX--;
                corY--;
                //cout << "corX : " << corX << ", corY : " << corY << endl << endl;
                if((corX >= x) && (corY >= y))
                        board[corX][corY] = char1;
            }
            status = 0;
        }
        st=0;st2=0;
    }
    if((x+1 < rows) && (y-1 >= 0) && (board[x+1][y-1] == char2)) //sol asagi
    {
        //cout << "deneme8\n";
        corY = y;
        corX = x;
        while((corX < rows) && (corY >= 0) && (st2 != -1) && (st != 2))
        {
            corX++;
            corY--;
            if(board[corX][corY] == char2)
                st = 1;
            else if(board[corX][corY] == char1)
                st = 2;
            else 
                st2 = -1;			
        }	
        if (st == 2)
        {
            temp = corX - x - 1;
            numberOfMoves += temp;             
        }	
        if(st == 2 && change == 1)
        {
            while((corX >= x) && (corY <= y))
            {
                corX--;
                corY++;
                //cout << "corX : " << corX << ", corY : " << corY << endl << endl;
                if((corX >= x) && (corY <= y))
                    board[corX][corY] = char1;
            }
            status = 0;
        }
        st=0;st2=0;		
    }
    if(status == 0)
            return 0;
    else
            return -1;			
}
void getUser(int &x, int &y)
{
    char c;

    cout << endl;
    cout << "You" << endl;
    cout << "Enter a move: " << endl;
    cin >> x;
    cin >> c;
    y = static_cast<int>(c);
    if(y <= 90 && y >= 65)
        y-=65;
    if(y <= 122 && y >= 97)
        y -= 97;
    x -= 1;
}
void control(char board[][20],const int &rows,const int &cols,int &cross,int &circular,int &point)
{
    cross = 0; circular = 0; point = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if(board[i][j] == 'X')
                cross++;
            if (board[i][j] == 'O')
                circular++;
            if(board[i][j] == '.')
                point++;
        }
    }
}