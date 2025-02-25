#include"bmp.h"
#include"playfair.h"

#include<stdio.h>
#include<stdlib.h>


int main()
{
	unsigned char* encrypte;
	// basic test with long text
	encrypte = bit_encrypt("Hello world!");
	for(int i=0; i < 12;i++) {
	    printf("%x ", encrypte[i]);
	    //80 9c 95 95 96 11 bc 96 b9 95 9d 10
	}
	free(encrypte);

	char* key="secreet";
	unsigned char* bmp;
	bmp=bmp_encrypt(key, "Hello word!");
	for (int i = 0; i < 12; i++)
	{
		printf("%x", bmp[i]);
	}
	printf("\n");
	char* bmpp;
	bmpp=bmp_decrypt(key,bmp);
	for (int i = 0; i < 12; i++)
	{
		printf("%c", bmpp[i]);
	}
	printf("\n");

	free(bmp);

	char *encrypted, *decrypted;

// even length of string
encrypted = playfair_encrypt("SeCReT", "Hello world");
printf("%s", encrypted);
// "Hello world" --> "HELXLOVORLDX"
// IS JZ JQ XN TK JC
decrypted = playfair_decrypt("SeCReT", encrypted);
printf("%s", decrypted);
// HELXLOVORLDX
free(encrypted);
free(decrypted);

// odd length of string
encrypted = playfair_encrypt("world", "Hello");
printf("%s", encrypted);
// "Hello" --> "HELXLO"
// JB RY DR
decrypted = playfair_decrypt("world", encrypted);
printf("%s", decrypted);
// HELXLO
free(encrypted);
free(decrypted);

// letter 'X' in message
encrypted = playfair_encrypt("Password", "Taxi please");
printf("%s", encrypted);
// "Taxi please" --> "TAXIPLEASE"
// UP YH AK DO OB
decrypted = playfair_decrypt("Password", encrypted);
printf("%s", decrypted);
// TAXIPLEASE
free(encrypted);
free(decrypted);

// multi 'X's in message
encrypted = playfair_encrypt("please", "Taxxxiii");
printf("%s", encrypted);
// "Taxxxiii" --> "TAXXXIIXIX"
// RS EE VJ JV JV
decrypted = playfair_decrypt("please", encrypted);
printf("%s", decrypted);
// TAXXXIIXIX
free(encrypted);
free(decrypted);

	return 0;
}