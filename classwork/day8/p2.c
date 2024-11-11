/*

switch(cond)
{
	case 1:
			--
			break;
	case 2:
			--
			break;
	default:
			--
			break;
}
*/

#include <stdio.h>

int main()
{

	char clrCode;

	//clrCode = getc(stdin);

	switch(getc(stdin))
	{
		default:
			printf("\nEnter the correct colour code\n");
			break;

		case 'O':
			printf("Orange");
			break;
		case 'B':
			printf("Black");
			break;
		case 68:
			printf("Black");
			break;
		case 'N':
			printf("Brown");
			break;
		
	}

	printf("\nProgram Ended\n");
	return 0;
}
