/*
** free.c for free in /home/zellou_i/rendu/PSU_2013_malloc
**
** Made by ilyas zelloufi
** Login   <zellou_i@epitech.net>
**
** Started on  Sun Feb  9 22:48:08 2014 ilyas zelloufi
** Last update Tue May 27 23:47:18 2014 ilyas zelloufi
*/

#include <stdio.h>
#include <string.h>
#include "malloc.h"

t_addr		*fusion(t_addr *tmp)
{
  if (tmp->prev != NULL && tmp->prev->isFree == 1) // si le block juste avant le block passé en paremetre est libre
    {
      tmp = tmp->prev;
      tmp->size += sizeof(*tmp) + tmp->next->size; // on le fusionne avec celui passe paremetre
      tmp->next = tmp->next->next; // et on vire celui passé en paremetre pr garder que le précedent qui est le resultat de la fusion
      if (tmp->next != NULL)
	tmp->next->prev = tmp;
    }
  if (tmp->next != NULL && tmp->next->isFree == 1) // si le block juste aprés le block passé en paremetre est libre
    {
      tmp->size += sizeof(*tmp) + tmp->next->size; // on le fusionne avec celui passe paremetre
      tmp->next = tmp->next->next; // et on vire celui passé en paremetre pr garder que le précedent qui est le resultat de la fusion
      if (tmp->next != NULL)
	tmp->next->prev = tmp;
    }
  return (tmp);
}

void		free(void *ptr)
{
  t_addr	*tmp;

  tmp = g_block;
  if (ptr != NULL)
    {
      while (tmp != NULL && (void *)(tmp) + sizeof(t_addr) != ptr) // on parcourt la liste juska tomber sur le block a free
	tmp = tmp->next;
      if (tmp != NULL) // si le block a free a bien été trouver
	{
	  tmp->isFree = 1; // on met le isFree a 1 pr dire qu'il est libre et on verifie si on peut pas le fusionné ac celui d'avant ou d'aprés avec fusion
	  tmp = fusion(tmp);
	}
    }
}
