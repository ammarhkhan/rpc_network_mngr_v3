/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "network_mngr.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <pwd.h>
#include <string.h>

#define MAX_LEN 100

char **
user_logins_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;
	struct passwd *ptr;

	 setpwent();

	// while(1){
	// 	ptr = getpwent();

	// 	if(ptr==NULL){
	// 	break;
	// }

	// char *userName = ptr->pw_name;

	// strcpy(result, userName);

	// //print out user ID and username
	// //-5 included to left align 5 column field
	// printf("%-5u %s\n", ptr->pw_uid, ptr->pw_name);

	// }

	ptr = getpwent();
	result = ptr-> pw_name;

	 endpwent();

	/*
	 * insert server code here
	 */

	return &result;
}

char **
date_1_svc(long *argp, struct svc_req *rqstp)
{
  struct tm *timeptr;
  time_t clock;
  static char *ptr;
  static char err[] = "Invalid Response \0";
  static char s[MAX_LEN];

  clock = time(0);
  timeptr = localtime(&clock);
  switch(*argp)
  {
  case 1:strftime(s,MAX_LEN,"%A, %B %d, %Y",timeptr);
    ptr=s;
    break;

  case 2:strftime(s,MAX_LEN,"%T",timeptr);
    ptr=s;
    break;
  
  case 3:strftime(s,MAX_LEN,"%A, %B %d, %Y - %T",timeptr);
    ptr=s;
    break;

  default: ptr=err;
    break;
  }

  return(&ptr);
}

double *
cpu_usage_1_svc(void *argp, struct svc_req *rqstp)
{
  long double uptimeMeasurement1, uptimeMeasurement2, idleTimeMeasurement1, idleTimeMeasurement2;
  static double totalIdleTime, totalUptime, totalUtilTime, percent;

  long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);

  FILE* file = fopen("/proc/uptime", "r");
  fscanf(file, "%Lf %Lf ", &uptimeMeasurement1, &idleTimeMeasurement1);
  fclose(file);

  sleep(2);

  file = fopen("/proc/uptime", "r");
  fscanf(file, "%Lf %Lf ", &uptimeMeasurement2, &idleTimeMeasurement2);
  fclose(file);

  totalIdleTime =  (idleTimeMeasurement2 / number_of_processors) - (idleTimeMeasurement1 / number_of_processors);
  totalUptime = uptimeMeasurement2 - uptimeMeasurement1;
  totalUtilTime = totalIdleTime / totalUptime;
  totalUtilTime*=100;
  percent = 100 - totalUtilTime;

  return &percent;
}

double *
mem_usage_1_svc(void *argp, struct svc_req *rqstp)
{
	static double  percentageMemoryUsed;
	
	struct sysinfo systemInfo;
	sysinfo(&systemInfo);

	unsigned long totalSystemMemory = systemInfo.totalram;
	unsigned long availableMemory = systemInfo.freeram;
	double percentageMemoryFree;

	percentageMemoryFree = ((double) availableMemory/ (double) totalSystemMemory);
	percentageMemoryFree *= 100;

	percentageMemoryUsed = 100 - percentageMemoryFree;
	return &percentageMemoryUsed;
}

double *
load_procs_per_min_1_svc(void *argp, struct svc_req *rqstp)
{
	static double  processLoadedPerMin;

	struct sysinfo systemInfo;
	sysinfo(&systemInfo);

	unsigned long procsLoadedOverLastMinute = systemInfo.loads[0];
	processLoadedPerMin = (double) procsLoadedOverLastMinute;

	return &processLoadedPerMin;
}

system_statistics *
get_current_system_stats_1_svc(void *argp, struct svc_req *rqstp)
{
	static system_statistics  result;

	/*
	 * insert server code here
	 */

	return &result;
}
