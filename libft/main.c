#include <stdio.h>
#include "libft.h"

int	main(void)
{
	// calloc

	int idx, * ptr, sum = 0;
    ptr = ft_calloc(10, sizeof(int));
    if (ptr == NULL) {
        printf("calloc Error! memory not allocated.");
        exit(0);
    }
    printf("calloc Building and calculating the sequence sum of the first 10 terms\n");
    for (idx = 0; idx < 10; ++idx) 
	{ 	* (ptr + idx) = idx;
        sum += * (ptr + idx);
    }
    printf("calloc: Sum = %d\n", sum);
    free(ptr);



	// strdup

	char 			source[] = "strdup: string dupliccated\n";
    char			*dest = ft_strdup(source);

    printf("%s", dest);
	free(dest);


	// substr

	char 			strtosub[] = "das ist der Substr String";
	unsigned int 	start = 12;
	size_t 			len = 13;
	char 			*substr;

	substr = ft_substr(strtosub, start, len);
	printf("substr: %s \n", substr);
	free(substr);



	// strjoin

	char			Anfang[] = "Der Anfang";
	char			Ende[] = ", das Ende.";
	char			*strjoin;

	strjoin = ft_strjoin(Anfang, Ende);
	printf("strjoin: %s\n", strjoin);
	free(strjoin);



	// strtrim
	char			strtrims1[] = "123456789123";
	char			strtrimset[] = "123";
	char			*trimmed;

	trimmed = ft_strtrim(strtrims1, strtrimset);

	printf("strtrim: %s\n", trimmed);
	free(trimmed);



	// split
	char	*s = "split  ||this|for|me|||||!|";
	int		i = 0;
	char	**result = ft_split(s, '|');
	// STEFFEN TODO mit dem Anzeigen des Array funktioniert das freigeben nicht mehr? Wegen hochzaählen result++ ?
	// while (*result)
	// {
	// 	printf("split: %s\n", *result);
	// 	result++;
	// }
	while (result[i]) {
		free(result[i]);
		i++;
	}
	free(result);



	// itoa
	char			*itoa;

	itoa = ft_itoa(-28);
	printf("itoa: %s\n", itoa);
	free(itoa);




	// // strmapi
	char f(unsigned int i, char c)
	{
		char str10;
		str10 = c + 1;
		return (str10);
		i++;
	}

	char *str8 = "abc";
	char *str9;
	str9 = ft_strmapi(str8, *f);
	printf("strmapi: %s\n", str9);
	free(str9);

	return (0);
}

