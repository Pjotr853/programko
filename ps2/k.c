#include <stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#define SIZE 4
#include "k.h"


bool vpravo(struct game *game);
bool vlavo(struct game *game);
bool dole(struct game *game);
bool hore(struct game *game);

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}




bool is_move_possible(const struct game game){
	int i=0, j=0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE-1; j++)
		{
			if (game.board[i][j]==game.board[i][j+1])
			{
				return true;
			}
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (game.board[i][j]==' ')
			{
				return true;
			}
		}
	}

    for ( i = 0; i < SIZE-1; i++)
	    {
		    for (j = 0; j < SIZE; j++)
		    {
			    if (game.board[i][j]==game.board[i+1][j])
			    {
				    return true;
			    }
		    }
	    }

	return false;
}

bool is_game_won(const struct game game){
	int i=0, j=0;
	for (i = 0; i < SIZE; i++)
		for ( j = 0; j < SIZE; j++)
		{
			if (game.board[i][j]=='K')
			{
				return true;
			}
		}
	

	return false;
}


bool vpravo(struct game *game) {
    int skore = 0;
    bool move = false;

    for (int r = 0; r < SIZE; r++) {
        int i = SIZE - 2;
        
        
        while (i >= 0) {
            if (game->board[r][i] != ' ' && game->board[r][i + 1] == ' ') {
                game->board[r][i + 1] = game->board[r][i];
                game->board[r][i] = ' ';
                move = true;
                i++;  
            } else {
                i--;
            }
        }

        i = SIZE - 2;
        while (i >= 0) {
            if (game->board[r][i] != ' ' && game->board[r][i + 1] == game->board[r][i]) {
                
                game->board[r][i + 1] = game->board[r][i] + 1;  
                game->board[r][i] = ' ';
                skore += 1 << (game->board[r][i + 1] - 'A');  
                move = true;
                i--;  
            } else {
                i--;
            }
        }


        i = SIZE - 2;
        while (i >= 0) {
            if (game->board[r][i] != ' ' && game->board[r][i + 1] == ' ') {
                game->board[r][i + 1] = game->board[r][i];
                game->board[r][i] = ' ';
                move = true;
                i++;  
            } else {
                i--;
            }
        }
    }

    
    game->score += skore;
    return move;
}


bool vlavo(struct game *game){	
	int skore=0, asci=0, num=0;
	int move=0;
	int r=0, i=0;
	int zvysok=0;
	for (r = 0; r < SIZE;r++)
	{
		
		i=1;
		while(i<SIZE){
			if (game->board[r][i]!=' ')
			{
				if (game->board[r][i-1]==' ')
				{
					if (i!=0)
					{
						game->board[r][i-1]=game->board[r][i];
						game->board[r][i]=' ';
						i=i-1;
						move=1;
						continue;
					}					
				}
			}

			if (game->board[r][i]!=' ')
			{
				if (game->board[r][i-1]==game->board[r][i])
				{
					if (i!=0)
					{
						asci=game->board[r][i-1];
						asci=asci+1;
					
						if(asci==66) { game->board[r][i-1]='B'; }
						if(asci==67) { game->board[r][i-1]='C'; }
						if(asci==68) { game->board[r][i-1]='D'; }
						if(asci==69) { game->board[r][i-1]='E'; }
						if(asci==70) { game->board[r][i-1]='F'; }
						if(asci==71) { game->board[r][i-1]='G'; }
						if(asci==72) { game->board[r][i-1]='H'; }
						if(asci==73) { game->board[r][i-1]='I'; }
						if(asci==74) { game->board[r][i-1]='J'; }
						if(asci==75) { game->board[r][i-1]='K'; }
				
						game->board[r][i]=' ';
						i=i+1;
						
						
						zvysok=asci%65+1;
					
						 num=2;
						for (int ij = 0; ij < zvysok;ij++)
						{
							num=num*2;
						}
						skore=skore+num/2;
	
						move=1;
					}					
				}
			}
			i++;
		}	
		i=1;
		while(i<SIZE){
			if (game->board[r][i]!=' ')
			{
				if (game->board[r][i-1]==' ')
				{
					if (i!=0)
					{
						game->board[r][i-1]=game->board[r][i];
						game->board[r][i]=' ';
						i=i-1;
						move=1;
						continue;
					}					
				}
			}
			i++;
		}	
	}
	game->score=game->score+skore;
	if (move==1)
	{
		return true;
	}
	return false;
}
bool dole(struct game *game) {	
    int skore = 0;
    bool move = false;

    for (int i = 0; i < SIZE; i++) {
        int r = SIZE - 2;

     
        while (r >= 0) {
            if (game->board[r][i] != ' ' && game->board[r + 1][i] == ' ') {
                game->board[r + 1][i] = game->board[r][i];
                game->board[r][i] = ' ';
                move = true;
                r++;  
                continue;
            }
            r--;
        }

        r = SIZE - 1;
        while (r > 0) {
            if (game->board[r][i] != ' ' && game->board[r - 1][i] == game->board[r][i]) {
                game->board[r - 1][i] = game->board[r - 1][i] + 1; 
                game->board[r][i] = ' ';

                int zvysok = game->board[r - 1][i] - 'A';
                int num = 2 << zvysok; 
                skore += num / 2;  

                move = true;
                r--;  
            } else {
                r--;
            }
        }

        r = SIZE - 2;
        while (r >= 0) {
            if (game->board[r][i] != ' ' && game->board[r + 1][i] == ' ') {
                game->board[r + 1][i] = game->board[r][i];
                game->board[r][i] = ' ';
                move = true;
                r++;  
                continue;
            }
            r--;
        }
    }

    game->score += skore;

    return move;
}


bool hore(struct game *game){	
	int skore=0, num=0, zvysok=0;
	int move=0;
	int asci=0;
	int r=0, i=0;
	for (i = 0; i < SIZE;i++)
	{
		r=1;
		while(r<SIZE){
			
			if (game->board[r][i]!=' '&& r != 0)
			{
				if (game->board[r-1][i]==' ')
				{
					if (r!=0 && r!= SIZE)
					{
						game->board[r-1][i]=game->board[r][i];
						game->board[r][i]=' ';
						move=move+1;
						r=r-1;
						
					
						continue;
					}
				}
			}
			r++;
		}
		r=0;
		while(r<SIZE){
			if (game->board[r][i]!=' ' && r != -1)
			{
				if (game->board[r+1][i]==game->board[r][i])
				{
					if (r!=-1)
					{
						asci=game->board[r][i];
						asci=asci+1;
				
						if(asci==66) { game->board[r][i]='B'; }
						if(asci==67) { game->board[r][i]='C'; }
						if(asci==68) { game->board[r][i]='D'; }
						if(asci==69) { game->board[r][i]='E'; }
						if(asci==70) { game->board[r][i]='F'; }
						if(asci==71) { game->board[r][i]='G'; }
						if(asci==72) { game->board[r][i]='H'; }
						if(asci==73) { game->board[r][i]='I'; }
						if(asci==74) { game->board[r][i]='J'; }
						if(asci==75) { game->board[r][i]='K'; }
				
						game->board[r+1][i]=' ';
						r=r+1;
						move++;
						
						zvysok=asci%65+1;
						num=2;
						for (int ij = 0; ij < zvysok; ij++)
						{
							num=num*2;
						}
						skore=skore+num/2;
						
					}					
				}
			}

			r=r+1;
		}
	r=1;
	while(r<SIZE){
			
			if (game->board[r][i]!=' '&& r != 0)
			{
				if (game->board[r-1][i]==' ')
				{
					if (r!=0 && r!= SIZE)
					{
						game->board[r-1][i]=game->board[r][i];
						game->board[r][i]=' ';
						r=r-1;
						move=move+1;
						continue;
					}
				}
			}
			r=r+1;
		}
	}
	
	game->score=game->score+skore;
	if (move!=0)
	{
		return true;
	}
	return false;
	
}

bool update(struct game *game, int dy, int dx){
	
	if (dy==0 && dx==-1)
	{
		if (vlavo(game)==true)
		{
			return true;
		}
		return false;
	}
	if (dy==1 && dx==0)
	{
		if (dole(game)==true)
		{
			return true;
		}
		return false;
	}
	
	if (dy==0 && dx==1)
	{	
		if (vpravo(game)==true)
		{
			return true;
		}
		return false;
	}
	if (dy==-1 && dx==0)
	{
		if(hore(game)==true){
		return true;
		}		
		return false;
	}
	return false;
}
