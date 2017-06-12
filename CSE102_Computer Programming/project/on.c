#include<stdio.h>

#define TEAM_FILE "teams.bin"
#define PLAYER_FILE "players.bin"
#define T_STATISTIC_FILE "team_statistics.bin"
#define P_STATISTIC_FILE "player_statistics.bin"
#define DEBUG
#define SIZE 100
#define MAXSIZE 500


typedef struct{
    char team_name[SIZE];
    char city[SIZE];
    char stadium[SIZE];
    int founding_date;
    char colors[SIZE];
}teams_t;

typedef struct{    
    char player_name[SIZE];
    char team_name[SIZE];
    int birth_date;
    char origin[SIZE];
    char position[SIZE];
    int salary;
}players_t;       

typedef struct{    
    int year, points, wins, loses, draws,
        goals_for, goals_against, goals_difference;
    char team_name[SIZE];    
}team_statistics_t;

typedef struct{
    int year, goals, assists, red_cards,
        yellow_cards;
    char player_name[SIZE];
}player_statistics_t;


void findNumberOfData(char team_file[],char player_file[],char t_team_file[],char p_player_file[],int *numberOfTeam,
                      int *numberOfPlayer,int *numberOfTstatistics,int *numberOfPstatistics);

int main() {

    int numberOfTeam,numberOfPlayer,numberOfTstatistics,numberOfPstatistics;
    
    findNumberOfData(TEAM_FILE,PLAYER_FILE,T_STATISTIC_FILE,P_STATISTIC_FILE,&numberOfTeam,
                          &numberOfPlayer,&numberOfTstatistics,&numberOfPstatistics);


}
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
    #if defined(DEBUG)
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
