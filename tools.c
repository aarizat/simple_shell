#include "functions.h"

/**
 * dir_path - concatenate 'cmd' with all of directories in the enviroment
 * varible PATH.
 * @cmd: command to concatenate.
 *
 * Return: An array of string with all concatenated directories with the cmd.
 */
char **dir_path(char *cmd)
{
	char *path, *token, *sub_dir, **arr_dir;
	int count = 1, i = 0;

	path = _getenv("PATH");
	for (; path[i]; i++)
	{
		if (path[i] == ':')
			count++;
	}
	arr_dir = malloc(sizeof(char *) * (count + 1));
	token = strtok(path, ":");
	for (i = 0; token != NULL; i++)
	{
		sub_dir = malloc(_strlen(token) + _strlen(cmd) + 2);
		_strcpy(sub_dir, token);
		_strcat(sub_dir, "/");
		_strcat(sub_dir, cmd);
		arr_dir[i] = sub_dir;
		token = strtok(NULL, ":");
	}
	free(path);
	arr_dir[count] = NULL;
	return (arr_dir);
}
/**
 * get_commands - takes a string from standard input.
 *
 * Return: An array of characteres which a copy of the string
 *         taken from stdin.
 */
char *get_commands(void)
{
	char *string, *line = NULL;
	size_t len = 0;
	int read;
	unsigned int i;

	write(1, "$ ", 2);
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (0);
	}
	string = malloc(_strlen(line));
	for (i = 0; i < _strlen(line) - 1; i++)
	{
		string[i] = line[i];
	}
	string[i] = '\0';
	free(line);
	return (string);
}
/**
 * _getenv - search a enviroment variable and returns its value.
 * @name: name of the enviroment variable to be searched.
 *
 * Return: pointer to value of the variable.
 */
char *_getenv(const char *name)
{
	int i;
	char *value = NULL;
	env_t *head = NULL;

	for (i = 0; environ[i]; i++)
	{
		add_node_list_env(&head, environ[i]);
	}
	while (head != NULL)
	{
		if (!_strcmp(head->key, name))
			value = _strdup(head->value);
		head = head->next;
	}
	free_list_env(head);
	return (value);
}
