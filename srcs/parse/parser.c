#include "lemin.h"

char **parser_file(char **split_file)
{
    char    tmp[FILE_READ_SIZE + 1];
    char    *str;
    char    *str2;
    int     len;

    str = NULL;
    str2 = NULL;
    while ((len = read(0, tmp, FILE_READ_SIZE)) > 0)
    {
        tmp[len] = '\0';
        if (str == NULL)
            str = ft_strdup(tmp);
        else
        {
            str2 = ft_strjoin(str, tmp);
            free(str);
            str = str2;
        }
    }
    if (ft_strstr(str2, "\n\n") != 0)
        exit(0);
    if ((split_file = ft_strsplit(str2, '\n')) == NULL)
        exit (0);
    ft_strdel(&str2);
    return (split_file);
}
