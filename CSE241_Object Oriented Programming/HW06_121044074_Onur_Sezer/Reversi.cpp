#include <cstdlib>
#include <cstring>
#include "Reversi.h"
using namespace std;

namespace SEZER{
    int Reversi::livingReversiGame = 0;
    Reversi::Reversi():sizeRow(4), sizeCol(4)
    {
        capacity = getSizeY() * getSizeX();
        gameCells = new Cell[capacity];
        int mid;
        int k=0;
        mid = getSizeX() / 2;
        for(int i = 0; i < getSizeX(); ++i)
        {
            for(int j = 0; j < getSizeY(); ++j)
            {
                char c = 97 + j;
                string str;
                str = c;
                if((i == mid-1) && (j == mid-1))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else if((i == mid-1) && (j == mid))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid) && (j == mid-1))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid) && (j == mid))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else				
                    gameCells[k] = (Cell(str,i+1,'.'));
                k++;
            }
        }
        livingReversiGame++;
        cout << "livingReversiGame : " << Reversi::getNumOfReversiGame() << endl;
    }
    Reversi::Reversi(const int size): sizeRow(size), sizeCol(size)
    {
        testReversi();  
        string str;
        int mid1, mid2;
        mid1 = getSizeX() / 2;
        mid2 = getSizeY() / 2;
        capacity = getSizeY() * getSizeX();
        gameCells = new Cell[capacity];
        int k=0;
        for(int i = 0; i < getSizeX(); ++i)
        {
            for(int j = 0; j < getSizeY(); ++j)
            {
                str = combineChar(j);
                if((i == mid1-1) && (j == mid2-1))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else if((i == mid1-1) && (j == mid2))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid1) && (j == mid2-1))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid1) && (j == mid2))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else												
                    gameCells[k] = (Cell(str,i+1,'.'));
                k++;
            }
        }
        livingReversiGame++;
        cout << "livingReversiGame : " << Reversi::getNumOfReversiGame() << endl;
    }
    Reversi::Reversi(const int row, const int col):sizeRow(row), sizeCol(col)
    {
        testReversi();  
        string str;
        int mid1, mid2;
        mid1 = getSizeX() / 2;
        mid2 = getSizeY() / 2;
        capacity = getSizeY() * getSizeX();
        gameCells = new Cell[capacity];
        int k=0;
        for(int i = 0; i < getSizeX(); ++i)
        {
            for(int j = 0; j < getSizeY(); ++j)
            {
                str = combineChar(j);
                if((i == mid1-1) && (j == mid2-1))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else if((i == mid1-1) && (j == mid2))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid1) && (j == mid2-1))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid1) && (j == mid2))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else												
                    gameCells[k] = (Cell(str,i+1,'.'));
                k++;
            }
        }
        livingReversiGame++;
        cout << "livingReversiGame : " << Reversi::getNumOfReversiGame() << endl;
    }
    Reversi::Reversi(const Reversi &other): capacity(other.capacity),
                                            sizeRow(other.getSizeX()),sizeCol(other.getSizeY()),circular(other.circular)// copy constructor
    {
        //cout << "COPY CONSTRUCTOR" << endl;
        gameCells = new Cell[capacity];
        for(int i=0; i < capacity; ++i)
            gameCells[i] = other.gameCells[i];
        livingReversiGame++;
        cout << "livingReversiGame : " << Reversi::getNumOfReversiGame() << endl;
    }
    ostream& operator <<(ostream &out,const Reversi &reversi)
    {
        int count=1;
        for (int k = 0; k < reversi.getSizeY(); ++k)
        {
            if (k == 0) {
                out << "    " << reversi.gameCells[k].getCorX();
            }
            else if(k < 25)
                out << "  " << reversi.gameCells[k].getCorX();
            else if(k == 25)
                out << "  " << reversi.gameCells[k].getCorX() << " ";
            else
                out << " " << reversi.gameCells[k].getCorX();
        }
        cout << endl;
        int k = 0;
        for (int i = 0; i < reversi.getSizeX(); ++i)
        {
            if(i >= 9)
                out << count << "  ";
            else
                out << " " << count << "  ";	
            count++;
            for (int j = 0; j < reversi.getSizeY(); ++j)
            {
                out << reversi.gameCells[k].getCh() << "  ";
                k++;
            }
            out << endl;
        }
        return out;
    }
    Reversi& Reversi::operator =(const Reversi& other) // assigment
    {
        //cout << "ASSIGMENT" << endl;
        if(this == &other)
            return *this;
        delete [] gameCells;
        capacity = other.capacity; 
        sizeRow = other.getSizeX();
        sizeCol = other.getSizeY();
        circular = other.circular;
        gameCells = new Cell[capacity];       
        for(int i = 0; i < capacity; ++i)
            gameCells[i] = other.gameCells[i];
        return *this;
    }
    void Reversi::displayBoard() const 
    {
        int count=1;
        for (int k = 0; k < getSizeY(); ++k)
        {
            if (k == 0) {
                cout << "    " << gameCells[k].getCorX();
            }
            else if(k < 25)
                cout << "  " << gameCells[k].getCorX();
            else if(k == 25)
                cout << "  " << gameCells[k].getCorX() << " ";
            else
                cout << " " << gameCells[k].getCorX();
        }
        cout << endl;
        int k = 0;
        for (int i = 0; i < getSizeX(); ++i)
        {
            if(i >= 9)
                cout << count << "  ";
            else
                cout << " " << count << "  ";	
            count++;
            for (int j = 0; j < getSizeY(); ++j)
            {
                cout << gameCells[k].getCh() << "  ";
                k++;
            }
            cout << endl;
        }
    }
    void Reversi::testReversi() const
    {
        if(!(getSizeX() >= 4 && getSizeY() >= 4))
        {
            cout << "Wrong Size !! \n"; // row ve col size'larinin en az 4 olmasini kontrol eder.
            exit(0);
        }
    }
    string Reversi::combineChar(const int j)
    {
        string str, str2;

        int div = j / 26;          
        int temp = j % 26;
        if(div > 0){
            if(div > 26){
                char c = 65 + temp;
                char b = div + 65 - 26 - 1;
                string str2;
                str2.push_back(b);
                str2.push_back(c);
                str = str2;
            }
            else{
                char c = 97 + temp;
                char b = div + 97 - 1;
                string str2;
                str2.push_back(b);
                str2.push_back(c);
                str = str2;
            }
        }
        else{
            string str2;
            char c = 97 + j;
            str2 = c;
            str = str2;
        }       
        return str;    
    }
    void Reversi::singleStepPlay()
    {
        int cross=0, point=0,numberOfMoves;
        int cont1 = 0,cont2 = 0, xCor=0, yCor=0;
        cout << *this;
        circular = 0;
        cont1 = controlElements(cross, point);
        int sum = circular + cross;
        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;

        if(cont1 != 0){  // yapabilicegi hamle sifirsa girmezse
            takeCommand(xCor, yCor);
            play(xCor, yCor);
        }
        cout << *this;
        circular = 0;
        controlElements(cross = 0, point = 0);
        sum = cross + circular;

        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
        cont2 = play();
        if(cont2 != -1){
            cout << *this;
            circular = 0;
            controlElements(cross = 0, point = 0);
            sum = cross + circular;
            cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
        }
        endOfGame(cont1,cont2);   
    }
    int Reversi::play(int xCor,int yCor)
    {  
        int status;
        int change,max = 0, mX, mY; 
        mX= xCor; mY = yCor;
        int numberOfMoves = 0;
        int userCont = 0;
        change = 0;
        int k = 0;
        for (int i = 0; i < getSizeX(); ++i)
        {
            for (int j = 0; j < getSizeY(); ++j)
            {
                if(gameCells[k].getCh() == '.')
                {
                    move(i,j,getSizeX(),getSizeY(),change,'O','X',numberOfMoves);
                    if(max < numberOfMoves)
                        max = numberOfMoves;
                }
                k++;
            }
        }
        userCont = max;
        if(userCont == 0){  // Hamle kalmazsa computera geciyor
            cout << endl;
            cout << "User Passes(no move possible)\n";
            return -1;
        }
        max = 0;	
        if(userCont != 0)
        {	
            change = 1;
            while(!(gameCells[yCor + ( xCor * getSizeY() ) ].getCh() == '.'))
            {         
                cout << "ERROR ENTERY !!!\n";
                takeCommand(xCor,yCor);
            }
            status = move(xCor,yCor,getSizeX(),getSizeY(),change,'O','X',numberOfMoves);
            while(status == -1)
            {
                cout << "ERROR ENTERY !!\n";
                takeCommand(xCor,yCor);
                status = move(xCor,yCor,getSizeX(),getSizeY(),change,'O','X',numberOfMoves);
            }
            cout << endl;
        }
        return 0;
    }
    int Reversi::play()
    {  
        int change,max = 0,mX,mY,sum;
        string str;    
        change = 0;
        int numberOfMoves = 0;
        int computerCont = 0;
        int k = 0;
        for (int i = 0; i < getSizeX(); ++i) // En buyuk hamleyi bulur
        {
            for (int j = 0; j < getSizeY(); ++j)
            {
                if(gameCells[k].getCh() == '.')
                {
                    move(i,j,getSizeX(),getSizeY(),change,'X','O',numberOfMoves);
                    if(max < numberOfMoves)
                    { 
                        max = numberOfMoves;
                        mX = i; mY = j;
                    }
                }
                k++;
            }
        }	
        computerCont = max;
        if (computerCont == 0){
            cout << endl;
            cout << "Computer Passes(no move possible)\n";
            return -1;
        }
        sum = max; max = 0;
        if(computerCont != 0)
        {
            change = 1;
            //cout << "numberOfMoves : " << sum << endl;
            move(mX,mY,getSizeX(),getSizeY(),change,'X','O',numberOfMoves);		
            cout << "\nComputer is Playing :" << endl;
            str = combineChar(mY);
            cout << mX+1 << str << endl;
            cout << endl;
        }
        return 0;
    }
    void Reversi::mainPlay()
    {
        int cross=0, point=0;
        int cont1 = 0,cont2 = 0, xCor=0, yCor=0;
        displayBoard();
        controlElements(cross, point);
        int sum = cross + circular;
        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;

        while(1){
            cont1 = controlElements(cross = 0, point = 0); 
            if(cont1 != 0){
                takeCommand(xCor, yCor);
                play(xCor, yCor);
            }
            if(0 == endOfGame(cont1,cont2))  // oyun biterse dongiden cikiyor
                break;
            displayBoard();
            controlElements(cross = 0, point = 0);
            sum = cross + circular;
            cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
            cont2 = play();
            if(cont2 != -1){
                displayBoard();
                controlElements(cross = 0, point = 0);
                sum = cross + circular;
                cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
            }
            cout << "Do you want exit from the printGame? y/n" << endl;
            char c; 
            cin >> c;
            if(c == 'y' || c == 'Y')
                break;
            while(!(c == 'y' || c == 'Y' || c == 'n' || c ==  'N'))
            {
                cout << "Enter y / n" << endl;
                cin >> c;
            }
            if(c == 'y' || c == 'Y')
                break;

        }
    }
    int Reversi::move(const int xCor,const int yCor,const int rows,const int cols,int change,const char char1,const char char2,int &numberOfMoves)
    {
            int cont,st2=0,st=0;
            int status = -1,corX,corY,temp;
            string str;
            int ix,y,x;

            x = xCor; y = yCor;
            numberOfMoves = 0;
            //cout << "x : " << x << ", y: " << y << endl;
            if((x+1 < rows) && ( gameCells[y + ( (x + 1) * getSizeY())].getCh() == char2)) //asagi
            {	
                //cout << "deneme\n";
                cont = x;
                while((cont < rows) && (st2 != -1) && (st != 2))
                {
                    cont++;
                    if(cont < rows){
                        if(gameCells[y + ( cont * getSizeY() )].getCh() == char2)
                            st = 1;
                        else if(gameCells[y + ( cont * getSizeY() )].getCh() == char1)
                            st = 2;
                        else
                            st2 = -1;	
                    }
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
                        str = gameCells[y + ( i * getSizeY() )].getCorX();
                        ix = gameCells[y + ( i * getSizeY() )].getCorY();
                        gameCells[y + ( i * getSizeY() )].setPosition(str,char1,ix);
                    }
                    status = 0;
                }
                st=0;st2=0;
            }
            if((x-1 >= 0) && (gameCells[y + ( (x - 1) * getSizeY())].getCh() == char2)) //yukari
            {
                //cout << "deneme2\n";
                cont = x;
                while((cont >= 0) && (st2 != -1) && (st != 2))
                {
                    cont--;
                    if(cont >= 0){
                        if(gameCells[y + (cont * getSizeY())].getCh() == char2)
                            st = 1;
                        else if(gameCells[y + (cont * getSizeY())].getCh() == char1)
                            st = 2;
                        else 
                            st2 = -1;
                    }			
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
                        str = gameCells[y + (i * getSizeY())].getCorX();
                        ix = gameCells[y + (i * getSizeY())].getCorY();
                        gameCells[y + (i * getSizeY())].setPosition(str,char1,ix);
                    }
                    status = 0;
                }		
                st=0;st2=0;
            }
            if((y+1 < cols) && (gameCells[(y+1) + (x * getSizeY())].getCh() == char2)) //sag
            {
                //cout << "deneme3\n";
                cont = y;
                while((cont < cols) && (st2 != -1) && (st != 2))
                {
                    cont++;
                    if(cont < cols){
                        if(gameCells[cont + (x * getSizeY())].getCh() == char2)
                            st = 1;
                        else if(gameCells[cont + (x * getSizeY())].getCh() == char1)
                            st = 2;
                        else 
                            st2 = -1;	
                    }	
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
                        str = gameCells[i + (x * getSizeY())].getCorX();
                        ix = gameCells[i + (x * getSizeY())].getCorY();
                        gameCells[i + (x * getSizeY())].setPosition(str,char1,ix);
                    }
                    status = 0;
                }
                st=0;st2=0;
            }
            if((y-1 >= 0) && (gameCells[(y-1) + (x * getSizeY())].getCh() == char2)) //sol
            {
                //cout << "deneme4\n";
                cont = y;
                while((cont >= 0) && (st2 != -1) && (st != 2))
                {
                    cont--;
                    if(cont >= 0){
                        if(gameCells[cont + (x * getSizeY())].getCh() == char2)
                            st = 1;
                        else if(gameCells[cont + (x * getSizeY())].getCh() == char1)
                            st = 2;
                        else 
                            st2 = -1;	
                    }		
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
                        str = gameCells[i + (x * getSizeY())].getCorX();
                        ix = gameCells[i + (x * getSizeY())].getCorY();
                        gameCells[i + (x * getSizeY())].setPosition(str,char1,ix);
                    }
                    status = 0;
                }
                st=0;st2=0;	
            }
            if((x-1 >= 0) && (y+1 < cols) && (gameCells[(y+1) + ((x-1) * getSizeY())].getCh() == char2)) //sag yukari
            { 
                //cout << "deneme5\n";
                corY = y;
                corX = x;
                while((corX >= 0) && (corY < cols) && (st2 != -1) && (st != 2))
                {
                    corX--;
                    corY++;
                    if((corX >= 0) && (corY < cols)){
                        if(gameCells[corY + (corX * getSizeY())].getCh() == char2)
                            st = 1;
                        else if(gameCells[corY + (corX * getSizeY())].getCh() == char1)
                            st = 2;
                        else 
                            st2 = -1;
                    }			
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
                        if((corX <= x) && (y <= corY)){
                            str = gameCells[corY + (corX * getSizeY())].getCorX();
                            ix = gameCells[corY + (corX * getSizeY())].getCorY();
                            gameCells[corY + (corX * getSizeY())].setPosition(str,char1,ix);
                        }
                    }
                    status = 0;
                }
                st=0;st2=0;		
            }
            if((x-1 >= 0) && (y-1 >= 0) && (gameCells[(y-1) + ((x-1) * getSizeY())].getCh() == char2)) //sol yukari
            {
                //cout << "deneme6\n";
                corY = y;
                corX = x;
                while((corX >= 0) && (corY >= 0) && (st2 != -1) && (st != 2))
                {
                    corX--;
                    corY--;
                    if((corX >= 0) && (corY >= 0)){
                        if(gameCells[corY + (corX * getSizeY())].getCh() == char2)
                            st = 1;
                        else if(gameCells[corY + (corX * getSizeY())].getCh() == char1)
                            st = 2;
                        else 
                            st2 = -1;	
                    }		
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
                        if((corX <= x) && (corY <= y)){
                            str = gameCells[corY + (corX * getSizeY())].getCorX();
                            ix = gameCells[corY + (corX * getSizeY())].getCorY();
                            gameCells[corY + (corX * getSizeY())].setPosition(str,char1,ix);
                        }
                    }
                    status = 0;
                }
                st=0;st2=0;	
            }
            if((x+1 < rows) && (y+1 < cols) && (gameCells[(y+1) + ((x+1) * getSizeY())].getCh() == char2)) //sag asagi
            {
                //cout << "deneme7\n";
                corY = y;
                corX = x;
                while((corX < rows) && (corY < cols) && (st2 != -1) && (st != 2))
                {
                    corX++;
                    corY++;
                    if((corX < rows) && (corY < cols)){
                        if(gameCells[corY + (corX * getSizeY())].getCh() == char2)
                                st = 1;
                        else if(gameCells[corY + (corX * getSizeY())].getCh() == char1)
                                st = 2;
                        else 
                                st2 = -1;		
                    }	
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
                        if((corX >= x) && (corY >= y)){
                            str = gameCells[corY + (corX * getSizeY())].getCorX();
                            ix = gameCells[corY + (corX * getSizeY())].getCorY();
                            gameCells[corY + (corX * getSizeY())].setPosition(str,char1,ix);
                        }
                    }
                    status = 0;
                }
                st=0;st2=0;
            }
            if((x+1 < rows) && (y-1 >= 0) && (gameCells[(y-1) + ((x+1) * getSizeY())].getCh() == char2)) //sol asagi
            {
                //cout << "deneme8\n";
                corY = y;
                corX = x;
                while((corX < rows) && (corY >= 0) && (st2 != -1) && (st != 2))
                {
                        corX++;
                        corY--;
                        if((corX < rows) && (corY >= 0)){
                            if(gameCells[corY + (corX * getSizeY())].getCh() == char2)
                                st = 1;
                            else if(gameCells[corY + (corX * getSizeY())].getCh() == char1)
                                st = 2;
                            else 
                                st2 = -1;	
                       }		
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
                        if((corX >= x) && (corY <= y)){
                            str = gameCells[corY + (corX * getSizeY())].getCorX();
                            ix = gameCells[corY + (corX * getSizeY())].getCorY();
                            gameCells[corY + (corX * getSizeY())].setPosition(str,char1,ix);
                        }
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
    void Reversi::takeCommand(int &xCor, int &yCor) 
    {
        string str;

        cout << endl;
        cout << "You" << endl;
        cout << "Enter a move: " << endl;
        cin >> xCor;
        cin >> str;

        int size = str.length();
        if(size == 1)
        {
            char c = str.at(0);
            yCor = static_cast<int>(c);
            if(yCor <= 90 && yCor >= 65)
                yCor-=65;
            if(yCor <= 122 && yCor >= 97)
                yCor -= 97;
        }
        else if(size == 2)
        {
            char c = str.at(0);
            int num = static_cast<int>(c);
            if(num <= 90 && num >= 65){
                num = num - 65 + 1;
                yCor = (26 * 26) + (num * 26);
                c = str.at(1);
                int num2 = static_cast<int>(c);
                num2 = num2 - 65;
                yCor += num2;
            }
            if(num <= 122 && num >= 97){
                num = num - 97 + 1;
                yCor = 26 * num;
                c = str.at(1);
                int num2 = static_cast<int>(c);
                num2 = num2 - 97;
                yCor += num2;
            }
        }
        xCor -= 1;
    }
    int Reversi::controlElements(int &cross,int &point )
    {
        circular = 0;
        int max = 0,numberOfMoves=0;
        for (int i = 0; i < getSizeX(); ++i)
        {
            for (int j = 0; j < getSizeY(); ++j)
            {
                if(gameCells[j + (i * getSizeY())].getCh() == 'X')
                    cross++;
                else if (gameCells[j + (i * getSizeY())].getCh() == 'O')
                    circular++;
                else if(gameCells[j + (i * getSizeY())].getCh() == '.')
                    point++;
            }
        } 

        for (int i = 0; i < getSizeX(); ++i)  // kullanici icin yapabilecigi max uzunluktaki hamleyi bulur
        {
            for (int j = 0; j < getSizeY(); ++j)
            {
                if(gameCells[j + (i * getSizeY())].getCh() == '.')
                {
                    move(i,j,getSizeY(),getSizeY(),0,'O','X',numberOfMoves);
                    if(max < numberOfMoves)
                        max = numberOfMoves;
                }
            }
        }
        return  max;
    }
    int Reversi::endOfGame(const int userCont,const int computerCont) 
    {
        int cross = 0, point = 0;
        circular = 0;
        controlElements(cross, point);
        if( (userCont == 0 && computerCont == -1) || point == 0)
        {
            displayBoard();
            cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
            cout << endl;
            if(userCont == 0 && computerCont == -1)
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

            return 0;
        }
        return -1;
    }
    Reversi Reversi::operator++()
    {
        int change,max = 0,mX,mY,sum;
        change = 0;
        int numberOfMoves = 0;
        int computerCont = 0;
        
        int k = 0;
        for (int i = 0; i < getSizeX(); ++i) // En buyuk hamleyi bulur
        {
            for (int j = 0; j < getSizeY(); ++j)
            {
                if(gameCells[k].getCh() == '.')
                {
                    move(i,j,getSizeX(),getSizeY(),change,'X','O',numberOfMoves);
                    if(max < numberOfMoves)
                    { 
                        max = numberOfMoves;
                        mX = i; mY = j;
                    }
                }
                k++;
            }
        }	
        computerCont = max;
        if (computerCont == 0){
            cout << endl;
            cout << "Computer Passes(no move possible)\n";
        }
        if(computerCont != 0)
        {
            change = 1;
            move(mX,mY,getSizeX(),getSizeY(),change,'X','O',numberOfMoves);		
        }
        return *this;
    }
    Reversi Reversi::operator++(int)
    {
        Reversi temp(*this);
        int change,max = 0,mX,mY,sum;
        change = 0;
        int numberOfMoves = 0;
        
        int k = 0;
        for (int i = 0; i < getSizeX(); ++i) // En buyuk hamleyi bulur
        {
            for (int j = 0; j < getSizeY(); ++j)
            {
                if(gameCells[k].getCh() == '.')
                {
                    move(i,j,getSizeX(),getSizeY(),change,'X','O',numberOfMoves);
                    if(max < numberOfMoves)
                    { 
                        max = numberOfMoves;
                        mX = i; mY = j;
                    }
                }
                k++;
            }
        }	
        if(max != 0)
        {
            change = 1;
            move(mX,mY,getSizeX(),getSizeY(),change,'X','O',numberOfMoves);		
        }
        return temp;
    }
    void Reversi::playGame()
    {
        int x,y;
        cout << "Enter sizes of board: " << endl;
        cin >> x >> y;
        resize(x,y);        
        mainPlay();
    }
    void Reversi::resize(int sizeX, int sizeY)
    {
        delete [] gameCells;
        capacity =  sizeX*sizeY;
        gameCells = new Cell[capacity];
        
        sizeRow = sizeX;
        sizeCol = sizeY;
        testReversi();  
        string str;
        int mid1, mid2;
        mid1 = getSizeX() / 2;
        mid2 = getSizeY() / 2;

        int k=0;
        for(int i = 0; i < getSizeX(); ++i)
        {
            for(int j = 0; j < getSizeY(); ++j)
            {
                str = combineChar(j);
                if((i == mid1-1) && (j == mid2-1))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else if((i == mid1-1) && (j == mid2))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid1) && (j == mid2-1))
                    gameCells[k] = (Cell(str,i+1,'O'));
                else if((i == mid1) && (j == mid2))
                    gameCells[k] = (Cell(str,i+1,'X'));
                else												
                    gameCells[k] = (Cell(str,i+1,'.'));
                k++;
            }
        }
        
    }
    bool Reversi::compareReversiGames(Reversi &other) 
    {
        int point = 0, cross = 0;
        controlElements(cross, point);
        other.controlElements(cross = 0, point = 0);
        return  (getCircular() > other.getCircular());
    }
    void Reversi::testCallByValeu(const Reversi test){cout << test;}
    void Reversi::testCallByRef(const Reversi &test){cout << test;}
    Reversi::~Reversi()
    {
        //cout << "destructor" << endl;
        delete [] gameCells;
        livingReversiGame--;
        cout << "livingReversiGame : " << Reversi::getNumOfReversiGame() << endl;
    }
}
