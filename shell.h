#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

typedef struct
{
	int in, out, size;
} myType;

void parse(char *buf, char **args);

void execute(char **args);

int builtin (char **args);

void lowlevelcopy(int in, int out, int size);

void *wrapperCopy(void *args);
/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
