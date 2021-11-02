/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:54:31 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 12:17:06 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_resolution(t_param *param, char *line)
{
	if (param->checks[4])
	{
		ft_putstr_fd("Error\nIl y a 2 fois la resolution !\n", 2);
		return (0);
	}
	if (!(check_resolution('R', line)))
		return (0);
	while (!(ft_isdigit(*line)))
		line++;
	if (!fill_w_h(param, line, 'w'))
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	if (!fill_w_h(param, line, 'h'))
		return (0);
	if (param->width <= 0 || param->height <= 0)
	{
		ft_putstr_fd("Error\nProbleme sur la resolution\n", 2);
		return (0);
	}
	return (5);
}

int	fill_w_h(t_param *param, char *line, int id)
{
	int	n;

	n = get_n(line);
	if (n == -1)
		return (0);
	if (id == 'w')
	{
		if (n > param->max_w)
			param->width = param->max_w * 9 / 10;
		else
			param->width = n;
	}
	else
	{
		if (n > param->max_h)
			param->height = param->max_h * 9 / 10;
		else
			param->height = n;
	}
	return (1);
}

int	get_n(char *line)
{
	char	*num;
	int		c;
	int		n;
	int		n_len;

	c = 0;
	n_len = 0;
	while (ft_isdigit(line[n_len]))
		n_len++;
	if (n_len > 10 || (n_len == 10 && ft_strncmp("2147483647", line, 10) < 0))
		return (0);
	num = malloc(n_len + 1);
	if (!num)
	{
		ft_putstr_fd("Error\nUn malloc a echoue\n", 2);
		return (-1);
	}
	while (ft_isdigit(*line) && c < n_len)
		num[c++] = *line++;
	num[c] = 0;
	n = ft_atoi(num);
	free(num);
	return (n);
}
