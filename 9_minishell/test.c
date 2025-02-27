# include <stdio.h> 
#include <stdbool.h> 		//bool



bool char_is_quoted(const char *str, char character) 
{
    bool in_single_quote;
    bool in_double_quote;

    in_single_quote = false;
    in_double_quote = false;
    
    if (!str)
        return false;

    while (*str)
    {
        if (*str == '\'')
            in_single_quote = !in_single_quote && !in_double_quote;
        else if (*str == '"')
            in_double_quote = !in_double_quote && !in_single_quote;

        if (*str == character && (in_single_quote || in_double_quote))
            return true;

        str++; // Moverse al siguiente carácter
    }

    return false;
}


bool not_allow_metacharacter(const char *line)
{
    char metachar[6];
    int i;
    
    metachar[0] = ';';
    metachar[1] = '\t';
    metachar[2] = '&';
    metachar[3] = '(';
    metachar[4] = ')';
	metachar[5] = '\n';
    
	if (!line)
		return (false);

	const char *ptr = line;

	while (*ptr) 
	{
		i = 0;
		while (i < 6) 
		{
			if (*ptr == metachar[i] && !char_is_quoted(line, *ptr))
            {
                printf("\033[0;34m ⚠️ INFO: estamos en: not_allow_metacharacter.\033[0m\n");
                return false; // Metacaracter sin comillas encontrado
            }
			i++;
		}
		ptr++;
	}
	return (true); // No se encontraron metacaracteres prohibidos sin comillas
}

//cc -Wall -Werror -Wextra test.c -o test
//char_is_quoted(const char *str, char character) 
int main (void)
{
	//char line[] = "echo \";hola\" ";
	//char line[] = "echo \"Comando; 1\"; echo \"Comando 2\"";
	char line[] ="echo \"Comando 1\"; echo \"Comando 2\"";
	//char line[] = "He said: 'Hello!'\";\"  ;        				hola unicorniuo54d98fvsdgf  sdgf";

	if ( not_allow_metacharacter(line) == false)
		printf ("retorna sintax error\n");
	else 
		printf("sigue\n");

	return (0);
}