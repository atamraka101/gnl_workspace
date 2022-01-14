#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_join(char **list, char **output);

int main()
{
	char **list = ((char*[6]){"split", "this", "for", "me", "!", NULL});
	char **output = NULL;
	output = (char **) malloc(sizeof(char *));

	ft_join(list, output);
	printf("output: %s\n", *output);
	if(output) {
		free(*output);
		free(output);
	}

}

int ft_join(char **list, char **output)
{
	if (!list)
		return (0);

	int i = 0;
	char *hold = NULL;
	char *prevHold = NULL;
	int l = 0;
	int xl = 0;

	while(list[i])
	{

		l = strlen(list[i]);

		if (prevHold)
			xl = strlen(prevHold);
		hold = (char *) malloc(sizeof(char) * (l + xl + 1));

		if (prevHold)
			strcat(hold, prevHold);
		printf("1. hold: %s\n", hold);
		strcat(hold, list[i]);
		printf("2. hold: %s\n", hold);

		if (prevHold)
			free(prevHold);
		prevHold = hold;
		i++;
	}
	*output = prevHold;
	//printf("OutPut in : %s\n", *output);
	return (1);
}
