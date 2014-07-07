/*
** realloc.c for realloc in /home/tang_j/PSU_2013_malloc
**
** Made by Jean Luc TANG
** Login   <tang_j@epitech.net>
**
** Started on  Sat Feb  1 23:40:33 2014 Jean Luc TANG
** Last update Tue May 27 23:56:24 2014 ilyas zelloufi
*/

#include <string.h>
#include "malloc.h"

size_t		align_size(size_t size) // on utilise cette fonction pr tjrs allouer la puissance de 4 la plus proche de la taille demander pr avoir des blocs avec des tailles "aligner"
{
  int		i;

  i = 1;
  while (4 * i < (int)size)
    i++;
  return (4 * i);
}

void		*realloc(void *ptr, size_t size)
{
  void		*new;
  t_addr	*tmp;

  size = align_size(size);
  if (ptr == NULL) // si le pointeur qu'on doit realloc est null on fait un malloc tt simplement
    return (malloc(size));
  tmp = g_block;
  while (tmp != NULL && (void *)(tmp) + sizeof(t_addr) != ptr) // sinon on cherche le block qu'on veut reallouer
    tmp = tmp->next;
  if (tmp == NULL) // si il existe pas on fait aussi un malloc normal
    return (malloc(size));
  if (size == tmp->size)
    return (ptr);
  if ((new = malloc(size)) == NULL)
    return (NULL);
  else if (size < tmp->size) // on copie ce qui se trouver dans l'ancien block avec une new size pr le realloc
    new = memcpy(new, ptr, size);
  else
    new = memcpy(new, ptr, tmp->size);
  free(ptr);
  return (new);
}
