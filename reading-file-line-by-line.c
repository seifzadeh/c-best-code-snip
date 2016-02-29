#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int read_line_by_line(char *filepath)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;


	if ( access( filepath, F_OK ) == -1)
	{
		printf("file not found\n");
	}

	fp = fopen(filepath, "r");
	if (fp == NULL) {
		printf("cannot open the file\n");
	}

	char *co, *cpo, *token = 0;

	while ((read = getline(&line, &len, fp)) != -1) {
		if (strlen(line) > 0)
		{
			co = cpo = strdup(line);
			token = strtok(co, "=");
			while ( token ) {

				printf("%s\n", token );
				token = strtok(NULL, "=");
			}

			free(cpo);
		}
	}

	fclose(fp);
	if (line)
		free(line);

}

int main(int argc, char const *argv[])
{
	read_line_by_line("file.ini");
	return 0;
}
