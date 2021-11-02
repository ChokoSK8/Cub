/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:43:44 by abrun             #+#    #+#             */
/*   Updated: 2021/10/13 12:53:23 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_matc(char **matc)
{
	int		n;

	n = 0;
	while (matc[n])
	{
		free(matc[n]);
		n++;
	}
	free(matc);
}
