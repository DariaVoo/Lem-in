#include "lemin.h"

char **parser_file(char **spl)
{
    char    tmp[FILE_READ_SIZE + 1];
    char    *str;
    char    *str2;
    int     len;

    str_init(&str, &str2);
    while ((len = read(0, tmp, FILE_READ_SIZE)) > 0)
    {
        tmp[len] = '\0';
        if (str == NULL)
        {
            str = ft_strdup(tmp);
            if (len < FILE_READ_SIZE)
            {
                str2 = ft_strdup(str);
                free(str);
            }
        }
        else
        {
            str2 = ft_strjoin(str, tmp);
            free(str);
            str = str2;
        }
    }
    if (ft_strstr(str2, "\n\n") != 0 || (spl = ft_strsplit(str2, '\n')) == NULL)
        ft_exit("Wrong MAP\n");
    ft_strdel(&str2);
    return (spl);
}
