/*
** malloc.h for malloc.h in /home/zellou_i/rendu/PSU_2013_malloc
**
** Made by ilyas zelloufi
** Login   <zellou_i@epitech.net>
**
** Started on  Sun Feb  9 22:49:30 2014 ilyas zelloufi
** Last update Sun Feb  9 22:49:37 2014 ilyas zelloufi
*/

#ifndef MALLOC_H_
# define MALLOC_H_

typedef struct	s_addr
{
  size_t	size;
  int		isFree;
  struct s_addr	*next;
  struct s_addr	*prev;
}		t_addr;

size_t		align_size(size_t size);
t_addr		*fusion(t_addr *tmp);
t_addr		*split(t_addr *tmp, size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void		*malloc(size_t size);
void		show_alloc_mem();
void		*check_malloc(size_t size);
void		*add_block(size_t size);

extern t_addr	*g_block;

#endif /* !MALLOC_H_ */
