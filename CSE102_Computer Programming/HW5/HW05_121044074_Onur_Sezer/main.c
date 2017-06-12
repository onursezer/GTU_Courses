/*############################################################################*/
/*HW05_121044074_Onur_Sezer                                                   */
/*______________________                                                      */
/*Written by Onur Sezer on October 29, 2014                                   */
/*                                                                            */             
/*Inputs:                                                                     */
/*Konsoldan ve in.txt den alinan degerler                                     */
/*                                                                            */
/*Outputs:                                                                    */
/*Konsola basar                                                               */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                             #defines                                       */
/*----------------------------------------------------------------------------*/
#define SIZE 100      /*size of content[]*/
#define MIN 97       /* 'a' nin ASCII degeri */
#define MAX 122      /* 'z' nin ASCII degeri */
#define MIN2 65      /* 'A' nin ASCII degeri */
#define MAX2 90      /* 'Z' nin ASCII degeri */
#define FARK 32      /*K.harf ve B.harfin ASCII degerleri farki*/
/*#####################################################*/
/*Fonksiyon girilen saatin uygunlugunu kontrol eder    */
/*input: int *hour,*minute                             */
/*output:Sonucu konsola basar                          */
/*#####################################################*/
int read_time(int *hour,int *minute);
/*#####################################################*/
/*Fonksiyon girilen saati diamond seklinin icine basar */
/*input: int d_hour,d_minute,d_size                    */
/*output:Sonucu konsola basar                          */
/*#####################################################*/
void print_time (int d_hour,int d_minute,int d_size);
/*#####################################################*/
/*Fonksiyon girilen degeri saate ekler veya cikarir    */
/*input: int d_hour,d_minute,d_size                    */
/*output:Sonucu konsola basar                          */
/*#####################################################*/
void increment_time (int inc);
/*###################################################################*/
/*Fonksiyon in.txt den alinan harflere  belirli islemler yapar       */
/*input: char str_filename[] , void(*pf_convertion)( char content[]) */
/*output:Sonucu konsola basar                                        */
/*###################################################################*/
void text_file_manipulator( char str_filename[],void(*pf_convertion)( char content[]));
/*#####################################################*/
/*Fonksiyon alinan harfleri buyuk harfe cevirir.       */
/*input: char content[]                                */
/*output:Sonucu konsola basar                          */
/*#####################################################*/
void uppercase(char content[]);
/*#####################################################*/
/*Fonksiyon alinan harfleri kucuk harfe cevirir.       */
/*input: char content[]                                */
/*output:Sonucu konsola basar                          */
/*#####################################################*/
void lowercase(char content[]);
/*########################################################*/
/*Fonksiyon  kelimelerin ilk harfini buyuk harfe cevirir  */
/*input: char content[]                                   */
/*output:Sonucu konsola basar                             */
/*########################################################*/ 
void capitalize(char content[]);
/*#####################################################################*/
/*Fonksiyon  buyuk harfi kucuk harfe, kucuk harfi buyuk harfe cevirir  */
/*input: char content[]                                                */
/*output:Sonucu konsola basar                                          */
/*#####################################################################*/ 
void toggle(char content[]);
/*#######################################################################################*/
/*Fonksiyon alinan iki dereceli fonksiyon ve girilen noktanin max,min yaklasimini bulur  */
/*input: double a, b, c, search_starting_point, step_size                                */
/*output:Sonucu konsola basar                                                            */
/*########################################################################################*/
void max_finder (double a,double b,double c,double search_starting_point,double step_size );
  

int main()  {
    
    int hour,minute,st,d_hour, d_minute, d_size,inc;
    double a,b,c,search_starting_point,step_size;
    
    /*//////////////////////////////////////*/
    puts("-------------------------------");
    printf("read_time:\n");
    read_time( &hour, &minute);
    puts("-------------------------------");
    /*//////////////////////////////////////*/


    /*//////////////////////////////////////*/
    puts("-------------------------------");
    printf("print_time:\n");
    scanf ("%d%d%d",&d_hour,&d_minute,&d_size);
    print_time ( d_hour, d_minute, d_size);
    puts("-------------------------------");
    /*//////////////////////////////////////*/


    /*//////////////////////////////////////*/
    puts("-------------------------------");
    printf("increment_time:\n");
    scanf ("%d ", & inc );
    increment_time (inc);
    puts("-------------------------------");
    /*//////////////////////////////////////*/


    /*//////////////////////////////////////*/
    puts("-------------------------------");
    printf("text_file_manipulator:\n");
    text_file_manipulator("in.txt", uppercase);
    text_file_manipulator("in.txt", lowercase);
    text_file_manipulator("in.txt", capitalize);
    text_file_manipulator("in.txt", toggle);
    puts("-------------------------------");
    /*//////////////////////////////////////*/


    /*//////////////////////////////////////*/
    puts("-------------------------------");
    printf("max_finder:\n");
    scanf ("%lf %lf %lf %lf %lf", &a, &b, &c, &search_starting_point, &step_size);
    max_finder (a , b, c, search_starting_point, step_size );
    puts("-------------------------------");
    /*//////////////////////////////////////*/

return 0;
}

int read_time(int *hour,int *minute)
{
    char ch;
    
    scanf("%d",hour);
    
    do{
        
        scanf("%c",&ch);

    }while(ch == ' ');
    
    scanf("%d",minute);
    
   

    if( !( *hour >= 0 && *hour <= 23 ) ){
        printf("Input is not valid.\n");
        return -1;
    }
    else if ( !( *minute >= 0 && *minute <= 59 ) ){
        printf("Input is not valid.\n");
        return -1;
    }
    else if ( ch != ':' ) {
        printf("Input is not valid.\n");
        return -1;
    }
    
    if(*hour < 10 && *minute < 10)
        printf("Hour:0%d\nMinute:0%d\n",*hour,*minute);
    else if(*hour < 10)
        printf("Hour:0%d\nMinute:%d\n",*hour,*minute);
    else if(*minute < 10)
         printf("Hour:%d\nMinute:0%d\n",*hour,*minute);
    else    
        printf("Hour:%d\nMinute:%d\n",*hour,*minute);
    
    return 0;
}

void print_time (int d_hour,int d_minute,int d_size)
{
    int i,j,space;
    
    if(d_size < 4) {
        if(d_hour < 10 && d_minute < 10)
            printf("0%d:0%d\n",d_hour,d_minute);
        else if(d_hour < 10)
            printf("0%d:%d\n",d_hour,d_minute);
        else if(d_minute < 10)
            printf("%d:0%d\n",d_hour,d_minute);
        else
            printf("%d:%d\n",d_hour,d_minute);        
    }
        
    else {
        d_size+=1;
        
        for(i=1;i<=d_size; i++) {
            if(i != d_size) {       
                
                for(j=1;j<=d_size-i;j++)
                    printf(" ");
                for(j=1;j<=2*i-1;j++) {
                    if(j == 1)           
                        printf("*");
                    if(j != 1 && j != 2*i-1)
                        printf(" ");
                    if(j != 1 && j == 2*i-1)
                        printf("*");
                }
            }
            
            else {
                
                space=d_size*2-1-2;
                space-=5;
                space/=2;
                
                printf("*");
                
                for(j=1;j<=space;j++)
                    printf(" ");
                
                if(d_hour < 10 && d_minute < 10)
                    printf("0%d:0%d",d_hour,d_minute);
                else if(d_hour < 10)
                    printf("0%d:%d",d_hour,d_minute);
                else if(d_minute < 10)
                    printf("%d:0%d",d_hour,d_minute);
                else
                    printf("%d:%d",d_hour,d_minute);
                
                for(j=1;j<=space;j++)
                    printf(" ");
                
                printf("*");

            }
            
            printf("\n");         
        }
        
        d_size-=1;
        for(i=d_size;i>=1; i--) {
            for(j=1;j<=d_size+1-i;j++)
                printf(" ");
            for(j=1;j<=2*i-1;j++) {
                if(j == 1)           
                    printf("*");
                if(j != 1 && j != 2*i-1)
                    printf(" ");
                if(j != 1 && j == 2*i-1)
                    printf("*");
            }
            printf("\n");         
        }
    }
}

void increment_time (int inc) 
{
    int hour,minute,temp,control;
    
    control = read_time(&hour,&minute);
    
    if(control != -1){
    
        if(inc > 0) {       
            minute += inc;
            temp = minute;
            minute %= 60;
            temp /= 60;
            hour+=temp;
            if(hour > 23)
                hour = hour%24;
            
        }
        else {
            minute += inc;
            while( minute < 0) {
                minute += 60;
                hour--;
                if(hour < 0)
                    hour = 24 + hour;
            }

        }
        if(hour < 10 && minute < 10)
            printf("0%d:0%d\n",hour,minute);
        else if(hour < 10)
            printf("0%d:%d\n",hour,minute);
        else if(minute < 10)
            printf("%d:0%d\n",hour,minute);
        else
            printf("%d:%d\n",hour,minute);
   } 
}
void text_file_manipulator( char str_filename[],void(*pf_convertion)(char content[]))
{
    char content[SIZE];
    char *st;

    
    FILE *inp;
    inp=fopen(str_filename,"r");
         
    for (st = fgets(content, SIZE, inp);
        st != 0;
        st = fgets(content, SIZE, inp)) 
    
    if(*pf_convertion == uppercase){
         printf("uppercase:\n");
         uppercase(content);
    }
    else if(*pf_convertion == lowercase) {
        printf("lowercase:\n");
        lowercase(content);
    }
    else if(*pf_convertion == capitalize){
        printf("capitalize:\n");
        capitalize(content);
    }
    else if(*pf_convertion == toggle){
        printf("toggle:\n");
        toggle(content);
    }
}
void uppercase(char content[])
{
    int i=0,j;
    
    while(content[i] != '\0'){
        i++;    
    }
    
           
    for(j=0; j<=i; j++){
        if( (int)content[j] >= MIN && (int)content[j] <= MAX)
            content[j] -= FARK;
        printf("%c",content[j]);
    }
     
}
void lowercase(char content[])
{
    int i=0,j;
    
    while(content[i] != '\0'){
        i++;    
    }
    
           
    for(j=0; j<=i; j++){
        if( (int)content[j] >= MIN2 && (int)content[j] <= MAX2)
            content[j] += FARK;
        printf("%c",content[j]);
    }

}
void capitalize(char content[])
{
    int i=0,j;
    
    while(content[i] != '\0'){
        i++;    
    }
    
    for(j=0; j<=i; j++){
        if( (int)content[0] >= MIN && (int)content[0] <= MAX)
            content[j] -= FARK;
        else if( content[j-1] == ' ' && ((int)content[j] >= MIN && (int)content[j] <= MAX) )
            content[j] -= FARK;
        else if( content[j-1] == ' ' && ((int)content[j] >= MIN2 && (int)content[j] <= MAX2) )
            content[j] += 0;
        else if((int)content[j] >= MIN2 && (int)content[j] <= MAX2)
            content[j] += FARK;
        
        printf("%c",content[j]);
    }
    
}
void toggle(char content[])
{
    int i=0,j;
    
    while(content[i] != '\0'){
    i++;    
    }
    
           
    for(j=0; j<=i; j++){
        if( (int)content[j] >= MIN2 && (int)content[j] <= MAX2)
            content[j] += FARK;
        else if( (int)content[j] >= MIN && (int)content[j] <= MAX)
            content[j] -= FARK;
        printf("%c",content[j]);
    }

}

void max_finder (double a,double b,double c,double search_starting_point,double step_size )
{   
    int n_step=-1;
    double x,y,turev,m_x;
    
    x = search_starting_point;
    turev = (-b)/(2*a);
    
    if(a > 0) {
        if(x < 0){
            do{
               
                y = a*x*x + b*x + c;
                x += step_size;
                n_step++;
                 
            }while(x <= turev);
                        
            m_x = x - step_size;
                        
            printf("Minimum point results ( m_x, m_y, n_step )\n");
            printf("%f %f %d\n",m_x,y,n_step);
        }
        else{
            do{
               
                y = a*x*x + b*x + c;
                x -= step_size;
                n_step++;
                 
            }while(x >= turev);
            
            
            m_x = x + step_size;

            printf("Minimum point results ( m_x, m_y, n_step )\n");
            printf("%f %f %d\n",m_x,y,n_step);
            

        }
    }
    else{
        if(x < 0){
            do{
               
                y = a*x*x + b*x + c;
                x += step_size;
                n_step++; 
            }while(x <= turev);
                        
            m_x = x - step_size;
            
            printf("Maximum point results ( m_x, m_y, n_step )\n");
            printf("%f %f %d\n",m_x,y,n_step);
        }
        else{
            do{
               
                y = a*x*x + b*x + c;
                x -= step_size;
                n_step++;                
            }while(x >= turev);
                        
            m_x = x + step_size;
            
            printf("Maximum point results ( m_x, m_y, n_step )\n");
            printf("%f %f %d\n",m_x,y,n_step);
            

        }

    }
    
}
/*############################################################################*/
/*              End of HW05_121044074_Onur_Sezer                              */
/*############################################################################*/
