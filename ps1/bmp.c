#include"bmp.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


unsigned char* bmp_encrypt(const char* key, const char* text){
	if (text==NULL)
	{
		return NULL;
	}
	if (key==NULL)
	{
		return NULL;
	}
	int i=0;

	for (i = 0; i < strlen(key); ++i)
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

	unsigned char *encrypted=(unsigned char*)calloc(strlen(text)+1, sizeof(char));
	char* otocenie=reverse(text);
	char* sifra=vigenere_encrypt(key,otocenie);
	unsigned char* bity=bit_encrypt(sifra);
	i=0;

	for (i = 0; i < strlen(text); ++i)
	{
		encrypted[i]=bity[i];
	}

	free(otocenie);
	free(sifra);
	free(bity);

	return (unsigned char*)encrypted;
}

char* bmp_decrypt(const char* key, const unsigned char* text){
	if (text==NULL || key==NULL)
	{
		return NULL;
	}

	for (int i = 0; i < strlen(key); ++i)
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

	int i=0;
	while(text[i]!='\0'){
		i=i+1;
	}

	char *decrypted = (char*)calloc(i+1,sizeof(char));
	char* bity= bit_decrypt(text);
	char* sifra=vigenere_decrypt(key,bity);
	char* otocenie=reverse(sifra);
	int j=0;
	for (j = 0; j < i; j++)
	{
		decrypted[j]=otocenie[j];
	}

	free(bity);
	free(sifra);
	free(otocenie);

	return decrypted;
}


char* reverse(const char* text){

		if (text==NULL)
	{
		return NULL;
	}

	int size=0, g=0, i=0;
	size=strlen(text);
	char *pole=(char*)malloc(size+1);

	for(g = size - 1; g >= 0; g--) {
        pole[i]=toupper(text[g]);
        i=i+1;
    }
    pole[i]='\0';
	
    return pole;
}
char* vigenere_encrypt(const char* key, const char* text){
		char abc[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int k=0, i=0, j=0, asci=0;

	if (key==NULL)
	{
		return 0;
	}
	if (text==NULL)
	{
		return 0;
	}
	for (i = 0; i < strlen(key); ++i)
	{
		asci=toupper(key[i]);
		if (asci>90)
		{
			return NULL;
		}
		if (asci>90)
		{
			return NULL;
		}
	}

	char *encrypt = (char*)calloc(strlen(text)+1,sizeof(char));

	i=0;
	while(text[i]!='\0'){
		int asci=0;
		int help=0;
		help=toupper(text[i]);
		asci=help;
		if (asci>64)
		{
			if (asci<91)
			{
				help=toupper(key[k]);
				for(j=0;j<26;j++)
				{
					if (help==abc[j])
					{	
						break;
					}
				}
				k=k+1;
				}
			
		}

	if (asci>64 )
	{
		if(asci<91)
		{
			for (int z=0;j>z;z++)
			{
				asci=asci+1;
				if (asci==91)
				{
					asci=65;
				}
			}
		}
		
	}

	help=asci;
	if (asci>64)
	{
		if (asci<91)
		{
			encrypt[i]=help;
		}
	}
	else{
		encrypt[i]=help;
	}
		i=i+1;
		if (key[k]=='\0')
		{
			k=0;
		}
	}
	encrypt[i]='\0';
	return encrypt;
}

char* vigenere_decrypt(const char* key, const char* text){
	char abc[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int j=0;
	int i=0;
	int k=0;
	if (key==NULL)
	{
		return 0;
	}
	if (text==NULL)
	{
		return 0;
	}
	for (i = 0; i < strlen(key); ++i)
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

	i=0;
	char *decrypt = (char*)calloc(strlen(text)+1, sizeof(char));

	while(text[i]!='\0'){
		int asci=0;
		char help;
		help=toupper(text[i]);
		asci=help;
		if (asci>64 && asci<91)
		{
			help=toupper(key[k]);
			for(j=0;j<26;j++)
			{
				if (help==abc[j])
				{	
					break;
				}
			}
			k=k+1;
		}

	if (asci>64)
	{
		if (asci<91)
		{
			int z=0;
			for (z=j;0<z;z--)
			{
				asci=asci-1;
				if (asci==64)
				{
					asci=90;
				}
			}
		}
		
	}
	help=asci;
	printf("%c",help );
	if (asci>64 && asci<91)
	{
		if(i!=0){
			decrypt[i]=tolower(help);
		}
		else{
			decrypt[i]=help;
		}
		
	}
	else{

		decrypt[i]=tolower(help);
	
	}

		i=i+1;
		if (key[k]=='\0')
		{
			k=0;
		}
		
	}
	printf("\n");
	decrypt[i]='\0';
	return decrypt;
}

unsigned char* bit_encrypt(const char* text){
	if (text == NULL)
	{
		return NULL;
	}

	int pismeno=0;
	char *pole=(char*)calloc(strlen(text)+1, sizeof(char));

	while(text[pismeno]!='\0'){
	int asci=0, help=0, i=0,jeden[4],dva[4], x=0, j=0;
	int bit[8]={0,0,0,0,0,0,0,0};

	asci=text[pismeno];
	i=7;
	while(asci!=0){					
		if (asci%2!=0)
		{
			asci=asci-1;
			bit[i]=1;
		}
		asci=asci/2;
		i=i-1;
	}

	jeden[3]=bit[3];	
	jeden[2]=bit[2];
	jeden[1]=bit[1];
	jeden[0]=bit[0]; 

	dva[3]=bit[7];
	dva[2]=bit[6];
	dva[1]=bit[5];
	dva[0]=bit[4];         

	help=jeden[0];
	jeden[0]=jeden[1];	
	jeden[1]=help;			
	help=jeden[2];	
	jeden[2]=jeden[3];	
	jeden[3]=help; 

	for (i=0;i<4;i++)			
	{
		if (jeden[i]==1)
		{
			if (dva[i]==0)
			{
				dva[i]=1;
				continue;
			}
			if (dva[i]==1)		
			{
				dva[i]=0;
			}
		}
	}

	bit[3]=jeden[3];
	bit[2]=jeden[2];
	bit[1]=jeden[1];
	bit[0]=jeden[0]; 
	bit[7]=dva[3];
	bit[6]=dva[2];
	bit[5]=dva[1];				
	bit[4]=dva[0];         

	
	for ( j = 0; j < 8; j++)
	{	
		x=(x*2)+bit[j];
	}
	   	pole[pismeno]=x;
	   	pismeno++;
	}
	return (unsigned char*)pole;
}


char* bit_decrypt(const unsigned char* text){
	if (text == NULL)
	{
		return NULL;
	}

	int i=0,size=0, pismeno=0, j=0, decimal_size=0, x=0;
	while(text[i]!='\0'){
		i=i+1;
	}
	size=i;
	
	char *pole=(char*)calloc(i+1, sizeof(char));

	while(size!=pismeno){	
	int asci = (int)text[pismeno];
	int bit[8]={0,0,0,0,0,0,0,0};
	int jeden[4],dva[4], help=0;
	
	i=7;
	while(asci!=0){			
		if (asci%2!=0)
		{
			asci=asci-1;
			bit[i]=1;
		}
		asci=asci/2;
		i=i-1;
	}

	jeden[3]=bit[3];
	jeden[2]=bit[2];
	jeden[1]=bit[1];
	jeden[0]=bit[0];
	dva[3]=bit[7];
	dva[2]=bit[6];
	dva[1]=bit[5];   		
	dva[0]=bit[4];         
		for (i=0;i<4;i++)			
	{
		if (jeden[i]==1)
		{
			if (dva[i]==0)
			{
				dva[i]=1;
				continue;
			}
			if (dva[i]==1)		
			{
				dva[i]=0;
			}
		}
	}

	help=jeden[0];	
	jeden[0]=jeden[1];	
	jeden[1]=help;			
	help=jeden[2];	
	jeden[2]=jeden[3];	
	jeden[3]=help; 

	bit[3]=jeden[3];
	bit[2]=jeden[2];
	bit[1]=jeden[1];	
	bit[0]=jeden[0]; 
	bit[7]=dva[3];
	bit[6]=dva[2];
	bit[5]=dva[1];			
	bit[4]=dva[0];         

	decimal_size=0, x=0;

	for (j = 0; j < 8; j++)
	{
		
		x=(x*2)+bit[j];
	}
	   	decimal_size=x;
	   	help=decimal_size;
	   	pole[pismeno]=help;
	   	pismeno++;
	}

	return pole;
}

