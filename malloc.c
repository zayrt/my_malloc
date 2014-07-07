/*
** malloc.c for malloc in /home/zellou_i/rendu/PSU_2013_malloc
**
** Made by ilyas zelloufi
** Login   <zellou_i@epitech.net>
**
** Started on  Sun Feb  9 22:47:41 2014 ilyas zelloufi
** Last update Tue May 27 23:51:21 2014 ilyas zelloufi
*/

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

t_addr		*g_block = NULL;

void		*add_block(size_t size) // cree un block 
{
  t_addr	*new_block;
  t_addr	*tmp;

  tmp = g_block;
  if ((new_block = sbrk(sizeof(t_addr) + size)) == (void *) -1)
    return (NULL);
  new_block->size = size;
  new_block->isFree = 0;
  new_block->next = NULL;
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_block;
      new_block->prev = tmp;
    }
  else
    g_block = new_block;
  new_block->next = NULL;
  return ((void *)(new_block) + sizeof(t_addr));
}

t_addr		*split(t_addr *tmp, size_t size) // sert a séparer un block en deux si il est plus gros que ce qui est demandé
{
  t_addr	*new;

  new = (void *)(tmp) + sizeof(t_addr) + size;
  new->size = tmp->size - size - sizeof(t_addr);
  tmp->size = size;
  new->isFree = 1;
  new->next = tmp->next;
  new->prev = tmp;
  if (tmp->next != NULL)
    tmp->next->prev = new;
  tmp->next = new;
  return (tmp);
}

void		*check_malloc(size_t size) // avant de cree un bloc on utilise cette fonction pr voir si il existe pas deja un bloc avec assez de mémoire
{
  t_addr	*tmp;

  tmp = g_block;
  while (tmp != NULL)
    {
      if (tmp->isFree == 1 && size <= tmp->size)
	{
	  tmp->isFree = 0;
	  if (tmp->size - size >= sizeof(t_addr) + 4)
	    tmp = split(tmp, size);
	  return ((void *)(tmp)+ sizeof(t_addr)); // si un bloc avec assez de mémoire a été retrouver on return l'addresse qui de la fin du bloc
	}
      tmp = tmp->next;
    }
  return (NULL); // si aucun bloc avec assez de mémoire est trouver on return null
}

void		*malloc(size_t size)
{
  void		*ptr;

  size = align_size(size);
  if ((ptr = check_malloc(size)) != NULL) // si un bloc ac assez de mémoire existe on le return 
    return (ptr);
  if ((ptr = add_block(size)) == NULL) // sinon on en cree un nouveau
    return (NULL);
  return (ptr);
}
