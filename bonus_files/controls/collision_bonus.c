/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:41:51 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls_bonus.h"

void	get_collision(t_n *n, t_point p)
{
	int	tmp;

	n->t = 0;
	n->b = 0;
	n->r = 0;
	n->l = 0;
	tmp = PIXEL - ((int)p.y % PIXEL);
	if (tmp < 25)
		n->b = tmp;
	tmp = (int)p.x % PIXEL;
	if (tmp < 25)
		n->l = tmp;
	tmp = (int)p.y % PIXEL;
	if (tmp < 25)
		n->t = tmp;
	tmp = (PIXEL - ((int)p.x % PIXEL));
	if (tmp < 25)
		n->r = tmp;
	n->tl = n->t && n->l;
	n->tr = n->t && n->r;
	n->bl = n->b && n->l;
	n->br = n->b && n->r;
}

bool	is_block(int c)
{
	int	i;

	i = -1;
	while (CL[++i])
	{
		if (c == CL[i])
			return (true);
	}
	return (false);
}

void	collision(t_point p, char **map, t_n c, t_n *t)
{
	t->b = c.b && is_block(map[((int)p.y / PIXEL) + 1][(int)p.x / PIXEL]);
	t->l = c.l && is_block(map[((int)p.y / PIXEL)][((int)p.x / PIXEL) - 1]);
	t->t = c.t && is_block(map[((int)p.y / PIXEL) - 1][(int)p.x / PIXEL]);
	t->r = c.r && is_block(map[(int)p.y / PIXEL][((int)p.x / PIXEL) + 1]);
	t->tl = c.l && c.t && is_block(map[((int)p.y / PIXEL) - 1] \
	[((int)p.x / PIXEL) - 1]) && !t->l && !t->t;
	t->tr = c.r && c.t && is_block(map[((int)p.y / PIXEL) - 1] \
	[((int)p.x / PIXEL) + 1]) && !t->r && !t->t;
	t->bl = c.l && c.b && is_block(map[((int)p.y / PIXEL) + 1] \
	[((int)p.x / PIXEL) - 1]) && !t->l && !t->b;
	t->br = c.r && c.b && is_block(map[((int)p.y / PIXEL) + 1] \
	[((int)p.x / PIXEL) + 1]) && !t->r && !t->b;
}
