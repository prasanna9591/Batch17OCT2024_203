#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char str1[40],str2[20];

	char d1[40],d2[40];

	char *ptr=NULL;

	printf("\nEnter the Main String: \n");
	scanf("%s",str1);
	printf("\nEnter the Sub String: ");
	scanf("%s",str2);
	ptr = strstr(str1,str2);
	if(ptr == NULL)
		printf("\nSub String %s not found\n",str2);
	else
	{
		printf("\nBase Address of s1=%u\n",&str1[0]);
		printf("\nSub String Found %s at %u",ptr,&ptr[0]);
	}
	
	printf("\n\n");
	return 0;
}
