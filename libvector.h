#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define TRUE 1
# define FALSE 0

// Doubly linked list with the purpose
// of acting in a similar fashion to
// C++ vectors.
typedef struct s_vector {
	size_t			index;
	void			*data;
	struct s_vector	*next;
	struct s_vector	*previous;
}	t_vector;

// VEKTOR FUNKTIONEN
t_vector	*alloc_vector(int n_elements);
int			vec_assign_element(t_vector *head, size_t idx, void *data);
t_vector	*vec_get_element(t_vector *head, size_t idx);
t_vector	*new_vector_element(t_vector *prev, size_t idx);
void		*free_vector(t_vector *vec, void (*dealloc) (void *));
int			vector_insert(t_vector *head, int idx, void *content);
int			vector_remove(t_vector *head, int idx, void (*dealloc)(void *));
t_vector	*vector_new(void *data);
void		update_indices(t_vector *vec, int arg);

// VEKTOR NAVI FUNKTIONEN
t_vector	*vector_get_last(t_vector *vec);
t_vector	*vector_get_first(t_vector *vec);
int			vector_size(t_vector *vec);

// VEKTOR OPERATION FUNKTIONEN
t_vector	*vector_push_back(t_vector *head, t_vector *new);
void		vector_pop_back(t_vector *head, void (*dealloc) (void *));
t_vector	*vector_push_front(t_vector **head, t_vector *new);
t_vector	*vector_pop_front(t_vector *head, void (*dealloc) (void *));

#endif
