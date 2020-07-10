#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char table[][26] = {

{'M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A',},
{'B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M',},
{'C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B',},
{'D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C',},
{'F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D',},
{'E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F',},
{'G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E',},
{'H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G',},
{'K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H',},
{'J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K',},
{'I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J',},
{'S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I',},
{'Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S',},
{'N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z',},
{'O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N',},
{'P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O',},
{'Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P',},
{'R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q',},
{'L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R',},
{'T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L',},
{'U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T',},
{'X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U',},
{'W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X',},
{'V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W',},
{'Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V',},
{'A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y',},

};
//Encrypt
void encrypt(char inputtext[21],char newKey[21])
{
	char outputPh1[21],g1[21],g2[21],ciphertext[21];
	int x,y,i,a=0,b=0;
	printf("Encryption Phase-1\n");
	printf("PlainText: %s\n",inputtext);
	printf("Key: %s\n",newKey);
	for(i=0;i<strlen(inputtext);i++)
	{
		y=inputtext[i]-65;
		x=newKey[i]-65;
		outputPh1[i]=table[x][y];
	}
	outputPh1[i] = '\0';
	printf("Output (phase-1): %s\n",outputPh1);
	printf("\nEncryption Phase-2\n");
	printf("Inputtext: %s\n",outputPh1);
	for(i=0;i<strlen(outputPh1)/2;i++)
				g1[i]=outputPh1[i];
	g1[i] = '\0';
	for(i;i<strlen(outputPh1);i++)
				g2[i-strlen(outputPh1)/2]=outputPh1[i];
	g2[i] = '\0';
		printf("group-1: %s\n",g1);
		printf("group-2: %s\n",g2);
			for(i=0;i<strlen(outputPh1);i++)
	{
		if(i%2==0)
			{
				ciphertext[i]=g1[a];
				a++;
			}
		else
			{
				ciphertext[i]=g2[b];
				b++;
			}
		}
				ciphertext[i]='\0';
		printf("Ciphertext: %s\n",ciphertext);

}
//Decrypt 
void decrypt (char inputtext[21],char newKey[21])
{
	int a=0,b=0,i,x,y;
	char g1[21],g2[21],outputPh2[21],plaintext[21];
	for(i=0;i<strlen(inputtext);i++)
	{
		if(i%2==0)
			{
				g1[a]=inputtext[i];
				a++;
			}
		else
			{
				g2[b]=inputtext[i];
				b++;
			}
		}
	g1[a] = '\0';
	g2[b] = '\0';
	printf("group-1: %s\n",g1);
	printf("group-2: %s\n",g2);
	a=0;
	b=0;
	for(i=0;i<strlen(inputtext)/2;i++)
				outputPh2[i]=g1[i];
				
	for(i=strlen(inputtext)/2;i<strlen(inputtext);i++)
				outputPh2[i]=g2[i-strlen(inputtext)/2];

		outputPh2[i]='\0';
		printf("Output (Phase-2): %s\n",outputPh2);	
		printf("\nDecryption Phase-1\n");
		printf("Inputtext: %s\n",outputPh2);
		printf("Key: %s\n",newKey);
		for(a=0;a<strlen(outputPh2);a++)
		{
			x=newKey[a]-65;
			for(i=0;i<26;i++)
				{
					if(table[x][i]==outputPh2[a])
						plaintext[a]=i+65;
				}	
		}
		plaintext[a] = '\0';
		printf("Plaintext: %s\n",plaintext);
		
	
}

// MainMenu
void main()
{

	int selection,textLen,a=0,b=0,x,y;
	char temp,plaintext[21],key[21],inputtext[21],newKey[21],decrytext[21];
	do
	{
		//MainMenu
		printf("Simple Cipher:\n");
		printf("[1]Encrypt\n");
		printf("[2]Decrypt\n");
		printf("[3]Exit\n");
		printf("Selection  ");
		scanf("%d",&selection);
		printf("\n");
		switch (selection)
		{
			case 1:
				//Scaning key and text
				printf("Enter key:"  );
				scanf("%s",&key);
				getchar();
				printf("Enter text:  ");
				scanf("%[^\n]",plaintext);
				getchar();
				//Triming the spaces
				for(a=0;a<strlen(plaintext);a++)
					{
						if(plaintext[a]!=' ')
							inputtext[b++]=plaintext[a];
					}
   					inputtext[b] = '\0';
   				//Resizing the key if needed
   				if (strlen(inputtext)==strlen(key))
   					strcpy(newKey,key);
   				else if (strlen(inputtext)>strlen(key))
   				{
   					strcpy(newKey,key);
   					b=0;
   					for(a=strlen(key);a<strlen(inputtext);a++)
   					{
   						newKey[a]=key[b++];
   						if(b==strlen(key))
   							b=0;
					   }
				   }
				else 
				{
					for(a=0;a<strlen(inputtext);a++)
						newKey[a]=key[a];
				}
				//Converting to uppercase if needed
				for(a=0;a<strlen(inputtext);a++)
				{
					inputtext[a]=toupper(inputtext[a]);
					newKey[a]=toupper(newKey[a]);
				}
				printf("\n********************** Encryption **********************\n");
				encrypt(inputtext,newKey);
				printf("********************************************************\n");

				break;

			case 2:

				//Scaning key and text
				printf("Enter key:"  );
				scanf("%s",&key);
				getchar();
				printf("Inputtext:  ");
				scanf("%[^\n]",decrytext);
				getchar();
				//Resizing the key if needed
				if (strlen(decrytext)==strlen(key))
   					strcpy(newKey,key);
   				else if (strlen(decrytext)>strlen(key))
   				{
   					strcpy(newKey,key);
   					b=0;
   					for(a=strlen(key);a<strlen(decrytext);a++)
   					{
   						newKey[a]=key[b++];
   						if(b==strlen(key))
   							b=0;
					   }
				   }
				else 
				{
					for(a=0;a<strlen(decrytext);a++)
						newKey[a]=key[a];
				}
				//Converting to uppercase if needed
				for(a=0;a<strlen(decrytext);a++)
				{
					decrytext[a]=toupper(decrytext[a]);
					newKey[a]=toupper(newKey[a]);
				}
				printf("\n********************** Decryption **********************\n");
				printf("Decryption Phase-2\n");
				decrypt(decrytext,newKey);	
				printf("********************************************************\n");
				break;
			case 3:
				printf("Goodbye :)\n");
				break;
			default:
				printf("Wrong input!!\n");
				break;
		}

	}
	while(selection!=3);
}
