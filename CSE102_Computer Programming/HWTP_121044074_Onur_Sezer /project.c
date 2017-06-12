#include "project.h"


void findNumberOfData(char team_file[],char player_file[],char t_team_file[],char p_player_file[],int *numberOfTeam,
                      int *numberOfPlayer,int *numberOfTstatistics,int *numberOfPstatistics)
{

    FILE *inp1,*inp2,*inp3,*inp4;
    teams_t teams;
    players_t players;
    team_statistics_t team_statistics;
    player_statistics_t player_statistics;
    int i=0,st;

    inp1 = fopen(team_file,"rb");
    inp2 = fopen(player_file,"rb");
    inp3 = fopen(t_team_file,"rb");
    inp4 = fopen(p_player_file,"rb");
    
    for(st = fread(&teams,sizeof(teams_t),1,inp1); st !=0;
        st = fread(&teams,sizeof(teams_t),1,inp1) )
        i++;
    *numberOfTeam = i;
    i=0; 
    for(st = fread(&players,sizeof(players_t),1,inp2); st !=0;
        st = fread(&players,sizeof(players_t),1,inp2) )
        i++;
    *numberOfPlayer = i;
    i=0;
    for(st = fread(&team_statistics,sizeof(team_statistics_t),1,inp3); st != 0;
        st = fread(&team_statistics,sizeof(team_statistics_t),1,inp3) )
        i++;
    *numberOfTstatistics = i;
    i = 0;
    for(st = fread(&player_statistics,sizeof(player_statistics_t),1,inp4); st != 0;
        st = fread(&player_statistics,sizeof(player_statistics_t),1,inp4) )
        i++;
    *numberOfPstatistics = i;
    #if defined (DEBUG)
        printf("*numberOfTeam : %d\n",*numberOfTeam);
        printf("*numberOfPlayer : %d\n",*numberOfPlayer);    
        printf("*numberOfTstatistics : %d\n",*numberOfTstatistics);    
        printf("*numberOfPstatistics : %d\n",*numberOfPstatistics);
    #endif
     
    fclose(inp1);    
    fclose(inp2);
    fclose(inp3);
    fclose(inp4);    
}
void insert_teams(FILE *bin,teams_t teams[],char *str)
{
    char *cmd;
    int num,st,j=0,i=0,ans;

    do{
        st = fread(&teams[j],sizeof(teams_t),1,bin);
        if(st != 0)
            j++;
        if(st == 0){
            cmd = strtok(str,",");
            strcpy(teams[j].team_name , cmd);                      
            for(i = 0; i < j; i++){
                if( strcmp(teams[j].team_name,teams[i].team_name) == 0 )
                    ans = 1;
            }            
        }
    }while(st != 0);
    
    
    if( ans != 1){

        cmd = strtok(NULL,",");
        strcpy(teams[j].city,cmd);
        cmd = strtok(NULL,",");
        strcpy(teams[j].stadium,cmd);
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        teams[j].founding_date = num;
        cmd = strtok(NULL,",");
        strcpy(teams[j].colors,cmd);
        
        fseek(bin,sizeof(teams_t)*j,SEEK_SET);   
        fwrite(&teams[j],sizeof(teams_t),1,bin);
   }
    else
        printf("Ayni takim girilemez!!\n");

    fclose(bin);
}
void insert_players(FILE *bin,players_t players[],char *str)
{
    
    char *cmd;
    int num,st,j=0,i=0,ans;

    do{
        st = fread(&players[j],sizeof(players_t),1,bin);
        if(st != 0)
            j++;
        if(st == 0){
            cmd = strtok(str,",");
            strcpy(players[j].player_name , cmd);                    
            for(i = 0; i < j; i++){
                if( strcmp(players[j].player_name,players[i].player_name) == 0 )
                    ans = 1;
            }            
        }

    }while(st != 0);
    
    
    if( ans != 1){

        cmd = strtok(NULL,",");
        strcpy(players[j].team_name,cmd);
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        players[j].birth_date = num;
        cmd = strtok(NULL,",");
        strcpy(players[j].origin,cmd);
        cmd = strtok(NULL,",");
        strcpy(players[j].position,cmd);  
        cmd = strtok(NULL,",");
        num = atoi(cmd);      
        players[j].salary = num;

        fseek(bin,sizeof(players_t)*j,SEEK_SET);   
        fwrite(&players[j],sizeof(players_t),1,bin);
   }
    else
        printf("Ayni oyuncu girilemez!!\n");

    fclose(bin);
}
void insert_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str)
{
    char *cmd;
    int num,st,j=0,i=0,ans;

    do{
        st = fread(&team_statistics[j],sizeof(team_statistics_t),1,bin);
        if(st != 0)
            j++;
        if(st == 0){

            cmd = strtok(str,",");
            num = atoi(cmd);
            team_statistics[j].year = num;
            cmd = strtok(NULL,",");
            strcpy(team_statistics[j].team_name, cmd);
                    
            for(i = 0; i < j; i++){
                if( team_statistics[j].year == team_statistics[i].year 
                   && strcmp(team_statistics[j].team_name, team_statistics[i].team_name) == 0)
                    ans = 1;
            }            
        }

    }while(st != 0);

    if( ans != 1){

        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].points = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].wins = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].loses = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].draws = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].goals_for = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].goals_against = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        team_statistics[j].goals_difference = num;

        fseek(bin,sizeof(team_statistics_t)*j,SEEK_SET);   
        fwrite(&team_statistics[j],sizeof(team_statistics_t),1,bin);
    }
    else
        printf("Ayni yila ayni takim girilemez!!\n");
 
    fclose(bin);

}
void insert_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str)
{
    char *cmd;
    int num,st,j=0,i=0,ans;

    do{
        st = fread(&player_statistics[j],sizeof(player_statistics_t),1,bin);
        if(st != 0)
            j++;
        if(st == 0){

            cmd = strtok(str,",");
            num = atoi(cmd);
            player_statistics[j].year = num;
            cmd = strtok(NULL,",");
            strcpy(player_statistics[j].player_name, cmd);
                    
            for(i = 0; i < j; i++){
                if( player_statistics[j].year == player_statistics[i].year 
                   && strcmp(player_statistics[j].player_name, player_statistics[i].player_name) == 0)
                    ans = 1;
            }            
        }

    }while(st != 0);

    if( ans != 1){

        cmd = strtok(NULL,",");
        num = atoi(cmd);
        player_statistics[j].goals = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        player_statistics[j].assists = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        player_statistics[j].red_cards = num;
        cmd = strtok(NULL,",");
        num = atoi(cmd);
        player_statistics[j].yellow_cards = num;


        fseek(bin,sizeof(player_statistics_t)*j,SEEK_SET);   
        fwrite(&player_statistics[j],sizeof(player_statistics_t),1,bin);
    }
    else
        printf("Ayni yila ayni oyuncu girilemez!!\n");
 
    fclose(bin);    
}
void delete_teams(FILE *bin,teams_t teams[],char *str)
{
    FILE *bin2;

    char str1[SIZE],str2[SIZE];
    char *cmd;
    int num,st,j=0,i=0,k,l,less=1;

    
    cmd = strtok(str,"=");
    strcpy(str1,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str2,cmd);
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
    #endif

    j = fread(teams,sizeof(teams_t),MAXSIZE,bin);

    if(strcmp(str1,"team_name") == 0){

         for(i = 0; i < j; i++){
             if( strcmp(teams[i].team_name,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     teams[l] = teams[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"city") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(teams[i].city,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     teams[l] = teams[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"stadium") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(teams[i].stadium,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     teams[l] = teams[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"founding_date") == 0){                        
         for(i = 0; i < j; i++){
             if( teams[i].founding_date == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     teams[l] = teams[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"colors") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(teams[i].colors,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     teams[l] = teams[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    bin2 = fopen(TEAM_FILE,"wb");
    for(i=0;i<j;i++){     
        fwrite(&teams[i],sizeof(teams_t),1,bin2);
    }
    fclose(bin2);

    #if defined (DEBUG)
        i=0;
        bin = fopen(TEAM_FILE,"rb");    
        for(st = fread(&teams[i],sizeof(teams_t),1,bin);st!=0;
             st = fread(&teams[i],sizeof(teams_t),1,bin) ){
            printf("teams[%d].team_name : %s\n",i,teams[i].team_name);
            i++;   
        }
        fclose(bin);
    #endif

}
void delete_players(FILE *bin,players_t players[],char *str)
{
    FILE *bin2;

    char str1[SIZE],str2[SIZE];
    char *cmd;
    int num,st,j=0,i=0,k,l,less=1;
    
    cmd = strtok(str,"=");
    strcpy(str1,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str2,cmd);
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
    #endif

    j = fread(players,sizeof(players_t),MAXSIZE,bin);

    if(strcmp(str1,"player_name") == 0){

         for(i = 0; i < j; i++){
             if( strcmp(players[i].player_name,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     players[l] = players[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"team_name") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(players[i].team_name,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     players[l] = players[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"birth_date") == 0){                         
         for(i = 0; i < j; i++){
             if( players[i].birth_date ==  atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     players[l] = players[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"origin") == 0){                        
         for(i = 0; i < j; i++){
             if( strcmp(players[i].origin,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     players[l] = players[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"position") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(players[i].position,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     players[l] = players[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }

    bin2 = fopen(PLAYER_FILE,"wb");
    for(i=0;i<j;i++){     
        fwrite(&players[i],sizeof(players_t),1,bin2);
    }
    fclose(bin2);
    
    #if defined (DEBUG)
        bin = fopen(PLAYER_FILE,"rb");    
        i=0;
        for(st = fread(&players[i],sizeof(players_t),1,bin);st!=0;
             st = fread(&players[i],sizeof(players_t),1,bin) ){
            printf("players[%d].player_name : %s\n",i,players[i].player_name);
            i++;   
        }
        fclose(bin);
    #endif
}
void delete_t_statistics(FILE *bin,team_statistics_t team_statistics[],char *str)
{
    FILE *bin2;

    char str1[SIZE],str2[SIZE];
    char *cmd;
    int num,st,j=0,i=0,k,l,less=1;
    
    cmd = strtok(str,"=");
    strcpy(str1,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str2,cmd);
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
    #endif

    j = fread(team_statistics,sizeof(team_statistics_t),MAXSIZE,bin);

    if(strcmp(str1,"year") == 0){

         for(i = 0; i < j; i++){
             if( team_statistics[i].year == atoi(str2) ) {
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"team_name") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(team_statistics[i].team_name,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"points") == 0){                         
         for(i = 0; i < j; i++){
             if( team_statistics[i].points == atoi(str2) ) {
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"wins") == 0){                        
         for(i = 0; i < j; i++){
             if( team_statistics[i].wins == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"loses") == 0){                         
         for(i = 0; i < j; i++){
             if( team_statistics[i].loses == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"draws") == 0){                         
         for(i = 0; i < j; i++){
             if( team_statistics[i].draws == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"goals_for") == 0){                         
         for(i = 0; i < j; i++){
             if( team_statistics[i].goals_for == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"goals_against") == 0){                         
         for(i = 0; i < j; i++){
             if( team_statistics[i].goals_against == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"goals_difference") == 0){                         
         for(i = 0; i < j; i++){
             if( team_statistics[i].goals_difference == atoi(str2) ) {
                 l = i;        
                 for(k = l+1; k < j; k++){
                     team_statistics[l] = team_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }

    bin2 = fopen(T_STATISTIC_FILE,"wb");
    for(i=0;i<j;i++){      
        fwrite(&team_statistics[i],sizeof(team_statistics_t),1,bin2);
    }
    fclose(bin2);

    #if defined (DEBUG)
        i=0;
        bin = fopen(T_STATISTIC_FILE,"rb");    
        for(st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin);st!=0;
             st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin) ){
            printf("team_statistics[%d].team_name : %s\n",i,team_statistics[i].team_name);
            i++;   
        }
        printf("i : %d\n",i);
        fclose(bin);
    #endif
}
void delete_p_statistics(FILE *bin,player_statistics_t player_statistics[],char *str)
{
    FILE *bin2;

    char str1[SIZE],str2[SIZE];
    char *cmd;
    int num,st,j=0,i=0,k,l,less=1;
    
    cmd = strtok(str,"=");
    strcpy(str1,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str2,cmd);

    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
    #endif

    j = fread(player_statistics,sizeof(player_statistics_t),MAXSIZE,bin);

    if(strcmp(str1,"year") == 0){
         for(i = 0; i < j; i++){
             if( player_statistics[i].year == atoi(str2) ) {
                 l = i;        
                 for(k = l+1; k < j; k++){
                     player_statistics[l] = player_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"player_name") == 0){                         
         for(i = 0; i < j; i++){
             if( strcmp(player_statistics[i].player_name,str2) == 0 ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     player_statistics[l] = player_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"goals") == 0){                         
         for(i = 0; i < j; i++){
             if( player_statistics[i].goals == atoi(str2) ) {
                 l = i;        
                 for(k = l+1; k < j; k++){
                     player_statistics[l] = player_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);

    }
    else if(strcmp(str1,"assists") == 0){                       
         for(i = 0; i < j; i++){
             if( player_statistics[i].assists == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     player_statistics[l] = player_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"red_cards") == 0){                         
         for(i = 0; i < j; i++){
             if( player_statistics[i].red_cards == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     player_statistics[l] = player_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }
    else if(strcmp(str1,"yellow_cards") == 0){                         
         for(i = 0; i < j; i++){
             if( player_statistics[i].yellow_cards == atoi(str2) ){
                 l = i;        
                 for(k = l+1; k < j; k++){
                     player_statistics[l] = player_statistics[k];
                     l = k;
                 }
                 j-=less;
                 i--;   
             }                
        }          
        fclose(bin);
    }

    bin2 = fopen(P_STATISTIC_FILE,"wb");
    for(i=0;i<j;i++){      
        fwrite(&player_statistics[i],sizeof(player_statistics_t),1,bin2);
    }  
    fclose(bin2);

    #if defined (DEBUG)
        i=0;
        bin = fopen(P_STATISTIC_FILE,"rb");    
        for(st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin);st!=0;
             st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin) ){
            printf("player_statistics[%d].player_name : %s\n",i,player_statistics[i].player_name);
            i++;   
        }
        fclose(bin);
    #endif
}
void update_teams(FILE *bin, teams_t teams[], char *str,char *str2)
{
    FILE *inp;
    char str3[SIZE],str4[SIZE],cont[SIZE],name[SIZE];
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0;
    
    printf("str : %s\nstr2 : %s\n",str,str2);

    cmd = strtok(str2,"=");
    cmd = strtok(NULL,"=");
    strcpy(str3,cmd);  /* takim ismi */
 
        
    for(st=fread(&teams[i],sizeof(teams_t),1,bin); st !=0;
        st=fread(&teams[i],sizeof(teams_t),1,bin) ){
        if(strcmp(teams[i].team_name,str3) == 0){
            j = i;
            #if defined (DEBUG)
                printf("teams[%d].team_name : %s\n",i,teams[i].team_name);
            #endif
        }
        i++;
    }
    fclose(bin);
    #if defined (DEBUG)
        printf("i : %d\n",i);
        printf("j : %d\n",j);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    for(i=0;i<k;i++){
        cmd = strtok(strp[i],"=");
        strcpy(cont,cmd);
        cmd = strtok(NULL,"=");
        strcpy(name,cmd);
        num = atoi(cmd);
        
        if(strcmp(cont,"team_name") == 0)
            strcpy(teams[j].team_name,name);
        if(strcmp(cont,"city") == 0)
            strcpy(teams[j].city,name);
        if(strcmp(cont,"stadium") == 0)
            strcpy(teams[j].stadium,name); 
        if(strcmp(cont,"founding_date") == 0)
            teams[j].founding_date = num; 
        if(strcmp(cont,"colors") == 0)
            strcpy(teams[j].colors,name);   
          
    }
    inp = fopen(TEAM_FILE,"rb+");

    fseek(inp,sizeof(teams_t)*j,SEEK_SET);
    fwrite(&teams[j],sizeof(teams_t),1,inp);
    fclose(inp);
    
    #if defined (DEBUG)
    printf("%s -- %s -- %s -- %d -- %s\n",teams[j].team_name,teams[j].city,teams[j].stadium,teams[j].founding_date,teams[j].colors);
    #endif
}
void update_players(FILE *bin, players_t players[], char *str,char *str2)
{

    FILE *inp;
    char str3[SIZE],str4[SIZE],cont[SIZE],name[SIZE];
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,less=1;

    cmd = strtok(str2,"=");
    cmd = strtok(NULL,"=");
    strcpy(str3,cmd);  /* player ismi */

           
    for(st=fread(&players[i],sizeof(players_t),1,bin); st !=0;
        st=fread(&players[i],sizeof(players_t),1,bin) ){
        if(strcmp(players[i].player_name,str3) == 0){
            j = i;
            #if defined (DEBUG)
                printf("players[%d].player_name : %s\n",i,players[i].player_name);
            #endif
        }
        i++;
    }
    fclose(bin);
    #if defined (DEBUG)
        printf("i : %d\n",i);
        printf("j : %d\n",j);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
    #endif
    
    for(i=0;i<k;i++){
        cmd = strtok(strp[i],"=");
        strcpy(cont,cmd);
        cmd = strtok(NULL,"="); 
        strcpy(name,cmd);
        num = atoi(cmd);
   
        if(strcmp(cont,"player_name") == 0)
            strcpy(players[j].player_name,name);
        if(strcmp(cont,"team_name") == 0)
            strcpy(players[j].team_name,name); 
        if(strcmp(cont,"birth_date") == 0)
            players[j].birth_date = num; 
        if(strcmp(cont,"position") == 0)
            strcpy(players[j].position,name); 
        if(strcmp(cont,"origin") == 0)
            strcpy(players[j].origin,name);
        if(strcmp(cont,"salary") == 0)
            players[j].salary = num;   
          
    }
    inp = fopen(PLAYER_FILE,"rb+");

    fseek(inp,sizeof(players_t)*j,SEEK_SET);
    fwrite(&players[j],sizeof(players_t),1,inp);
    fclose(inp);

    #if defined (DEBUG)
        printf("%s -- %s -- %d -- %s -- %s -- %d\n",players[j].player_name,players[j].team_name,players[j].birth_date,players[j].origin,players[j].position,players[j].salary);
    #endif
}
void update_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str,char *str2)
{
    FILE *inp;
    char str3[SIZE],str4[SIZE],cont[SIZE],name[SIZE];
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,less=1;

    cmd = strtok(str2,"=");
    cmd = strtok(NULL,"=");
    strcpy(str3,cmd);  /* takim ismi */

 
    for(st=fread(&team_statistics[i],sizeof(team_statistics_t),1,bin); st !=0;
        st=fread(&team_statistics[i],sizeof(team_statistics_t),1,bin) ){
        if( strcmp(team_statistics[i].team_name,str3) == 0 ){
            j = i;
            #if defined (DEBUG)
                printf("team_statistics[%d].team_name : %s\n",i,team_statistics[i].team_name);
            #endif
        }
        i++;
    }
    fclose(bin);
    #if defined (DEBUG)
        printf("i : %d\n",i);
        printf("j : %d\n",j);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    for(i=0;i<k;i++){
        cmd = strtok(strp[i],"=");
        strcpy(cont,cmd);
        cmd = strtok(NULL,"=");
        strcpy(name,cmd);
        num = atoi(cmd);

        if(strcmp(cont,"year") == 0)
            team_statistics[j].year = num;        
        if(strcmp(cont,"team_name") == 0)
            strcpy(team_statistics[j].team_name,name);
        if(strcmp(cont,"points") == 0)
            team_statistics[j].points = num;
        if(strcmp(cont,"wins") == 0)
            team_statistics[j].wins = num; 
        if(strcmp(cont,"loses") == 0)
            team_statistics[j].loses = num; 
        if(strcmp(cont,"draws") == 0)
            team_statistics[j].draws = num; 
        if(strcmp(cont,"goals_for") == 0)
            team_statistics[j].goals_for = num;
        if(strcmp(cont,"goals_against") == 0)
            team_statistics[j].goals_against = num; 
        if(strcmp(cont,"goals_difference") == 0)
            team_statistics[j].goals_difference = num;  
          
    }
    inp = fopen(T_STATISTIC_FILE,"rb+");

    fseek(inp,sizeof(team_statistics_t)*j,SEEK_SET);
    fwrite(&team_statistics[j],sizeof(team_statistics_t),1,inp);
    fclose(inp);
    
    #if defined (DEBUG)
        printf("%d -- %s -- %d -- %d -- %d -- %d -- %d -- %d -- %d\n",team_statistics[j].year,team_statistics[j].team_name,team_statistics[j].points,team_statistics[j].wins,team_statistics[j].loses,team_statistics[j].draws,team_statistics[j].goals_for,team_statistics[j].goals_against, team_statistics[j].goals_difference);
    #endif    
}
void update_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str,char *str2)
{
    FILE *inp;
    char str3[SIZE],str4[SIZE],cont[SIZE],name[SIZE];
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,less=1;

    cmd = strtok(str2,"=");
    cmd = strtok(NULL,"=");
    strcpy(str3,cmd);  /* player ismi */
            
    for(st=fread(&player_statistics[i],sizeof(player_statistics_t),1,bin); st !=0;
        st=fread(&player_statistics[i],sizeof(player_statistics_t),1,bin) ){
        if( strcmp(player_statistics[i].player_name,str3) == 0 ){
            j = i;
            #if defined (DEBUG)
                printf("player_statistics[%d].player_name : %s\n",i,player_statistics[i].player_name);
            #endif
        }
        i++;
    }
    fclose(bin);
    #if defined (DEBUG)
        printf("i : %d\n",i);
        printf("j : %d\n",j);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
    #endif
    
    for(i=0;i<k;i++){
        cmd = strtok(strp[i],"=");
        strcpy(cont,cmd);
        cmd = strtok(NULL,"="); 
        strcpy(name,cmd);
        num = atoi(cmd);
   
        if(strcmp(cont,"year") == 0)
            player_statistics[j].year = num;
        if(strcmp(cont,"player_name") == 0)
            strcpy(player_statistics[j].player_name,name); 
        if(strcmp(cont,"goals") == 0)
            player_statistics[j].goals = num; 
        if(strcmp(cont,"assists") == 0)
            player_statistics[j].assists = num; 
        if(strcmp(cont,"red_cards") == 0)
            player_statistics[j].red_cards = num;
        if(strcmp(cont,"yellow_cards") == 0)
            player_statistics[j].yellow_cards = num;   
          
    }
    inp = fopen(P_STATISTIC_FILE,"rb+");

    fseek(inp,sizeof(player_statistics_t)*j,SEEK_SET);
    fwrite(&player_statistics[j],sizeof(player_statistics_t),1,inp);
    fclose(inp);

    #if defined (DEBUG)
        printf("%d -- %s -- %d -- %d -- %d -- %d \n",player_statistics[j].year,player_statistics[j].player_name,player_statistics[j].goals,player_statistics[j].assists,player_statistics[j].red_cards,player_statistics[j].yellow_cards);
    #endif
}
void select_teams(FILE *bin, teams_t teams[], char *str)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m;

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
    #endif
    
    i=0;
    for(st = fread(&teams[i],sizeof(teams_t),1,bin); st !=0;
        st = fread(&teams[i],sizeof(teams_t),1,bin) )
        i++;
    m = i;
    printf("\n-------------- SELECT TEAMS -------------\n\n");
    printf("************************************\n");
    for(i=0;i<k;i++){
        if(strcmp(strp[i],"team_name") == 0){
            printf("TEAMS\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,teams[l].team_name);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"city") == 0){
            printf("CITYS\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,teams[l].city);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"stadium") == 0){
            printf("STATDİUMS\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,teams[l].stadium);
            printf("************************************\n");

        }
        if(strcmp(strp[i],"founding_date") == 0){
            printf("FOUNDİNG DATES\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,teams[l].founding_date);
            printf("************************************\n");

        }
        if(strcmp(strp[i],"colors") == 0){
            printf("COLORS\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,teams[l].colors);
            printf("************************************\n");
        }     
    }
    
    fclose(bin);
}
void select_players(FILE *bin, players_t players[], char *str)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m;

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif
        
    i=0;
    for(st = fread(&players[i],sizeof(players_t),1,bin); st !=0;
        st = fread(&players[i],sizeof(players_t),1,bin) )
        i++;
    m = i;
    printf("\n-------------- SELECT PLAYERS -------------\n\n");
    printf("************************************\n");
    for(i=0;i<k;i++){
        if(strcmp(strp[i],"player_name") == 0){
            printf("PLAYER NAMES\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,players[l].player_name);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"team_name") == 0){
            printf("TEAM NAMES\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,players[l].team_name);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"birth_date") == 0){
            printf("BİRTH DATES\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,players[l].birth_date);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"position") == 0){
            printf("POSİTİONS\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,players[l].position); 
            printf("************************************\n");
        }
        if(strcmp(strp[i],"origin") == 0){
            printf("ORİGİNS\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,players[l].origin);
            printf("************************************\n");
        } 
        if(strcmp(strp[i],"salary") == 0){
            printf("SALARYS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,players[l].salary);
            printf("************************************\n");
        }   
    }
    
    fclose(bin);
}
void select_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m;

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif
        
    i=0;
    for(st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin); st !=0;
        st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin) )
        i++;
    m = i;
    printf("\n-------------- SELECT TEAMS_STATİSTİCS -------------\n\n");
    printf("************************************\n");
    for(i=0;i<k;i++){
        if(strcmp(strp[i],"year") == 0){
            printf("YEARS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].year);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"team_name") == 0){
            printf("TEAM NAMES\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,team_statistics[l].team_name);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"points") == 0){
            printf("POİNTS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].points);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"wins") == 0){
            printf("WİNS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].wins);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"loses") == 0){
            printf("LOSES\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].loses); 
            printf("************************************\n");
        }
        if(strcmp(strp[i],"draws") == 0){
            printf("DRAWS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].draws);
            printf("************************************\n");
        } 
        if(strcmp(strp[i],"goals_for") == 0){
            printf("GOALS FOR\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].goals_for);
            printf("************************************\n");
        }  
        if(strcmp(strp[i],"goals_against") == 0){
            printf("GOALS AGAİNST\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].goals_against);
            printf("************************************\n");
        } 
        if(strcmp(strp[i],"goals_difference") == 0){
            printf("GOALS DİFFERENCE\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,team_statistics[l].goals_difference);
            printf("************************************\n");
        }  
    }
    
    fclose(bin);
}
void select_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m;

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif
        
    i=0;
    for(st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin); st !=0;
        st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin) )
        i++;
    m = i;
    printf("\n-------------- SELECT PLAYERS_STATİSTİCS -------------\n\n");
    printf("************************************\n");
    for(i=0;i<k;i++){
        if(strcmp(strp[i],"year") == 0){
            printf("YEARS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,player_statistics[l].year);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"player_name") == 0){
            printf("PLAYER NAMES\n");
            for(l=0;l<m;l++)
                printf("%d. %s\n",l+1,player_statistics[l].player_name);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"goals") == 0){
            printf("GOALS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,player_statistics[l].goals);
            printf("************************************\n");
        }
        if(strcmp(strp[i],"assists") == 0){
            printf("ASSİSTS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,player_statistics[l].assists); 
            printf("************************************\n");
        }
        if(strcmp(strp[i],"red_cards") == 0){
            printf("RED CARDS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,player_statistics[l].red_cards);
            printf("************************************\n");
        } 
        if(strcmp(strp[i],"yellow_cards") == 0){
            printf("YELLOW CARDS\n");
            for(l=0;l<m;l++)
                printf("%d. %d\n",l+1,player_statistics[l].yellow_cards);
            printf("************************************\n");
        }   
    }    
    fclose(bin);
}
void sort_teams(FILE *bin,teams_t teams[],char *str1,char *str2,char *str3)
{
    
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;
    teams_t temp;
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
        printf("str3 : %s\n",str3);
    #endif

    cmd = strtok(str1,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif
    
    
    i=0;
    for(st = fread(&teams[i],sizeof(teams_t),1,bin); st !=0;
        st = fread(&teams[i],sizeof(teams_t),1,bin) )
        i++;
    m = i;
    if(strcmp(str2,"founding_date") == 0){
        printf("\n----------- TEAMS SORT -------------\n\n");
        printf("************************************\n");
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"team_name") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("TEAMS ASC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date < teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS DESC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date > teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,teams[l].team_name,teams[l].founding_date);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"city") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("CITYS ASC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date < teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("CITYS DESC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date > teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,teams[l].city,teams[l].founding_date);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"stadium") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("STADIUMS ASC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date < teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("STADIUMS DESC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date > teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,teams[l].stadium,teams[l].founding_date);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"colors") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("COLORS ASC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date < teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("COLORS DESC SORT\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(teams[g].founding_date > teams[g-1].founding_date){
                                temp = teams[g];
                                teams[g] = teams[g-1];
                                teams[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,teams[l].colors,teams[l].founding_date);
                printf("************************************\n");
            }     
        }
    }
    else
        printf("Hatali Giris Yapildi!!.\n");
    
    fclose(bin);
}
void sort_players(FILE *bin,players_t players[],char *str1,char *str2,char *str3)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;
    players_t temp;
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
        printf("str3 : %s\n",str3);
    #endif

    cmd = strtok(str1,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif

    i=0;
    for(st = fread(&players[i],sizeof(players_t),1,bin); st !=0;
        st = fread(&players[i],sizeof(players_t),1,bin) )
        i++;
    m = i;

    if( strcmp(str2,"salary") == 0 ){  
        printf("\n----------- PLAYERS SORT -------------\n\n");
        printf("************************************\n");  
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary < players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYER_NAME DESC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary > players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].player_name,players[l].salary);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"team_name") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary < players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary > players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].team_name,players[l].salary);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"position") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("POSITIONS ASC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary < players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("POSITIONS DESC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary > players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].position,players[l].salary);
                printf("************************************\n");
     
            }
            if(strcmp(strp[i],"origin") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("ORİGİNS ASC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary < players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("ORİGİNS DESC SORT with SALARY\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].salary > players[g-1].salary){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].origin,players[l].salary);
                printf("************************************\n");

            }      
        }
    }
    else if(strcmp(str2,"birth_date") == 0){
        printf("\n----------- PLAYERS SORT -------------\n\n");
        printf("************************************\n");
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date < players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYER_NAME DESC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date > players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].player_name,players[l].birth_date);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"team_name") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date < players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date > players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].team_name,players[l].birth_date);
                printf("************************************\n");
            }
            if(strcmp(strp[i],"position") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("POSITIONS ASC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date < players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("POSITIONS DESC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date > players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].position,players[l].birth_date);
                printf("************************************\n");
     
            }
            if(strcmp(strp[i],"origin") == 0){
                if(strcmp(str3,"asc") == 0){
                    printf("ORİGİNS ASC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date < players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("ORİGİNS DESC SORT with BİRTH_DATE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(players[g].birth_date > players[g-1].birth_date){
                                temp = players[g];
                                players[g] = players[g-1];
                                players[g-1] = temp;
                            }
                }
                for(l=0;l<m;l++)      
                    printf("%d. %-15s = %d\n",l+1,players[l].origin,players[l].birth_date);
                printf("************************************\n");

            }      
        }

    }
    else
        printf("Hatali Giris Yapildi!!.\n");
    fclose(bin);
}
void sort_t_statistics(FILE *bin,team_statistics_t team_statistics[],char *str1,char *str2,char *str3)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;
    team_statistics_t temp;
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
        printf("str3 : %s\n",str3);
    #endif

    cmd = strtok(str1,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif

    i=0;
    for(st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin); st !=0;
        st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin) )
        i++;
    m = i;
    if(strcmp(str1,"team_name") == 0) {
        printf("\n----------- TEAMS_STATİSTİCS SORT -------------\n\n");
        printf("************************************\n");
        if(strcmp(str2,"year") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with YEAR\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].year < team_statistics[g-1].year){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with YEAR\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].year > team_statistics[g-1].year){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].year);
            printf("************************************\n");
        }
        if(strcmp(str2,"points") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with POİNTS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].points < team_statistics[g-1].points){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with POİNTS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].points > team_statistics[g-1].points){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].points);
            printf("************************************\n");
        }
        if(strcmp(str2,"wins") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with WİNS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].wins < team_statistics[g-1].wins){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with WİNS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].wins > team_statistics[g-1].wins){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].wins);
            printf("************************************\n");
        }
        if(strcmp(str2,"loses") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with LOSES\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].loses < team_statistics[g-1].loses){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with LOSES\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].loses > team_statistics[g-1].loses){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].loses); 
            printf("************************************\n");
        }
        if(strcmp(str2,"draws") == 0){
           if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with DRAWS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].draws < team_statistics[g-1].draws){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with DRAWS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].draws > team_statistics[g-1].draws){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].draws);
            printf("************************************\n");
        } 
        if(strcmp(str2,"goals_for") == 0){
           if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with GOALS_FOR\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].goals_for < team_statistics[g-1].goals_for){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with GOALS_FOR\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].goals_for > team_statistics[g-1].goals_for){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].goals_for);
            printf("************************************\n");
        }  
        if(strcmp(str2,"goals_against") == 0){
           if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with GOALS_AGAİNTS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].goals_against < team_statistics[g-1].goals_against){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with GOALS_AGAİNTS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].goals_against > team_statistics[g-1].goals_against){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].goals_against);
            printf("************************************\n");
        } 
        if(strcmp(str2,"goals_difference") == 0){
           if(strcmp(str3,"asc") == 0){
                    printf("TEAMS_NAME ASC SORT with GOALS_DIFFERENCE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].goals_difference < team_statistics[g-1].goals_difference){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("TEAMS_NAME DESC SORT with GOALS_DIFFRENCE\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(team_statistics[g].goals_difference > team_statistics[g-1].goals_difference){
                                temp = team_statistics[g];
                                team_statistics[g] = team_statistics[g-1];
                                team_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,team_statistics[l].team_name,team_statistics[l].goals_difference);
            printf("************************************\n");
        }  
    }
    else
        printf("Hatali Giris Yapildi!!..\n");        

}
void sort_p_statistics(FILE *bin,player_statistics_t player_statistics[],char *str1,char *str2,char *str3)
{
    char *strp[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;
    player_statistics_t temp;
    
    #if defined (DEBUG)
        printf("str1 : %s\n",str1);
        printf("str2 : %s\n",str2);
        printf("str3 : %s\n",str3);
    #endif

    cmd = strtok(str1,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("%s\n",strp[i]);
        printf("k : %d\n",k);
    #endif

    i=0;
    for(st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin); st !=0;
        st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin) )
        i++;
    m = i;


    if(strcmp(str1,"player_name") == 0) {
        printf("\n----------- PLAYERS_STATİSTİCS SORT -------------\n\n");
        printf("************************************\n");
        if(strcmp(str2,"year") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with YEAR\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].year < player_statistics[g-1].year){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYERS_NAME DESC SORT with YEAR\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].year > player_statistics[g-1].year){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,player_statistics[l].player_name,player_statistics[l].year);
            printf("************************************\n");
        }
        if(strcmp(str2,"goals") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with GOALS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].goals < player_statistics[g-1].goals){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYERS_NAME DESC SORT with GOALS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].goals > player_statistics[g-1].goals){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,player_statistics[l].player_name,player_statistics[l].goals);
            printf("************************************\n");
        }
        if(strcmp(str2,"assists") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with ASSİSTS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].assists < player_statistics[g-1].assists){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYERS_NAME DESC SORT with ASSİSTS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].assists > player_statistics[g-1].assists){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,player_statistics[l].player_name,player_statistics[l].assists); 
            printf("************************************\n");
        }
        if(strcmp(str2,"red_cards") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with RED_CARDS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].red_cards < player_statistics[g-1].red_cards){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYERS_NAME DESC SORT with RED_CARDS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].red_cards > player_statistics[g-1].red_cards){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,player_statistics[l].player_name,player_statistics[l].red_cards);
            printf("************************************\n");
        } 
        if(strcmp(str2,"yellow_cards") == 0){
            if(strcmp(str3,"asc") == 0){
                    printf("PLAYERS_NAME ASC SORT with YELLOW_CARDS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].yellow_cards < player_statistics[g-1].yellow_cards){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
                else if(strcmp(str3,"desc") == 0){
                    printf("PLAYERS_NAME DESC SORT with YELLOW_CARDS\n");
                    for(l=0;l<m-1;l++)
                        for(g=m-1;g>l;g--)
                            if(player_statistics[g].yellow_cards > player_statistics[g-1].yellow_cards){
                                temp = player_statistics[g];
                                player_statistics[g] = player_statistics[g-1];
                                player_statistics[g-1] = temp;
                            }
                }
            for(l=0;l<m;l++)
                printf("%d. %-15s = %d\n",l+1,player_statistics[l].player_name,player_statistics[l].yellow_cards);
            printf("************************************\n");
        }   
    }
    else
        printf("Hatali Giris Yapildi!!..\n");        
}
void where_teams(FILE *bin, teams_t teams[], char *str,char *str2)
{
    char *strp[SIZE],str3[SIZE],str4[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;
    
    cmd = strtok(str2,"=");
    strcpy(str3,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str4,cmd);

    #if defined (DEBUG)
        printf("str3 : %s\n",str3);
        printf("str4 : %s\n",str4);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;
    
    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("srtp[%d] : %s\n",i,strp[i]);
    #endif

    i=0;
    for(st = fread(&teams[i],sizeof(teams_t),1,bin); st !=0;
        st = fread(&teams[i],sizeof(teams_t),1,bin) )
        i++;
    m = i;
        
        if(strcmp(str3,"team_name") == 0){
            printf("************************************\n");
            for(l=0;l<m;l++)
                if( strcmp(teams[l].team_name,str4 ) == 0)
                    g = l;
            for(i=0;i<k;i++){
                if(strcmp(strp[i],"team_name") == 0){
                    printf("TEAM\n");
                    printf("%s\n",teams[g].team_name);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"city") == 0){
                    printf("CITY\n");
                    printf("%s\n",teams[g].city);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"stadium") == 0){
                    printf("STATDİUM\n");
                    printf("%s\n",teams[g].stadium);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"founding_date") == 0){
                    printf("FOUNDİNG DATE\n");
                    printf("%d\n",teams[g].founding_date);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"colors") == 0){
                    printf("COLOR\n");
                    printf("%s\n",teams[g].colors);
                    printf("************************************\n");
                }     
            }
        }
        else if(strcmp(str3,"city") == 0){
            printf("************************************\n");
            for(l=0;l<m;l++)
                if( strcmp(teams[l].city,str4 ) == 0)
                    g = l;
            for(i=0;i<k;i++){
                if(strcmp(strp[i],"team_name") == 0){
                    printf("TEAM\n");
                    printf("%s\n",teams[g].team_name);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"city") == 0){
                    printf("CITY\n");
                    printf("%s\n",teams[g].city);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"stadium") == 0){
                    printf("STATDİUM\n");
                    printf("%s\n",teams[g].stadium);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"founding_date") == 0){
                    printf("FOUNDİNG DATE\n");
                    printf("%d\n",teams[g].founding_date);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"colors") == 0){
                    printf("COLOR\n");
                    printf("%s\n",teams[g].colors);
                    printf("************************************\n");
                }     
            }
        }
        else if(strcmp(str3,"stadium") == 0){
            printf("************************************\n");
            for(l=0;l<m;l++)
                if( strcmp(teams[l].stadium,str4 ) == 0)
                    g = l;
            for(i=0;i<k;i++){
                if(strcmp(strp[i],"team_name") == 0){
                    printf("TEAM\n");
                    printf("%s\n",teams[g].team_name);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"city") == 0){
                    printf("CITY\n");
                    printf("%s\n",teams[g].city);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"stadium") == 0){
                    printf("STATDİUM\n");
                    printf("%s\n",teams[g].stadium);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"founding_date") == 0){
                    printf("FOUNDİNG DATE\n");
                    printf("%d\n",teams[g].founding_date);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"colors") == 0){
                    printf("COLOR\n");
                    printf("%s\n",teams[g].colors);
                    printf("************************************\n");
                }     
            }

        }
        else if(strcmp(str3,"founding_date") == 0){
            printf("************************************\n");
            for(l=0;l<m;l++)
                if( teams[l].founding_date == atoi(str4) )
                    g = l;
            for(i=0;i<k;i++){
                if(strcmp(strp[i],"team_name") == 0){
                    printf("TEAM\n");
                    printf("%s\n",teams[g].team_name);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"city") == 0){
                    printf("CITY\n");
                    printf("%s\n",teams[g].city);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"stadium") == 0){
                    printf("STATDİUM\n");
                    printf("%s\n",teams[g].stadium);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"founding_date") == 0){
                    printf("FOUNDİNG DATE\n");
                    printf("%d\n",teams[g].founding_date);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"colors") == 0){
                    printf("COLOR\n");
                    printf("%s\n",teams[g].colors);
                    printf("************************************\n");
                }     
            }

        }
        else if(strcmp(str3,"colors") == 0){
            printf("************************************\n");
            for(l=0;l<m;l++){
                if( strcmp(teams[l].colors,str4 ) == 0 )
                    g = l;
            }
            for(i=0;i<k;i++){
                if(strcmp(strp[i],"team_name") == 0){
                    printf("TEAM\n");
                    printf("%s\n",teams[g].team_name);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"city") == 0){
                    printf("CITY\n");
                    printf("%s\n",teams[g].city);
                    printf("************************************\n");
                }
                if(strcmp(strp[i],"stadium") == 0){
                    printf("STATDİUM\n");
                    printf("%s\n",teams[g].stadium);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"founding_date") == 0){
                    printf("FOUNDİNG DATE\n");
                    printf("%d\n",teams[g].founding_date);
                    printf("************************************\n");

                }
                if(strcmp(strp[i],"colors") == 0){
                    printf("COLOR\n");
                    printf("%s\n",teams[g].colors);
                    printf("************************************\n");
                }     
            }
        }         
    fclose(bin);
}
void where_players(FILE *bin, players_t players[], char *str,char *str2)
{
    char *strp[SIZE],str3[SIZE],str4[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;

    cmd = strtok(str2,"=");
    strcpy(str3,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str4,cmd);

    #if defined (DEBUG)
        printf("str3 : %s\n",str3);
        printf("str4 : %s\n",str4);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;

    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("srtp[%d] : %s\n",i,strp[i]);
    #endif

    i=0;
    for(st = fread(&players[i],sizeof(players_t),1,bin); st !=0;
        st = fread(&players[i],sizeof(players_t),1,bin) )
        i++;
    m = i;
 

    if(strcmp(str3,"player_name") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( strcmp(players[l].player_name,str4 ) == 0)
                g = l;  
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAME\n");
                printf("%s\n",players[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",players[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"birth_date") == 0){
                printf("BİRTH DATE\n");
                printf("%d\n",players[g].birth_date);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"position") == 0){
                printf("POSİTİON\n");
                printf("%s\n",players[g].position); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"origin") == 0){
                printf("ORİGİN\n");
                printf("%s\n",players[g].origin);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"salary") == 0){
                printf("SALARY\n");
                printf("%d\n",players[g].salary);
                printf("************************************\n");
            }
        }  
    }
    else if(strcmp(str3,"team_name") == 0){ 
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( strcmp(players[l].team_name,str4 ) == 0)
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAME\n");
                printf("%s\n",players[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",players[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"birth_date") == 0){
                printf("BİRTH DATE\n");
                printf("%d\n",players[g].birth_date);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"position") == 0){
                printf("POSİTİON\n");
                printf("%s\n",players[g].position); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"origin") == 0){
                printf("ORİGİN\n");
                printf("%s\n",players[g].origin);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"salary") == 0){
                printf("SALARY\n");
                printf("%d\n",players[g].salary);
                printf("************************************\n");
            }
        } 
    }
    else if(strcmp(str3,"birth_date") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( players[l].birth_date == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAME\n");
                printf("%s\n",players[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",players[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"birth_date") == 0){
                printf("BİRTH DATE\n");
                printf("%d\n",players[g].birth_date);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"position") == 0){
                printf("POSİTİON\n");
                printf("%s\n",players[g].position); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"origin") == 0){
                printf("ORİGİN\n");
                printf("%s\n",players[g].origin);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"salary") == 0){
                printf("SALARY\n");
                printf("%d\n",players[g].salary);
                printf("************************************\n");
            }
        } 
    }
    else if(strcmp(str3,"position") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( strcmp(players[l].position,str4 ) == 0)
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAME\n");
                printf("%s\n",players[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",players[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"birth_date") == 0){
                printf("BİRTH DATE\n");
                printf("%d\n",players[g].birth_date);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"position") == 0){
                printf("POSİTİON\n");
                printf("%s\n",players[g].position); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"origin") == 0){
                printf("ORİGİN\n");
                printf("%s\n",players[g].origin);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"salary") == 0){
                printf("SALARY\n");
                printf("%d\n",players[g].salary);
                printf("************************************\n");
            }
        } 
    }
    else if(strcmp(str3,"origin") == 0) {
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( strcmp(players[l].origin,str4 ) == 0)
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAME\n");
                printf("%s\n",players[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",players[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"birth_date") == 0){
                printf("BİRTH DATE\n");
                printf("%d\n",players[g].birth_date);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"position") == 0){
                printf("POSİTİON\n");
                printf("%s\n",players[g].position); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"origin") == 0){
                printf("ORİGİN\n");
                printf("%s\n",players[g].origin);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"salary") == 0){
                printf("SALARY\n");
                printf("%d\n",players[g].salary);
                printf("************************************\n");
            }
        } 
    }    
    else if(strcmp(str3,"salary") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( players[l].salary == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAME\n");
                printf("%s\n",players[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",players[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"birth_date") == 0){
                printf("BİRTH DATE\n");
                printf("%d\n",players[g].birth_date);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"position") == 0){
                printf("POSİTİON\n");
                printf("%s\n",players[g].position); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"origin") == 0){
                printf("ORİGİN\n");
                printf("%s\n",players[g].origin);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"salary") == 0){
                printf("SALARY\n");
                printf("%d\n",players[g].salary);
                printf("************************************\n");
            }
        } 
    }
    fclose(bin);
}
void where_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str,char *str2)
{
    char *strp[SIZE],str3[SIZE],str4[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;

    cmd = strtok(str2,"=");
    strcpy(str3,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str4,cmd);

    #if defined (DEBUG)
        printf("str3 : %s\n",str3);
        printf("str4 : %s\n",str4);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;

    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("srtp[%d] : %s\n",i,strp[i]);
    #endif

    i=0;
    for(st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin); st !=0;
        st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin) )
        i++;
    m = i;
 
   if(strcmp(str3,"year") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].year == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"team_name") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( strcmp(team_statistics[l].team_name,str4) == 0 )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                    printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"points") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].points == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"wins") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].wins == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"loses") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].loses == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"draws") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].draws == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"goals_for") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].goals_for == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"goals_against") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].goals_against == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    else if(strcmp(str3,"goals_difference") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( team_statistics[l].goals_difference == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEAR\n");
                printf("%d\n",team_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"team_name") == 0){
                printf("TEAM NAME\n");
                printf("%s\n",team_statistics[g].team_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"points") == 0){
                printf("POİNTS\n");
                printf("%d\n",team_statistics[g].points);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"wins") == 0){
                printf("WİNS\n");
                printf("%d\n",team_statistics[g].wins);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"loses") == 0){
                printf("LOSES\n");
                printf("%d\n",team_statistics[g].loses); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"draws") == 0){
                printf("DRAWS\n");
                printf("%d\n",team_statistics[g].draws);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_for") == 0){
                printf("GOALS FOR\n");
                printf("%d\n",team_statistics[g].goals_for);
                printf("************************************\n");
            }  
            else if(strcmp(strp[i],"goals_against") == 0){
                printf("GOALS AGAİNST\n");
                printf("%d\n",team_statistics[g].goals_against);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"goals_difference") == 0){
                printf("GOALS DİFFERENCE\n");
                printf("%d\n",team_statistics[g].goals_difference);
                printf("************************************\n");
            }
        }
    }
    fclose(bin);
}
void where_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str,char *str2)
{
    char *strp[SIZE],str3[SIZE],str4[SIZE];
    char *cmd;
    int num,st,j=-1,i=0,k=0,l,m,g;

    cmd = strtok(str2,"=");
    strcpy(str3,cmd);
    cmd = strtok(NULL,"=");
    strcpy(str4,cmd);

    #if defined (DEBUG)
        printf("str3 : %s\n",str3);
        printf("str4 : %s\n",str4);
    #endif

    cmd = strtok(str,",");
    strp[k] = cmd;
    for(k=1; cmd != NULL;k++){
        cmd = strtok(NULL,",");
        if(cmd != NULL)
            strp[k] = cmd;
    }
    k-=1;

    #if defined (DEBUG)
        for(i=0;i<k;i++)
            printf("srtp[%d] : %s\n",i,strp[i]);
    #endif

    i=0;
    for(st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin); st !=0;
        st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin) )
        i++;
    m = i;

    if(strcmp(str3,"year") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( player_statistics[l].year == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEARS\n");
                printf("%d\n",player_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAMES\n");
                printf("%s\n",player_statistics[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"goals") == 0){
                printf("GOALS\n");
                printf("%d\n",player_statistics[g].goals);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"assists") == 0){
                printf("ASSİSTS\n");
                printf("%d\n",player_statistics[g].assists); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"red_cards") == 0){
                printf("RED CARDS\n");
                printf("%d\n",player_statistics[g].red_cards);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"yellow_cards") == 0){
                printf("YELLOW CARDS\n");
                printf("%d\n",player_statistics[g].yellow_cards);
                printf("************************************\n");
            }   
        }
    }
    else if(strcmp(str3,"player_name") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( strcmp(player_statistics[l].player_name,str4) == 0 )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEARS\n");
                printf("%d\n",player_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAMES\n");
                printf("%s\n",player_statistics[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"goals") == 0){
                printf("GOALS\n");
                printf("%d\n",player_statistics[g].goals);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"assists") == 0){
                printf("ASSİSTS\n");
                printf("%d\n",player_statistics[g].assists); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"red_cards") == 0){
                printf("RED CARDS\n");
                printf("%d\n",player_statistics[g].red_cards);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"yellow_cards") == 0){
                printf("YELLOW CARDS\n");
                printf("%d\n",player_statistics[g].yellow_cards);
                printf("************************************\n");
            }   
        }
    }
    else if(strcmp(str3,"goals") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( player_statistics[l].goals == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEARS\n");
                printf("%d\n",player_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAMES\n");
                printf("%s\n",player_statistics[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"goals") == 0){
                printf("GOALS\n");
                printf("%d\n",player_statistics[g].goals);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"assists") == 0){
                printf("ASSİSTS\n");
                printf("%d\n",player_statistics[g].assists); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"red_cards") == 0){
                printf("RED CARDS\n");
                printf("%d\n",player_statistics[g].red_cards);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"yellow_cards") == 0){
                printf("YELLOW CARDS\n");
                printf("%d\n",player_statistics[g].yellow_cards);
                printf("************************************\n");
            }   
        }
    }
    else if(strcmp(str3,"assists") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( player_statistics[l].assists == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEARS\n");
                printf("%d\n",player_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAMES\n");
                printf("%s\n",player_statistics[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"goals") == 0){
                printf("GOALS\n");
                printf("%d\n",player_statistics[g].goals);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"assists") == 0){
                printf("ASSİSTS\n");
                printf("%d\n",player_statistics[g].assists); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"red_cards") == 0){
                printf("RED CARDS\n");
                printf("%d\n",player_statistics[g].red_cards);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"yellow_cards") == 0){
                printf("YELLOW CARDS\n");
                printf("%d\n",player_statistics[g].yellow_cards);
                printf("************************************\n");
            }   
        }
    }
    else if(strcmp(str3,"red_cards") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( player_statistics[l].red_cards == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEARS\n");
                printf("%d\n",player_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAMES\n");
                printf("%s\n",player_statistics[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"goals") == 0){
                printf("GOALS\n");
                printf("%d\n",player_statistics[g].goals);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"assists") == 0){
                printf("ASSİSTS\n");
                printf("%d\n",player_statistics[g].assists); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"red_cards") == 0){
                printf("RED CARDS\n");
                printf("%d\n",player_statistics[g].red_cards);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"yellow_cards") == 0){
                printf("YELLOW CARDS\n");
                printf("%d\n",player_statistics[g].yellow_cards);
                printf("************************************\n");
            }   
        }
    }
    else if(strcmp(str3,"yellow_cards") == 0){
        printf("************************************\n");
        for(l=0;l<m;l++)
            if( player_statistics[l].yellow_cards == atoi(str4) )
                g = l;
        for(i=0;i<k;i++){
            if(strcmp(strp[i],"year") == 0){
                printf("YEARS\n");
                printf("%d\n",player_statistics[g].year);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"player_name") == 0){
                printf("PLAYER NAMES\n");
                printf("%s\n",player_statistics[g].player_name);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"goals") == 0){
                printf("GOALS\n");
                printf("%d\n",player_statistics[g].goals);
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"assists") == 0){
                printf("ASSİSTS\n");
                printf("%d\n",player_statistics[g].assists); 
                printf("************************************\n");
            }
            else if(strcmp(strp[i],"red_cards") == 0){
                printf("RED CARDS\n");
                printf("%d\n",player_statistics[g].red_cards);
                printf("************************************\n");
            } 
            else if(strcmp(strp[i],"yellow_cards") == 0){
                printf("YELLOW CARDS\n");
                printf("%d\n",player_statistics[g].yellow_cards);
                printf("************************************\n");
            }   
        }
    }

    fclose(bin);
}

