/*############################################################################*/
/*HW06_121044074_Onur_Sezer                                                   */
/*______________________                                                      */
/*Written by Onur Sezer on October 2, 2014                                    */
/*                                                                            */             
/*Inputs:                                                                     */
/*Konsoldan alinan degerler                                                   */
/*                                                                            */
/*Outputs:                                                                    */
/*Konsola basar                                                               */
/*############################################################################*/
/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
/*----------------------------------------------------------------------------*/
/*                             #defines                                       */
/*----------------------------------------------------------------------------*/
#define SIZE 1000
/*#########################################################*/
/*Fonksiyon kullanicini girdigi degerleri arraye doldurur  */
/*input: double arr[], int* size                           */
/*output:                                                  */
/*#########################################################*/
void fill_vector(double arr[], int* size);
/*#########################################################*/
/*Fonksiyon arrayin icindeki degerleri ekrana basar        */
/*input: double arr[], int size                            */
/*output:                                                  */
/*#########################################################*/
void print_vector(double arr[], int size);
/*##################################################################*/
/*Fonksiyon iki arrayin elemanlarini toplar.                        */
/*input: double arr1[], double arr2[], int size_arr1, int size_arr2 */
/*output:                                                           */
/*##################################################################*/
void add_vector(double arr1[], double arr2[], int size_arr1, int size_arr2);
/*##################################################################*/
/*Fonksiyon arrayin icindeki degerleri ekrana basar                 */
/*input: double arr1[], double arr2[], int size_arr1, int size_arr2 */
/*output:                                                           */
/*##################################################################*/
void sub_vector(double arr1[], double arr2[], int size_arr1, int size_arr2);
/*#########################################################*/
/*Fonksiyon arrayin elmanlarinin buyuklugunu bulur.        */
/*input: double arr1[],int size_arr1                       */
/*output:                                                  */
/*#########################################################*/
void mag (double arr1[],int size_arr1);
/*#####################################################################*/
/*input: double arr1_x[],arr1_y[],arr1_z[],arr2_x[],arr2_y[],arr2_z[]  */
/*           int size_arr1,size_arr2)                                  */
/*output:                                                              */
/*#####################################################################*/
void dist(double arr1_x[],double arr1_y[],double arr1_z[],double arr2_x[],double arr2_y[],double arr2_z[], int size_arr1,int size_arr2);
/*#########################################################*/
/*input: double arr1_x[],arr1_y[],arr1_z[]                 */
/*            int size_arr1                                */
/*output:                                                  */
/*#########################################################*/
void most_distant(double arr1_x[],double arr1_y[],double arr1_z[], int size_arr1);

int main() {
    double arr[SIZE],arr1[SIZE],arr2[SIZE],
        arr1_x[SIZE],arr1_y[SIZE],arr1_z[SIZE],arr2_x[SIZE],arr2_y[SIZE],arr2_z[SIZE];
    int size,size_arr1,size_arr2;

	
	puts("-------------------------------");
    printf("testing the function print_vector \n");
	fill_vector(arr,&size);
	print_vector(arr,size);
	puts("-------------------------------");
    

    puts("-------------------------------");
    printf("testing the function add_vector \n");
	fill_vector(arr1,&size_arr1);
	fill_vector(arr2,&size_arr2);
	add_vector(arr1,arr2,size_arr1,size_arr2);
	puts("-------------------------------");


    puts("-------------------------------");
    printf("testing the function sub_vector \n");
	fill_vector(arr1,&size_arr1);
	fill_vector(arr2,&size_arr2);
	sub_vector(arr1,arr2,size_arr1,size_arr2);
	puts("-------------------------------");


    puts("-------------------------------");
    printf("testing the function mag \n");	
	fill_vector(arr1,&size_arr1);
	mag (arr1,size_arr1);
	puts("-------------------------------");


    puts("-------------------------------");
    printf("testing the function dist \n");
	printf("arr1_x:\n");
	fill_vector(arr1_x,&size_arr1);
	printf("arr1_y:\n");	
	fill_vector(arr1_y,&size_arr1);
	printf("arr1_z:\n");
	fill_vector(arr1_z,&size_arr1);
    printf("\n");
	printf("arr2_x:\n");
	fill_vector(arr2_x,&size_arr2);
	printf("arr2_y:\n");
	fill_vector(arr2_y,&size_arr2);
	printf("arr2_z:\n");
	fill_vector(arr2_z,&size_arr2);
	dist(arr1_x,arr1_y,arr1_z,arr2_x,arr2_y,arr2_z,size_arr1,size_arr2);
    puts("-------------------------------");
	
    
	puts("-------------------------------");
    printf("testing the function most_distant \n");
	fill_vector(arr1_x,&size_arr1);	
	fill_vector(arr1_y,&size_arr1);
	fill_vector(arr1_z,&size_arr1);
	most_distant(arr1_x,arr1_y,arr1_z,size_arr1);
	puts("-------------------------------"); 

return 0;
}
void fill_vector(double arr[], int* size)
{
    int i;
    
    scanf("%d",size);
    
    for(i=0;i < *size; i++){
        scanf("%lf",&arr[i]);
    }
}
void print_vector(double arr[], int size)
{
    int i;
    
    printf("[");
    for(i=0;i<size;i++){
        printf("%.1f",arr[i]);
        if(i < size-1)            
            printf(",");    
    }
    printf("]\n");
}
void add_vector(double arr1[], double arr2[], int size_arr1, int size_arr2)
{
    int i;   
    
    if(size_arr1 == size_arr2){ 
        for(i=0;i<size_arr1;i++){
            arr1[i] += arr2[i];
        }
        printf("Add:");
        print_vector(arr1,size_arr1);
    }
    else {
        printf("\n*********ERROR*********\n");
    }  
}
void sub_vector(double arr1[], double arr2[], int size_arr1, int size_arr2)
{
    int i;    
    if(size_arr1 == size_arr2){ 
        for(i=0;i<size_arr1;i++){
            arr1[i] -= arr2[i];
        }
        printf("Sub:");
        print_vector(arr1,size_arr1);
    }
    else {
        printf("\n*********ERROR*********\n");
    }
}
void mag (double arr1[],int size_arr1)
{
    int i;
    double sum=0;

    for(i=0; i<size_arr1; i++){
        sum = sum + arr1[i] * arr1[i];
    }
    
    printf("Mag:%.2f\n",sqrt(sum));
}
void dist(double arr1_x[],double arr1_y[],double arr1_z[],double arr2_x[],double arr2_y[],double arr2_z[], int size_arr1,int size_arr2)
{
    int i;
    double num;

    if(size_arr1 == size_arr2){ 
        printf("Dist: [");
        for(i=0;i<size_arr1;i++){
            num = sqrt( pow(arr2_x[i]-arr1_x[i],2)+pow(arr2_y[i]-arr1_y[i],2)+pow(arr2_z[i]-arr1_z[i],2) );
            printf("%.2f",num);
            if(i != size_arr1-1)
                printf(",");
        }
        printf("]\n");
    }
     else {
        printf("\n*********ERROR*********\n");
    }
}
void most_distant(double arr1_x[],double arr1_y[],double arr1_z[], int size_arr1)
{
    int i,j,a=0;
    double max,dist,distance[SIZE];
   
    for(i=0;i<size_arr1;i++){
        for(j=i+1;j<size_arr1;j++){
            dist = sqrt( pow( (arr1_x[i]-arr1_x[j]),2 ) + pow( (arr1_y[i]-arr1_y[j]),2 ) + pow( (arr1_z[i]-arr1_z[j]),2 ) );
            distance[a] = dist;
            a++;      
        }    
    }
    
    max = distance[0];
    for(i=1;i<a;i++){
        if(distance[i] > max)
            max = distance[i];
    }
        
    printf("Max Dist:%.2f\n",max);    
}
/*############################################################################*/
/*              End of HW06_121044074_Onur_Sezer                              */
/*############################################################################*/
