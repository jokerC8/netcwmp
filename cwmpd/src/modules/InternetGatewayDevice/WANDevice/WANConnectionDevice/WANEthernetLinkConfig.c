//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANEthernetLinkConfig.X_NGB_VLANEnabled
int cpe_get_igd_WANEthernetLinkConfig_X_NGB_VLANEnabled(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    int wan_device_conn_num;
	tcapi_get_special_instance(name, 2, &wan_device_conn_num);

    switch (wan_device_conn_num) {
        case 1:
            break;
        case 2:
            *value = PSTRDUP("True");
            break;
        case 3:
            *value = PSTRDUP("True");
            break;
        default:
            break;
    }
	return FAULT_CODE_OK;
}
//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANEthernetLinkConfig.X_NGB_VLAN
int cpe_get_igd_WANEthernetLinkConfig_X_NGB_VLAN(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    int wan_device_conn_num;
	tcapi_get_special_instance(name, 2, &wan_device_conn_num);

    switch (wan_device_conn_num) {
        case 1:
            break;
        case 2:
            *value = PSTRDUP("100");
            break;
        case 3:
            *value = PSTRDUP("200");
            break;
        default:
            break;
    }
	return FAULT_CODE_OK;
}
//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANEthernetLinkConfig.X_NGB_802_1p
int cpe_get_igd_WANEthernetLinkConfig_X_NGB_802_1p(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	FUNCTION_TRACE();
    int wan_device_conn_num;
	tcapi_get_special_instance(name, 2, &wan_device_conn_num);

    switch (wan_device_conn_num) {
        case 1:
            break;
        case 2:
            *value = PSTRDUP("0");
            break;
        case 3:
            *value = PSTRDUP("4");
            break;
        default:
            break;
    }
	return FAULT_CODE_OK;
}