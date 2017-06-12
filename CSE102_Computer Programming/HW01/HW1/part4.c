/*############################################################################*/
/*HW01_121044074_part4.c                                                      */
/*______________________                                                      */
/*Written by Onur Sezer on September 20, 2014                                 */
/*                                                                            */
/*Description:                                                                */
/*____________                                                                */
/*Program kullanicinin girdigi noktalarin hangi sekli ifade ettigini bulur    */
/*Inputs:                                                                     */
/*Kullanicidan dort nokta alir                                                */
/*                                                                            */
/*Outputs:                                                                    */
/*Bulunan sekli konsola yazar                                                 */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                             Includes                                       */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

/*----------------------------------------------------------------------------*/
/*                           Function Prototypes                              */
/*----------------------------------------------------------------------------*/
/*##########################################################*/
/*Fonksiyon iki nokta arasındaki egimi bulur                */
/*double :x1,y1,x2,y2                                       */
/*output:Cıkan sonucu return yapar                          */
double slope(double x1,double y1,double x2,double y2);

int main() {
    /*START_OF_MAIN*/
    
    double x1,y1,x2,y2,x3,y3,x4,y4;
    double m;
    /*END_OF_VARIABLES*/
   
    printf("Please enter 4 2D points:\n");
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    printf("Your points can construct:\n");
    
    if( slope(x1,y1,x2,y2) == (m=slope(x2,y2,x3,y3)) && m == slope(x3,y3,x4,y4) ){
        printf("A line\n");
        return 0;
        }
    if( slope(x1,y1,x2,y2) == (m=slope(x2,y2,x3,y3)) && m != slope(x3,y3,x4,y4) ){
        printf("A triangle\n");
        return 0;
        }
    if( slope(x1,y1,x2,y2) == (m=slope(x2,y2,x4,y4)) && m != slope(x4,y4,x3,y3) ){
        printf("A triangle\n");
        return 0;
        }
    if( slope(x1,y1,x3,y3) == (m=slope(x3,y3,x4,y4)) && m != slope(x4,y4,x2,y2) ){
        printf("A triangle\n");
        return 0;
        }
    if( slope(x2,y2,x3,y3) == (m=slope(x3,y3,x4,y4)) && m != slope(x4,y4,x1,y1) ){
        printf("A triangle\n");
        return 0;
        }                
    
    if( slope(x1,y1,x2,y2) != (m=slope(x2,y2,x3,y3)) && m != slope(x3,y3,x4,y4) ){
        printf("A quadrilateral\n");
        return 0;
        }         
    /*END_OF_MAIN*/
}

double slope(double x1,double y1,double x2,double y2) {    

    return (y2-y1)/(x2-x1);
}
/*############################################################################*/
/*              End of HW01_Onur_Sezer_121044074_part4.c                      */
/*############################################################################*/ 
 
