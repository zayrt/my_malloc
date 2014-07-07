/*
** show_alloc_mem.c for malloc in /home/tang_j/rendu/PSU_2013_malloc
**
** Made by Jean Luc TANG
** Login   <tang_j@epitech.net>
**
** Started on  Sun Feb  9 14:44:48 2014 Jean Luc TANG
** Last update Tue May 27 23:51:52 2014 ilyas zelloufi
*/

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

void		show_alloc_mem() // affiche l'addresse et la taille de tous les bloc pr avoir une idée de toutes les allocations qui ont été faite
{
  t_addr	*tmp;
  void		*break_heap;

  tmp = g_block;
  break_heap = sbrk(0);
  printf("break : %p\n", break_heap);
  while (tmp != NULL)
    {
      if (tmp->isFree == 0)
	{
	  printf("%p -", (void *)(tmp) + sizeof(t_addr));
	  printf("%p", (void *)(tmp) + sizeof(t_addr) + (int)tmp->size);
	  printf(" : %d octets\n", (int)tmp->size);
	}
      tmp = tmp->next;
    }
}
