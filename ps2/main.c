#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 4
#include "k.h"
#include "hof.h"

bool save(const struct player list[], const int size);
void render(const struct game game);
int load(struct player list[]);


int main(){

struct game game = {
    .board = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    },
    .score = 0
};

	add_random_tile(&game);
	add_random_tile(&game);
	render(game);
	bool result=false;
while(is_move_possible(game)==true){
	char velociti;
	printf("zadaj smer\n");
	scanf("%c",&velociti);
	getchar();
	result=false;
	if (velociti=='s')
	{
		result = update(&game, 1, 0);
	}
	if (velociti=='w')
	{
		 result = update(&game, -1, 0);
	}
	if (velociti=='d')
	{
		 result = update(&game, 0,1);
	}
	if (velociti=='a')
	{
		 result = update(&game, 0,-1);
	}
	
	
	if (result==true)
	{
		add_random_tile(&game);
	}
	if (is_game_won(game))
	{
		printf("vyhral si\n");
	}
	render(game);


}
struct player list[10];
	int pocet;
	pocet=load(list);
	printf("pocet = %d\n",pocet );
	printf("\n\n\n\n\n");


	if (save(list,pocet))
	{
		printf("save \n");
	}

struct player player = {
    .name = "fero",
    .score = 10
};
if (add_player(list,&pocet, player))
	{
		
		printf("add_player true\n");
	}

	return 0;
}
