/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:52:38 by agiraud           #+#    #+#             */
/*   Updated: 2022/07/22 23:28:57 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_msg(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

void	perror_msg(char *str)
{
	perror(str);
	exit (1);
}
