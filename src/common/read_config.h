#ifndef _READ_CONFIG_H
#define _READ_CONFIG_H

#include "src/common/slurm_protocol_defs.h"

/* 
 * init_slurm_conf - initialize or re-initialize the slurm configuration 
 *	values.   
 * IN/OUT ctl_conf_ptr - pointer to data structure to be initialized
 */
extern void init_slurm_conf (slurm_ctl_conf_t *ctl_conf_ptr);

/*
 * parse_config_spec - parse the overall configuration specifications, update  
 *	values
 * IN/OUT in_line - input line, parsed info overwritten with white-space
 * IN ctl_conf_ptr - pointer to data structure to be updated
 * RET 0 if no error, otherwise an error code
 *
 * NOTE: slurmctld and slurmd ports are built thus:
 *	if SlurmctldPort/SlurmdPort are set then
 *		get the port number based upon a look-up in /etc/services
 *		if the lookup fails then translate SlurmctldPort/SlurmdPort  
 *		into a number
 *	These port numbers are overridden if set in the configuration file
 */
extern int parse_config_spec (char *in_line, slurm_ctl_conf_t *ctl_conf_ptr);

/*
 * read_slurm_conf_ctl - load the slurm configuration from the configured 
 *	file. 
 * OUT ctl_conf_ptr - pointer to data structure to be filled
 * RET 0 if no error, otherwise an error code
 */
extern int read_slurm_conf_ctl (slurm_ctl_conf_t *ctl_conf_ptr);

/* 
 * report_leftover - report any un-parsed (non-whitespace) characters on the
 * configuration input line (we over-write parsed characters with whitespace).
 * IN in_line - what is left of the configuration input line.
 * IN line_num - line number of the configuration file.
 */
extern void report_leftover (char *in_line, int line_num);

/* validate configuration
 *
 * IN/OUT ctl_conf_ptr - a configuration as loaded by read_slurm_conf_ctl
 *
 * NOTE: default slurmctld and slurmd ports are built thus:
 *	if SLURMCTLD_PORT/SLURMD_PORT are set then
 *		get the port number based upon a look-up in /etc/services
 *		if the lookup fails then translate SLURMCTLD_PORT/SLURMD_PORT 
 *		into a number
 *	These port numbers are overridden if set in the configuration file
 * NOTE: a backup_controller or control_machine of "localhost" are over-written
 *	with this machine's name.
 * NOTE: if backup_addr is NULL, it is over-written by backup_controller
 * NOTE: if control_addr is NULL, it is over-written by control_machine
 */
extern void validate_config (slurm_ctl_conf_t *ctl_conf_ptr);

#endif /* !_READ_CONFIG_H */
