/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:48:49 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 16:26:15 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/includes/printlib.h"

typedef struct		s_map
{
	char			**rooms;
	char			*rooms_list;
	char			*ants_str;
	char			*links;
	int				q_rooms;
	int				ants;
	int				check;
	int				**tab;
	int				run[2];
	int				init_2;
	int				m;
	int				e;
	int				w;
	int				k;
	int				a;
	int				**tab_final;
	int				**pow_room;
	int				*room;
	int				*s;
	int				*bl;
	int				*bl_s;
	int				**ways;
	int				**w_a;
	int				k_w;
	int				n;
}					t_map;

typedef struct		s_queue
{
	int				v;
	int				f;
	struct s_queue	*next;
}					t_queue;

void				read_flags(int argc, char **argv, t_map *m);
void				count_ants(t_map *m, char *line);
void				rooms(t_map *m, char *line, int i);
void				links(t_map *m, char *line, int j);
void				add_rooms(t_map *m);
void				create_tab(t_map *m);
char				*join_str(char *s1, char *s2);
void				free_array(char **array, t_map *m, int error);
int					room_index(t_map *m, char *room_name, int start);
void				print_map(t_map *m);
void				print_matrix(t_map *m);
void				exit_func(t_map *m, int error, char *message);
int					ft_isspace(char c);
int					dfs(t_map *p);
void				add_element_end_queue(int data, t_queue *head, int f);
int					check_queue(int data, t_queue *head);
t_queue				*remove_element(t_queue *head);
int					remove_element_c(t_queue *head);
void				init_alg(t_map *p);
void				add_pow(int i, t_map *p);
void				init_pow_rooms(t_map *p);
void				init_bfs(t_queue *q, t_map *p);
int					bfs_layer(t_map *p, t_queue *q, int i);
void				bfs_queue(int f, int i, t_map *p, t_queue *q);
int					bfs_check(t_map *p, t_queue *q, int i);
int					bfs_check_break(t_map *p, t_queue *q, int i);
void				bfs(t_map *p);
int					dfs(t_map *p);
void				dfs_completion(t_map *p, int i, int e);
void				dfs_recoil(t_map *p, int i, int e);
int					dfs_one(int e, t_map *p);
int					vivod(int i, t_map *p);
void				vivi(t_map *p);
int					size_ways(t_map *p);
int					count_way(t_map *p, int i);
int					add_way(t_map *p, int i, int l, int j);
void				add_ways(t_map *p);
void				sort_ways(int **w_a, int n);
void				distrib_ants(t_map *p);
void				nool_w_a(int **w_a, int n);
int					mins(int **w, int n);
void				tabtotab(int **t, int **t2, int n);
void				start_end(t_map *p);
int					check_start(t_map *p);
void				nool_arr(int *m, int n);
void				result_show(t_map *p);
void				nool_tab(int **tab, int n);
void				alg(t_map *p);
void				dissolve(t_map *p);
void				dissolve_ways(t_map *p);
int					start_alg(t_map *p);
void				way_plus(t_map *p);
#endif
