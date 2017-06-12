/*############################################################################*/
/*HW01_121044074_part1.c                                                      */
/*______________________                                                      */
/*Written by Onur Sezer on September 20, 2014                                 */
/*                                                                            */
/*Description:                                                                */
/*____________                                                                */
/*Kullanicidan alinan degere gore belirli toplam islemi yapar                 */
/*Inputs:                                                                     */
/*Kullanicidan k degerini alinir                                              */
/*                                                                            */
/*Outputs:                                                                    */
/*Konsola islemin sonucu basar                                                */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

/*----------------------------------------------------------------------------*/
/*                           Function Prototypes                              */
/*----------------------------------------------------------------------------*/
/*###################################################*/
/*Fonksiyon belirli toplam islemini yapar            */
/*input: int k                                       */
/*output: Toplam islemini return edilir              */
/*###################################################*/
double term(int k);
/*###################################################*/
/*input: int k                                       */
/*Fonksiyon ust alma islemi yapar                    */
/*output: sonuc return edilir                        */
/*###################################################*/
int calculate_top(int k);

int main() {
    
    /*START_OF_MAIN*/
    int k;
    double sum;
    
    /*END_OF_VARIABLES*/
    
    printf("Enter k value:\n");
    scanf("%d",&k);
    
    if(k == 1)
        sum=term(k);
    
    else if(k == 2)
        sum=term(1)+term(2);
    
    else if(k == 3)
        sum=term(1)+term(2)+term(3);
    
    printf("Result is: %.2f\n",sum);      
            
    return 0;
    /*END_OF_MAIN*/
}
double term(int k) {
    
   return 1.0/((calculate_top(k))*(k+1));

}
int calculate_top(int k) {
    
    return k*k*k*k;
}
/*############################################################################*/
/*              End of HW01_Onur_Sezer_121044074_part1                        */
/*############################################################################*/
