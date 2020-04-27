/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:14:47 by amartino          #+#    #+#             */
/*   Updated: 2020/04/27 21:11:19 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t		get_nb_of_move(void)
{
	char		*line;
	ssize_t		nb_of_move;
	ssize_t		ret;
	ssize_t		fd;

	nb_of_move = 0;
	fd = open("result/tmp.txt", O_RDWR);
	if (fd != FAILURE)
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			nb_of_move++;
			ft_strdel(&line);
		}
	}
	if (fd == FAILURE || ret == FAILURE)
		nb_of_move = FAILURE;
	close(fd);
	ft_strdel(&line);
	return (nb_of_move);
}

ssize_t		collision_in_filename(t_vector *name, int8_t suffixe)
{
	ssize_t		fd;

	fd = FAILURE;
	vct_addstr(name, "_");
	if (vct_addnb(name, suffixe) == SUCCESS)
	{
	fd = open(vct_getstr(name), O_RDWR | O_CREAT | O_EXCL, 0744);
	if (fd == FAILURE)
	{
		vct_pop(name, (1 + ft_int64_t_len((int64_t)suffixe, 10)));
		suffixe++;
		fd = collision_in_filename(name, suffixe);
	}
	}
	return (fd);
}

void		write_final_result(ssize_t fd)
{
	char		*line;
	ssize_t		ret;
	ssize_t		fd_tmp;

	fd_tmp = open("result/tmp.txt", O_RDWR);
	if (fd_tmp != FAILURE)
	{
		while ((ret = get_next_line(fd_tmp, &line)) > 0)
		{
			ft_dprintf(fd, "%s\n", line);
			ft_strdel(&line);
		}
	}
	close(fd_tmp);
	ft_strdel(&line);
}

ssize_t		write_in_std_out(void)
{
	char		*line;
	ssize_t		ret;
	ssize_t		read_limit;
	ssize_t		fd_tmp;

	fd_tmp = open("result/tmp.txt", O_RDWR);
	ret = FAILURE;
	read_limit = 0;
	if (fd_tmp != FAILURE)
	{
		while ((ret = get_next_line(fd_tmp, &line)) > 0
				&& read_limit < READ_LIMIT)
		{
			if ((ret = ft_dprintf(STD_OUT, "%s\n", line)) == FAILURE)
				break ;
			ft_strdel(&line);
			read_limit++;
		}
		if (read_limit == READ_LIMIT)
			ret = FAILURE;
	}
	close(fd_tmp);
	ft_strdel(&line);
	return (ret);
}

void		save_final_result_in_file(t_stack *s)
{
	t_vector	*name;
	ssize_t		fd;

	name = vct_newstr("result/");
	vct_addnb(name, (s->size_a + s->size_b));
	vct_addstr(name, "_nb_in_");
	vct_addnb(name, (int64_t)get_nb_of_move());
	vct_addstr(name, "_moves");
	fd = open(vct_getstr(name), O_RDWR | O_CREAT | O_EXCL, 0744);
	if (fd == FAILURE)
		fd = collision_in_filename(name, 1);
	write_final_result(fd);
	close(fd);
	vct_del(&name);
}
