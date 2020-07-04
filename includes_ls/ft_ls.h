/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:46:35 by lspiess           #+#    #+#             */
/*   Updated: 2019/09/16 16:50:01 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPS "1Rrlat"

#include "libft.h"
#include <stdio.h>//REMOVE MEEEE

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

/*
** storing command line options
*/

typedef struct		s_lsops {
	int				isrec;
	int				manyargs;
	int				isfirst;
	int				one;
	int				rec;
	int				r;
	int				l;
	int				a;
	int				t;
	int				err;
	char			errchar;
}					t_lsops;

/*
** storing data extracted from stat() or lstat().
** warning, the name member is not stored on the heap but will point to the
** dirent d_name struct member.
*/

typedef struct		s_data {
	char			*perms;
	int				hardlinks;
	char			*ownername;
	char			*ownergroup;
	long long int	filesize;
	char			*name;
	char			*path;
	char			*pathname;
	int				type;//4 dirs, 8 files and hardlinks, 10 symlinks
	int				timeval;
	char			*timestr;
	char			*symlinkname;
	long			blcks;
	int				major;
	int				minor;
	struct s_data	*next;
	struct s_data	*root;
}					t_data;

/*
** storing fields widths for the -l option
*/

typedef struct		s_lsformat {
	int				permwid;
	int				hardlnwid;
	int				ownernamewid;
	int				grpnamewid;
	int				filesizewid;
	int				timewid;
	int				major;
	int				minor;
}					t_lsformat;

/*
** AVL tree nodes
*/

typedef struct		s_lsnode {
	struct s_data	*data;
	int				branchlen;
	struct s_lsnode	*left;
	struct s_lsnode	*right;
}					t_lsnode;

/*
** storing the DIR, dirent, and buf struct pointers of a given file,
** as well as the complete filename with path to be passed as arg to
** opendir and readdir.
*/

typedef struct		s_lsdirdata {
	DIR				*dirp;
	struct dirent	*filp;
	struct stat		buf;
	char			*pathname;
	char			*recpath;
	t_lsops			ops;
}					t_lsdirdata;

/*
** storing the names of the directories for the -R options
*/

typedef struct		s_reclst {
	t_lsops			ops;
	char			*dirname;
}					t_reclist;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

void				ft_ls_print_datavars(t_data *data, t_data **datap);

char				*ft_ls_appendpaths(char *pathsofar, char *filename);
void				ft_ls_printpath(char *path, char *filename, t_lsops ops);

void				ft_lsdata_init(t_data **datap);

int					ft_ls_init_dirp(t_lsdirdata *d, char **pathp,
						char *filename, t_lsnode **rootp);
int					ft_lsopencurrentdir_seekfile(t_lsdirdata *d,
						char *filename);
void				ft_lstree_lprint(t_data *data, t_lsops ops,
						t_lsformat wid);
void				ft_ls_filename(t_lsdirdata *d, t_lsops ops, char *filename,
						char *path);

void				ft_ls_nodinit(t_lsnode **nodep);

void				ft_lsprinterr(char *path, char *filename, char *pathname);

void				ft_ls_init_lsformat(t_lsformat *f);

void				ft_ls_setcolumns(t_data *data, t_lsformat *lsformat);

void				ft_lsdata_freelist(t_data *data);
void				ft_ls_get_filpdata(char *path, struct dirent *filp,
						t_data **datap);
void				ft_call_statorlstat(uint8_t type, char *pathname,
						struct stat *bufp);
void				ft_ls_get_statdata(struct stat buf, t_lsformat *lsformat,
						t_data *data, t_lsops ops);
void				ft_ls_getmajorminor(struct stat buf, t_data **datap);

void				ft_ls_nodset(t_lsnode *node, t_lsnode *left,
						t_lsnode *right, t_data *data);
void				ft_ls_addnode(t_lsnode *root, t_data *newdata,
						t_lsops ops);
void				ft_lstree_avl(t_lsnode *root);

int					ft_putstr_buf(char *buf, char *s, int wid, int i);
int					ft_putstrl_buf(char *buf, char *s, int wid, int i);
int					ft_putint_buf(char *buf, int nb, int wid, int idx);
int					ft_putlld_buf(char *buf, long long nb, int wid, int idx);

void				ft_putstr_nl(char *s);
int					ft_ls_parseprintpath(char *s);
void				ft_putstr_nlpath(char *s);
void				ft_lstree_print(t_lsnode *root, t_lsops ops,
						t_lsformat lsformat);
void				ft_putstr_nl(char *s);

void				ft_lstree_freetree(t_lsnode *node);

char				*ft_lsrec_apppaths(char *path, char *filename);

int					ft_ls_init(t_lsdirdata *d, char **pathp,
						char *filename, t_lsnode **nodep);

void				ft_ls_recursive(t_lsnode **headp, t_lsops ops,
						char **pathsofarp);

void				ft_closedirp_freepath_freetree(t_lsdirdata *d, char **pathp,
						t_lsnode **rootp);


void				ft_ls_rec_or_free(t_lsops ops, t_lsnode **rootp,
						t_data **datap, t_lsdirdata *d);

void				ft_lsprintblocks(t_lsnode *root);

void				ft_ls(t_lsops ops, char *s, char *path);

#endif
