#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define SIZE 4
#include "k.h"


bool right(struct game *game), left(struct game *game), down(struct game *game), up(struct game *game);

void add_random_tile(struct game *game){
    int row, col;
   
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}

bool is_game_won(const struct game game){
	int i=0, j=0;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (game.board[i][j]=='K')
			{
				return true;
			}
		}
	}

	return false;
}

bool is_move_possible(const struct game game){
	int i=0, j=0;

	for (i = 0; i < SIZE-1; i++)
	    {
		    for (j = 0; j < SIZE; j++)
		    {
			    if (game.board[i][j]==game.board[i+1][j])
			    {
				    return true;
			    }
		    }
	    }

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

	return false;
}



bool up(struct game *game){	
	int score=0, asci=0,move=0, rest=0, number=0;
	int i=0, r=0, j=0;
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
						r=r-1;
						move=move+1;
						continue;
					}
				}
			}
			r=r+1;
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
						asci++;
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
						
						move=move+1;
						r=r+1;
						rest=asci%65+1;
						number=2;
						for (j = 0; j < rest; ++j)
						{
							number=number*2;
						}
						score=score+number/2;
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
						move=move+1;
						r=r-1;
						
						continue;
					}
				}
			}
			r=r+1;
		}
	}
	game->score=game->score+score;
	if (move!=0)
	{
		return true;
	}
	return false;
	
}

bool down(struct game *game){	
	int score=0, r=0, i=0, move=0, asci=0, rest=0, number=0, j=0;
	for ( i = 0; i < SIZE;i++)
	{
		
		r=SIZE-2;
		while(r>-1){
			if (game->board[r][i]!=' '&& r!=(SIZE-1))
			{
				
				if(game->board[r+1][i]==' '){
					game->board[r+1][i]=game->board[r][i];
					game->board[r][i]=' ';
					
					move=1;
					r=r+1;
					continue;
				}
				
			}
			r=r-1;
			}
			r=SIZE-1;
			while(r>-1){

		if(r!=0){
		
			if (game->board[r][i]!=' ')
			{
				if(game->board[r-1][i]==game->board[r][i]){
				
					asci=game->board[r-1][i];
					asci=asci+1;
					if(asci==66) { game->board[r-1][i]='B'; }
					if(asci==67) { game->board[r-1][i]='C'; }
					if(asci==68) { game->board[r-1][i]='D'; }
					if(asci==69) { game->board[r-1][i]='E'; }
					if(asci==70) { game->board[r-1][i]='F'; }
					if(asci==71) { game->board[r-1][i]='G'; }
					if(asci==72) { game->board[r-1][i]='H'; }
					if(asci==73) { game->board[r-1][i]='I'; }
					if(asci==74) { game->board[r-1][i]='J'; }
					if(asci==75) { game->board[r-1][i]='K'; }

					game->board[r][i]=' ';
					r=r-1;
					rest=asci%65+1;
					number=2;
					move=1;
					
					for (j= 0; j < rest; j++)
					{
						number=number*2;
					}
					score=score+number/2;
		
				}
			}
			
		}
		r=r-1;
	}
		r=SIZE-2;

		while(r>-1){
			if (game->board[r][i]!=' ')
			{
				if(game->board[r+1][i]==' '){
					game->board[r+1][i]=game->board[r][i];
					game->board[r][i]=' ';
					r=r+1;
					move=1;
					continue;
				}
			}
			r=r-1;
		}
	}
	game->score=game->score+score;
	if (move==1)
	{
		return true;
	}
	return false;
}


bool right(struct game *game){	
	int score=0, r=0, i=0, move=0, asci=0, rest=0, number=0, j=0;
	
	for ( r = 0; r < SIZE;r++)
	{
		 i=SIZE-2;
		while(i>-1){
			if (game->board[r][i]!=' ')
			{
				if (game->board[r][i+1]==' ')
				{
					if (i!=(SIZE-1))
					{
						game->board[r][i+1]=game->board[r][i];
						game->board[r][i]=' ';
						
						move=1;
						i=i+1;
						continue;
					}
				}
			}
			if (game->board[r][i]!=' ')
			{
				if (game->board[r][i+1]==game->board[r][i])
				{
					if (i!=(SIZE-1))
					{
						asci=game->board[r][i+1];
						asci=asci+1;
						if(asci==66) { game->board[r][i+1]='B'; }
						if(asci==67) { game->board[r][i+1]='C'; }
						if(asci==68) { game->board[r][i+1]='D'; }
						if(asci==69) { game->board[r][i+1]='E'; }
						if(asci==70) { game->board[r][i+1]='F'; }
						if(asci==71) { game->board[r][i+1]='G'; }
						if(asci==72) { game->board[r][i+1]='H'; }
						if(asci==73) { game->board[r][i+1]='I'; }
						if(asci==74) { game->board[r][i+1]='J'; }
						if(asci==75) { game->board[r][i+1]='K'; }
						game->board[r][i]=' ';

						rest=asci%65+1;
						
						
						number=2;
						i=i-1;
						for (j = 0; j < rest; j++)
						{
							number=number*2;
						}
						
						move=1;
						score=score+number/2;
					}
				}
			}
		i=i-1;

		}

		i=SIZE-2;
		while(i>-1){
			if (game->board[r][i]!=' ')
			{
				if (game->board[r][i+1]==' ')
				{
					if (i!=(SIZE-1))
					{
						game->board[r][i+1]=game->board[r][i];
						game->board[r][i]=' ';
						move=1;
						i=i+1;
						continue;
					}
				}
			}
		i=i-1;

		}
	
	}
	game->score=game->score+score;
	if (move==1)
	{
		return true;
	}
	return false;
}

bool left(struct game *game){	
	int score=0, r=0, i=0, move=0, asci=0, rest=0, number=0, j=0;
	for (r = 0; r < SIZE;r++)
	{
		;
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
						
						move=1;
						i=i-1;
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

						rest=asci%65+1;
						
						number=2;
						for (j = 0; j < rest; j++)
						{
							number=number*2;
						}
						score=score+number/2;
						
						move=1;
					}					
				}
			}
			i=i+1;
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
			i=i+1;
		}	
	}
	game->score=game->score+score;
	if (move==1)
	{
		return true;
	}
	return false;
}


bool update(struct game *game, int dy, int dx){

	if (dy==0 && dx==1)
	{	
		if (right(game)==true)
		{
			return true;
		}
		return false;
	}
	else{
		if (dy==1 && dx==0)
		{
			if (down(game)==true)
			{
				return true;
			}
			return false;
		}
		else{
			if (dy==-1 && dx==0)
			{
				if(up(game)==true){
				return true;
				}		
				return false;
			}
			else{
				if (dy==0 && dx==-1)
				{
					if (left(game)==true)
					{
						return true;
					}
					return false;
				}

			}

		}

	}
	
	
	
	
	return false;
}
