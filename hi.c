#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_env(char **envp) 
{
    int i = 0;
    while (envp[i] != NULL) 
	{
        printf("%s\n", envp[i]);
        i++;
    }
}

void set_env_var(char **envp, char *name, char *value) 
{
    char *env_var = malloc(strlen(name) + strlen(value) + 2);
    sprintf(env_var, "%s=%s", name, value);

    int i = 0;
    while (envp[i] != NULL) 
	{
        if (strncmp(envp[i], name, strlen(name)) == 0 && envp[i][strlen(name)] == '=') 
		{
            // Update existing environment variable
            free(envp[i]);
            envp[i] = env_var;
            return;
        }
        i++;
    }

    // Add new environment variable
    envp[i] = env_var;
    envp[i + 1] = NULL;
}

int main(int argc, char **argv, char **envp) 
{
    if (argc >= 2) 
	{
        if (strcmp(argv[1], "export") == 0) 
		{
            if (argc >= 3) 
			{
                char *name = strtok(argv[2], "=");
                char *value = strtok(NULL, "=");
                if (name != NULL && value != NULL) 
				{
                    set_env_var(envp, name, value);
                }
				else
				{
                    printf("Invalid syntax: export NAME=VALUE\n");
                }
            }
			else
			{
                print_env(envp);
            }
        } 
		else 
		{
            printf("Command not supported: %s\n", argv[1]);
        }
    }
	else 
	{
        printf("Usage: ./minishell export [NAME=VALUE]\n");
    }

    return 0;
}
