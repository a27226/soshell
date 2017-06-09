#include "shell.h"

char prompt[100];


int main ()
{
  int len;
  char buf[1024];		/* um comando */
  char *args[64];		/* com um maximo de 64 argumentos */

  strcpy (prompt, "SOSHELL: Introduza um comando : prompt>");

  while (1)
    {
      printf ("%s", prompt);

      if ( fgets(buf,1023,stdin) == NULL)
	{
	  printf ("\n");
	  exit (0);
	}
	len=strlen(buf);
	if ( 1==len ) continue;  // string is only a barra n
	if ( buf[len-1] == '\n' ) buf[len-1] ='\0';
	
        parse (buf, args);	/* particiona a string em argumentos */

        if (!builtin (args))
	  execute (args);		/* executa o comando */
    }
  return 0;
}

int builtin (char **args)
{
  if(strcmp (args[0], "mycp") == 0)
  {
	pthread_t th;
	myType * data = (myType *) malloc(sizeof(myType));
	int in = open(args[1], O_RDONLY);
	int out = creat(args[2], S_IWUSR | S_IRUSR);
	int size = 1024;
	if(args[3]!=NULL)
		size=atoi(args[3]);
	pthread_create(&th, NULL, wrapperCopy, (void*)data);
	return 1;
  }
  if (strcmp (args[0], "sair") == 0)
    {
      exit (0);
      return 1;
    }
/*
  if (strcmp (args[0], "qualquercoisa") == 0)
    {
       funcinalidade
       return 1;
    }

   if ( strcmp(args[0],"socp")==0) { socp(..,..) open/creat/read/write ; return 1; }
*/

//devolver 0 indique que não há comnando embutido

  return 0;
}
