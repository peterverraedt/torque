#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "pbs_job.h"

int LOGLEVEL = 10;

attribute_def job_attr_def[100];

int lock_ji_mutex(

  svr_job        *pjob,
  const char *id,
  const char *msg,
  int        logging)

  {
  return(0);
  }

int csv_length(const char *csv_str)
  {
  return(0);
  }

char *csv_nth(const char *csv_str, int n)
  {
  return(NULL);
  }

char* remove_from_csv(

  char* src,            /* I - line with csv values*/
  char* model_pattern   /* I - pattern with models*/)
  {
  return(NULL);
  }

char *csv_find_string(
    
  const char *csv_str,
  const char *search_str)

  {
  return(NULL);
  }

int ctnodes(

  const char *spec)

  {
  return(0);
  }

int str_to_attr(

  const char           *name,   /* I */
  const char           *val,    /* I */
  pbs_attribute        *attr,   /* O */
  struct attribute_def *padef,  /* I */
  int                   limit,  /* I */
  int                   index)

  {
  return(0);
  }


int attr_to_str(

  std::string      &ds,     /* O */
  attribute_def    *at_def, /* I */
  pbs_attribute    &attr,   /* I */
  bool              XML)    /* I */

  {
  return(0);
  }

