#include <stdlib.h>
#include "queue.h"

SortedPacketQueue* create_queue() {
    SortedPacketQueue* q = (SortedPacketQueue*)malloc(sizeof(SortedPacketQueue));
    q->head = NULL;
    q->current_size = 0;
    return q;
}

void dispatch_priority_packet(SortedPacketQueue* q, int id, int priority) {
    PacketNode* new_node = (PacketNode*)malloc(sizeof(PacketNode));
    new_node->packet_id = id;
    new_node->priority_rank = priority;
    new_node->next_packet = NULL;

    // Base Case: List is empty or new node has higher priority than the head node
    if (q->head == NULL || priority > q->head->priority_rank) {
        new_node->next_packet = q->head;
        q->head = new_node;
    } else {
        // Traverse the linked list to find the correct sorted insertion spot
        PacketNode* tracker = q->head;
        while (tracker->next_packet != NULL && tracker->next_packet->priority_rank >= priority) {
            tracker = tracker->next_packet;
        }
        new_node->next_packet = tracker->next_packet;
        tracker->next_packet = new_node;
    }
    q->current_size++;
}

PacketNode extract_next_transit(SortedPacketQueue* q) {
    if (q->head == NULL) {
        PacketNode empty = {-1, -1, NULL};
        return empty;
    }
    PacketNode* transit_target = q->head;
    PacketNode dynamic_copy = *transit_target;

    q->head = q->head->next_packet;
    free(transit_target);
    q->current_size--;
    
    return dynamic_copy;
}

void destroy_queue(SortedPacketQueue* q) {
    PacketNode* current = q->head;
    while (current != NULL) {
        PacketNode* temp = current->next_packet;
        free(current);
        current = temp;
    }
    free(q);
}
