#ifndef CUB3D_H
# define CUB3D_H

// ========== LIBRARY ========== //

#include "libft/libft.h"
#include <fcntl.h>

int	main(int ac, char **av);

// ========================================================================= //
//                               PARSING                                     //
// ========================================================================= //

// ARGS //

int	check_arg(int ac, char **av);
int	valid_cub(char **av);
int	open_cub(char *file);

#endif