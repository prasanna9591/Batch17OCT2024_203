#include <stdio.h>


int main()
{
	char Name[5];
	int iter;
	for(iter=0;iter<20;iter++)
		scanf("%c",&Name[iter]);

	Name[5-1] ='\0';

	for(iter=0;iter<20;iter++)
		printf("\n%c=%d",Name[iter],Name[iter]);
	
	printf("\n\n");

	printf("\n%s\n",Name);
	puts(Name);
	printf("\n\n");
	return 0;
}
