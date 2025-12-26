/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:41:51 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:05:58 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls.h"

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

void	collision(t_point p, char **map, t_n c, t_n *t)
{
	t->b = c.b && map[((int)p.y / PIXEL) + 1][(int)p.x / PIXEL] == '1';
	t->l = c.l && map[((int)p.y / PIXEL)][((int)p.x / PIXEL) - 1] == '1';
	t->t = c.t && map[((int)p.y / PIXEL) - 1][(int)p.x / PIXEL] == '1';
	t->r = c.r && map[(int)p.y / PIXEL][((int)p.x / PIXEL) + 1] == '1';
	t->tl = c.l && c.t && map[((int)p.y / PIXEL) - 1][((int)p.x / PIXEL)
		- 1] == '1' && !t->l && !t->t;
	t->tr = c.r && c.t && map[((int)p.y / PIXEL) - 1][((int)p.x / PIXEL)
		+ 1] == '1' && !t->r && !t->t;
	t->bl = c.l && c.b && map[((int)p.y / PIXEL) + 1][((int)p.x / PIXEL)
		- 1] == '1' && !t->l && !t->b;
	t->br = c.r && c.b && map[((int)p.y / PIXEL) + 1][((int)p.x / PIXEL)
		+ 1] == '1' && !t->r && !t->b;
}
