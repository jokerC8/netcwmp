#include "DeviceInfo/DeviceInfo.c"
#include "ManagementServer/ManagementServer.c"
#include "WANDevice/WANDevice.c"
#include "LANDevice/LANDevice.c"
#include "LANDevice/WLANConfiguration/WLANConfiguration.c"
#include "LANDevice/WLANConfiguration/PreSharedKey/PreSharedKey.c"
#include "LANDevice/LANEthernetInterfaceConfig/LANEthernetInterfaceConfig.c"
#include "LANDevice/LANHostConfigManagement/IPInterface/IPInterface.c"
#include "WANDevice/WANConnectionDevice/WANConnectionDevice.c"
#include "WANDevice/WANConnectionDevice/WANIPConnection.c"
#include "WANDevice/WANConnectionDevice/WANPPPConnection.c"
#include "WANDevice/WANConnectionDevice/WANIPConnection/X_NGB_WANEponLinkConfig.c"


// char* cpe_get_igd_device_summary(void * arg, void * pool)
// {
//     //pool_t * p = (pool_t *)pool;
//     return	NULL;
// }
//
// char* cpe_get_igd_lan_device_number_of_entries(void * arg, void * pool)
// {
//     //pool_t * p = (pool_t *)pool;
//     return NULL;
// }

//InternetGatewayDevice.DeviceSummary
int cpe_get_igd_device_summary (cwmp_t * cwmp, const char * name,
                                char ** value, pool_t * pool)
{
    FUNCTION_TRACE();
    *value = PSTRDUP ("DVB+OTT+EOC BOX");
    return FAULT_CODE_OK;
}

int cpe_get_igd_lan_device_number_of_entries (cwmp_t * cwmp, const char * name,
                                char ** value, pool_t * pool)
{
    FUNCTION_TRACE();
    *value = PSTRDUP("1");
    return FAULT_CODE_OK;
}

int cpe_get_igd_wan_device_number_of_entries (cwmp_t * cwmp, const char * name,
                                char ** value, pool_t * pool)
{
    FUNCTION_TRACE();
    *value = PSTRDUP("1");
    return FAULT_CODE_OK;
}
