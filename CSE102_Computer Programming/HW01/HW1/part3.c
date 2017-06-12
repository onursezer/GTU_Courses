/*############################################################################*/
/*HW01_121044074_part3.c                                                      */
/*______________________                                                      */
/*Written by Onur Sezer on September 20, 2014                                 */
/*                                                                            */
/*Description:                                                                */
/*____________                                                                */
/*Program agirlik analizi yapar                                               */
/*Inputs:                                                                     */
/*Kullanicinin girdigi weight ve height                                       */
/*                                                                            */
/*Outputs:                                                                    */
/*Agirlik analizi sonucunu konsola basar                                      */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>


/*----------------------------------------------------------------------------*/
/*                           Function Prototypes                              */
/*----------------------------------------------------------------------------*/
/*###############################################################*/
/*Fonksiyon belirli formulle kullanıcının agırlıgını analiz eder */
/*input: double weight,height                                    */
/*output:Cıkan sonucu return yapar                               */
/*###############################################################*/ 
double calculate_healthy(double weight,double height);
 
int main() {
    
    /*START_OF_MAIN*/
    double weight,height;
    double healthy;
    
    /*END_OF_VARIABLES*/
    
    printf("Welcome to Weight Analyzer.\n");
    printf("Please enter your weight and height:\n ");
    
    scanf("%lf%lf",&weight,&height);
    
    healthy=calculate_healthy(weight,height);
    
    if(healthy<18.5)
        printf("You are underweight.\n");
    else if(healthy<25)
        printf("You are healthy.\n");
    else if(healthy>25)
        printf("You are overweight.\n");    
           
    return 0;
    /*END_OF_MAIN*/
}
double calculate_healthy(double weight,double height) {

    return weight/(height*height);
}
/*############################################################################*/
/*              End of HW01_Onur_Sezer_121044074_part3.c                      */
/*############################################################################*/
