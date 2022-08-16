/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:59:18 by ygunay            #+#    #+#             */
/*   Updated: 2022/08/16 14:32:01 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*ret;
	int		fd;
	size_t	i;

	fd = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	i = 0;
	while (i < 20)
	{
		ret = get_next_line(fd);
		printf("str is %s\n", ret);
		free(ret);
		++i;
	}
	close(fd);
	return (0);
}
