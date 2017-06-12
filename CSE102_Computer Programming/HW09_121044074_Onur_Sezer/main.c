/*############################################################################*/
/*HW09_121044074_Onur_Sezer                                                   */
/*______________________                                                      */
/*Written by Onur Sezer on December 07, 2014                                  */
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
#define M_SIZE 40
#define TRUE 1
#define FALSE 0
/*----------------------------------------------------------------------------*/
/*                  Function Prototypes                                       */
/*----------------------------------------------------------------------------*/
/*PART_1*/
void test_part1();
void string_rev(char *str);
/*PART_2*/
void test_part2();
int maze_run(int x,int y,int size,char str[][M_SIZE]);
/*PART_3*/
void test_part3();
void test_set_operations(char *set);
int is_set(char *set);
int is_empty(const char *set);
int is_element(char ele, const char *set);
void adds_element(const char *sub, char *set);
void print_set(const char *set);
void print_with_commas(const char *str);
int is_subset(const char *sub, const char *set);
void set_union(const char *set1, char *set2);

int main() {
    
    puts("-------------------------------");
    printf("testing the function test_part1: \n");
    test_part1();
    puts("-------------------------------"); 

    puts("-------------------------------");
    printf("testing the function test_part2: \n");
    test_part2();
    puts("-------------------------------");

    puts("-------------------------------");
    printf("testing the function test_part3: \n");
    test_part3();
    puts("-------------------------------"); 

    return 0;
}
void test_part1()
{   
    char str[SIZE];

    gets(str);
    printf("Output:\n");
    string_rev(str);
    printf("\n");

}
void string_rev(char *str)
{

    if( str[0] != '\0' ) { 
        string_rev(&str[1]);
        printf("%c",str[0]);    
    }
}
void test_part2()
{
    int x,y,i=0,j,size,a,b=0;
    char str[M_SIZE][M_SIZE],skip;
    
    gets(str[i]);
    a = strlen(str[i]);

    for(i=1; b!=-1; i++){
        gets(str[i]);
        b = strlen(str[i]);
        if(a != b)
            b = -1;
    }

    sscanf(str[i-1],"%d%d",&x,&y);

    str[x][y] = '.';

    printf("x:%d  y:%d\n",x,y);        
    
    size = a;

    maze_run(x,y,size,str);
     
    printf("\nOutput:\n");   

    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            printf("%c",str[i][j]);
        printf("\n");
    }
}
int maze_run(int x,int y,int size,char str[][M_SIZE])
{   
    int ans=-1;

    if(x-1 == 0 && str[x-1][y] == '0'){
        str[x-1][y] = '.';
        ans = 0;
        return ans;
    }
    else if(x+1 == size-1 && str[size-1][y] == '0'){
        str[size-1][y] = '.';
        ans = 0;
        return ans;
    }
 
    else if(y-1 == 0 && str[x][y-1] == '0'){
        str[x][y-1] = '.';
        ans=0;
        return ans;
    }
    else if(y+1 == size-1 && str[x][size-1] == '0'){
        str[x][size-1] = '.';
        ans=0;
        return ans;
    }
    
    if(ans != 0 ){

        if(ans !=0 && (str[x-1][y] == '0') ){
            str[x-1][y] = '.';
            x -= 1;
            printf(" ");  
            ans = maze_run(x,y,size,str);
                 
        }
        if( ans !=0 && (str[x][y-1] == '0') ){
            str[x][y-1] = '.';
            y -= 1;  
            printf(" ");         
            ans = maze_run(x,y,size,str);
                            
        }
        if( ans !=0 && (str[x+1][y] == '0') ){
            str[x+1][y] = '.';
            x += 1;
            printf(" ");
            ans = maze_run(x,y,size,str);
               
        }
        if( ans !=0 && (str[x][y+1] == '0') ){
            str[x][y+1] = '.';
            y += 1;
            printf(" ");
            ans = maze_run(x,y,size,str);
                
        }
    }

}
void test_part3()
{   
    char st[SIZE],set[SIZE],ch,sub[SIZE],skip;
    int status;

    printf("Enter a string:\n");
    gets(set);
    
    while(is_set(set) != TRUE){

        printf("String is not set!!\n");
        gets(set);
    }

    test_set_operations(set);

}
void test_set_operations(char *set)
{
    char st[SIZE],ch,sub[SIZE],skip;
    int status;

    printf("Enter the command => [em,el,as,ps,psc,su,un,q]\n");
    scanf("%s%c",st,&skip);
    
    while( strcmp(st,"q") != 0 ) {

        if(strcmp(st,"em") == 0){
            
            status = is_empty(set);

            if(status == TRUE)
                printf("String is empty.\n");
            else
                printf("String is not empty.\n");
          
        }
        else if ( strcmp(st,"el") == 0 ) {
            
            printf("Enter a character\n");
            scanf("%c",&ch);
            status = is_element(ch,set);

            if(status == TRUE)
                printf("%c is element of the string.\n",ch);
            else
                printf("%c is not element of the string.\n",ch);            
            
        }
        else if ( strcmp(st,"as") == 0 ) {
            
            gets(sub);
            adds_element(sub,set);

        }
        else if ( strcmp(st,"ps") == 0 ) {

            print_set(set);

        }
        else if ( strcmp(st,"psc") == 0 ) {

            print_with_commas(set);            
    
        }
        else if ( strcmp(st,"su") == 0 ) {

            gets(sub);
            status = is_subset(sub,set);

            if(status == TRUE)
                printf("%s is subset of the %s.\n",sub,set);
            else
                printf("%s is not subset of the %s.\n",sub,set);            

       }
       else if ( strcmp(st,"un") == 0 ) {
            
            gets(sub);
            set_union(sub,set);

        }
        
       printf("Enter the command => [em,el,as,ps,psc,su,un,q]\n");
       scanf("%s%c",st,&skip);
    }

}
int is_set(char *set)
{
    int i,j,st,ans = TRUE,result=0;

    for(i=0; set[i] != '\0'; i++){
        for(j=0; set[j] != '\0'; j++){
            if(i != j && set[i] == set[j])
                return FALSE;
        }  
    }

    return ans;
}
int is_empty(const char *set)
{
    int ans;

    if(set[0] == '\0')
        ans = TRUE;
    else
        ans = FALSE;

    return ans;
}
int is_element(char ele, const char *set)
{
    int i,ans;
    ans = FALSE;
    
    for(i=0; set[i] != '\0'; i++){
        if(set[i] == ele)
            ans = TRUE;    
    }
    
    return ans;
}
void adds_element(const char *set1, char *set2)
{
    char result[SIZE];
    int i,j,k;

    for(i=0; set2[i] != '\0'; i++) {
        result[i] = set2[i];
    }


    for(j=0; set1[j] != '\0'; j++) {
        if( is_element(set1[j],set2) != TRUE ){  
            result[i] = set1[j];
            i++;
        }
    }

    result[i] = '\0';

    strcpy(set2,result);
}
void print_set(const char *set)
{
    int i;
    
    for(i=0; set[i] != '\0'; i++) {
        printf("%c",set[i]);
    }
    printf("\n");    
}
void print_with_commas(const char *set)
{
    int i;

    i=0;
    printf("{");
    for(i=0; set[i] != '\0'; i++){
        printf("%c",set[i]);
        if(set[i+1] != '\0')
            printf(",");
    }
    printf("}\n");

}
int is_subset(const char *sub, const char *set)
{
    int i,ans,ans1,ans2=-1;

    for(i=0; sub[i] != '\0'; i++){

        if( is_element(sub[i],set) == TRUE )
            ans1 = 1;
        else
            ans2 = 0; 
    }

    if(ans2 == 0)
        ans = 0;
    else
        ans = 1;

    return ans;

}
void set_union(const char *set1, char *set2)
{
    char result[SIZE];
    int i,j,k;

    for(i=0; set2[i] != '\0'; i++) {
        result[i] = set2[i];
    }


    for(j=0; set1[j] != '\0'; j++) {
        if( is_element(set1[j],set2) != TRUE ){  
            result[i] = set1[j];
            i++;
        }
    }

    
    result[i] = '\0';

    strcpy(set2,result);

}
/*############################################################################*/
/*              End of HW09_121044074_Onur_Sezer                              */
/*############################################################################*/
