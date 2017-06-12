#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEBUG
#define SIZE 100
#define MAXSIZE 500
#define TEAM_FILE "teams.bin"
#define PLAYER_FILE "players.bin"
#define T_STATISTIC_FILE "team_statistics.bin"
#define P_STATISTIC_FILE "player_statistics.bin"
#define EQUAL(str1,str2) strcmp((str1),(str2))==0
#define JUMP_ROW(size) if(command[(size)-1] == '\n') \
                            command[(size)-1] = '\0'

 
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


/*           #function prototypes             */

void insert_teams(FILE *bin, teams_t teams[], char *str);
void insert_players(FILE *bin, players_t players[], char *str);
void insert_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str);
void insert_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str);
void delete_teams(FILE *bin,teams_t teams[],char *str);
void delete_players(FILE *bin,players_t players[],char *str);
void delete_t_statistics(FILE *bin,team_statistics_t team_statistics[],char *str);
void delete_p_statistics(FILE *bin,player_statistics_t player_statistics[],char *str);
void update_teams(FILE *bin, teams_t teams[], char *str,char *str2);
void update_players(FILE *bin, players_t players[], char *str,char *str2);
void update_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str,char *str2);
void update_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str,char *str2);
void select_teams(FILE *bin, teams_t teams[], char *str);
void select_players(FILE *bin, players_t players[], char *str);
void select_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str);
void select_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str);
void sort_teams(FILE *bin,teams_t teams[],char *str1,char *str2,char *str3);    
void sort_players(FILE *bin,players_t players[],char *str1,char *str2,char *str3);
void sort_t_statistics(FILE *bin,team_statistics_t team_statistics[],char *str1,char *str2,char *str3);
void sort_p_statistics(FILE *bin,player_statistics_t player_statistics[],char *str1,char *str2,char *str3);
void where_teams(FILE *bin, teams_t teams[], char *str,char *str2);
void where_players(FILE *bin, players_t players[], char *str,char *str2);
void where_t_statistics(FILE *bin, team_statistics_t team_statistics[], char *str,char *str2);
void where_p_statistics(FILE *bin, player_statistics_t player_statistics[], char *str,char *str2);
void findNumberOfData(char team_file[],char player_file[],char t_team_file[],char p_player_file[],int *numberOfTeam,
                      int *numberOfPlayer,int *numberOfTstatistics,int *numberOfPstatistics);

