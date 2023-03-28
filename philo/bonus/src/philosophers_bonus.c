
#include "../inc/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (argc != 5 && argc != 6)
		print_error_b("Eksik veya fazla arguman");
	init_all_b(&sim, argv);
	ft_simulation_b(&sim);
}
