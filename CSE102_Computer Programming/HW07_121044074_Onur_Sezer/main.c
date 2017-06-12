/*############################################################################*/
/*HW07_121044074_Onur_Sezer                                                   */
/*______________________                                                      */
/*Written by Onur Sezer on November 13, 2014                                  */
/*                                                                            */             
/*############################################################################*/
/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
/*----------------------------------------------------------------------------*/
/*                             #defines                                       */
/*----------------------------------------------------------------------------*/
#define SIZE 100

void test_part1();
int check_success(char board[][SIZE],char ch,int size);
void test_part2();
void test_part3();
int enqueue(int queue[],int *tail_p,int *head_p,int maxsize);
int dequeue(int queue[],int *head_p,int *elem_p,int maxsize);
void test_part4();
int medyan(int i,int j,int arr2D[][SIZE],int data_size,int filter_size);


int main() {
 
/* 
    puts("-------------------------------");
    printf("testing the function test_part1\n");
    test_part1();
    puts("-------------------------------");
 

    puts("-------------------------------");
    printf("testing the function test_part2\n");
    test_part2();
    puts("-------------------------------");
*/    

    puts("-------------------------------");
    printf("testing the function test_part3\n");
    test_part3();
    puts("-------------------------------");
/* 
    puts("-------------------------------");
    printf("testing the function test_part4 \n");
    test_part4();
    puts("-------------------------------");
*/
    return 0;
}
void test_part1()
{
    int size,i,j,st;
    char ch,skip,board[SIZE][SIZE];
  
    scanf("%d",&size);
    scanf("%c",&skip);
    scanf("%c",&ch);
    scanf("%c",&skip);

    if( ch == 'x' || ch == 'X' || ch == 'o' || ch == 'O' ){
       
        for(i=0;i<size;i++){
            j=0;
            scanf("%c",&board[i][j]);
            j=1;
            while(j<size ){
                scanf("%c",&board[i][j]);
                if(board[i][j] != ' ')
                    j++;
            }
            scanf("%c",&skip);
        } 
        
       st = check_success(board,ch,size);
        
        if(st == 1)
            printf("\nWin\n");
        if(st == 0)
            printf("\nLose\n");
        if(st == -1)
            printf("\nDraw\n");
    }
    else
        printf("Yanlis Karekter!!\n");
    
}
int check_success(char board[][SIZE],char ch,int size)
{   
    int i,j,ct2=-1,ct,status=-1,status2=-1;

    /**xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

    if(ch == 'x'){
        /********************    YATAY   *********************/
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'x')
                    ct=1;
                if(board[i][j] == 'o')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'o')
                    ct=1;
                if(board[i][j] == 'x')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }
        if(status2 == 1)
            return 0;
        if(status == 1)
            return 1;
        
        status=-1;
        status2=-1;
        /********************    SAG CAPRAZ   *********************/
        i=0; j=0;
        while(i < size){
            if(board[i][j] == 'x')
                ct = 1;
            if(board[i][j] == 'o')
                ct2 = 0;
            i++;
            j++;
        }
        if(ct2 != 0)
            return 1;
        
        ct2=-1;

        /********************    SOL CAPRAZ   *********************/

        i=0; j=size-1;
        while(i < size){
            if(board[i][j] == 'x')
                ct = 1;
            if(board[i][j] == 'o')
                ct2 = 0;
            i++;
            j--;
        }
        if(ct2 != 0)
            return 1;

        ct2=-1;

        /********************    DİKEY   *********************/
        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'x')
                    ct=1;
                if(board[i][j] == 'o')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;          
            ct2=-1;
        }

        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'o')
                    ct=1;
                if(board[i][j] == 'x')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }

        if(status2 == 1) 
            return 0;
        if(status == 1)
            return 1;

        return -1;
    }

    /*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

    else if(ch == 'X'){

    /********************    YATAY   *********************/
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'X')
                    ct=1;
                if(board[i][j] == 'O')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'O')
                    ct=1;
                if(board[i][j] == 'X')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }
        if(status2 == 1)
            return 0;
        if(status == 1)
            return 1;
        
        status=-1;
        status2=-1;
        /********************    SAG CAPRAZ   *********************/
        i=0; j=0;
        while(i < size){
            if(board[i][j] == 'X')
                ct = 1;
            if(board[i][j] == 'O')
                ct2 = 0;
            i++;
            j++;
        }
        if(ct2 != 0)
            return 1;
        
        ct2=-1;

        /********************    SOL CAPRAZ   *********************/

        i=0; j=size-1;
        while(i < size){
            if(board[i][j] == 'X')
                ct = 1;
            if(board[i][j] == 'O')
                ct2 = 0;
            i++;
            j--;
        }
        if(ct2 != 0)
            return 1;

        ct2=-1;

        /********************    DİKEY   *********************/
        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'X')
                    ct=1;
                if(board[i][j] == 'O')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'O')
                    ct=1;
                if(board[i][j] == 'X')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }

        if(status2 == 1) 
            return 0;
        if(status == 1)
            return 1;

        return -1;
    }

    /*ooooooooooooooooooooooooooooooooooooooooooooooooooooo*/

    else if(ch == 'o'){
    
    /********************    YATAY   *********************/
        
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'o')
                    ct=1;
                if(board[i][j] == 'x')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'x')
                    ct=1;
                if(board[i][j] == 'o')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }
        if(status2 == 1)
            return 0;
        if(status == 1)
            return 1;
        
        status=-1;
        status2=-1;
        /********************    SAG CAPRAZ   *********************/
        i=0; j=0;
        while(i < size){
            if(board[i][j] == 'o')
                ct = 1;
            if(board[i][j] == 'x')
                ct2 = 0;
            i++;
            j++;
        }
        if(ct2 != 0)
            return 1;
        
        ct2=-1;

        /********************    SOL CAPRAZ   *********************/

        i=0; j=size-1;
        while(i < size){
            if(board[i][j] == 'o')
                ct = 1;
            if(board[i][j] == 'x')
                ct2 = 0;
            i++;
            j--;
        }
        if(ct2 != 0)
            return 1;

        ct2=-1;

        /********************    DİKEY   *********************/
        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'o')
                    ct=1;
                if(board[i][j] == 'x')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'x')
                    ct=1;
                if(board[i][j] == 'o')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }

        if(status2 == 1) 
            return 0;
        if(status == 1)
            return 1;

        return -1;
    }

    /*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/

    else if(ch == 'O'){

    /********************    YATAY   *********************/
        
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'O')
                    ct=1;
                if(board[i][j] == 'X')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j] == 'X')
                    ct=1;
                if(board[i][j] == 'O')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }
        if(status2 == 1)
            return 0;
        if(status == 1)
            return 1;
        
        status=-1;
        status2=-1;
        /********************    SAG CAPRAZ   *********************/
        i=0; j=0;
        while(i < size){
            if(board[i][j] == 'O')
                ct = 1;
            if(board[i][j] == 'X')
                ct2 = 0;
            i++;
            j++;
        }
        if(ct2 != 0)
            return 1;
        
        ct2=-1;

        /********************    SOL CAPRAZ   *********************/

        i=0; j=size-1;
        while(i < size){
            if(board[i][j] == 'O')
                ct = 1;
            if(board[i][j] == 'X')
                ct2 = 0;
            i++;
            j--;
        }
        if(ct2 != 0)
            return 1;

        ct2=-1;

        /********************    DİKEY   *********************/
        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'O')
                    ct=1;
                if(board[i][j] == 'X')
                    ct2=0;
            }
            if(ct2 != 0)
                status=1;
            ct2=-1;
        }

        for(j=0;j<size;j++){
            for(i=0;i<size;i++){
                if(board[i][j] == 'X')
                    ct=1;
                if(board[i][j] == 'O')
                    ct2=0;
            }
            if(ct2 != 0)
                status2=1;
            ct2=-1;
        }

        if(status2 == 1) 
            return 0;
        if(status == 1)
            return 1;

        return -1;
    }
}
void test_part2()
{
    int i=0,n,j=0,k=0,l=0,ct=0,size=0,a,b=0,c,g;
    char skip,temp[SIZE],temp2[SIZE][SIZE],temp3[SIZE][SIZE],arr[SIZE],arr2[SIZE][SIZE];    
        
    scanf("%d",&n);
    n-=1;

    scanf("%c",&skip);
    while(skip == ' '){
        scanf("%c",&skip);
    }

    scanf("%c",&arr[i]);

    while(arr[i] != '\n'){
        i++;
        scanf("%c",&arr[i]);
    }

    while(k < i){
        if(arr[k] != ' '){
            arr2[j][l] = arr[k];
            l++;
        } 
        else{
            j++;
            if(ct < l)
                ct = l;
            l=0;
        }
        k++;
    }
    if(ct < l)
        ct = l;
    
    for( i = 0; i <= j; i++ ) {
		for( g = j; g > i; g-- )  {
            if( atoi(arr2[g]) > atoi(arr2[g-1]) ) {
		        strcpy(temp,arr2[g-1]);
			    strcpy(arr2[g-1],arr2[g]);
			    strcpy(arr2[g],temp);
            }
        }
    }
    
    
    for( i=0; i <= j; i++ ){
        while( arr2[i][b] != '\0'){
            size++;
            b++;
        }
        if( size - 1 < ct-1 ){        
            a=0;            
            for( c=0; c < ct-size; c++ ){
                    temp3[a][c] = '0';                 
            }     
            strcpy(temp2[a],temp3[a]);
            strcat(temp2[a],arr2[i]);
            strcpy(arr2[i],temp2[a]);
        }           
            b=0;
            size=0;
    }

    n=(ct-1)-n;
         
    for( i = 0; i <= j; i++ ) {
		for( l = j; l > i; l-- )  {
            if(arr2[l][n] == arr2[l-1][n]){
                if(atoi(arr2[l]) < atoi(arr2[l-1]) ){
                    strcpy(temp,arr2[l-1]);
			        strcpy(arr2[l-1],arr2[l]);
			        strcpy(arr2[l],temp);  
                }
    
            }    
            if( arr2[l][n] < arr2[l-1][n] ) {
			    strcpy(temp,arr2[l-1]);
			    strcpy(arr2[l-1],arr2[l]);
			    strcpy(arr2[l],temp);
            }
        }
    }

    for( i = 0; i <= j; i++ )
        printf("%s\n",arr2[i]);
}
void test_part3(){
    char ch;
    int queue[SIZE],tail=0,i=0,j,maxsize=10,st,head=0,headc,num,elem,size;
    
    scanf("%c",&ch);
    while(ch != 'q'){
        if(ch == 'e'){
            enqueue(queue,&tail,&head,maxsize);                
        }   
        else if(ch == 'd'){
            dequeue(queue,&head,&elem,maxsize); 
        }
        else if(ch == 'p'){
            printf("queue: ");
            j=head;
            size = tail - head + 1;
            if(size < 0)
                size = maxsize - head + (tail+1);
            if(size == 0)
                size = 10;
            for(i=1; i < size; i++ ){
                printf("%d ",queue[j]);
                j++;
                j = j % maxsize; 
            }
         
            printf("\n");        
        } 
        scanf("%c",&ch);
    }
       
}

int enqueue(int queue[],int *tail_p,int *head_p,int maxsize)
{
    int num,size;
    char skip;
    /***********/
    size = *tail_p - *head_p + 1;
    if(size < 0)
        size = maxsize - *head_p + (*tail_p + 1);
    /***********/
    
    scanf("%d%c",&num,&skip);
    if(skip == '\n'){
        if(*tail_p == *head_p && (*tail_p + *head_p != 0) ){

            *tail_p = *tail_p + 1;

            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);

            if(size < maxsize)
                *tail_p = *tail_p % maxsize;

            queue[*tail_p] = num;
            *tail_p = *tail_p + 1;
          
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            if(size < maxsize)
                *tail_p = *tail_p % maxsize;
        }
        else if(size < maxsize) {

            if(size < maxsize)
                queue[*tail_p] = num;

            /***********/
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            /************/

            if(size < maxsize)
                *tail_p = *tail_p + 1;

            /************/
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            /************/

            if(size < maxsize)
                *tail_p = *tail_p % maxsize;
        }
        else if(size >= maxsize) {
            printf("maxsize gecilemez!!\n");
        }
    
    }
    else{
        if(*tail_p == *head_p && (*tail_p + *head_p != 0) ){
            *tail_p = *tail_p + 1;
            /***********/
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            /************/

            if(size < maxsize)
                *tail_p = *tail_p % maxsize;
            queue[*tail_p] = num;
            *tail_p = *tail_p + 1;
            /***********/
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            /************/

            if(size < maxsize)
                *tail_p = *tail_p % maxsize;
        }
        else if(size < maxsize){       
            queue[*tail_p] = num;
            *tail_p = *tail_p + 1;
            /***********/
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            /************/

            if(size < maxsize)
                *tail_p = *tail_p % maxsize;
        }
            
        do{
            scanf("%d%c",&num,&skip);
            queue[*tail_p] = num;
            *tail_p = *tail_p + 1;
            /***********/
            size = *tail_p - *head_p + 1;
            if(size < 0)
                size = maxsize - *head_p + (*tail_p + 1);
            /************/

            if(size < maxsize)
                *tail_p = *tail_p % maxsize;
    
        }while( skip != '\n' && (size < maxsize) ); 
        if(size >= maxsize){
            printf("maxsize gecilemez!!\n");
        } 
    }
    return 1;
}

int dequeue(int queue[],int *head_p,int *elem_p,int maxsize)
{
    *elem_p = queue[*head_p];
    *head_p = *head_p + 1;
    *head_p = *head_p % maxsize;
    return 1;   
}

void test_part4()
{
    int filter_size,data_size,i,j,arr[SIZE][SIZE];

    scanf("%d",&data_size);
    scanf("%d",&filter_size);

    for(i=0;i<data_size;i++)
        for(j=0;j<data_size;j++)
            scanf("%d",&arr[i][j]);
    
    printf("Output:\n");

    for(i=0; i < data_size; i++){
        for(j=0; j < data_size; j++){

            arr[i][j] = medyan(i,j,arr,data_size,filter_size);
 
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
            
}
int medyan(int i,int j,int arr[][SIZE],int data_size,int filter_size)
{
    int medyan[SIZE],l=0,k=0,up,down,left,right,a,b,c,m,n,temp;
    
    k = ( filter_size - 1 ) / 2;

    
    up = j + k;
    down = j - k;
    right = i + k;  
    left = i - k;

    while( up > data_size-1)
        up--;
    
    while( down < 0)
        down++;

    while( right > data_size-1)
        right--;

    while( left < 0)
        left++;

    for(a=left; a<=right; a++){
        for(b=down; b<=up; b++){
            
            medyan[l] = arr[a][b];

            l++;      
        }
 
    }  

   l-=1;

   for(m=0; m<=l; m++){
        for(n=l; n>m; n--){
            if(medyan[n] < medyan[n-1]){
                temp = medyan[n-1];
                medyan[n-1] = medyan[n];
                medyan[n] = temp;    
            }
        }
    }
    
    c = l % 2;
    
    if(c == 0)
        return medyan[l/2 +1];
    else
         return ( medyan[l/2] + medyan[l/2 + 1] ) / 2;  
}
/*############################################################################*/
/*              End of HW07_121044074_Onur_Sezer                              */
/*############################################################################*/
