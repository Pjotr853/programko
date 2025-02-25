#include"playfair.h"

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char* playfair_decrypt(const char* key, const char* text){
	if (key==NULL || text==NULL)
	{
		return NULL;
	}

	char *vysledok=(char*)calloc(strlen(text)+1,sizeof(char));
	char pole[5][5];
 
 	int size=0, size1=0, i=0, y=0, j=0, x=0, pocet=0, r=0, s=0, a=0,b=0,c=0,d=0, A=0, help=0;
 	char abc[25]={"ABCDEFGHIJKLMNOPQRSTUVXYZ"};
	size=strlen(key);
	char key1[size];
	strcpy(key1,key);
	for (j = 0; j < size; j++)
	{
		if (key1[j]=='W')
		{
			key1[j]='V';
		}
		if (key1[j]=='w')
		{
			key1[j]='V';
		}
		
	}


	for (i = 0; i < size; i++)
	{
		for (j=0;j<size; j++)
		{
			if (toupper(key1[i])==toupper(key1[j]))
			{

				pocet++;
				if (pocet!=1)
				{
					if (toupper(key1[i])==toupper(key1[j]))
					{
						key1[j]='.';
					}
				}
			}
		}

		pocet=0;
	}
	

	size=strlen(key1);
 	size1=size;				

for ( i = 0; i < 5;i++)
 	{
 		for ( j = 0; j < 5;j++)
 		{
 			pole[i][j]='-';
 		}
 		
 	}


x=0;
	 while(x!=size1){
	 	int asci=toupper(key1[x]);
	 	if (asci>64)
	 	{
	 		if (asci<91)
	 		{
	 			pole[r][s]=toupper(key1[x]);
	 			s++;
	 		}
	 	}
	 	if (s==5)
	 	{
	 		s=0;
	 		r++;
	 	}
	 	x++;
	 }


	 for ( i = 0; i < 25; i++)
	 {
	 	for ( j = 0; j < size1; ++j)
	 	{	 		
	 		if (toupper(key1[j])==abc[i])
	 		{
	 			abc[i]='.';
	 		}
	 	}
	 }

 	for ( i = 0; i < 25; i++){
 		
 		if (abc[i]!='.')
	 	{
	 		pole[r][s]=abc[i];
	 		s++;
	 	}
	 	if (s==5)
	 	{
	 		s=0;
	 		r++;
	 	}
 	}

 	char veta[(strlen(text+1))];
 	j=0;
 	for ( i = 0; i < (strlen(text)); ++i)
 	{
 		if (text[i]!=' ')
 		{
 			if (islower(text[i]))
 			{
 				free(vysledok);
 				return NULL;
 			}
 			veta[j]=text[i];
 			j++;
 		}
 		 if (text[i]=='W')
 		{
 			free(vysledok);
 			return NULL;
 		}
 	}
 	veta[j]='\0';

 	j=1;
 	i=0;
 	

 	while(veta[i]!='\0')	
 	{

	 	for (x=0;x<5;x++)
	 	{
	 		for (y=0;y<5;y++)
	 		{
	 			if (veta[j]==pole[x][y])
	 			{
	 				c=x;
	 				d=y;
	 			}
	 			if (veta[i]==pole[x][y])
	 			{
	 				a=x;
	 				b=y;
	 			}
	 			
	 		}
	 	}

	 	if (d==b)
	 		{
		 		a=a-1;
		 		c=c-1;
		 		if (c==-1)
		 		{
		 			c=4;
		 		}
	 		}
		 		if(a==-1)
		 		{
		 			a=4;
		 		}
		 		
	 	else{

	 		if (c==a)
		 	{
		 		d=d-1;
		 		b=b-1;
		 		if (d==-1)
		 		{
		 			d=4;
		 		}
		 		if(b==-1)
		 		{
		 			b=4;
		 		}
		 		
		 	}
	 		else{
	 			help=b;
	 			b=d;
	 			d=help;
	 		}
	 	}

	 	vysledok[A]=pole[a][b];
	 	A=A+1;
	 	vysledok[A]=pole[c][d];
	 	A=A+1;

	 	j=j+2;
	 	i=i+2;
	 	
 	}

	return vysledok;
}

 char* playfair_encrypt(const char* key, const char* text){
 	int i=0;
 	if (text==NULL)
	{
		return 0;
	}
	if (text==NULL)
	{
		return 0;
	}
	for (i = 0; i < strlen(key); i++)
	{
		int asci=toupper(key[i]);
		if (asci<65)
		{
			return NULL;
		}
		if (asci>90)
		{
			return NULL;
		}
	}


 	char pole[5][5];
 	int r=0, s=0, k=0, y=0,A=0, j=0,size=0, size1=0, question=0, znak=0, a=0,b=0,c=0,d=0, velkost=0, x=0, z=0, help=0; 
 	char abc[25]={"ABCDEFGHIJKLMNOPQRSTUVXYZ"}, veta[25];
	size=strlen(key);
	char key1[size];
	strcpy(key1,key);
	for ( i = 0; i < size; ++i)
	{
		if (key1[i]=='w')
		{
			key1[i]='V';
		}
		if (key1[i]=='W')
		{
			key1[i]='V';
		}
	}

	for (i = 0; i < size; i++)
	{
		for (j=0;j<size;j++)
		{
			if (key1[i]==key1[j] && i!=j)
			{
				for (y=j;y<strlen(key1);y++)
				{
					key1[y]=key1[y+1];
				}
			}
		}
	}


	size=strlen(key1);
 	size1=size;				
 	for(A = 0; A < 25; A++){
 		if (size>0)
 		{
	 		if (islower(key1[k]))
	 		{
	 			pole[r][s]=toupper(key1[k]);
	 		}
	 		else{
	 			pole[r][s]=key1[k];
	 		}
 		}
 		else{	
 			while(question!=1){								
 				for (z = 0; z<size1; z++)
 				{
 					if (abc[znak]==toupper(key1[z]))
 					{
 						question=2;				
 					}
 				}
 				if (question==2)
 				{
 					znak=znak+1;
 					question=0;
 				}
 				else{
 					pole[r][s]=abc[znak];
 					znak=y=znak+1;
 					question=1;
 				}
 			}											
 		}
 		question=0;
 		s=s+1;
 		k=k+1;
 		size=size-1;
 		
 		
 		if (s>4)
 		{
 			r=r+1;
 			s=0;
 			
 		}
 	}								
 	
 	strcpy(veta,text);
 	

 	for (i=0;i<strlen(text);i++)
 	{	
 		if (veta[i]==' ')
 		{
 			for (y = i; y <strlen(text); y++)
 			{
 				veta[y]=veta[y+1];
 			}
 			y=y+1;
 			veta[y]='\0';
 		}

 		if (tolower(veta[i]))
 		{
 			veta[i]=toupper(veta[i]);
 		}
 	}
 	veta[i+1]='\0';
 	i=0;
 	while(veta[i]!='\0'){
 		if(veta[i]=='X'){
 			i++;
 		}
 		else{
 			if (veta[i]==veta[i+1])
 			{
 				
 				for (z=strlen(veta);i<z;z--)
 				{
 					veta[z]=veta[z-1];
 				}
 				veta[i+1]='X';
 				veta[(strlen(veta)+1)]='\0';
 				i=i+1;
 			}
 		}
 			i=i+1;
 	}

 	if (strlen(veta)%2!=0)
 	{
 		veta[i]='X';
 	}
 	veta[(strlen(veta)+1)]='\0';

 	i=0;
 	while(veta[i]!='\0'){
 		if (veta[i]<='A')
 		{
 			if (veta[i]>='Z')
	 		{
	 			veta[i]='\0';
	 		}
 		}
 		i=i+1;
 	}
 	
 	
 	velkost=strlen(veta)+(strlen(veta)/2)+1;
 	char *vysledok=(char*)calloc(velkost,sizeof(char));

 	A=0;
 	i=0;
 	j=1;
 	
 	
 	while(veta[i]!='\0')	
 	{
 		if (i!=0)
	 	{
	 		vysledok[A]=' ';
	 		A++;
	 	}

	 	for (x=0;x<5;x++)
	 	{
	 		for (y=0;y<5;y++)
	 		{
	 			if (veta[i]=='W')
	 			{
	 				veta[i]='V';
	 			}
	 			if (veta[j]=='W')
	 			{
	 				veta[j]='V';
	 			}
	 			
 				if (veta[i]==pole[x][y])
	 			{
	 				a=x;
	 				b=y;
	 			}
	 			if (veta[j]==pole[x][y])
	 			{
	 				c=x;
	 				d=y;
	 			}
	 			
	 			
	 		}
	 	}

	 	if (d==b)
	 		{
		 		a=a+1;
		 		c=c+1;
		 		if (c==5)
		 		{
		 			c=0;
		 		}
		 		if(a==5)
		 		{
		 			a=0;
		 		}
		 		
	 		}
	 	else{

	 		if (c==a)
		 	{
		 		b=b+1;
		 		d=d+1;
		 		if (d==5)
		 		{
		 			d=0;
		 		}
		 		if(b==5)
		 		{
		 			b=0;
		 		}
		 		
		 	}
	 		else{
	 			help=b;
	 			b=d;
	 			d=help;
	 		}
	 	}
	 	vysledok[A]=pole[a][b];
	 	A=A+1;
	 	vysledok[A]=pole[c][d];
	 	A=A+1;

	 	j=j+2;
	 	i=i+2;
	 	
 	}
 	vysledok[A]='\0';

 	return vysledok;
 }
