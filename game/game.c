#include <stdio.h>
#include <string.h>
#define BUFFER 100


typedef struct player{
    char name[50];
    unsigned int level;
    float health;
    float experience;
} Player;

Player player;
typedef struct enemy{
    char name[50];
    char type[10];
    unsigned int level;
    float health;
} Enemy;

void create_player(){    
    
    char creation_choice;
    printf("[1] to Create Your Own Player | [2] for Default: ");
    scanf("%c",&creation_choice);

    if (creation_choice!='1'){
        char name[6]="Player";
        for (int i=0;i<strlen(name);i++)
            player.name[i]=name[i];
        player.level=1;
        player.health=100.0;
    }
    else{
        printf("Enter player name: ");
        fgets(player.name,BUFFER,stdin);
        player.name[strcspn(player.name,"\n")]=0;
    }
    printf("Enter player level: ");
    scanf("%ud",&player.level);
    while(getchar()!='\n');

    printf("Enter player health: ");
    scanf("%f",&player.health);
    while(getchar()!='\n');

}

void level_up(int increase){
    player.level++;
}
int main(){
    create_player();

    return 0;
    



    
    
}