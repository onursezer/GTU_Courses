/*############################################################################*/
/*HW01_121044074_part5.c                                                      */
/*______________________                                                      */
/*Written by Onur Sezer on September 20, 2014                                 */
/*                                                                            */
/*Description:                                                                */
/*____________                                                                */
/*Program belirli sorular sorarak ogrencinin levelini bulur                   */
/*Inputs:                                                                     */
/*Cevaplara girilen integer degerler                                          */
/*                                                                            */
/*Outputs:                                                                    */
/*Konsola ogrencinin levelini basar                                           */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

int main() {

    /*START_OF_MAIN*/
    int num1,num2,num3,total_score;
    
    /*END_OF_VARIABLES*/
    
    printf("How many times have you stayed awake till morning at GIT?\n");
    printf("(possible answers: 1 , 2 ,3)\n");
    scanf("%d",&num1);
    
    printf("How many different species of animals have you seen at GIT?\n");   
    printf("(possible answers: 1 , 2 ,3)\n");
    scanf("%d",&num2);
    
    printf("How long have you been at GIT?\n");
    printf("(possible answers: 1 , 2 ,3)\n");
    scanf("%d",&num3);
    
    total_score=num1+num2+num3;
    
    printf("Your GIT student level is:\n");
    
    if(total_score < 4)
        printf("Noob\n");
    else if(total_score < 7)
        printf("Whizz-kid\n");
    else
        printf("Pro\n");        

    return 0;
    /*END_OF_MAIN*/
}
/*############################################################################*/
/*              End of HW01_Onur_Sezer_121044074_part5.c                      */
/*############################################################################*/

