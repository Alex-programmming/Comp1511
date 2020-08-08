// Abstract Data Type Queue demo
// Marc Chee, April 2019

// This file describes the interface to a queue of ints
// It must be included in other code files to be of use

// ======================================================
// The type "queue" refers to a queue_internals pointer.
// In other files, programs can use queue, but they will
// not get direct access to the queue's internal workings
// nor will they know exactly what they are
typedef struct queueInternals *Queue;

// ======================================================
// These functions are the only way external code can
// manipulate a queue.

// functions to create and destroy queues
Queue queueCreate();
void queueFree(Queue q);

// Add and remove items from queues
// Removing the item returns the item for use
void queueAdd(Queue q, int item);
int queueRemove(Queue q);

// Check on the size of the queue
int queueSize(Queue q);
