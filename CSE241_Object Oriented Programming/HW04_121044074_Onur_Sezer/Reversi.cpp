#include "Reversi.h"

using namespace std;

int Reversi::numberOfAlive = 0;

void Cell::setPosition(const string x,const char c, const int y)
{
    corX = x;
    corY = y;
    ch = c;
}
void Cell::printCell() const
{ 
    cout << "corX : " << getCorX() << " corY : " << getCorY() << " ch: " << getCh()  << endl; 
} 
Reversi::Reversi(const char *name)
{
    int i = 0;
    while(name[i] != '\0')
    {
        nameOfFile[i] = name[i];
        i++;
    }
    nameOfFile[i] = '\0';
}
Reversi::Reversi(): sizeRow(4),sizeCol(4)
{
    int mid;
    mid = sizeRow / 2;
    for(int i = 0; i < sizeRow; ++i)
    {
        gameCells.push_back(vector <Cell> ());
        for(int j = 0; j < sizeCol; ++j)
        {
            char c = 97 + j;
            string str;
            str = c;
            if((i == mid-1) && (j == mid-1))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else if((i == mid-1) && (j == mid))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid) && (j == mid-1))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid) && (j == mid))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else												
                gameCells[i].push_back(Cell(str,i+1,'.'));
        }	
    }
    numberOfAlive += 4;
}
Reversi::Reversi(const int row):sizeRow(row),sizeCol(row)
{
    string str;
    testReversi();    
    int mid;
    mid = sizeRow / 2;
    for(int i = 0; i < sizeRow; ++i)
    {
        gameCells.push_back(vector <Cell> ());
        for(int j = 0; j < sizeCol; ++j)
        {   
            str = combineChar(j); 
            if((i == mid-1) && (j == mid-1))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else if((i == mid-1) && (j == mid))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid) && (j == mid-1))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid) && (j == mid))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else												
                gameCells[i].push_back(Cell(str,i+1,'.'));
        }	
    }
    numberOfAlive += 4;
}
Reversi::Reversi(const int row, const int col) : sizeRow(row), sizeCol(col)
{
    string str;
    testReversi();    
    int mid1, mid2;
    mid1 = sizeRow / 2;
    mid2 = sizeCol / 2;
    for(int i = 0; i < sizeRow; ++i)
    {
        gameCells.push_back(vector <Cell> ());
        for(int j = 0; j < sizeCol; ++j)
        {   
            str = combineChar(j);
            if((i == mid1-1) && (j == mid2-1))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else if((i == mid1-1) && (j == mid2))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid1) && (j == mid2-1))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid1) && (j == mid2))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else												
                gameCells[i].push_back(Cell(str,i+1,'.'));
        }	
    }
    numberOfAlive += 4;
}
void Reversi::displayBoard() const 
{
    int count=1;
    for (int k = 0; k < sizeCol; ++k)
    {
        if (k == 0) {
            cout << "    " << gameCells[0][k].getCorX();
        }
        else if(k < 25)
            cout << "  " << gameCells[0][k].getCorX();
        else if(k == 25)
            cout << "  " << gameCells[0][k].getCorX() << " ";
        else
            cout << " " << gameCells[0][k].getCorX();
    }
    cout << endl;
    for (int i = 0; i < sizeRow; ++i)
    {
        if(i >= 9)
            cout << count << "  ";
        else
            cout << " " << count << "  ";	
        count++;
        for (int j = 0; j < sizeCol; ++j)
        {
            cout << gameCells[i][j].getCh() << "  ";
        }
        cout << endl;
    }
}
void Reversi::testReversi() const
{
    if(!(sizeRow >= 4 && sizeCol >= 4))
    {
        cout << "Wrong Size !! \n"; // row ve col size'larinin en az 4 olmasini kontrol eder.
        exit(0);
    }
}
int Reversi::play(int xCor,int yCor)
{  
    int status;
    int change,max = 0, mX, mY; 
    mX= xCor; mY = yCor;
    int numberOfMoves = 0;
    int userCont = 0;
    change = 0;
    for (int i = 0; i < sizeRow; ++i)
    {
        for (int j = 0; j < sizeCol; ++j)
        {
            if(gameCells[i][j].getCh() == '.')
            {
                move(i,j,sizeRow,sizeCol,change,'O','X',numberOfMoves);
                if(max < numberOfMoves)
                    max = numberOfMoves;
            }
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
        while(!(gameCells[xCor][yCor].getCh() == '.'))
        {         
            cout << "ERROR ENTERY !!!\n";
            takeCommand(xCor,yCor);
        }
        status = move(xCor,yCor,sizeRow,sizeCol,change,'O','X',numberOfMoves);
        while(status == -1)
        {
            cout << "ERROR ENTERY !!\n";
            takeCommand(xCor,yCor);
            status = move(xCor,yCor,sizeRow,sizeCol,change,'O','X',numberOfMoves);
        }
        cout << endl;
    }
    return 0;
}
int Reversi::play()
{  
    int change,max = 0,mX,mY,sum;
    char ch;    
    change = 0;
    int numberOfMoves = 0;
    int computerCont = 0;
    for (int i = 0; i < sizeRow; ++i) // En buyuk hamleyi bulur
    {
        for (int j = 0; j < sizeCol; ++j)
        {
            if(gameCells[i][j].getCh() == '.')
            {
                move(i,j,sizeRow,sizeCol,change,'X','O',numberOfMoves);
                if(max < numberOfMoves)
                { 
                    max = numberOfMoves;
                    mX = i; mY = j;
                }
            }
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
        move(mX,mY,sizeRow,sizeCol,change,'X','O',numberOfMoves);		
        cout << "\nComputer is Playing :" << endl;
        ch = mY + 97;
        cout << mX+1 << ch << endl;
        cout << endl;
    }
    return 0;
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
	if((x+1 < rows) && ( gameCells[x+1][y].getCh() == char2)) //asagi
	{	
            //cout << "deneme\n";
            cont = x;
            while((cont < rows) && (st2 != -1) && (st != 2))
            {
                cont++;
                if(cont < rows){
                    if(gameCells[cont][y].getCh() == char2)
                        st = 1;
                    else if(gameCells[cont][y].getCh() == char1)
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
                    str = gameCells[i][y].getCorX();
                    ix = gameCells[i][y].getCorY();
                    gameCells[i][y].setPosition(str,char1,ix);
                }
                status = 0;
            }
            st=0;st2=0;
	}
	if((x-1 >= 0) && (gameCells[x-1][y].getCh() == char2)) //yukari
	{
            //cout << "deneme2\n";
            cont = x;
            while((cont >= 0) && (st2 != -1) && (st != 2))
            {
                cont--;
                if(cont >= 0){
                    if(gameCells[cont][y].getCh() == char2)
                        st = 1;
                    else if(gameCells[cont][y].getCh() == char1)
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
                    str = gameCells[i][y].getCorX();
                    ix = gameCells[i][y].getCorY();
                    gameCells[i][y].setPosition(str,char1,ix);
                }
                status = 0;
            }		
            st=0;st2=0;
	}
	if((y+1 < cols) && (gameCells[x][y+1].getCh() == char2)) //sag
	{
            //cout << "deneme3\n";
            cont = y;
            while((cont < cols) && (st2 != -1) && (st != 2))
            {
                cont++;
                if(cont < cols){
                    if(gameCells[x][cont].getCh() == char2)
                        st = 1;
                    else if(gameCells[x][cont].getCh() == char1)
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
                    str = gameCells[x][i].getCorX();
                    ix = gameCells[x][i].getCorY();
                    gameCells[x][i].setPosition(str,char1,ix);
                }
                status = 0;
            }
            st=0;st2=0;
	}
	if((y-1 >= 0) && (gameCells[x][y-1].getCh() == char2)) //sol
	{
            //cout << "deneme4\n";
            cont = y;
            while((cont >= 0) && (st2 != -1) && (st != 2))
            {
                cont--;
                if(cont >= 0){
                    if(gameCells[x][cont].getCh() == char2)
                        st = 1;
                    else if(gameCells[x][cont].getCh() == char1)
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
                    str = gameCells[x][i].getCorX();
                    ix = gameCells[x][i].getCorY();
                    gameCells[x][i].setPosition(str,char1,ix);
                }
                status = 0;
            }
            st=0;st2=0;	
	}
	if((x-1 >= 0) && (y+1 < cols) && (gameCells[x-1][y+1].getCh() == char2)) //sag yukari
	{
            //cout << "deneme5\n";
            corY = y;
            corX = x;
            while((corX >= 0) && (corY < cols) && (st2 != -1) && (st != 2))
            {
                corX--;
                corY++;
                if((corX >= 0) && (corY < cols)){
                    if(gameCells[corX][corY].getCh() == char2)
                        st = 1;
                    else if(gameCells[corX][corY].getCh() == char1)
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
                        str = gameCells[corX][corY].getCorX();
                        ix = gameCells[corX][corY].getCorY();
                        gameCells[corX][corY].setPosition(str,char1,ix);
                    }
                }
                status = 0;
            }
            st=0;st2=0;		
	}
	if((x-1 >= 0) && (y-1 >= 0) && (gameCells[x-1][y-1].getCh() == char2)) //sol yukari
	{
            //cout << "deneme6\n";
            corY = y;
            corX = x;
            while((corX >= 0) && (corY >= 0) && (st2 != -1) && (st != 2))
            {
                corX--;
                corY--;
                if((corX >= 0) && (corY >= 0)){
                    if(gameCells[corX][corY].getCh() == char2)
                        st = 1;
                    else if(gameCells[corX][corY].getCh() == char1)
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
                        str = gameCells[corX][corY].getCorX();
                        ix = gameCells[corX][corY].getCorY();
                        gameCells[corX][corY].setPosition(str,char1,ix);
                    }
                }
                status = 0;
            }
            st=0;st2=0;	
	}
	if((x+1 < rows) && (y+1 < cols) && (gameCells[x+1][y+1].getCh() == char2)) //sag asagi
	{
            //cout << "deneme7\n";
            corY = y;
            corX = x;
            while((corX < rows) && (corY < cols) && (st2 != -1) && (st != 2))
            {
                corX++;
                corY++;
                if((corX < rows) && (corY < cols)){
                    if(gameCells[corX][corY].getCh() == char2)
                            st = 1;
                    else if(gameCells[corX][corY].getCh() == char1)
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
                        str = gameCells[corX][corY].getCorX();
                        ix = gameCells[corX][corY].getCorY();
                        gameCells[corX][corY].setPosition(str,char1,ix);
                    }
                }
                status = 0;
            }
            st=0;st2=0;
	}
	if((x+1 < rows) && (y-1 >= 0) && (gameCells[x+1][y-1].getCh() == char2)) //sol asagi
	{
            //cout << "deneme8\n";
            corY = y;
            corX = x;
            while((corX < rows) && (corY >= 0) && (st2 != -1) && (st != 2))
            {
                    corX++;
                    corY--;
                    if((corX < rows) && (corY >= 0)){
                        if(gameCells[corX][corY].getCh() == char2)
                            st = 1;
                        else if(gameCells[corX][corY].getCh() == char1)
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
                        str = gameCells[corX][corY].getCorX();
                        ix = gameCells[corX][corY].getCorY();
                        gameCells[corX][corY].setPosition(str,char1,ix);
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
void Reversi::mainPlay()
{
    int cross=0, point=0,numberOfMoves;
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
        numberOfAlive += (circular + cross) - sum;
        sum = cross + circular;
        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
        cont2 = play();
        if(cont2 != -1){
            displayBoard();
            controlElements(cross = 0, point = 0);
            numberOfAlive += (circular + cross) - sum;
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
int Reversi::controlElements(int &cross,int &point )
{
    circular = 0;
    int max = 0,numberOfMoves=0;
    for (int i = 0; i < sizeRow; ++i)
    {
        for (int j = 0; j < sizeCol; ++j)
        {
            if(gameCells[i][j].getCh() == 'X')
                cross++;
            else if (gameCells[i][j].getCh() == 'O')
                circular++;
            else if(gameCells[i][j].getCh() == '.')
                point++;
        }
    } 
    
    for (int i = 0; i < sizeRow; ++i)  // kullanici icin yapabilecigi max uzunluktaki hamleyi bulur
    {
        for (int j = 0; j < sizeCol; ++j)
        {
            if(gameCells[i][j].getCh() == '.')
            {
                move(i,j,sizeRow,sizeCol,0,'O','X',numberOfMoves);
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
void Reversi::playGame()
{
    int x,y;
    cout << "Enter sizes of board: " << endl;
    cin >> x >> y;
    
    string str;
    int mid1, mid2;

    int point = 0, cross = 0;
    controlElements(cross, point);
   
    sizeRow = x;
    sizeCol = y;
    testReversi();
    mid1 = sizeRow / 2;
    mid2 = sizeCol / 2;
    for(int i = 0; i < sizeRow; ++i)
    {
        gameCells.push_back(vector <Cell> ());
        for(int j = 0; j < sizeCol; ++j)
        {   
            str = combineChar(j);
            if((i == mid1-1) && (j == mid2-1))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else if((i == mid1-1) && (j == mid2))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid1) && (j == mid2-1))
                gameCells[i].push_back(Cell(str,i+1,'O'));
            else if((i == mid1) && (j == mid2))
                gameCells[i].push_back(Cell(str,i+1,'X'));
            else												
                gameCells[i].push_back(Cell(str,i+1,'.'));
        }	
    }
    numberOfAlive += 4;
    mainPlay();
}
void Reversi::readFile()
{
    string str;
    char c;
    int i=0,j=0;
    ifstream file;
    file.open(nameOfFile);
     
    if (file.fail()){
        cout << "File could not open !!" << endl;
        exit(1);
    }
    gameCells.push_back(vector <Cell> ());
    do{
        file.get(c);
        if(c != '\n' && c != ' '){
            str = combineChar(j);                
            j++;
            if(c == 'O' || c == 'X')
                numberOfAlive += 1;
            gameCells[i].push_back(Cell(str,i+1,c));
        }
        else if(c == '\n'){
            i++;
            sizeCol = j;
            j=0;
            gameCells.push_back(vector <Cell> ());
            //cout << "newline\n";
        }
    }while(!file.eof());
    sizeRow = i + 1;
    file.close();
}
void Reversi::writeFile(const char fileName[]) const
{
    ofstream file;
    file.open(fileName);
    if(file.fail())
    {
        cout << "File could not open !!" << endl;
        exit(1);
    }
    for (int i = 0; i < sizeRow; ++i)
    {
        for (int j = 0; j < sizeCol; ++j)
        {
            file << gameCells[i][j].getCh() << "  ";
        }
        if(i != sizeRow - 1)
            file << "\n";
    }
    
    file.close();
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
bool Reversi::compareReversiGames(Reversi &other) 
{
    int point = 0, cross = 0;
    controlElements(cross, point);
    other.controlElements(cross =0, point = 0);
    return  (getCircular() > other.getCircular());
}
void Reversi::singleStepPlay()
{
    int cross=0, point=0,numberOfMoves;
    int cont1 = 0,cont2 = 0, xCor=0, yCor=0;
    displayBoard();
    circular = 0;
    cont1 = controlElements(cross, point);
    int sum = circular + cross;
    cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
       
    if(cont1 != 0){
        takeCommand(xCor, yCor);
        play(xCor, yCor);
    }
    displayBoard();
    circular = 0;
    controlElements(cross = 0, point = 0);
    numberOfAlive += (circular + cross) - sum;
    sum = cross + circular;
    
    cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
    cont2 = play();
    if(cont2 != -1){
        displayBoard();
        circular = 0;
        controlElements(cross = 0, point = 0);
        numberOfAlive += (circular + cross) - sum;
        sum = cross + circular;
        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
    }
    endOfGame(cont1,cont2);   
}