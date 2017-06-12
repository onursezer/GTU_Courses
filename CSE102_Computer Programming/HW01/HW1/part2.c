/*############################################################################*/
/*HW01_121044074_part2.c                                                      */
/*______________________                                                      */
/*Written by Onur Sezer on September 20, 2014                                 */
/*                                                                            */
/*Description:                                                                */
/*____________                                                                */
/*Belirli olan degeri kullanicinin tahmin etmesi beklenir                     */
/*Inputs:                                                                     */
/*Kullanicidan alinir.                                                        */
/*                                                                            */
/*Outputs:                                                                    */
/*Konsola dogru yada yanlis girdigini basar                                   */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

int main() {

    /*START_OF_MAIN*/
    int num,g=40;
    
    /*END_OF_VARIABLES*/
    
    printf("\nWelcome to Guessing Game.\n");
    printf("You have three turns to be successful.\n");
    printf("Pick a number between 1 and 100.\n");
    
    scanf("%d",&num);
    
    if(num == g){
        printf("Congratulations!\n");
        return 0;
    }
    else 
        if(num<g)
            printf("To low...\n");
         else if(num>g)
            printf("To high...\n");
    
    scanf("%d",&num);
    
    if(num == g){
        printf("Congratulations!\n");
        return 0;
    }
    else 
        if(num<g)
            printf("To low...\n");
         else if(num>g)
            printf("To high...\n");
     
    scanf("%d",&num);
     
    if(num == g){
       printf("Congratulations!\n");
       return 0;
      }
      
    if(num != g)
        printf("You lose!\n");
      
      
    return 0;
    /*END_OF_MAIN*/
}
/*############################################################################*/
/*              End of HW01_Onur_Sezer_121044074_part2.c                      */
/*############################################################################*/
