#ifndef QUEUE_H
#define QUEUE_H

typedef struct PacketNode {
    int packet_id;
    int priority_rank; // Priority tier: 0 (Normal Diagnostics) to 10 (Critical System Fault)
    struct PacketNode* next_packet;
} PacketNode;

typedef struct {
    PacketNode* head;
    int current_size;
} SortedPacketQueue;

SortedPacketQueue* create_queue();
void dispatch_priority_packet(SortedPacketQueue* q, int id, int priority);
PacketNode extract_next_transit(SortedPacketQueue* q);
void destroy_queue(SortedPacketQueue* q);

#endif
