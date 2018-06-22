#ifndef __LIBTCAPI_H
#define __LIBTCAPI_H

int
tcapi_get_special_instance (const char* node_name, int instance_no,
                            int *instance_num);
int 
get_config_value(char *cmd, char *value, unsigned size);

#endif
