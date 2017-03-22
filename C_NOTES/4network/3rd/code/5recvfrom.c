#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_ether.h>

#define SIZE 1024

//数据链路层包的类型
#define PROT_IP		0x0800		/* IP protocol			*/
#define PROT_ARP	0x0806		/* IP ARP protocol		*/
#define PROT_RARP	0x8035		/* IP ARP protocol		*/
#define PROT_VLAN	0x8100		/* IEEE 802.1q protocol		*/


typedef unsigned char uchar;
typedef unsigned short ushort;

/*
 *	Ethernet header 以太网头信息
 */
typedef struct {
	uchar		et_dest[6];	/* Destination node		*/
	uchar		et_src[6];	/* Source node			*/
	ushort		et_protlen;	/* Protocol or length		*/
	uchar		et_dsap;	/* 802 DSAP			*/
	uchar		et_ssap;	/* 802 SSAP			*/
	uchar		et_ctl;		/* 802 control			*/
	uchar		et_snap1;	/* SNAP				*/
	uchar		et_snap2;
	uchar		et_snap3;
	ushort		et_prot;	/* 802 protocol			*/
} Ethernet_t;

void eth_packet_analyc(void *data)
{
    Ethernet_t *p = (Ethernet_t *)data;
    //输出目标mac地址
    printf("dest mac: %2x:%2x:%2x:%2x:%2x:%2x\n", p->et_dest[0], p->et_dest[1], p->et_dest[2], p->et_dest[3],  p->et_dest[4],  p->et_dest[5]);
    //输出源mac地址
    printf("src  mac: %2x:%2x:%2x:%2x:%2x:%2x\n", p->et_src[0], p->et_src[1], p->et_src[2], p->et_src[3],  p->et_src[4],  p->et_src[5]);
    
    //超过两个字节则存在大小端问题
    //判断包的类型
    switch(ntohs(p->et_protlen))
    {
        case  PROT_IP:
            printf("IP数据报\n");
            break;
        case PROT_ARP:
            printf("ARP请求或者应答\n");
            break;
        case PROT_RARP:
            printf("RARP请求或者应答.\n");
            break;
        case PROT_VLAN:
            printf("IEEE 802.1q protocol\n");
            break;
        default:
            printf("不能够被识别的协议..\n");
            ;
    }

}

int main(void)
{
    int sockfd = -1;
    int ret = -1;
    char buf[SIZE];


    //AF_PACKET: Low level packet interface  底层数据包接口
    //SOCK_RAW:  Provides raw network protocol access. 提供原始的网络协议访问
    //ETH_P_ALL:  所有的包类型
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    //sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err1;
    }

    printf("sockfd: %d\n", sockfd);

    printf("sizeof(Ethernet_t): %d\n", sizeof(Ethernet_t));

    while(1)
    {
        memset(buf, 0, SIZE);
        ret = recvfrom(sockfd, buf, SIZE, 0, NULL, NULL); 
        printf("ret: %d  \n", ret);    

        eth_packet_analyc(buf);
    }


    close(sockfd);
    return 0;
err1:
   return -1;
}





