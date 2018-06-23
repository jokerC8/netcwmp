#include "libtcapi.h"

int  cpe_refresh_igd_wanconnectiondevice(cwmp_t * cwmp, parameter_node_t * param_node, callback_register_func_t callback_reg)
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
        if (wan_index == 1) {
            parameter_node_t * wan1conn_param;
            cwmp_model_copy_parameter(param_node, &wan1conn_param, 1);
            // if(wan_index == 2)
            // {
            //      parameter_node_t * wan2conn_param;
            //      cwmp_model_copy_parameter(param_node, &wan2conn_param, 2);
            // }
            parameter_node_t * wan2conn_param;
            cwmp_model_copy_parameter(param_node, &wan2conn_param, 2);
            parameter_node_t * wan3conn_param;
            cwmp_model_copy_parameter(param_node, &wan3conn_param, 3);
        } else if (wan_index == 2) {
            //not support yet
        }
        cwmp_model_refresh_object(cwmp, param_node, 0, callback_reg);
    }
    return FAULT_CODE_OK;
}

int cpe_get_igd_WANConnectionDevice_WANConnectionNumberOfEntries (cwmp_t * cwmp, const char * name,
                                char ** value, pool_t * pool)
{
    FUNCTION_TRACE();
    *value = PSTRDUP("3");
    return FAULT_CODE_OK;
}

int cpe_get_igd_WANConnectionDevice_WANPPPConnectionNumberOfEntries (cwmp_t * cwmp, const char * name,
                                char ** value, pool_t * pool)
{
    FUNCTION_TRACE();
    int index = 0;
    int ret = tcapi_get_special_instance(name, 1, &index);
    if (ret) {
        return FAULT_CODE_9005;
    }
    switch (index) {
        case 1:
            *value = PSTRDUP("0");
            break;
        case 2:
            *value = PSTRDUP("1");
            break;
        case 3:
            *value = PSTRDUP("0");
            break;
        default:
            return FAULT_CODE_9005;

    }
    return FAULT_CODE_OK;
}

int cpe_get_igd_WANConnectionDevice_WANIPConnectionNumberOfEntries (cwmp_t * cwmp, const char * name,
                                char ** value, pool_t * pool)
{
    FUNCTION_TRACE();
    int index = 0;
    int ret = tcapi_get_special_instance(name, 1, &index);
    if (ret) {
        return FAULT_CODE_9005;
    }
    switch (index) {
        case 1:
            *value = PSTRDUP("1");
            break;
        case 2:
            *value = PSTRDUP("0");
            break;
        case 3:
            *value = PSTRDUP("0");
            break;
        default:
            return FAULT_CODE_9005;

    }
    return FAULT_CODE_OK;
}