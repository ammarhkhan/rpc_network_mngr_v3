/*
 * network_mngr.x - Specification of remote date, time, date and time service.
 */

/*
 * Define 1 procedure :
 * date_1() accepts a long and returns a string. 
 */

program NETWORK_MNGR_PROG {
    version NETWORK_MNGR {
	    string DATE(long) = 1; 
        double CPU_USAGE(void) = 2;
        double MEM_USAGE(void) = 3;
        double LOAD_PROCS_PER_MIN(void) = 4;
        string USER_LOGINS(void) = 5; 
    } = 1;			                /* version number = 1     */
} = 0x31234567;			   /* program number        */
