/*############################################################################*/
/*HW08_121044074_Onur_Sezer                                                   */
/*______________________                                                      */
/*Written by Onur Sezer on November 27, 2014                                  */
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
/*----------------------------------------------------------------------------*/
/*                  Function Prototypes                                       */
/*----------------------------------------------------------------------------*/
void test_part1();
void test_part2();
void test_part3();
void test_part4();
void test_part5();
void test_part6();
void sort_pointer(char *ptr[],int size);

int main() {
    
   
   /* puts("-------------------------------");
    printf("testing the function test_part1 \n");
    test_part1();
    puts("-------------------------------");

    puts("-------------------------------");
    printf("testing the function test_part2 \n");
    test_part2();
    puts("-------------------------------");
 
    puts("-------------------------------");
    printf("testing the function test_part3 \n");
    test_part3();
    puts("-------------------------------");
 */   
    puts("-------------------------------");
    printf("testing the function test_part4 \n");
    test_part4();
    puts("-------------------------------");

 /*   puts("-------------------------------");
    printf("testing the function test_part5 \n");
    test_part5();
    puts("-------------------------------");

    puts("-------------------------------");
    printf("testing the function test_part6 \n");
    test_part6();
    puts("-------------------------------");
  */  
}
void test_part1()
{
    char str[SIZE];
    char str2[]=" ",str3[SIZE];
    char *token,temp;
    int i,j;

    gets(str);

    token = strtok(str,str2);

    strcpy(str3,token);
    
    i = strlen(str3);
 
    printf("Output:\n");

    if(i % 2 == 0){ 
        for(j=0;j<i/2;j++){
            temp = str3[j];
            str3[j] = str3[i-1-j];
            str3[i-1-j] = temp;          
        }
    }
    else{
        for(j=0;j<=i/2;j++){
            temp = str3[j];
            str3[j] = str3[i-1-j];
            str3[i-1-j] = temp;          
        }
  
    }
    printf("%s ",str3);
        

    while(token != NULL){


        token = strtok(NULL,str2);

        if(token != NULL){
            strcpy(str3,token);
            
            i = strlen(str3);
         
            if(i % 2 == 0){ 
                for(j=0; j < i/2; j++){
                    temp = str3[j];
                    str3[j] = str3[i-1-j];
                    str3[i-1-j] = temp;          
                }
            }
            else{
                for(j=0; j <= i/2; j++){
                    temp = str3[j];
                    str3[j] = str3[i-1-j];
                    str3[i-1-j] = temp;          
                }
          
            }
            
            printf("%s ",str3);
        }
 
    }
    printf("\n");
}
void test_part2()
{
    char temp[SIZE],str1[SIZE],str2[SIZE],str3[SIZE][SIZE],str4[SIZE][SIZE];
    char *token,space[]=" ";
    int n,i=0,j,k=0,z,sayi,num;
      
    scanf("%d ",&num);
    gets(str1);
    gets(str2);

    token = strtok(str1,space);

    strcpy(str3[i],token);
    
    while(token != NULL){

        token = strtok(NULL,space);

        if(token != NULL){
            i++;
            strcpy(str3[i],token);
        }
    }
    


    token = strtok(str2,space);

    strcpy(str4[k],token);
    
    while(token != NULL){

        token = strtok(NULL,space);

        if(token != NULL){
            k++;
            strcpy(str4[k],token);
        }
    }
    
    if(i<k)
        z = i;
    else
        z = k;

    for(j=0; j <= z; j++){
        if(j%num == 0){
            strcpy(temp,str3[j]);
            strcpy(str3[j],str4[j]);
            strcpy(str4[j],temp);
        }
    
    }
    printf("Output:\n");  
    for(j=0; j <= i; j++)
        printf("%s ",str3[j]);
    printf("\n"); 

    for(j=0;j <= k; j++)
        printf("%s ",str4[j]); 
    printf("\n");
    
    
}
void test_part3()
{
    char str[SIZE];
    
    int i=0,j=0,z=0,k=0,e=0,l;
    char temp;

    gets(str);

    do{
        k++;
        i++;

        if(str[i-1] == ' ' || str[i-1] == '\0'){

            if((i-1-z) % 2 == 0){
                for(j=z;j<(i-1) - k/2;j++){
                   
                    temp  = str[j];
                    str[j] = str[i-2-e];
                    str[i-2-e] = temp;
                    e++;
                }
            }
            else{
                for(j=z;j<=(i-1) - k/2;j++){
                   
                    temp  = str[j];
                    str[j] = str[i-2-e];
                    str[i-2-e] = temp;
                    e++;
                }
                    
            }
            z = i;
            k=0;
            e=0;
         }

         l=i-1;
    }while(str[l] != '\0');
    
    printf("Output:\n");
    printf("%s\n",str);    
}
void test_part4()
{
    char str1[SIZE],str2[SIZE],str3[SIZE][SIZE],str4[SIZE][SIZE],temp[SIZE][SIZE];
    int i=0,j=0,z=0,k=0,e=0,l,num,size,size1,size2;
       
    scanf("%d ",&num);
    gets(str1);
    gets(str2);


    do{
        i++;

        if(str1[i-1] == ' ' || str1[i-1] == '\0'){

                for(j=z; j <= (i-1); j++){
                   
                    str3[k][e]  = str1[j];
                    e++;  
                }
                str3[k][e] = '\0';
        
            z = i;
            k++;
            e=0;
         }

         l=i-1;
    }while(str1[l] != '\0');
    size1=k;

    i=0;j=0;z=0;k=0;e=0;
    
    do{
        i++;

        if(str2[i-1] == ' ' || str2[i-1] == '\0'){

                for(j=z; j <= (i-1); j++){
                   
                    str4[k][e]  = str2[j];
                    e++;  
                }
                str4[k][e] = '\0';
        
            z = i;
            k++;
            e=0;
         }

         l=i-1;
    }while(str2[l] != '\0');

    size2=k;

    j=0;

    if(size1 < size2)
        size = size1;
    else
        size = size2;

    for(i=0; i < size; i++){
        if(i % num == 0){
            
            j=0;
            while(str3[i][j] != '\0'){
                temp[i][j] = str3[i][j];
                j++;
            }
            temp[i][j] = '\0';
                        
            j=0;
            while(str4[i][j] != '\0'){
                str3[i][j] = str4[i][j];
                j++;
            }
            str3[i][j] = '\0';
          
            j=0;
            while(temp[i][j] != '\0'){
                str4[i][j] = temp[i][j];
                j++;
            }
            str4[i][j] = '\0';
        }
    
    }


    printf("Output:\n");
    for(i=0;i<size1;i++)
        printf("%s ",str3[i]);

    printf("\n");


    for(i=0;i<size2;i++)
        printf("%s ",str4[i]);
        
    printf("\n");
}
void test_part5()
{
    char str[SIZE][SIZE],temp[SIZE],skip;
    int i,j,num;

    
    scanf("%d",&num);
    
    if(num <= 10){

        scanf("%c",&skip);
        for(i=0; i < num; i++)
            gets(str[i]);

        printf("Output:\n");
       
        
        for(i=1; i <= num-1; i++){
            j = i;
            while(j > 0 && strcmp(str[j],str[j-1]) < 0){
                
                strcpy(temp,str[j-1]);
                strcpy(str[j-1],str[j]);
                strcpy(str[j],temp);
                 
                j--;              
            }
        }


        for(i=0; i < num; i++)
            puts(str[i]);

    }
    else
        printf("Maximum string count should be 10.\n");

}
void test_part6()
{
    char str[SIZE][SIZE],*sorted[SIZE],skip;
    int i,j,num;

    
    scanf("%d",&num);
    
    if(num <= 10){

        scanf("%c",&skip);
        for(i=0; i < num; i++)
            gets(str[i]);

        for(i=0; i < num; i++)
            sorted[i] = str[i];    
        
        sort_pointer(sorted,num);

        printf("Output:\n");
       
        for(i=0; i < num; i++)
            puts(sorted[i]);

    }
    else
        printf("Maximum string count should be 10.\n");   
}
void sort_pointer(char *ptr[],int size)
{
    char *temp;
    int i,j;
       
        
        for(i=1; i <= size-1; i++){
            j = i;
            while(j > 0 && strcmp(ptr[j],ptr[j-1]) < 0){
                
                temp = ptr[j-1];
                ptr[j-1] = ptr[j];
                ptr[j] = temp;
                 
                j--;              
            }
        }

}
/*############################################################################*/
/*              End of HW08_121044074_Onur_Sezer                              */
/*############################################################################*/
