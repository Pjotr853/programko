#include<stdio.h>
#include<stdlib.h>

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

while(is_move_possible(game)==true){
	char smer;
	printf("zadaj smer\n");
	scanf("%c",&smer);
	getchar();
	bool result=false;
	if (smer=='d')
	{
		 result = update(&game, 0,1);
	}
	if (smer=='a')
	{
		 result = update(&game, 0,-1);
	}
	if (smer=='s')
	{
		result = update(&game, 1, 0);
	}
	if (smer=='w')
	{
		 result = update(&game, -1, 0);
	}
	
	if (result==true)
	{
		add_random_tile(&game);
	}
	if (is_game_won(game))
	{
		printf("vyhra si\n");
	}
	render(game);


}
struct player list[10];
	int pocet;
	pocet=load(list);
	printf("pocet = %d\n",pocet );
	printf("\n\n\n\n\n\n");


	if (save(list,pocet))
	{
		printf("returt true\n");
	}


struct player player = {
    .name = "johna",
    .score = 10
};
if (add_player(list,&pocet, player))
	{
		
		printf("returt true\n");
	}

	return 0;
}
