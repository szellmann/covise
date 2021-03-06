/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

#ifndef IBVERBSTRANSPORT_H
#define IBVERBSTRANSPORT_H

#ifdef HAVE_IBVERBS

#include <infiniband/verbs.h>
#include <rdma/rdma_cma.h>

class Context
{

public:
    struct ibv_context *context;
    struct ibv_pd *pd;
    struct ibv_mr *mr;
    struct ibv_cq *cq;
    struct ibv_srq *srq;
    struct ibv_comp_channel *ch;
    struct ibv_qp *qp;
    void *buf;
    unsigned size;
    int tx_depth;
    struct ibv_sge list;
    struct ibv_send_wr wr;
    struct rdma_cm_id *cm_id;
    struct rdma_event_channel *cm_channel;
};

class Destination
{

public:
    Destination()
    {
        lid = 0;
        qpn = 0;
        psn = 0;
        rkey = 0;
        vaddr = 0;
    }
    int lid;
    int qpn;
    int psn;
    unsigned int rkey;
    unsigned long long vaddr;
};

#endif

class IBVerbsTransport
{

public:
    IBVerbsTransport();
    ~IBVerbsTransport();

#ifdef HAVE_IBVERBS

    Destination *init_dest(Context *ctx, int ib_port = 1);

    Context *init_ctx(unsigned size,
                      int tx_depth, int port, unsigned char *buf);

    int connect_ctx(Context *ctx, int port, int my_psn,
                    Destination *dest);

    uint16_t get_local_lid(Context *ctx, int port);
    int client_connect(const char *servername, int port);

    Destination *client_exch_dest(int sockfd,
                                  Destination *my_dest);

    int server_connect(int port);
    Destination *server_exch_dest(int connfd, Destination *my_dest);

private:
    int page_size;
    struct ibv_device *ib_dev;

#endif
};

#endif
