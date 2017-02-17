#include "license_pbs.h" /* See here for the software license */
#include <pbs_config.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h> /* sockaddr_in */
#include <errno.h>
#include <set>

#include "mom_server.h" /* mom_server */
#include "resmon.h" /* PBS_MAXSERVER */
#include "attribute.h" /* attribute_def, pbs_attribute */
#include "net_connect.h" /* connection, PBS_NET_MAX_CONNECTIONS */
#include "log.h" /* LOG_BUF_SIZE */
#include "list_link.h" /* tlist_head */
#include "resource.h" /* resource_def */
#include "u_tree.h" /* AvlTree */
#include "pbs_job.h" /* job */
#include "mom_func.h" /* radix_buf */
#include "dis.h"
#include "complete_req.hpp"
#include "pmix_operation.hpp"
#include "pmix_tracker.hpp"
#include "authorized_hosts.hpp"


#ifdef NVIDIA_GPUS
int             MOMNvidiaDriverVersion    = 0;
int             use_nvidia_gpu = TRUE;
#endif  /* NVIDIA_GPUS */

std::list<mom_job *> alljobs_list;
int              is_reporter_mom = FALSE;
int              is_login_node   = FALSE;
int PBSNodeCheckEpilog;
int PBSNodeCheckProlog;
int internal_state;
int create_job_cpuset(mom_job *pj) { return 0; }
int use_cpusets(mom_job *pj) { return 0; }
const char *path_jobs = "some path to nowhere."; /* mom_main.c */
int multi_mom = 1; /* mom_main.c */
int svr_resc_size = 0; /* resc_def_all.c */
u_long localaddr = 0; /* mom_main.c */
time_t time_now = 0; /* mom_main.c */
mom_server mom_servers[PBS_MAXSERVER]; /* mom_server.c */
attribute_def job_attr_def[10]; /* src/server/job_attr_def.c */
int exiting_tasks = 0; /* mom_main.c */
const char *dis_emsg[10]; /* dis.h */
char *path_prologuserp; /* mom_main.c */
struct connection svr_conn[PBS_NET_MAX_CONNECTIONS]; /* net_server.c */
tlist_head svr_newjobs; /* mom_main.c */
resource_def *svr_resc_def; /* resc_def_all.c */
int port_care = TRUE; /* mom_main.c */
unsigned int pbs_rm_port = 0; /* mom_main.c */
AvlTree okclients; /* mom_main.c */
tlist_head mom_polljobs; /* mom_main.c */
char *path_prologp; /* mom_main.c */
tlist_head svr_alljobs; /* mom_main.c */
int LOGLEVEL = 7; /* force logging code to be exercised as tests run */ /* mom_main.c/pbsd_main.c */
int maxupdatesbeforesending = 0;
int    ServerStatUpdateInterval = DEFAULT_SERVER_STAT_UPDATES;
time_t          LastServerUpdateTime = 0;  /* NOTE: all servers updated together */
bool            ForceServerUpdate = false;
char log_buffer[LOG_BUF_SIZE];
int log_event_counter;
bool exit_called = false;
bool ms_val = true;
job_pid_set_t    global_job_sid_set;
char             mom_alias[PBS_MAXHOSTNAME + 1];

#undef disrus
unsigned short disrus(tcp_chan *c, int *retval)
  {
  *retval = DIS_SUCCESS;
  return(0);
  }

int mom_job_save(mom_job *pjob, int mom_port)
  {
  return(0);
  }

void mom_job_purge(mom_job *pjob) {}

int decode_DIS_svrattrl(struct tcp_chan *chan, tlist_head *phead)
  {
  return(0);
  }

ssize_t read_nonblocking_socket(int fd, void *buf, ssize_t count)
  {
  return(0);
  }

int TMakeTmpDir(mom_job *pjob, char *tmpdir)
  {
  return(0);
  }

unsigned long gettime(resource *pres)
  {
  return(0);
  }

void exec_bail(mom_job *pjob, int code, std::set<int> *contacted_sisters) {}

int AVL_list(AvlTree tree, char **Buf, long *current_len, long *max_len)
  {
  return(0);
  }

int exec_job_on_ms(mom_job *pjob)
  {
  return(0);
  }

struct passwd *check_pwd_return;
bool check_pwd(mom_job *pjob)
  {
  bool good = false;
  if(check_pwd_return == NULL)
    {
    good = true;
    }
  return(good);
  }

int mom_do_poll(mom_job *pjob)
  {
  return(0);
  }

void delete_link(struct list_link *old)
  {
  return;
  }

char *get_job_envvar(mom_job *pjob, const char *variable)
  {
  return(0);
  }

int open_tcp_stream_to_sisters(mom_job *pjob, int com, tm_event_t parent_event, int mom_radix, hnodent *hosts, struct radix_buf **sister_list, tlist_head *phead, int flag)
  {
  return(0);
  }

int open_demux(u_long addr, int port)
  {
  return(0);
  }

int mom_get_sample()
  {
  return(0);
  }

int run_pelog(int which, char *specpelog, mom_job *pjog, int pe_io_type, int deletejob)
  {
  return(0);
  }

#undef disrul
unsigned long disrul(struct tcp_chan * chan, int *retval)
  {
  static int rc = 0;
  return(rc++);
  }

const char * getuname(void )
  {
  return(0);
  }

size_t write_nonblocking_socket(int fd, const void *buf, ssize_t count)
  {
  return(0);
  }

struct tcp_chan *DIS_tcp_setup(int fd)
  {
  return(NULL);
  }

int find_attr(struct attribute_def *attr_def, const char *name, int limit)
  {
  return(0);
  }

#undef disrui
unsigned disrui(struct tcp_chan *chan, int *retval)
  {
  *retval = DIS_SUCCESS;
  return(0);
  }

int kill_task(mom_job *pjob, struct task *task, int sig, int pg)
  {
  return(0);
  }

int DIS_tcp_wflush(struct tcp_chan * chan)
  {
  return(0);
  }

int diswcs(struct tcp_chan * chan, const char *value, size_t nchars)
  {
  return(0);
  }

unsigned long getsize(resource *pres)
  {
  return(0);
  }

void *get_next(list_link pl, char *file, int line)
  {
  if ((pl.ll_next == NULL) ||
      ((pl.ll_next == &pl) && (pl.ll_struct != NULL)))
    {
    return NULL;
    }
  return(pl.ll_next->ll_struct);
  }

int add_host_to_sister_list(char *hostname, unsigned short port, struct radix_buf *rb)
  {
  return(0);
  }

char *disrcs(struct tcp_chan * chan, size_t *nchars, int *retval)
  {
  return(0);
  }

int start_process(task *tsk, char **argv, char **envp)
  {
  return(0);
  }

#undef diswui
int diswui(struct tcp_chan * chan, unsigned value)
  {
  return(0);
  }

void free_sisterlist(struct radix_buf **list, int radix)
  {
  return;
  }

int write_tcp_reply(struct tcp_chan *chan, int protocol, int version, int command, int exit_code)
  {
  return(0);
  }

int mom_set_use(mom_job *pjob)
  {
  return(0);
  }

void free_attrlist(tlist_head *pattrlisthead) {}

void attrl_fixlink(tlist_head *phead)
  {
  return;
  }

struct resource_def *find_resc_def_return = NULL;
resource_def *find_resc_def(resource_def *rscdf, const char *name, int limit)
  {
  if (find_resc_def_return == NULL)
    {
    find_resc_def_return = (struct resource_def *)calloc(1, sizeof(*find_resc_def_return));
    }
  if (find_resc_def_return->rs_name != NULL)
    {
    free((void*)find_resc_def_return->rs_name);
    }
  find_resc_def_return->rs_name = strdup(name);
  return(find_resc_def_return);
  }

struct radix_buf **allocate_sister_list(int radix)
  {
  return(0);
  }

int tcp_connect_sockaddr(struct sockaddr *sa, size_t sa_size, bool use_log)
  {
  return(10);
  }

void append_link(tlist_head *head, list_link *new_link, void *pobj) 
  {
  if (pobj != NULL)
    {
    new_link->ll_struct = pobj;
    }
  else
    {
    /* WARNING: This mixes list_link pointers and ll_struct
         pointers, and may break if the list_link we are operating
         on is not the first embeded list_link in the surrounding
         structure, e.g. work_task.wt_link_obj */

    new_link->ll_struct = (void *)new_link;
    }

  new_link->ll_prior = head->ll_prior;

  new_link->ll_next  = head;
  head->ll_prior = new_link;
  new_link->ll_prior->ll_next = new_link; /* now visible to forward iteration */
  }

void sister_job_nodes(mom_job *pjob, char *radix_hosts, char *radix_ports )
  {
  return;
  }

int TTmpDirName(mom_job *pjob, char *tmpdir, int tmdir_size)
  {
  return(0);
  }

void job_nodes(mom_job &pjob) {}

void close_conn(int sd, int has_mutex) {}

int diswul(struct tcp_chan * chan, unsigned long value)
  {
  return(0);
  }

int rpp_eom(int index)
  {
  return(0);
  }

resource *find_resc_entry(pbs_attribute *pattr, resource_def *rscdf)
  {
  return(NULL);
  }

mom_job *mock_mom_find_job_return = NULL;
mom_job *mom_find_job(const char *jobid)
  {
  if (strcmp("jobid", jobid) != 0)
    {
    return(NULL);
    }
  if (mock_mom_find_job_return == NULL)
    {
    mock_mom_find_job_return = new mom_job();
    mock_mom_find_job_return->set_str_attr(JOB_ATR_Cookie, strdup("cookie"));
    }
  return(mock_mom_find_job_return);
  }

#undef diswsi
int diswsi(tcp_chan *c, int value)
  {
  return(0);
  }

mom_job *mock_job_alloc_return = NULL;
mom_job *mom_job_alloc(void )
  {
  if (mock_job_alloc_return == NULL)
    {
    mock_job_alloc_return = new mom_job();
    }
  return(mock_job_alloc_return);
  }

int timeval_subtract(struct timeval *result, struct timeval *x, struct timeval *y)
  {
  return(0);
  }

int allocate_demux_sockets(mom_job *pjob, int flag)
  {
  return(0);
  }

int kill_job(mom_job *pjob, int sig, const char *killer_id_name, const char *why_killed_reason)
  {
  return(0);
  }

int add_to_resend_things(resend_momcomm *mc)
  {
  return(0);
  }

im_compose_info *create_compose_reply_info(const char *jobid, const char *cookie, hnodent *np, int command, tm_event_t event, tm_task_id taskid, const char *data)
  {
  return(0);
  }

int get_hostaddr_hostent_af(int *local_errno, const char *hostname, unsigned short *af_family, char **host_addr, int *host_addr_len)
  {
  return(0);
  }

pid_t fork_me(int conn) 
  {
  return(0);
  }

void DIS_tcp_close(struct tcp_chan *chan) {}

void DIS_tcp_cleanup(struct tcp_chan *chan) {}

ssize_t write_ac_socket(int fd, const void *buf, ssize_t count)
  {
  return(0);
  }

ssize_t read_ac_socket(int fd, void *buf, ssize_t count)
  {
  return(0);
  }

int getpeername(int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __len)  __THROW
  {
  memset(__addr, 0, sizeof(*__addr));
  return(0);
  }

char * netaddr_long(long ap, char *out)
  {
  u_long  ipadd;

  ipadd = ap;

  sprintf(out, "%ld.%ld.%ld.%ld",
           (ipadd & 0xff000000) >> 24,
           (ipadd & 0x00ff0000) >> 16,
           (ipadd & 0x0000ff00) >> 8,
           (ipadd & 0x000000ff));

  return out;
  }

char * netaddr(struct sockaddr_in *ap)
  {
  static char out[80];
  char tmp[80];

  if (ap == NULL)
    return (char *)"unknown";

  netaddr_long( ntohl(ap->sin_addr.s_addr), tmp);

  sprintf(out, "%s:%d", tmp, ntohs(ap->sin_port));

  return out;
  }

int AVL_is_in_tree_no_port_compare(u_long key, uint16_t port, AvlTree tree)
  {
  return(1);
  }

int disrst_return_index = 0;
#define disrst_array_size 10
char *disrst_array[disrst_array_size];
char *disrst(struct tcp_chan *chan, int *retval)
  {
  if (disrst_return_index >= disrst_array_size)
    {
    *retval = -1;
    return(NULL);
    }
    *retval = DIS_SUCCESS;
    return(disrst_array[disrst_return_index++]);
  }

int disrsi_return_index = 0;
const int disrsi_array_size = 10;
#define disrsi_array_size 10
int disrsi_array[disrsi_array_size];
#undef disrsi
int disrsi(struct tcp_chan *chan, int *retval)
  {
  if (disrsi_return_index >= disrsi_array_size)
    {
    *retval = -1;
    return(-1);
    }
  *retval = DIS_SUCCESS;
  return disrsi_array[disrsi_return_index++];
  }

void log_err(int errnum, const char *routine, const char *text) {}
void log_record(int eventtype, int objclass, const char *objname, const char *text) {}
void log_event(int eventtype, int objclass, const char *objname, const char *text) 
  {
  log_event_counter++;
  }
void log_ext(int type, const char *func_name, const char *msg, int o) {}

bool am_i_mother_superior(const mom_job &pjob)
  {
  bool mother_superior = ((pjob.ji_nodeid == 0) && ((pjob.get_svrflags() & JOB_SVFLG_HERE) != 0));
    
  return(mother_superior);
  }

void create_cpuset_reservation_if_needed(mom_job &pjob){}

int setup_gpus_for_job(

  mom_job  *pjob) /* I */

  {
  return(PBSE_NONE);
  }

int trq_cg_create_all_cgroups(mom_job *pjob)
  {
  return(PBSE_NONE);
  }

int trq_cg_reserve_cgroup(mom_job *pjob)
  {
  return(PBSE_NONE);
  }

void check_state(int Force) {}

void complete_req::set_task_usage_stats(int req_index, int task_index, unsigned long cput_used, unsigned long long mem_used)
  {
  }

int set_job_cgroup_memory_limits(mom_job *pjob)
  {
  return(PBSE_NONE);
  }

int trq_cg_add_devices_to_cgroup(mom_job *pjob)
  {
  return(PBSE_NONE);
  }

task::~task() {}

#ifdef ENABLE_PMIX
std::map<unsigned int, pmix_operation> existing_connections;
std::map<std::string, pmix_operation>  pending_fences;

pmix_operation::pmix_operation() {}
pmix_operation::pmix_operation(const pmix_operation &other) {}
pmix_operation::pmix_operation(char *rank_str, mom_job *pjob) {}

pmix_operation &pmix_operation::operator =(const pmix_operation &other)
  {
  return(*this);
  }

pmix_status_t pmix_operation::complete_operation(mom_job *pjob, long timeout)
  {
  return(PMIX_SUCCESS);
  }

bool pmix_operation::mark_reported(

  const std::string &hostname)

  {
  return(true);
  }

void pmix_operation::execute_callback() {}

unsigned int pmix_operation::get_operation_id() const
  {
  return(this->op_id);
  }

void pmix_operation::add_data(const std::string &add_data)
  {
  if (this->data.size() != 0)
    this->data += ",";
  this->data += add_data;
  }

int  clean_up_connection(mom_job *pjob, struct sockaddr_in *source_addr, unsigned int op_id, bool ms)
  {
  return(0);
  }

#endif

#ifdef PENABLE_LINUX_CGROUPS
int init_torque_cgroups()
  {
  return(PBSE_NONE);
  }

int trq_cg_add_process_to_all_cgroups(

  const char *job_id,
  pid_t       job_pid)

  {
  return(PBSE_NONE);
  }

string cg_memory_path;
string cg_cpuacct_path;
string cg_cpuset_path;
string cg_devices_path;

int trq_cg_add_process_to_task_cgroup(

  string     &cgroup_path, 
  const char *job_id, 
  const unsigned int req_index,
  const unsigned int task_index,
  pid_t       new_pid)

  {
  return(PBSE_NONE);
  }

complete_req::complete_req() {}

int complete_req::get_req_and_task_index_from_local_rank(
    
  int           local_rank,
  unsigned int &req_index,
  unsigned int &task_index,
  const char   *host) const

  {
  return(PBSE_NONE);
  }

bool have_incompatible_dash_l_resource(

  pbs_attribute *pattr)

  {
  return(false);
  }

req &complete_req::get_req(

  int i)

  {
  return(this->reqs[i]);
  }

bool per_task;

bool req::is_per_task() const

  {
  return(per_task);
  }

#endif

bool authorized_hosts::is_authorized(unsigned long addr)
  {
  return(true);
  }

void authorized_hosts::list_authorized_hosts(std::string &output) {}

authorized_hosts::authorized_hosts() {}
authorized_hosts auth_hosts;

job::job() 
  
  {
  memset(&this->ji_qs, 0, sizeof(this->ji_qs));
  }

job::~job() {}

mom_job::mom_job() : ji_tasks()
  {
  }
mom_job::~mom_job() {}

int mom_job::initialize_joined_job_from_json(Json::Value &js)
  {
  return(PBSE_NONE);
  }

void job::set_attr_flag(int index, int flag_val)

  {
  if ((index >= 0) &&
      (index < JOB_ATR_LAST))
    this->ji_wattr[index].at_flags = flag_val; 
  }

int job::get_mom_exitstat() const
  {
  return(this->ji_qs.ji_un.ji_momt.ji_exitstat);
  }

void job::set_mom_exitstat(int ev)
  {
  this->ji_qs.ji_un.ji_momt.ji_exitstat = ev;
  }

pbs_net_t job::get_svraddr() const
  {
  return(this->ji_qs.ji_un.ji_momt.ji_svraddr);
  }

void job::set_attr_flag_bm(int index, int bm)
  {
  if ((index >= 0) &&
      (index < JOB_ATR_LAST))
    this->ji_wattr[index].at_flags |= bm;
  }

struct timeval *job::get_tv_attr(int index)
  {
  return(&this->ji_wattr[index].at_val.at_timeval);
  }

int job::set_tv_attr(int index, struct timeval *tv)
  {
  memcpy(&(this->ji_wattr[index].at_val.at_timeval), tv, sizeof(struct timeval));
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

int job::set_resc_attr(int index, std::vector<resource> *resources)
  {
  this->ji_wattr[index].at_val.at_ptr = resources;
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

void job::set_exec_exitstat(int ev)
  {
  this->ji_qs.ji_un.ji_exect.ji_exitstat = ev;
  }

unsigned short job::get_ji_mom_rmport() const
  {
  return(this->ji_qs.ji_un.ji_exect.ji_mom_rmport);
  }

int job::set_creq_attr(int index, complete_req *cr)
  {
  this->ji_wattr[index].at_val.at_ptr = cr;
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

void job::set_qs_version(int version)
  {
  this->ji_qs.qs_version = version;
  }

void job::set_queue(const char *queue)
  {
  snprintf(this->ji_qs.ji_queue, sizeof(this->ji_qs.ji_queue), "%s", queue);
  }

int job::get_un_type() const
  {
  return(this->ji_qs.ji_un_type);
  }

void job::set_ji_momaddr(unsigned long momaddr)
  {
  this->ji_qs.ji_un.ji_exect.ji_momaddr = momaddr;
  }

void job::set_ji_mom_rmport(unsigned short mom_rmport)
  {
  this->ji_qs.ji_un.ji_exect.ji_mom_rmport = mom_rmport;
  }

void job::set_ji_momport(unsigned short momport)
  {
  this->ji_qs.ji_un.ji_exect.ji_momport = momport;
  }

const char *job::get_queue() const
  {
  return(this->ji_qs.ji_queue);
  }

void job::set_scriptsz(size_t scriptsz)
  {
  this->ji_qs.ji_un.ji_newt.ji_scriptsz = scriptsz;
  }

size_t job::get_scriptsz() const
  {
  return(this->ji_qs.ji_un.ji_newt.ji_scriptsz);
  }

pbs_net_t job::get_fromaddr() const
  {
  return(this->ji_qs.ji_un.ji_newt.ji_fromaddr);
  }

int job::get_fromsock() const
  {
  return(this->ji_qs.ji_un.ji_newt.ji_fromsock);
  }

void job::set_fromaddr(pbs_net_t fromaddr)
  {
  this->ji_qs.ji_un.ji_newt.ji_fromaddr = fromaddr;
  }

void job::set_fromsock(int sock)
  {
  this->ji_qs.ji_un.ji_newt.ji_fromsock = sock;
  }

int job::get_qs_version() const
  {
  return(this->ji_qs.qs_version);
  }

void job::set_un_type(int type)
  {
  this->ji_qs.ji_un_type = type;
  }

int job::get_exec_exitstat() const
  {
  return(this->ji_qs.ji_un.ji_exect.ji_exitstat);
  }

int job::get_svrflags() const
  {
  return(this->ji_qs.ji_svrflags);
  }

void job::set_modified(bool m)
  {
  this->ji_modified = m;
  }

void job::set_attr(int index)
  {
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  }

void job::set_fileprefix(const char *prefix)
  {
  strcpy(this->ji_qs.ji_fileprefix, prefix);
  }

int job::set_char_attr(int index, char c)
  {
  this->ji_wattr[index].at_val.at_char = c;
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

void job::set_svrflags(int flags)
  {
  this->ji_qs.ji_svrflags = flags;
  }

const char *job::get_destination() const
  {
  return(this->ji_qs.ji_destin);
  }

void job::free_attr(int index)
  {
  }

void job::set_substate(int substate)
  {
  this->ji_qs.ji_substate = substate;
  }

void job::set_state(int state)
  {
  this->ji_qs.ji_state = state;
  }

void job::set_destination(const char *destination)
  {
  snprintf(this->ji_qs.ji_destin, sizeof(this->ji_qs.ji_destin), "%s", destination);
  }

pbs_net_t job::get_ji_momaddr() const
  {
  return(this->ji_qs.ji_un.ji_exect.ji_momaddr);
  }

bool job::has_been_modified() const
  {
  return(this->ji_modified);
  }

tlist_head *job::get_list_attr(int index)
  {
  return(&this->ji_wattr[index].at_val.at_list);
  }

complete_req *job::get_creq_attr(int index) const
  {
  complete_req *cr = NULL;
  if (this->ji_wattr[index].at_flags & ATR_VFLAG_SET)
    cr = (complete_req *)this->ji_wattr[index].at_val.at_ptr;

  return(cr);
  }

void job::set_exgid(unsigned int gid)
  {
  this->ji_qs.ji_un.ji_momt.ji_exgid = gid;
  }

void job::set_exuid(unsigned int uid)
  {
  this->ji_qs.ji_un.ji_momt.ji_exuid = uid;
  }

unsigned short job::get_ji_momport() const
  {
  return(this->ji_qs.ji_un.ji_exect.ji_momport);
  }

void job::set_jobid(const char *jobid)
  {
  strcpy(this->ji_qs.ji_jobid, jobid);
  }

int job::get_attr_flags(int index) const
  {
  return(this->ji_wattr[index].at_flags);
  }

struct jobfix &job::get_jobfix()
  {
  return(this->ji_qs);
  }

int job::set_bool_attr(int index, bool b)
  {
  this->ji_wattr[index].at_val.at_bool = b;
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

bool job::get_bool_attr(int index) const
  {
  return(this->ji_wattr[index].at_val.at_bool);
  }

std::vector<resource> *job::get_resc_attr(int index)
  {
  return((std::vector<resource> *)this->ji_wattr[index].at_val.at_ptr);
  }

const char *job::get_str_attr(int index) const
  {
  return(this->ji_wattr[index].at_val.at_str);
  }

const char *job::get_jobid() const
  {
  return(this->ji_qs.ji_jobid);
  }

int job::get_substate() const
  {
  return(this->ji_qs.ji_substate);
  }

int job::get_state() const
  {
  return(this->ji_qs.ji_state);
  }

void job::unset_attr(int index)
  {
  this->ji_wattr[index].at_flags = 0;
  }

bool job::is_attr_set(int index) const
  {
  return((this->ji_wattr[index].at_flags & ATR_VFLAG_SET) != 0);
  }

const char *job::get_fileprefix() const
  {
  return(this->ji_qs.ji_fileprefix);
  }

int job::set_long_attr(int index, long l)
  {
  this->ji_wattr[index].at_val.at_long = l;
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

int job::set_str_attr(int index, char *str)
  {
  this->ji_wattr[index].at_val.at_str = str;
  this->ji_wattr[index].at_flags |= ATR_VFLAG_SET;
  return(PBSE_NONE);
  }

long job::get_long_attr(int index) const
  {
  return(this->ji_wattr[index].at_val.at_long);
  }

time_t job::get_start_time() const
  {
  return(this->ji_qs.ji_stime);
  }

void job::set_start_time(time_t t)
  {
  this->ji_qs.ji_stime = t;
  }

pbs_attribute *job::get_attr(int index)
  {
  return(this->ji_wattr + index);
  }

void mom_job_free(mom_job *pjob) {}
