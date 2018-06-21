#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <linux/sockios.h>

int cpe_get_localip(const char * eth_name, char *hostip)
{
    register int fd,intrface,retn=0;
    struct ifreq buf[32];
    struct ifconf ifc;
    char domain_host[100] = {0};
    char local_ip_addr[20] = {0};
    char local_mac[20] = {0};
    //Get Domain Name --------------------------------------------------
    strcpy(local_ip_addr, "127.0.0.1");
    if (!hostip)
        return -1;
    if (getdomainname(&domain_host[0], 100) != 0)
    {
        return -1;
    }
    //------------------------------------------------------------------
    //Get IP Address & Mac Address ----------------------------------------
    if ((fd=socket(AF_INET,SOCK_DGRAM,0))>=0)
    {
        ifc.ifc_len=sizeof buf;
        ifc.ifc_buf=(caddr_t)buf;
        if (!ioctl(fd,SIOCGIFCONF,(char*)&ifc))
        {
            intrface=ifc.ifc_len/sizeof(struct ifreq);
            while (intrface-->0)
            {
                if (!(ioctl(fd,SIOCGIFFLAGS,(char*)&buf[intrface])))
                {
                    if (buf[intrface].ifr_flags&IFF_PROMISC)
                    {
                        retn++;
                    }
                }
                //Get IP Address
                if (!(ioctl(fd,SIOCGIFADDR,(char*)&buf[intrface])))
                {
		    if(strcmp(eth_name, buf[intrface].ifr_name) == 0)
		    {
                    sprintf(local_ip_addr, "%s", inet_ntoa(((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr));
		
		    break;
		    }
                }
                //Get Hardware Address

            }//While
        }
    }
    if ( fd > 0 )
    {
        close(fd);
    }

    strcpy(hostip, local_ip_addr);

    return CWMP_OK;
}

//InternetGatewayDevice.ManagementServer.mac
int cpe_get_igd_ms_mac(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{    
	// *value = cwmp_conf_pool_get(pool, "cwmp:acs_username");
    int i = 0;
    char macstr[18] = {0};
    unsigned char macaddr[ETH_ALEN]={0};
    struct ifreq req;
 
    int s=socket(AF_INET,SOCK_DGRAM,0);
    if (s <= 0)
        return FAULT_CODE_9002;
    strcpy(req.ifr_name,"eth0.4001");
    req.ifr_hwaddr.sa_family=ARPHRD_ETHER;
    int err=ioctl(s,SIOCGIFHWADDR,&req);
    close(s);
    if(err != -1) {
        memcpy(macaddr,req.ifr_hwaddr.sa_data,ETH_ALEN);
        for (; i < ETH_ALEN; i++) {
            sprintf(macstr + 3*i, "%02x:",macaddr[i]);
        }
        macstr[sizeof(macstr) - 1] = '\0';
        *value = PSTRDUP(macstr);
        return FAULT_CODE_OK;
    }
    return FAULT_CODE_9002;
}

//InternetGatewayDevice.ManagementServer.Username
int cpe_get_igd_ms_username(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{    
	*value = cwmp_conf_pool_get(pool, "cwmp:acs_username");
    return FAULT_CODE_OK;
}

//InternetGatewayDevice.ManagementServer.Username
int cpe_set_igd_ms_username(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
    //save password to database or config file
    int ret = cwmp_conf_set("cwmp:acs_username", value);
    if (ret == 1)
        return FAULT_CODE_OK;
    else
        return FAULT_CODE_9002;
}

//InternetGatewayDevice.ManagementServer.Password
int cpe_get_igd_ms_password(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
	  *value = cwmp_conf_pool_get(pool, "cwmp:acs_password");
	  return FAULT_CODE_OK;
}

int cpe_set_igd_ms_password(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
    //save password to database or config file
    int ret = cwmp_conf_set("cwmp:acs_password", value);
    if (ret == 1)
        return FAULT_CODE_OK;
    else
        return FAULT_CODE_9002;
}

//InternetGatewayDevice.ManagementServer.URL
int cpe_get_igd_ms_url(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{    
	*value = cwmp_conf_pool_get(pool, "cwmp:acs_url");
    return FAULT_CODE_OK;
}

//InternetGatewayDevice.ManagementServer.URL
int cpe_set_igd_ms_url(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
    //save password to database or config file
    int ret = cwmp_conf_set("cwmp:acs_url", value);
    if (ret == 1)
        return FAULT_CODE_OK;
    else
        return FAULT_CODE_9002;
}

//get wan3 interface name
static int get_wan3_interface(char *ifname)
{
	FILE *fp = NULL;
	char *cmd = "uci get network.wan3.ifname";
	if (NULL == (fp == popen(cmd, "r"))) {
		cwmp_log_error("%s failed (%s)\n", __FUNCTION__,strerror(errno));
		return -1;
	}
	if (NULL == (fgets(ifname, 32, fp))) {
		cwmp_log_error("%s failed (%s)\n", __FUNCTION__,strerror(errno));
		pclose(fp);
		return -1;
	}
	pclose(fp);
	return 0;
}

//InternetGatewayDevice.ManagementServer.ConnectionRequestURL
int cpe_get_igd_ms_connectionrequesturl(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
    char buf[256]={0};
    char local_ip[32]={0};
 
    cpe_get_localip("eth0.4001", local_ip);
    int port = cwmp_conf_get_int("cwmpd:httpd_port");
    snprintf(buf, 256, "http://%s:%d", local_ip, port);
    *value = PSTRDUP(buf);
    return FAULT_CODE_OK;
}

//InternetGatewayDevice.ManagementServer.ConnectionRequestUsername
int cpe_get_igd_ms_connectionrequestusername(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{
    *value = cwmp_conf_pool_get(pool, "cwmp:cpe_username");
    return FAULT_CODE_OK;
}
int cpe_set_igd_ms_connectionrequestusername(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	int ret = cwmp_conf_set("cwmp:cpe_username", value);
	if (ret == 1)
 	   return FAULT_CODE_OK;
	return FAULT_CODE_9002;
}

//InternetGatewayDevice.ManagementServer.ConnectionRequestPassword
int cpe_get_igd_ms_connectionrequestpassword(cwmp_t * cwmp, const char * name, char ** value, pool_t * pool)
{    
    *value = cwmp_conf_pool_get(pool, "cwmp:cpe_password");
    return FAULT_CODE_OK;
}
int cpe_set_igd_ms_connectionrequestpassword(cwmp_t * cwmp, const char * name, const char * value, int length, callback_register_func_t callback_reg)
{
	int ret = cwmp_conf_set("cwmp:cpe_password", value);
	if (ret == 1)
    	return FAULT_CODE_OK;
	return FAULT_CODE_9002;
}
