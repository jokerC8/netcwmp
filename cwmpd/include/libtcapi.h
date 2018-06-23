#ifndef __LIBTCAPI_H
#define __LIBTCAPI_H

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <linux/sockios.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int
tcapi_get_special_instance (const char* node_name, int instance_no,
                            int *instance_num);
int 
get_config_value(char *cmd, char *value, unsigned size);

char *
get_mac_addr(char *ifname);

char *
get_local_ipaddr(char * ifname);
#endif
