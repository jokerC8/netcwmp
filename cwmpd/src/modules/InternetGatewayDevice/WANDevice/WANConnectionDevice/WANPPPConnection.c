#include "libtcapi.h"

int  cpe_refresh_igd_wanpppconnection(cwmp_t * cwmp, parameter_node_t * param_node, callback_register_func_t callback_reg)
{
    FUNCTION_TRACE();

    if(!param_node)
    {
        return FAULT_CODE_9002;
    }
    parameter_node_t * tmp_param, *tmp_node, *child_param;
    child_param = param_node->child;
    if(child_param)
    {
        for(tmp_param=child_param->next_sibling; tmp_param; )
        {
            cwmp_log_info("refresh WANConnectionDevice node, delete param %s\n", tmp_param->name);
            tmp_node = tmp_param->next_sibling;
            cwmp_model_delete_parameter(tmp_param);
            tmp_param = tmp_node;
        }
        child_param->next_sibling = NULL;

        int wan_index = get_index_after_paramname(param_node, "WANDevice"); 
        int wan_conn_dev_index = get_index_after_paramname(param_node, "WANConnectionDevice"); 

        if(wan_index == 1)
        {
            parameter_node_t * pppconn_param;
            switch(wan_conn_dev_index)
            {
                case 1: 
                    // cwmp_model_copy_parameter(param_node, &pppconn_param, 1);
                    break;

                case 2:
                    cwmp_model_copy_parameter(param_node, &pppconn_param, 1); 
                    // cwmp_model_copy_parameter(param_node, &pppconn_param, 2);
                    break;
				case 3:
					cwmp_model_copy_parameter(param_node, &pppconn_param, 1);
					break;
            }
        }
        else
        if(wan_index == 2)
        {
            //don't support
        }
        cwmp_model_refresh_object(cwmp, param_node, 0, callback_reg); 
    }
    return FAULT_CODE_OK;
}

//get pppoe username or password
static char *get_pppoe_username_password(char *type)
{
	FILE *fp = NULL;
	char cmdline[256] = { 0 };
	
	if (!strncasecmp(type, "username", strlen("username"))) {
		snprintf(cmdline, sizeof(cmdline) - 1, "%s%s","uci get network.wan.", "username");
	} else if (!strncasecmp(type, "password", strlen("password")))
	snprintf(cmdline, sizeof(cmdline) - 1, "%s%s","uci get network.wan.", "password");
	cmdline[strlen(cmdline)] = '\0';

	if (NULL == (fp = popen(cmdline, "r"))) {
		return NULL;
	}
	
	if (NULL == fgets(cmdline, sizeof(cmdline), fp)) {
		pclose(fp);
		return NULL;
	}
	pclose(fp);
	return strndup(cmdline, strlen(cmdline));
}

//set pppoe username or password
static int set_pppoe_username_password(char *type, char *value)
{
	FUNCTION_TRACE();
	char cmdline[256] = { 0 };
	char *proto = "uci set network.wan.proto=pppoe";
	if (!strncmp(type, "Username", strlen("Username"))) {
		snprintf(cmdline, sizeof(cmdline) - 1, "%s%s","uci set network.wan.username=",value);
		cmdline[strlen(cmdline)] = '\0';
	} else if (!strncmp(type, "Password", strlen("Password"))) {
		snprintf(cmdline, sizeof(cmdline) - 1, "%s%s","uci set network.wan.password=",value);
		cmdline[strlen(cmdline)] = '\0';
	} else {
		return -1;
	}
	//uci set pppoe username,password,proto
	system(proto);
	system(cmdline);
	system("uci commit network");
	return 0;
}

int cpe_get_igd_WANPPPConnection_Username(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	char *param_name;
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);
	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				param_name = strrchr(name, '.');
				if (NULL == param_name) {
					cwmp_log_error("no such parameter\n");
					return FAULT_CODE_9005;
				}
				param_name++;
				*value = get_pppoe_username_password(param_name);
			}
			break;
		case 3:
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_Username(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	int ret;
	char *para_name;
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);
	para_name = strrchr(name, '.');
	if (para_name == NULL) {
		cwmp_log_error("no such parameter\n");
		return FAULT_CODE_9005;
	}
	para_name++;
	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				ret = set_pppoe_username_password(para_name, value);
			}
			break;
		case 3:
			break;
		default:
			break;
	}
	if (ret == 0)
		return FAULT_CODE_OK;
	
	return FAULT_CODE_9005;
}

int cpe_get_igd_WANPPPConnection_Password(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	char *param_name;
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);
	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				param_name = strrchr(name, '.');
				if (NULL == param_name) {
					cwmp_log_error("no such parameter\n");
					return FAULT_CODE_9005;
				}
				param_name++;
				*value = get_pppoe_username_password(param_name);
			}
			break;
		case 3:
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_Password(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	int ret;
	char *para_name;
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);
	para_name = strrchr(name, '.');
	if (para_name == NULL) {
		cwmp_log_error("no such parameter\n");
		return FAULT_CODE_9005;
	}
	para_name++;
	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				ret = set_pppoe_username_password(para_name, value);
			}
			break;
		case 3:
			break;
		default:
			break;
	}
	if (ret == 0)
		return FAULT_CODE_OK;
	
	return FAULT_CODE_9005;
}

int cpe_get_igd_WANPPPConnection_X_NGB_LanInterface(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);

	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				*value = PSTRDUP("lan1 lan2 lan4");
			}
			break;
		case 3:
			if (wan_ppp_conn_num == 1) {
				*value = PSTRDUP("lan3");
			}
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_X_NGB_ServiceList(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);

	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			*value = PSTRDUP("INTERNET");
			break;
		case 3:
			*value = PSTRDUP("OTHER");
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_Enable(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	*value = PSTRDUP("1");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_Enable(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_DNSServers(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	*value = PSTRDUP("0.0.0.0");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_DNSServers(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_MACAddress(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);

	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				*value = get_mac_addr("eth0.1000");
			}
			break;
		case 3:
			if (wan_ppp_conn_num == 1) {
				*value = get_mac_addr("eth0.2000");
			}
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_MACAddress(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_ConnectionTrigger(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	*value = PSTRDUP("OnDemand");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_ConnectionTrigger(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_ConnectionType(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ppp_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);

	switch (wan_device_conn_num) {
		case 1:
			break;
		case 2:
			if (wan_ppp_conn_num == 1) {
				*value = PSTRDUP("IP_Routed");
			}
			break;
		case 3:
			if (wan_ppp_conn_num == 1) {
				*value = PSTRDUP("IP_Bridged");
			}
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANPPPConnection_ConnectionType(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_DefaultGateway(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	*value = PSTRDUP("0.0.0.0");
	return FAULT_CODE_OK;
}

int cpe_get_igd_WANPPPConnection_ExternalIPAddress(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	// int wan_device_conn_num, wan_ppp_conn_num;
	// tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	// tcapi_get_special_instance(name, 1, &wan_ppp_conn_num);

	// switch (wan_device_conn_num) {
	// 	case 1: //vlan for tr069
	// 		break;
	// 	case 2: //vlan for pppoe
	// 		if (wan_ppp_conn_num == 1) {
	// 			*value = get_local_ipaddr("pppoe-wan");
	// 		}
	// 		break;
	// 	case 3: //vlan for internal network
	// 		break;
	// 	default:
	// 		break;
	// }
	return FAULT_CODE_OK;
}