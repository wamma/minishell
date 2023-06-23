/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:21:50 by seocha            #+#    #+#             */
/*   Updated: 2023/06/23 17:26:38 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static int	ft_cnt_split_s(const char *str)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			cnt ++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
	}
	return (cnt);
}

static char	*ft_arr_s(const char *str)
{
	int		cnt;
	char	*word;

	cnt = 0;
	while (str[cnt] && !is_space(str[cnt]))
		cnt++;
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

void	free_split_s(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split_space(char const *s)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_cnt_split_s(s) + 1));
	if (!s || !arr)
		return (NULL);
	while (*s)
	{
		while (*s && is_space(*s))
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_arr_s(s);
		if (arr[i] == NULL)
		{
			free_split_s(arr, i);
			return (NULL);
		}
		i++;
		while (*s && !is_space(*s))
			s++;
	}
	arr[i] = 0;
	return (arr);
}
