/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <vlahorba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:19 by llelias           #+#    #+#             */
/*   Updated: 2019/01/17 22:20:57 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(char *file)
{
	int		dim;
	t_env	*e;

	dim = 0;
	e = c_env(dim, file);
	dim = ft_nsqr(e->nop_m * 4);
	change_dim(e, dim);
	while ((!solve_sh(*e, 0)))
		change_dim(e, e->dim + 1);
	make_map(*e);
	return (0);
}

/*
** Set FLAG to 1 for fillit project.
** If FLAG == 0, fillit will take a second argument either a 1 or 0
** to determine which algorithm to use a 0 for sharris, 1 for llelias
*/

int		main(int argc, char **argv)
{
	char	*file;
	int		flag;

	flag = 1;
	if (flag)
	{
		if (argc != 2)
			usage();
	}
	else if (argc != 3)
		usage();
	file = argv[1];
	return (fillit(file));
}
