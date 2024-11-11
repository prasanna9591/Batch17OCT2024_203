#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char str1[20],str2[20];

	char d1[40],d2[40];

	char *ptr=NULL;


	scanf("%s%s",str1,str2);
	strcpy(d1,str1);
	printf("\nd1=%s",d1);
	strcat(d1,str2);
	printf("\nd1=%s",d1);
	printf("\n\n");
	return 0;
}
