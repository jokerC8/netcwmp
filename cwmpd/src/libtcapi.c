#include "libtcapi.h"

/* FIXME: get instance num for node name by parent No.*/
/*
 * \param instance_no, the num for parent
 */
int tcapi_get_special_instance (const char* node_name, int instance_no,
                                int *instance_num)
{
    char *p = NULL;
    char tmp_str[1024] = { 0 };
    int len = 0;
    int i = 0;

    if ((NULL == node_name) || (NULL == instance_num))
    {
         return -1;
    }

    strcpy (tmp_str, node_name);
    for (i = 0; i < instance_no; i++)
    {
          p = strrchr (tmp_str, '.');
         if (NULL != p)
         {
            len = strlen (tmp_str) - strlen (p);

            tmp_str[len] = '\0';
         }
    }

    if ((NULL != p) || (0 == instance_no))
    {
        p = strrchr (tmp_str, '.');

        if (NULL != p)
        {
            *instance_num = atoi (p + 1);
        }
        else
        {
            cwmp_log_error ("NULL for get . from str\n");
            return -1;
        }
    }
    else
    {
        cwmp_log_error ("NULL for get . from str\n");
        return -1;
    }

    return 0;
}

//get values from file int /etc/config
int get_config_value(char *cmd, char *value, unsigned size)
{
    FILE *fp = NULL;

    if (NULL == (fp = popen(cmd, "r"))) {
        cwmp_log_error("%s failed (%s)\n", __FUNCTION__, strerror(errno));
        return -1;
    }
    if (NULL == fgets(value, size, fp)) {
        cwmp_log_error("%s failed (%s)\n", __FUNCTION__, strerror(errno));
        pclose(fp);
        return -1;
    }
    return 0;
}

//get mac address of special interface
char *get_mac_addr(char *ifname)
{
    int i = 0;
    char macstr[18] = {0};
    unsigned char macaddr[ETH_ALEN]={0};
    struct ifreq req;
 
    int s=socket(AF_INET,SOCK_DGRAM,0);
    if (s <= 0)
        return NULL;
    strcpy(req.ifr_name,ifname);
    req.ifr_hwaddr.sa_family=ARPHRD_ETHER;
    int err=ioctl(s,SIOCGIFHWADDR,&req);
    close(s);
    if (err == -1)
        return NULL;
    memcpy(macaddr,req.ifr_hwaddr.sa_data,ETH_ALEN);
    for (; i < ETH_ALEN; i++) {
        sprintf(macstr + 3*i, "%02x:",macaddr[i]);
    }
    macstr[sizeof(macstr) - 1] = '\0';
    return strndup(macstr,strlen(macstr));
}

//get ip of special interface
char *get_local_ipaddr(char * ifname)
{
    char *temp = NULL;
    int inet_sock;
    struct ifreq ifr;

    inet_sock = socket(AF_INET, SOCK_DGRAM, 0); 
    if (inet_sock <=0 ) {
        return NULL;
    }
    memset(ifr.ifr_name, 0, sizeof(ifr.ifr_name));
    memcpy(ifr.ifr_name, ifname, strlen(ifname));

    if(0 != ioctl(inet_sock, SIOCGIFADDR, &ifr)) 
    {   
        perror("ioctl error");
        close(inet_sock);
        return NULL;
    }

    temp = inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr);     
    close(inet_sock);
    return strndup(temp, strlen(temp));
}