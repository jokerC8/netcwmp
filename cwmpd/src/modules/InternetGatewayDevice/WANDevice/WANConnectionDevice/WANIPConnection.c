int  cpe_refresh_igd_wanipconnection(cwmp_t * cwmp, parameter_node_t * param_node, callback_register_func_t callback_reg)
{
    FUNCTION_TRACE();

    if(!param_node)
    {
        return FAULT_CODE_9002;
    }
    parameter_node_t * tmp_param, *tmp_node, *child_param;
    child_param = param_node->child;
    if(child_param) {
        for(tmp_param=child_param->next_sibling; tmp_param; ) {
            cwmp_log_info("refresh WANConnectionDevice node, delete param %s\n", tmp_param->name);
            tmp_node = tmp_param->next_sibling;
            cwmp_model_delete_parameter(tmp_param);
            tmp_param = tmp_node;
        }
        child_param->next_sibling = NULL;

        int wan_index = get_index_after_paramname(param_node, "WANDevice"); 
        int wan_conn_dev_index = get_index_after_paramname(param_node, "WANConnectionDevice"); 

        if(wan_index == 1) {
            parameter_node_t * ipconn_param;
            switch(wan_conn_dev_index){
                case 1: 
                    cwmp_model_copy_parameter(param_node, &ipconn_param, 1);
                    break;

                case 2:
                    // cwmp_model_copy_parameter(param_node, &ipconn_param, 1); 
                    // cwmp_model_copy_parameter(param_node, &ipconn_param, 2);
                    break;
                case 3:
                    // cwmp_model_copy_parameter(param_node, &ipconn_param, 1);
                    break;
            }
        } else if(wan_index == 2){
            //don't support
        }

        cwmp_model_refresh_object(cwmp, param_node, 0, callback_reg); 
    }

    return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.X_NGB_ServiceList
int cpe_get_igd_WANIPConnection_X_NGB_ServiceList(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ip_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ip_conn_num);

	switch (wan_device_conn_num) {
		case 1: //vlan for tr069
            if (wan_ip_conn_num == 1) {
                *value = PSTRDUP("TR069");
            }
			break;
		case 2: //vlan for pppoe
			break;
		case 3: //vlan for internal network
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_X_NGB_ServiceList(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.MTU
int cpe_get_igd_WANIPConnection_MTU(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ip_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ip_conn_num);

	switch (wan_device_conn_num) {
		case 1: //vlan for tr069
            if (wan_ip_conn_num == 1) {
                *value = PSTRDUP("1460");
            }
			break;
		case 2: //vlan for pppoe
			break;
		case 3: //vlan for internal network
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_MTU(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.AddressingType
int cpe_get_igd_WANIPConnection_AddressingType(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ip_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ip_conn_num);

	switch (wan_device_conn_num) {
		case 1: //vlan for tr069
            if (wan_ip_conn_num == 1) {
                *value = PSTRDUP("DHCP");
            }
			break;
		case 2: //vlan for pppoe
			break;
		case 3: //vlan for internal network
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_AddressingType(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.PossibleConnectionTypes
int cpe_get_igd_WANIPConnection_PossibleConnectionTypes(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ip_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ip_conn_num);

	switch (wan_device_conn_num) {
		case 1: //vlan for tr069
            if (wan_ip_conn_num == 1) {
                *value = PSTRDUP("Unconfigured, IP_Routed, IP_Bridged");
            }
			break;
		case 2: //vlan for pppoe
			break;
		case 3: //vlan for internal network
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_PossibleConnectionTypes(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.Enable
int cpe_get_igd_WANIPConnection_Enable(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    *value = PSTRDUP("1");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_Enable(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.ExternalIPAddress
int cpe_get_igd_WANIPConnection_ExternalIPAddress(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    *value = PSTRDUP("0.0.0.0");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_ExternalIPAddress(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.SubnetMask
int cpe_get_igd_WANIPConnection_SubnetMask(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    *value = PSTRDUP("0.0.0.0");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_SubnetMask(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.DefaultGateway
int cpe_get_igd_WANIPConnection_DefaultGateway(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    *value = PSTRDUP("0.0.0.0");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_DefaultGateway(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.DNSServers
int cpe_get_igd_WANIPConnection_DNSServers(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    *value = PSTRDUP("0.0.0.0");
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_DNSServers(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.MACAddress
int cpe_get_igd_WANIPConnection_MACAddress(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
	int wan_device_conn_num, wan_ip_conn_num;
	tcapi_get_special_instance(name, 3, &wan_device_conn_num);
	tcapi_get_special_instance(name, 1, &wan_ip_conn_num);

	switch (wan_device_conn_num) {
		case 1: //vlan for tr069
            if (wan_ip_conn_num == 1) {
                *value = get_mac_addr("eth0.1000");
            }
			break;
		case 2: //vlan for pppoe
			break;
		case 3: //vlan for internal network
			break;
		default:
			break;
	}
	return FAULT_CODE_OK;
}

int cpe_set_igd_WANIPConnection_MACAddress(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}