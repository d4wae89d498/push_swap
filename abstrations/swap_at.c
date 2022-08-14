#include "solver.h"

t_instruction	swap_at(t_stack *s, int x, int y, int vx, int vy)
{
	if (!s->size || x == y || s->size == 1)
		return (0);
	if (s->data[x] == vy && s->data[y] == vx)
		return (0);
	if (x > y)
	{
		if (s->size - x < y)
		{
			printf("rotate to top until x\n");
			if (x - y < s->size / 2)
			{
				printf("swp until y to bottom\n");
				if (s->data[s->size - 1] == vx)
					return sa;
				else if (s->data[s->size - 2] == vx)
					return ra;
				else if (s->data[s->size - 1] == vy)
					return rra;
				else if (s->data[s->size - 2] == vy)
					return sa;
				else
					return ra;
			}
			else
			{
				printf("swp until y to top\n");
				if (s->data[s->size - 2] == vx)
					return sa;
				else if (s->data[s->size - 1] == vx)
					return rra;
				else if (s->data[s->size - 1] == vy)
					return ra;
				else if (s->data[s->size - 2] == vy)
					return sa;
				else
					return ra;
			}
		}
		else
		{
			printf("rotate to bottom until y\n");
			if (x - y < s->size / 2)
			{
				printf("swap until x to bottom\n");
				if (s->data[s->size - 1] == vy)
					return sa;
				else if (s->data[s->size - 2] == vy)
					return ra;
				else if (s->data[s->size - 1] == vx)
					return rra;
				else if (s->data[s->size - 2] == vx)
					return sa;

				else
					return ra;
			}
			else
			{
				printf("swap until x to top\n");
				if (s->data[s->size - 2] == vy)
					return sa;
				else if (s->data[s->size - 1] == vy)
					return ra;
				else if (s->data[s->size - 1] == vx)
					return rra;
				else if (s->data[s->size - 2] == vx)
					return sa;

				else
					return ra;
			}
		}
	}
	else
	{
		if (s->size - y < x)
		{
			printf("rotate to top until y\n");
			if (y - x < s->size / 2)
			{
				printf("swap until x to bottom\n");
				if (s->data[s->size - 1] == vy)
					return sa;
				else if (s->data[s->size - 2] == vy)
					return ra;
				else if (s->data[s->size - 1] == vx)
					return rra;
				else if (s->data[s->size - 2] == vx)
					return sa;
				else
					return ra;
			}
			else
			{
				printf("swap until x to top\n");
				if (s->data[s->size - 2] == vy)
					return sa;
				else if (s->data[s->size - 1] == vy)
					return rra;
				else if (s->data[s->size - 1] == vx)
					return ra;
				else if (s->data[s->size - 2] == vx)
					return sa;
				else
					return ra;
			}
		}
		else
		{
			printf("rotate to bottom until x\n");
			if (y - x < s->size / 2)
			{
				printf("swap until y to bottom\n");
				if (s->data[s->size - 1] == vx)
					return sa;
				else if (s->data[s->size - 2] == vx)
					return ra;
				else if (s->data[s->size - 1] == vy)
					return rra;
				else if (s->data[s->size - 2] == vy)
					return sa;
				else
					return ra;
			}
			else
			{
				printf("swap until y to top\n");
				if (s->data[s->size - 2] == vx)
					return sa;
				else if (s->data[s->size - 1] == vx)
					return rra;
				else if (s->data[s->size - 1] == vy)
					return ra;
				else if (s->data[s->size - 2] == vy)
					return sa;
				else
					return ra;
			}
		}
	}
	return (0);
}
