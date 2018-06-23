#include "cwmp/model.h"
#include "data_model.h"
#include "cwmp_module.h"
#include "InternetGatewayDevice/InternetGatewayDevice.c"

model_func_t ModelFunction[] =
{
    {"cpe_get_igd_device_summary", cpe_get_igd_device_summary},
    {"cpe_get_igd_lan_device_number_of_entries", cpe_get_igd_lan_device_number_of_entries},
    {"cpe_get_igd_wan_device_number_of_entries", cpe_get_igd_wan_device_number_of_entries},
    {"cpe_get_igd_di_manufacturer", cpe_get_igd_di_manufacturer},
    {"cpe_get_igd_di_manufactureroui", cpe_get_igd_di_manufactureroui},
    {"cpe_get_igd_di_productclass", cpe_get_igd_di_productclass},
    {"cpe_get_igd_di_serialnumber", cpe_get_igd_di_serialnumber},
    {"cpe_get_igd_di_specversion", cpe_get_igd_di_specversion},
    {"cpe_get_igd_di_hardwareversion", cpe_get_igd_di_hardwareversion},
    {"cpe_get_igd_di_softwareversion", cpe_get_igd_di_softwareversion},
    {"cpe_get_igd_di_provisioningcode", cpe_get_igd_di_provisioningcode},

    {"cpe_get_igd_ms_mac", cpe_get_igd_ms_mac},
    {"cpe_get_igd_ms_ipaddr", cpe_get_igd_ms_ipaddr},
    {"cpe_get_igd_ms_url", cpe_get_igd_ms_url},
    {"cpe_set_igd_ms_url", cpe_set_igd_ms_url},
    {"cpe_get_igd_ms_username", cpe_get_igd_ms_username},
    {"cpe_set_igd_ms_username", cpe_set_igd_ms_username},
    {"cpe_get_igd_ms_password", cpe_get_igd_ms_password},
    {"cpe_set_igd_ms_password", cpe_set_igd_ms_password},
    {"cpe_get_igd_ms_PeriodicInformEnable", cpe_get_igd_ms_PeriodicInformEnable},
    {"cpe_set_igd_ms_PeriodicInformEnable", cpe_set_igd_ms_PeriodicInformEnable},
    {"cpe_get_igd_ms_PeriodicInformInterval", cpe_get_igd_ms_PeriodicInformInterval},
    {"cpe_set_igd_ms_PeriodicInformInterval", cpe_set_igd_ms_PeriodicInformInterval},
    {"cpe_get_igd_ms_connectionrequesturl", cpe_get_igd_ms_connectionrequesturl},
    {"cpe_get_igd_ms_connectionrequestusername", cpe_get_igd_ms_connectionrequestusername},
    {"cpe_get_igd_ms_connectionrequestpassword", cpe_get_igd_ms_connectionrequestpassword},
    {"cpe_set_igd_ms_connectionrequestusername", cpe_set_igd_ms_connectionrequestusername},
    {"cpe_set_igd_ms_connectionrequestpassword", cpe_set_igd_ms_connectionrequestpassword},


    {"cpe_refresh_igd_wandevice", cpe_refresh_igd_wandevice},
    {"cpe_refresh_igd_wanconnectiondevice", cpe_refresh_igd_wanconnectiondevice},
    {"cpe_refresh_igd_wanipconnection", cpe_refresh_igd_wanipconnection},
    {"cpe_refresh_igd_wanpppconnection", cpe_refresh_igd_wanpppconnection},

    {"cpe_get_igd_WANIPConnection_Enable", cpe_get_igd_WANIPConnection_Enable},
    {"cpe_set_igd_WANIPConnection_Enable", cpe_set_igd_WANIPConnection_Enable},
    {"cpe_get_igd_WANIPConnection_ExternalIPAddress", cpe_get_igd_WANIPConnection_ExternalIPAddress},
    {"cpe_set_igd_WANIPConnection_ExternalIPAddress", cpe_set_igd_WANIPConnection_ExternalIPAddress},
    {"cpe_get_igd_WANIPConnection_SubnetMask", cpe_get_igd_WANIPConnection_SubnetMask},
    {"cpe_set_igd_WANIPConnection_SubnetMask", cpe_set_igd_WANIPConnection_SubnetMask},
    {"cpe_get_igd_WANIPConnection_DefaultGateway", cpe_get_igd_WANIPConnection_DefaultGateway},
    {"cpe_set_igd_WANIPConnection_DefaultGateway", cpe_set_igd_WANIPConnection_DefaultGateway},
    {"cpe_get_igd_WANIPConnection_DNSServers", cpe_get_igd_WANIPConnection_DNSServers},
    {"cpe_set_igd_WANIPConnection_DNSServers", cpe_set_igd_WANIPConnection_DNSServers},
    {"cpe_get_igd_WANIPConnection_MACAddress", cpe_get_igd_WANIPConnection_MACAddress},
    {"cpe_set_igd_WANIPConnection_MACAddress", cpe_get_igd_WANIPConnection_MACAddress},
    {"cpe_get_igd_WANIPConnection_X_NGB_ServiceList", cpe_get_igd_WANIPConnection_X_NGB_ServiceList},
    {"cpe_set_igd_WANIPConnection_X_NGB_ServiceList", cpe_set_igd_WANIPConnection_X_NGB_ServiceList},
    {"cpe_get_igd_WANIPConnection_MTU", cpe_get_igd_WANIPConnection_MTU},
    {"cpe_set_igd_WANIPConnection_MTU", cpe_set_igd_WANIPConnection_MTU},
    {"cpe_get_igd_WANIPConnection_AddressingType", cpe_get_igd_WANIPConnection_AddressingType},
    {"cpe_set_igd_WANIPConnection_AddressingType", cpe_set_igd_WANIPConnection_AddressingType},
    {"cpe_get_igd_WANIPConnection_PossibleConnectionTypes", cpe_get_igd_WANIPConnection_PossibleConnectionTypes},
    {"cpe_set_igd_WANIPConnection_PossibleConnectionTypes", cpe_set_igd_WANIPConnection_PossibleConnectionTypes},
    {"cpe_get_X_NGB_WANEponLinkConfig_VLANIDMark", cpe_get_X_NGB_WANEponLinkConfig_VLANIDMark},
    {"cpe_set_X_NGB_WANEponLinkConfig_VLANIDMark", cpe_set_X_NGB_WANEponLinkConfig_VLANIDMark},
    {"cpe_get_X_NGB_WANEponLinkConfig_X_NGB_802_1p", cpe_get_X_NGB_WANEponLinkConfig_X_NGB_802_1p},
    {"cpe_set_X_NGB_WANEponLinkConfig_X_NGB_802_1p", cpe_set_X_NGB_WANEponLinkConfig_X_NGB_802_1p},

    {"cpe_get_igd_WANConnectionDevice_WANConnectionNumberOfEntries", cpe_get_igd_WANConnectionDevice_WANConnectionNumberOfEntries},
    {"cpe_get_igd_WANConnectionDevice_WANIPConnectionNumberOfEntries", cpe_get_igd_WANConnectionDevice_WANIPConnectionNumberOfEntries},
    {"cpe_get_igd_WANConnectionDevice_WANPPPConnectionNumberOfEntries", cpe_get_igd_WANConnectionDevice_WANPPPConnectionNumberOfEntries},
    
    {"cpe_get_igd_WANPPPConnection_Enable", cpe_get_igd_WANPPPConnection_Enable},
    {"cpe_set_igd_WANPPPConnection_Enable", cpe_set_igd_WANPPPConnection_Enable},
  	{"cpe_get_igd_WANPPPConnection_Username", cpe_get_igd_WANPPPConnection_Username},
  	{"cpe_set_igd_WANPPPConnection_Username", cpe_set_igd_WANPPPConnection_Username},
  	{"cpe_get_igd_WANPPPConnection_Password", cpe_get_igd_WANPPPConnection_Password},
  	{"cpe_set_igd_WANPPPConnection_Password", cpe_set_igd_WANPPPConnection_Password},

    {"cpe_get_igd_WANPPPConnection_DNSServers", cpe_get_igd_WANPPPConnection_DNSServers},
    {"cpe_set_igd_WANPPPConnection_DNSServers", cpe_set_igd_WANPPPConnection_DNSServers},
    {"cpe_get_igd_WANPPPConnection_MACAddress", cpe_get_igd_WANPPPConnection_MACAddress},
    {"cpe_set_igd_WANPPPConnection_MACAddress", cpe_set_igd_WANPPPConnection_MACAddress},
    {"cpe_get_igd_WANPPPConnection_ConnectionTrigger", cpe_get_igd_WANPPPConnection_ConnectionTrigger},
    {"cpe_set_igd_WANPPPConnection_ConnectionTrigger", cpe_set_igd_WANPPPConnection_ConnectionTrigger},
    {"cpe_get_igd_WANPPPConnection_ConnectionType", cpe_get_igd_WANPPPConnection_ConnectionType},
    {"cpe_set_igd_WANPPPConnection_ConnectionType", cpe_set_igd_WANPPPConnection_ConnectionType},
    {"cpe_get_igd_WANPPPConnection_DefaultGateway", cpe_get_igd_WANPPPConnection_DefaultGateway},
    {"cpe_get_igd_WANPPPConnection_ExternalIPAddress", cpe_get_igd_WANPPPConnection_ExternalIPAddress},

    {"cpe_refresh_igd_landevice", cpe_refresh_igd_landevice},
    {"cpe_refresh_igd_lanethernetinterfaceconfig", cpe_refresh_igd_lanethernetinterfaceconfig},
    {"cpe_refresh_igd_ipinterface", cpe_refresh_igd_ipinterface},
    {"cpe_refresh_igd_wlanconfiguration", cpe_refresh_igd_wlanconfiguration},
    {"cpe_refresh_igd_presharedKey", cpe_refresh_igd_presharedKey},

    {"cpe_get_igd_WLANConfiguration_Enable", cpe_get_igd_WLANConfiguration_Enable},
    {"cpe_set_igd_WLANConfiguration_Enable", cpe_set_igd_WLANConfiguration_Enable},
    {"cpe_get_igd_WLANConfiguration_BeaconType", cpe_get_igd_WLANConfiguration_BeaconType},
    {"cpe_set_igd_WLANConfiguration_BeaconType", cpe_set_igd_WLANConfiguration_BeaconType},
    {"cpe_get_igd_WLANConfiguration_WPAEncryptionModes", cpe_get_igd_WLANConfiguration_WPAEncryptionModes},
    {"cpe_set_igd_WLANConfiguration_WPAEncryptionModes", cpe_set_igd_WLANConfiguration_WPAEncryptionModes},
    {"cpe_get_igd_WLANConfiguration_WPAAuthenticationMode", cpe_get_igd_WLANConfiguration_WPAAuthenticationMode},
    {"cpe_set_igd_WLANConfiguration_WPAAuthenticationMode", cpe_set_igd_WLANConfiguration_WPAAuthenticationMode},
    {"cpe_get_igd_WLANConfiguration_SSID", cpe_get_igd_WLANConfiguration_SSID},
    {"cpe_set_igd_WLANConfiguration_SSID", cpe_set_igd_WLANConfiguration_SSID},
    {"cpe_get_igd_PreSharedKey_PreSharedKey", cpe_get_igd_PreSharedKey_PreSharedKey},
    {"cpe_set_igd_PreSharedKey_PreSharedKey", cpe_set_igd_PreSharedKey_PreSharedKey},
};

int get_index_after_paramname(parameter_node_t * param, const char * tag_name)
{
    parameter_node_t * parent;
    parameter_node_t * tmp;
    for(parent=param->parent, tmp = param; parent; tmp = parent, parent = parent->parent)
    {
        if(TRstrcmp(parent->name, tag_name) == 0)
        {
             if(is_digit(tmp->name) == 0)
             {
                return TRatoi(tmp->name);
             }
        }
    }
    return -1;
}


void cwmp_model_load(cwmp_t * cwmp, const char * xmlfile)
{

    cwmp_model_load_xml(cwmp, xmlfile, ModelFunction, sizeof(ModelFunction)/sizeof(model_func_t));
}
