  
#include "fillit.h"

static int	blockletter(char *blockcode, char *buf, char c, int temp[5])
{
	if (buf[(temp[0] + 5 * temp[1])] == '.')
	{
		blockcode[temp[2]] = '.';
		temp[2]++;
		return (1);
	}
	else if (buf[(temp[0] + 5 * temp[1])] == '#')
	{
		blockcode[temp[2]] = c;
		temp[2]++;
		return (1);
	}
	return (-1);
}

static void	checkright(char *blockcode, char *buf, char c, int temp[5])
{
	temp[3] += blockletter(blockcode, buf, c, temp);
	blockcode[temp[2]++] = 'r';
	temp[0]++;
}

static void	checkleft(char *blockcode, char *buf, char c, int temp[5])
{
	temp[3] += blockletter(blockcode, buf, c, temp);
	blockcode[temp[2]++] = 'l';
	temp[0]--;
}

static void	checkdown(char *blockcode, char *buf, char c, int temp[5])
{
	temp[3] += blockletter(blockcode, buf, c, temp);
	blockcode[temp[2]++] = 'd';
	temp[1]++;
}

char		*codeblock(char *bc, char *buf, char c, int code[6])
{
	int		temp[5];

	temp[0] = code[2];
	temp[1] = code[3];
	temp[2] = 0;
	temp[3] = 0;
	temp[4] = code[4] * code[5];
	while (temp[3] < (temp[4] - 1))
	{
		while (temp[0] < code[0] && temp[3] < (temp[4] - 1))
			checkright(bc, buf, c, temp);
		if (temp[1] < code[1] && temp[3] < (temp[4] - 1))
			checkdown(bc, buf, c, temp);
		while (temp[0] > code[2] && temp[3] < (temp[4] - 1))
			checkleft(bc, buf, c, temp);
		if (temp[1] < code[1] && temp[3] < (temp[4] - 1))
			checkdown(bc, buf, c, temp);
	}
	blockletter(bc, buf, c, temp);
	return (bc);
}

