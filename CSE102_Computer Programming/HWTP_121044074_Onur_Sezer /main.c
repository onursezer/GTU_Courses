#include "project.h"

int main(int argc,char *argv[]) {

    FILE *teams_bin,*players_bin,*t_statistics,*p_statistics,
            *file_cont,*file_cont2,*file_cont3,*file_cont4,*inp;
            
    char command[SIZE],str1[SIZE],str2[SIZE],str3[SIZE],str4[SIZE];
    char *cmd;
    int size; 
    int numberOfTeam,numberOfPlayer,numberOfTstatistics,numberOfPstatistics;
    teams_t *teams;
    players_t *players;
    team_statistics_t *team_statistics;
    player_statistics_t *player_statistics;
    strcpy(str3,"empty");  
    strcpy(str4,"empty");  
    
    printf("*****************************************************\n");
    printf("*                                                   *\n");
    printf("*  * * * * * * * * * * * * * * * * * * * * * * * *  *\n");
    printf("*  *                                             *  *\n");
    printf("*  *  WELCOME to Program of SüperLig Database!!  *  *\n");
    printf("*  *                                             *  *\n");
    printf("*  * * * * * * * * * * * * * * * * * * * * * * * *  *\n");
    printf("*                                                   *\n");
    printf("*****************************************************\n");  
    printf("\nEnter a commands:\n");
    if(argc == 3 || argc == 4)
        printf("Commands were taken.\n");

    teams_bin = fopen(TEAM_FILE,"rb");
    if(teams_bin == NULL){
        file_cont = fopen(TEAM_FILE,"wb");
        teams = (teams_t *)calloc(1,sizeof(teams_t));
        fclose(file_cont);
    }
    players_bin = fopen(PLAYER_FILE,"rb");
    if(players_bin == NULL){
        file_cont2 = fopen(PLAYER_FILE,"wb");
        players = (players_t *)calloc(1,sizeof(players_t));
        fclose(file_cont2);
    }
    t_statistics = fopen(T_STATISTIC_FILE,"rb");
    if(t_statistics == NULL){
        file_cont3 = fopen(T_STATISTIC_FILE,"wb");
        team_statistics = (team_statistics_t *)calloc(1,sizeof(team_statistics_t));
        fclose(file_cont3);
    }
    p_statistics = fopen(P_STATISTIC_FILE,"rb");
    if(p_statistics == NULL){
        file_cont4 = fopen(P_STATISTIC_FILE,"wb");
        player_statistics = (player_statistics_t *)calloc(1,sizeof(player_statistics_t));
        fclose(file_cont4);
    }

    if(argc == 2){
        file_cont = fopen(TEAM_FILE,"wb");
        file_cont2 = fopen(PLAYER_FILE,"wb");
        file_cont3 = fopen(T_STATISTIC_FILE,"wb");
        file_cont4 = fopen(P_STATISTIC_FILE,"wb");
        fclose(file_cont);  
        fclose(file_cont2);        
        fclose(file_cont3);        
        fclose(file_cont4);              
    }   
 
    findNumberOfData(TEAM_FILE,PLAYER_FILE,T_STATISTIC_FILE,P_STATISTIC_FILE,&numberOfTeam,
                          &numberOfPlayer,&numberOfTstatistics,&numberOfPstatistics);
    if(teams_bin != NULL){
        if(numberOfTeam != 0)
            teams = (teams_t *)calloc(numberOfTeam+1,sizeof(teams_t));
        else
            teams = (teams_t *)calloc(1,sizeof(teams_t));
    }
    if(players_bin != NULL){
        if(numberOfPlayer != 0) 
            players = (players_t *)calloc(numberOfPlayer+1,sizeof(players_t));
        else
            players = (players_t *)calloc(1,sizeof(players_t));
    }
    if(t_statistics != NULL){ 
        if(numberOfTstatistics != 0)
            team_statistics = (team_statistics_t *)calloc(numberOfTstatistics+1,sizeof(team_statistics_t));
        else
            team_statistics = (team_statistics_t *)calloc(1,sizeof(team_statistics_t));
    }
    if(p_statistics != NULL){
        if(numberOfPstatistics != 0) 
            player_statistics = (player_statistics_t *)calloc(numberOfPstatistics+1,sizeof(player_statistics_t));
        else
            player_statistics = (player_statistics_t *)calloc(1,sizeof(player_statistics_t));
    }

    if(argc == 1){
        fgets(command,SIZE,stdin);
        size = strlen(command);
        JUMP_ROW(size);   
    }
    else if(argc == 3 || argc == 4){
        inp = fopen(argv[2],"r");
        fgets(command,SIZE,inp);
        size = strlen(command);
        JUMP_ROW(size);                    
    }
    
    cmd = strtok(command," ");
    
    while(argc != 2 && EQUAL(command,"q") != 1 ){
        
        if( EQUAL(cmd,"insert") ) {

            size = strlen(cmd);
            strcpy(str1,&command[size+1]);
            cmd = strtok(str1," ");
            strcpy(str2,cmd);             /*   insert edilecek bilgiler */
            size = strlen(cmd);
            strcpy(str3,&str1[size+4]);    /* teams, player, t_statistics, p_statictis*/
                      

            if(EQUAL(str3,"teams") ){
                teams_bin = fopen(TEAM_FILE,"rb+");                
                insert_teams(teams_bin,teams,str2);                
            }
            else if(EQUAL(str3,"players") ){
                players_bin = fopen(PLAYER_FILE,"rb+");
                insert_players(players_bin,players,str2);
                                   
            }
            else if(EQUAL(str3,"team_statistics") ){
                t_statistics = fopen(T_STATISTIC_FILE,"rb+");
                insert_t_statistics(t_statistics, team_statistics, str2);
            }
            else if(EQUAL(str3,"player_statistics") ){
                p_statistics = fopen(P_STATISTIC_FILE,"rb+");
                insert_p_statistics(p_statistics, player_statistics, str2);
            }   
        }
        else if( EQUAL(cmd,"delete") ) {

            size = strlen(cmd);
            strcpy(str1,&command[size+1]);
            strcpy(str1,&str1[7]);
            cmd = strtok(str1," ");
            strcpy(str1,cmd);
            cmd = strtok(NULL," ");
            cmd = strtok(NULL," ");
            strcpy(str2,cmd);

            #if defined (DEBUG)
                printf("str2 : %s\n",str2);
                printf("str1 : %s\n",str1);
            #endif

            if( EQUAL(str1,"teams") ) {
                teams_bin = fopen(TEAM_FILE,"rb+");
                delete_teams(teams_bin,teams,str2);
            } 
            else if( EQUAL(str1,"players") ) {
                players_bin = fopen(PLAYER_FILE,"rb+");
                delete_players(players_bin,players,str2); 
            }
            else if( EQUAL(str1,"team_statistics") ) {
                t_statistics = fopen(T_STATISTIC_FILE,"rb+"); 
                delete_t_statistics(t_statistics,team_statistics,str2);
            }
            else if( EQUAL(str1,"player_statistics") ) {
                p_statistics = fopen(P_STATISTIC_FILE,"rb+"); 
                delete_p_statistics(p_statistics,player_statistics,str2);
            }   
        }
        else if(EQUAL(cmd,"update") ) {
            cmd = strtok(NULL," ");
            strcpy(str1,cmd);
            cmd = strtok(NULL," ");
            cmd = strtok(NULL," ");
            strcpy(str2,cmd);
            cmd = strtok(NULL," ");
            cmd = strtok(NULL," ");
            strcpy(str3,cmd);
            
                
            if( EQUAL(str2,"teams") ){
                teams_bin = fopen(TEAM_FILE,"rb+");
                update_teams(teams_bin,teams,str1,str3);

            }
            if( EQUAL(str2,"players") ){
                players_bin = fopen(PLAYER_FILE,"rb+");
                update_players(players_bin,players,str1,str3);
            }
            if( EQUAL(str2,"team_statistics") ){
                t_statistics = fopen(T_STATISTIC_FILE,"rb+");
                update_t_statistics(t_statistics,team_statistics,str1,str3);    
            }
            if( EQUAL(str2,"player_statistics") ){
                p_statistics = fopen(P_STATISTIC_FILE,"rb+");
                update_p_statistics(p_statistics,player_statistics,str1,str3);
        
            }                
        }
        else if( EQUAL(cmd,"select") ) {
            cmd = strtok(NULL," ");
            strcpy(str1,cmd);           /*yazdilicak elmanlar*/
            cmd = strtok(NULL," ");
            cmd = strtok(NULL," ");
            strcpy(str2,cmd);           /*secilen tablo*/
            cmd = strtok(NULL," "); 

            if(cmd == NULL ){
                if( EQUAL(str2,"teams") ){
                    teams_bin = fopen(TEAM_FILE,"rb+");
                    select_teams(teams_bin,teams,str1);    
                }   
                if( EQUAL(str2,"players") ){
                    players_bin = fopen(PLAYER_FILE,"rb+"); 
                    select_players(players_bin,players,str1);              
                }   
                if( EQUAL(str2,"team_statistics") ){
                    t_statistics = fopen(T_STATISTIC_FILE,"rb+"); 
                    select_t_statistics(t_statistics,team_statistics,str1);              
                }
                if( EQUAL(str2,"player_statistics") ){
                    p_statistics = fopen(P_STATISTIC_FILE,"rb+");   
                    select_p_statistics(p_statistics,player_statistics,str1);      
                }
            }    
            else if(EQUAL(cmd,"sort") ){
                cmd = strtok(NULL," "); /*by*/
                cmd = strtok(NULL," "); /*siralanacak elemen*/
                strcpy(str3,cmd);
                cmd = strtok(NULL," ");
                strcpy(str4,cmd);

                printf("str3 : %s\n",str3);
                printf("str4 : %s\n",str4);
                
                if( EQUAL(str2,"teams") ){
                    teams_bin = fopen(TEAM_FILE,"rb+");
                    sort_teams(teams_bin,teams,str1,str3,str4);    
                }
                if( EQUAL(str2,"players") ){
                    players_bin = fopen(PLAYER_FILE,"rb+");
                    sort_players(players_bin,players,str1,str3,str4);                                     
                }
                if( EQUAL(str2,"team_statistics") ){
                    t_statistics = fopen(T_STATISTIC_FILE,"rb+");
                    sort_t_statistics(t_statistics,team_statistics,str1,str3,str4);
                }    
                if( EQUAL(str2,"player_statistics") ){
                    p_statistics = fopen(P_STATISTIC_FILE,"rb+"); 
                    sort_p_statistics(p_statistics,player_statistics,str1,str3,str4);
                }            
            }
            else if(EQUAL(cmd,"where") ){
                printf("whereeee\n");
                cmd = strtok(NULL," "); /*yazdirilacak elemen*/  
                strcpy(str3,cmd);
                printf("str3 : %s\n",str3);

                if( EQUAL(str2,"teams") ){
                    teams_bin = fopen(TEAM_FILE,"rb+");
                    where_teams(teams_bin,teams,str1,str3);    
                }   
                if( EQUAL(str2,"players") ){
                    players_bin = fopen(PLAYER_FILE,"rb+"); 
                    where_players(players_bin,players,str1,str3);              
                }   
                if( EQUAL(str2,"team_statistics") ){
                    t_statistics = fopen(T_STATISTIC_FILE,"rb+"); 
                    where_t_statistics(t_statistics,team_statistics,str1,str3);              
                }
                if( EQUAL(str2,"player_statistics") ){
                    p_statistics = fopen(P_STATISTIC_FILE,"rb+");   
                    where_p_statistics(p_statistics,player_statistics,str1,str3);      
                }
            }

            strcpy(str3,"empty");  
            strcpy(str4,"empty");
        }
        else
            printf("%s HATALI KOMUD!!..\n",cmd);

        findNumberOfData(TEAM_FILE,PLAYER_FILE,T_STATISTIC_FILE,P_STATISTIC_FILE,&numberOfTeam,
                          &numberOfPlayer,&numberOfTstatistics,&numberOfPstatistics);

        if(numberOfTeam != 0)
            teams = (teams_t *)calloc(numberOfTeam+1,sizeof(teams_t));
        if(numberOfPlayer != 0) 
            players = (players_t *)calloc(numberOfPlayer+1,sizeof(players_t));
        if(numberOfTstatistics != 0)
            team_statistics = (team_statistics_t *)calloc(numberOfTstatistics+1,sizeof(team_statistics_t));
        if(numberOfPstatistics != 0) 
            player_statistics = (player_statistics_t *)calloc(numberOfPstatistics+1,sizeof(player_statistics_t));

        if(argc == 1){
            fgets(command,SIZE,stdin);
            size = strlen(command);
            JUMP_ROW(size);     
        }
        else if(argc == 3 || argc == 4){
            fgets(command,SIZE,inp);
            size = strlen(command);
            JUMP_ROW(size);                        
        }
        cmd = strtok(command," ");        
    }
    if(argc == 4){
        file_cont = fopen(TEAM_FILE,"wb");
        file_cont2 = fopen(PLAYER_FILE,"wb");
        file_cont3 = fopen(T_STATISTIC_FILE,"wb");
        file_cont4 = fopen(P_STATISTIC_FILE,"wb");
        fclose(file_cont);  
        fclose(file_cont2);        
        fclose(file_cont3);        
        fclose(file_cont4);              
    }
	
    free(teams);
    free(players);
    free(team_statistics);
    free(player_statistics);              
}
