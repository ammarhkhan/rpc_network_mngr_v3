/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "network_mngr.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

char **
user_logins_1(void *argp, CLIENT *clnt)
{
	static char *clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, USER_LOGINS,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_wrapstring, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

char **
date_1(long *argp, CLIENT *clnt)
{
	static char *clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, DATE,
		(xdrproc_t) xdr_long, (caddr_t) argp,
		(xdrproc_t) xdr_wrapstring, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
cpu_usage_1(void *argp, CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, CPU_USAGE,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
mem_usage_1(void *argp, CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, MEM_USAGE,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

double *
load_procs_per_min_1(void *argp, CLIENT *clnt)
{
	static double clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, LOAD_PROCS_PER_MIN,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_double, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

system_statistics *
get_current_system_stats_1(void *argp, CLIENT *clnt)
{
	static system_statistics clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GET_CURRENT_SYSTEM_STATS,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_system_statistics, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}