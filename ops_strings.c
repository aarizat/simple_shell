/**
 * _strlen - Calculate the lenght of a string
 * @s: string
 *
 * Return: lenght of the s string
 */
int _strlen(char *s)
{
	int count = 0;

	for (; s[count]; count++)
	{}
	return (count);
}
/**
 *_strcmp - Compare two string
 * @s1: First string
 * @s2: Second String
 *
 * Return: Integer number.
 */
int _strcmp(char *s1, char *s2)
{
	char *r = s1, char *l = s2;
	int res = 0;

	for (; *r || *l; r++, l++)
	{
		res = *r - *l;
		if (res != 0)
			return (res);
	}
	return (res);
}
/**
 * *_strcpy - Redirections with strings.
 * @dest: the variable contains s1.
 * @src: The variable contains the string.
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int c, length;

	length = _strlen(src) + 1;
	for (c = 0; c < length && src[c] != '\0'; c++)
		dest[c] = src[c];
	if (c < length)
		dest[c] = '\0';
	return (dest);
}
