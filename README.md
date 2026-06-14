# PacketQueue-Linked

A prioritized data transmission queue written in C99 for smart edge routers. It models the network buffer as an explicit **Singly Linked List ordered by priority**, ensuring critical system alerts (like structural fire or hardware system crash markers) jump to the head of the transmission queue.

## 🛠️ Data Structure Mappings
* **Data Layout:** Dynamic Singly Linked List tracking priority values.
* **Insertion Complexity:** $O(N)$ linear worst-case insertion to maintain strict sorting order.
* **Extraction Complexity:** $O(1)$ constant time for immediate transmission dispatch.
