/*
 * network_mngr.x - Specification of remote date, time, date and time service.
 */

/*
 * Define 1 procedure :
 * date_1() accepts a long and returns a string. 
 */

struct system_statistics {
    char *date;
    double *cpu_usage;
    double *mem_usage;
    double *load_procs_per_min;
};

program NETWORK_MNGR_PROG {
    version NETWORK_MNGR {
        string USER_LOGINS(void) = 1; 
	    string DATE(long) = 2; 
        double CPU_USAGE(void) = 3;
        double MEM_USAGE(void) = 4;
        double LOAD_PROCS_PER_MIN(void) = 5;
        system_statistics GET_CURRENT_SYSTEM_STATS(void)=6;

    } = 1;			                /* version number = 1     */
} = 0x31234567;			   /* program number        */
