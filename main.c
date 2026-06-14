#include <stdio.h>
#include "queue.h"

int main() {
    printf("📡 Activating PacketQueue-Linked Streaming Pipeline Interface...\n\n");

    SortedPacketQueue* router_buffer = create_queue();

    // Ingest varying telemetry payloads [Packet ID, Priority Rank]
    dispatch_priority_packet(router_buffer, 101, 2);  // Standard temperature logging loop
    dispatch_priority_packet(router_buffer, 999, 10); // Critical fire sensor warning trigger
    dispatch_priority_packet(router_buffer, 102, 3);  // Routine power utilization metrics

    printf("📥 Enqueued Packets: ID 101 (P=2), ID 999 (P=10), ID 102 (P=3)\n");

    PacketNode next_transit = extract_next_transit(router_buffer);
    printf("\n🚀 Dispatching Next Packet for Network Transmission:\n");
    printf("   👉 Selected Target Packet ID: %d\n", next_transit.packet_id);
    printf("   👉 Evaluated Urgency Tier Level: %d\n", next_transit.priority_rank);

    destroy_queue(router_buffer);
    return 0;
}
