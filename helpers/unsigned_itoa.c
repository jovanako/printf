#include "libftprintf.h"

static size_t	calculate_int_length(unsigned int n)
{
	size_t	int_len;

	int_len = 0;
	if (n == 0)
		int_len = 1;
	while (n > 0)
	{
		n /= 10;
		int_len++;
	}
	return (int_len);
}

static char	*generate_string(char *result, unsigned int n, size_t int_len)
{
	while (int_len && n)
	{
		result[int_len] = (n % 10) + '0';
		n /= 10;
        int_len--;
	}
	return (result);
}

int		unsigned_itoa(int n)
{
	size_t	int_len;
    int     count;
	char	*result;

    n = (unsigned int)n;
	int_len = calculate_int_length(n);
	result = (char *)malloc(int_len * (sizeof(char) + 1));
	if (!result)
		return (0);
	result[int_len] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		count =  write_str(result);
        return (count);
	}
	result = generate_string(result, n, int_len - 1);
    count = write_str(result);
	return (count);
}