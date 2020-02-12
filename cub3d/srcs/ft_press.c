/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:47:16 by corozco           #+#    #+#             */
/*   Updated: 2020/02/09 15:53:00 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_exit(void)
{
	exit(0);
	return (0);
}

static int		key_press(int key, t_data *d)
{
	if (key == 13)
		if (d->move.up == 0)
			d->move.up = 1;
	if (key == 1)
		if (d->move.down == 0)
			d->move.down = 1;
	if (key == 0)
		if (d->move.left == 0)
			d->move.left = 1;
	if (key == 2)
		if (d->move.right == 0)
			d->move.right = 1;
	if (key == 12)
		if (d->move.qleft == 0)
			d->move.qleft = 1;
	if (key == 14)
		if (d->move.eright == 0)
			d->move.eright = 1;
	if (key == 257)
		d->sp = 0.15;
	if (key == 49)
		if (d->pl.mobile == 0)
			d->pl.mobile = 1;
	return (0);
}

static int		key_release(int key, t_data *d)
{
	if (key == 13)
		d->move.up = 0;
	if (key == 1)
		d->move.down = 0;
	if (key == 0)
		d->move.left = 0;
	if (key == 2)
		d->move.right = 0;
	if (key == 12)
		d->move.qleft = 0;
	if (key == 14)
		d->move.eright = 0;
	if (key == 53)
		exit(0);
	if (key == 257)
		d->sp = 0.07;
	if (key == 49)
		d->pl.mobile = 0;
	return (0);
}

void			ft_press(t_data *d)
{
	mlx_hook(d->win_ptr, 2, 1L << 0, key_press, d);
	mlx_hook(d->win_ptr, 3, 1L << 0, key_release, d);
	mlx_hook(d->win_ptr, 17, 1L << 17, ft_exit, d);
}