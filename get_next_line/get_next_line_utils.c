#include "get_next_line.h"

/* Function computes the length of the string 'str' */
size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}


/* The function copies 'n' bytes from memory area 'src' to memory area 'dst'. */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/* Function copies up to (dstsize - 1) characters from the string 'src' to
'dst', NUL-terminating the result if dstsize is not 0. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!src || !dst)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= srclen)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, srclen);
		dst[srclen] = '\0';
	}
	return (srclen);
}

/* Function writes 'len' bytes of value 'c' to the string 'b'. */
void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
		((unsigned char *)b)[--len] = (unsigned char)c;
	return (b);
}

/* Function to fill memory space with '0's. */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

/* Function allocates space for 'count' objects that are 'size' bytes each and
returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero. */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

/*
Arguments:
s is a pointer to the original string.
start - the character index in the source line from which to start copying.
len is the maximum length to copy.

Return value:
Returns a pointer to the copied substring, or NULL if copying is not
succeeded.

Description:
The function copies a substring from the original string s starting at index
start and length at most len. On success, returns a pointer to the copied
substring.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	src_len;
	char	*dest;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len + 1 || len == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	if ((src_len - start) < len)
		len = src_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (dest);
	ft_strlcpy(dest, (s + start), len + 1);
	return (dest);
}

/* Function allocates memory for a copy of the string 's1', does the copy,
and returns a pointer to it. */
char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup)
		ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

/* Allocates memory and returns a new string, which is the result of the
concatenation of ’s1’ and ’s2’ */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (new_str);
	new_str = (char *)ft_memcpy(new_str, s1, s1_len);
	ft_memcpy((new_str + s1_len), s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}

/* Function locates the first occurrence of 'c' in string 's'.

It returns a pointer to the byte located, or NULL if 'c' does not exist within
'n' bytes. */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == ch)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/* Function locates the first '(char)c' in the string pointed to by 's'.

Terminating `\0' is considered to be part of the string; if 'c' is `\0',
the functions locate the terminating `\0'. */
char	*ft_strchr(const char *s, int c)
{
	size_t	srcsize;

	srcsize = ft_strlen(s);
	return ((char *)ft_memchr(s, c, srcsize + 1));
}
