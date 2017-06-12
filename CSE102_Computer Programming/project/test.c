#include<stdio.h>
#include<string.h>

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


int main() {

    FILE *bin=fopen("players.bin","rb"),
           *bin2=fopen("teams.bin","rb"),
            *bin3=fopen("team_statistics.bin","rb"),
             *bin4=fopen("player_statistics.bin","rb")   ;
    teams_t teams[MAXSIZE];
    players_t players[MAXSIZE];
    team_statistics_t team_statistics[MAXSIZE];
    player_statistics_t player_statistics[MAXSIZE];
 
    int st,j=0,i=0;   
    
    
    
 for(st = fread(&teams[i],sizeof(teams_t),1,bin2);st!=0;
         st = fread(&teams[i],sizeof(teams_t),1,bin2) ){        
    printf("%s -- %s -- %s -- %d -- %s\n",teams[i].team_name,teams[i].city,teams[i].stadium,teams[i].founding_date,teams[i].colors);
    i++;    
    }
    fclose(bin2);



   for(st = fread(&players[i],sizeof(players_t),1,bin);st!=0;
         st = fread(&players[i],sizeof(players_t),1,bin) ){  
printf("%s -- %s -- %d -- %s -- %s -- %d\n",players[i].player_name,players[i].team_name,players[i].birth_date,players[i].origin,players[i].position,players[i].salary);
i++;
}
fclose(bin);


  for(st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin3);st!=0;
         st = fread(&team_statistics[i],sizeof(team_statistics_t),1,bin3) ){   

            printf("%d -- %s -- %d -- %d -- %d -- %d -- %d -- %d -- %d\n",team_statistics[i].year,team_statistics[i].team_name,team_statistics[i].points,team_statistics[i].wins,team_statistics[i].loses,team_statistics[i].draws,team_statistics[i].goals_for,team_statistics[i].goals_against, team_statistics[i].goals_difference);
            i++;
    }
fclose(bin3);

 for(st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin4);st!=0;
         st = fread(&player_statistics[i],sizeof(player_statistics_t),1,bin4) ){   

            printf("%d -- %s -- %d -- %d -- %d -- %d \n",player_statistics[i].year,player_statistics[i].player_name,player_statistics[i].goals,player_statistics[i].assists,player_statistics[i].red_cards,player_statistics[i].yellow_cards);
            i++;
    }
fclose(bin4);
    
    


}
