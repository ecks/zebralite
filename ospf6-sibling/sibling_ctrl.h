#ifndef SIBLING_CTRL_H
#define SIBLING_CTRL_H

enum sc_state_update_req
{
  CTRL_INT_UP_REQ,
  CTRL_LEAD_ELECT_RCVD_REQ,
  LEAD_ELECT_COMPL
};

void sibling_ctrl_init();
//void sibling_ctrl_state_transition(enum sibling_ctrl_state);
timestamp_t sibling_ctrl_ingress_timestamp();

void sibling_ctrl_add_ctrl_client(unsigned int hostnum, char * ifname, char * area);
void sibling_ctrl_set_addresses(struct in6_addr * sibling_ctrl);

void sibling_ctrl_interface_init(struct ospf6_interface * oi);

struct interface * sibling_ctrl_if_lookup_by_name(const char * ifname);
struct interface * sibling_ctrl_if_lookup_by_index(int ifindex);

void sibling_ctrl_route_set(struct ospf6_route * route);

int sibling_ctrl_first_xid_rcvd();

// functions dealing with restart msg queue
timestamp_t sibling_ctrl_first_timestamp_rcvd();
struct list * sibling_ctrl_restart_msg_queue();
int sibling_ctrl_push_to_restart_msg_queue(struct rfpbuf * msg_rcvd);

#endif
