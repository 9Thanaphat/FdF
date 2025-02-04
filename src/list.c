#include "fdf.h"

t_list	*create_node(int height, int color)
{
	t_list *new_node = malloc(sizeof(t_list));
	new_node->height = height;
	new_node->color = color;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->last = new_node;
	return (new_node);
}

void	insert_node(t_list *head_node, int height, int color)
{
	//printf("insert node\n");
	t_list *new_node = create_node(height, color);
	t_list *last_node = head_node->last;

	last_node->next = new_node;
	new_node->next = NULL;
	head_node->last = new_node;
}

void	print_last(t_list *head_node)
{
	printf("last_node height : %d\n", head_node->last->height);
}

void	array_to_node(t_grid *grid, t_list *node, int i)
{
	if (!node)
		return ;
	printf("array[%d] = \n", i);
	grid->array[i] = node;
	array_to_node(grid ,node->next, i + 1);
}

void	print_node(t_list *node)
{
	//printf("h :%d color : 0x%x\n", node->height, node->color);
	if (node->next != NULL)
		print_node(node->next);
}
