#include "libtcapi.h"

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.X_NGB_WANEponLinkConfig.VLANIDMark
int cpe_get_X_NGB_WANEponLinkConfig_VLANIDMark(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	//InternetGatewayDevice.WANDevice.1.WANConnectionDevice.1.X_NGB_WANEponLinkConfig.VLANIDMark=4001
	FUNCTION_TRACE();
	int index = 0;
	int ret = tcapi_get_special_instance(name, 2, &index);
    if (ret) {
		return FAULT_CODE_9005;
	}
	if (index == 1) {
		*value = PSTRDUP("4001");
	}
	return FAULT_CODE_OK;
}

int cpe_set_X_NGB_WANEponLinkConfig_VLANIDMark(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}

//InternetGatewayDevice.WANDevice.WANConnectionDevice.WANIPConnection.X_NGB_WANEponLinkConfig.X_NGB_802_1p
int cpe_get_X_NGB_WANEponLinkConfig_X_NGB_802_1p(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	//InternetGatewayDevice.WANDevice.1.WANConnectionDevice.1.X_NGB_WANEponLinkConfig.X_NGB_802_1p =6
	FUNCTION_TRACE();
	int index = 0;
	int ret = tcapi_get_special_instance(name, 2, &index);
    if (ret) {
		return FAULT_CODE_9005;
	}
	if (index == 1) {
		*value = PSTRDUP("6");
	}
	return FAULT_CODE_OK;
}

int cpe_set_X_NGB_WANEponLinkConfig_X_NGB_802_1p(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	FUNCTION_TRACE();
	return FAULT_CODE_OK;
}