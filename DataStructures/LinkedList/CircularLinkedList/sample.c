//
//  ring_buffer.c/cpp
//
//  Created by brainelectronics on 14.08.2020
//  Modified on 14.08.2020
//
//  Copyright (c) 2020 brainelectronics. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

// activate the define to see some more debug content
#define SHOW_DEBUG_CONTENT

// create structure of nodes in the ringbuffer
typedef struct Node {
    uint32_t data;        //< content of this node
    bool isEmpty;         //< flag to indicate content of not
    struct Node *next;    //< pointer to next node in linked list
} node_t;

// define actual ring buffer layout
typedef struct ring_buffer {
    node_t *head;         //< head of ring buffer linked list
    node_t *latest;       //< latest (newest) node
    node_t *oldest;       //< oldest node
} ring_buffer_t;

node_t* getNode()
{
    // calloc space for 1 Node and set all of them to 0
    return ((node_t*)calloc(1, sizeof(node_t)));
}

ring_buffer_t* getEmptyRingbuffer()
{
    // calloc space for 1 Node and set all of them to 0
    return ((ring_buffer_t*)calloc(1, sizeof(ring_buffer_t)));
}

void create_buffer(ring_buffer_t *pb, uint32_t size)
{
    // create a first new node in memory
    pb->head = getNode();
    pb->head->isEmpty = true;
    
    // create tmp node to travel with, start at head of list
    node_t *ptr = pb->head;
    node_t *newNode = NULL;
    
    for (uint32_t i = 0; i < size-1; i++)
    {
        // create new empty node in memory
        newNode = getNode();
        
        // set the empty flag
        newNode->isEmpty = true;
        
        // add new node as next of current one
        ptr->next = newNode;
        
        // change to recently created node
        ptr = ptr->next;
    }
    
    // the next of last is the head (close loop of linked list)
    ptr->next = pb->head;
    
    // head is at this point in time the latest and oldest node
    pb->latest = pb->head;
    pb->oldest = pb->head;
}

ring_buffer_t* create_new_buffer(uint32_t size)
{
    ring_buffer_t *newRing = NULL;
    
    // create a new ring buffer in memory
    newRing = getEmptyRingbuffer();
    
    // fill the new ring buffer with empty nodes
    create_buffer(newRing, size);
    
    return newRing;
}

void insert(ring_buffer_t *pb, int data)
{
#ifdef SHOW_DEBUG_CONTENT
    printf("Insert %d\n", data);
#endif
    
    // the oldest node will be updated with the data
    // and thereby becomes the latest node
    pb->latest = pb->oldest;
    
    // overwrite oldest node's data with the new data
    pb->oldest->data = data;
    
    // remove empty flag
    pb->oldest->isEmpty = false;
    
    // next of oldest node becomes oldest node
    pb->oldest = pb->oldest->next;
}

void pop(ring_buffer_t *pb)
{
#ifdef SHOW_DEBUG_CONTENT
    printf("Remove %d\n", pb->oldest->data);
#endif
    
    // set empty flag (no content)
    pb->oldest->isEmpty = true;
    
    // move oldest to next of oldest
    pb->oldest = pb->oldest->next;
}

void printNodeData(node_t *ptr)
{
    if (ptr->isEmpty == true)
    {
        printf("NULL");
    }
    else
    {
        printf("%d", ptr->data);
    }
}

void displayList(ring_buffer_t *pb)
{
    // get head of ring buffer
    node_t *ptr = pb->head;
    
#ifdef SHOW_DEBUG_CONTENT
    printf("head content: %d\n", pb->head->data);
    printf("latest content: %d\n", pb->latest->data);
    printf("oldest content: %d\n", pb->oldest->data);
#endif
    
    // loop until next node is the head node
    while (ptr->next != pb->head)
    {
        printNodeData(ptr);
        printf(" -> ");
        
        // move to next node
        ptr = ptr->next;
    }
    // use a do-while loop or show data of last element here
    // do {
    // } while (ptr != b.head);
    printNodeData(ptr);
   
    printf("\n");
}

void calcAverage(ring_buffer_t *pb, int *pResult)
{
    // get head of ring buffer
    node_t *ptr = pb->head;
    
    int sum = 0;
    int numberOfElements = 0;
    
    // loop until next node is the head node
    while (ptr->next != pb->head)
    {
        // take data only into account if it is not marked as empty
        if (ptr->isEmpty == false)
        {
            numberOfElements++;
            sum += ptr->data;
        }
        
        // move to next node
        ptr = ptr->next;
    }
    // use a do-while loop or take data of last element here
    // do {
    // } while (ptr != pb->head);
    if (ptr->isEmpty == false)
    {
        numberOfElements++;
        sum += ptr->data;
    }
    
    // put calculated average to pointer
    if (numberOfElements > 0)
    {
        *pResult = sum/numberOfElements;
    }
    else
    {
        *pResult = 0;
    }
    
#ifdef SHOW_DEBUG_CONTENT
    printf("elements: %d, sum: %d, avg: %d\n", numberOfElements, sum, *pResult);
#endif
}

uint32_t getLength(ring_buffer_t *pb)
{
    // get head of ring buffer
    node_t *ptr = pb->head;
    
    // length of ring buffer is at least one
    uint32_t length = 1;
    
    // loop until next node is the head node
    while (ptr->next != pb->head)
    {
        length++;
        
        // move to next node
        ptr = ptr->next;
    }
    
    return length;
}

node_t* getSecondLastNode(ring_buffer_t *pb)
{
    // get head of ring buffer
    node_t *ptr = pb->head;
    
    // loop until node after next node is the head node
    while (ptr->next->next != pb->head)
    {
        // move to next node
        ptr = ptr->next;
    }
    
#ifdef SHOW_DEBUG_CONTENT
    printf("Second last node content is: ");
    printNodeData(ptr);
    printf("\n");
#endif
    
    return ptr;
}

node_t* getLastNode(ring_buffer_t *pb)
{
    // get next of second last node (which is the last node itself)
    node_t *ptr = getSecondLastNode(pb)->next;
    
#ifdef SHOW_DEBUG_CONTENT
    printf("Last node content is: ");
    printNodeData(ptr);
    printf("\n");
#endif
    
    return ptr;
}

node_t* getNodeBefore(ring_buffer_t *pb, node_t *pThis)
{
    // get head of ring buffer
    node_t *ptr = pb->head;
    
    // loop until next node is the given node
    while (ptr->next != pThis)
    {
        // move to next node
        ptr = ptr->next;
    }
    
#ifdef SHOW_DEBUG_CONTENT
    printf("Node before ");
    printNodeData(pThis);
    printf(": ");
    printNodeData(ptr);
    printf("\n");
#endif
    
    return ptr;
}

void shrinkRingbuffer(ring_buffer_t *pb, int decrease)
{
    if (decrease == 0)
    {
        // nothing to do
        return;
    }
    
    int currentLength = getLength(pb);
    int desiredLength = currentLength - decrease;
    node_t *tmp = NULL;
    node_t *nodeToRemove = NULL;
    
#ifdef SHOW_DEBUG_CONTENT
    printf("Shrinking ring buffer from %d to %d\n", currentLength, desiredLength);
#endif
    
    // new length can't be less than 1
    if (desiredLength < 1)
    {
        printf("Ring buffer size can't be less than 1, changing size to 1\n");
        desiredLength = 1;
    }
    
    // loop until the desired length is reached
    // e.g. node before oldest: 9 (tmp), oldest: 5 (nodeToRemove)
    // 8->9->5->6->7
    // 8->9---->6->7
    // new oldest: 6
    while (currentLength > desiredLength)
    {
        // get node before oldest
        tmp = getNodeBefore(pb, pb->oldest);
        
        // node to be removed (oldest) is next of node before oldest
        nodeToRemove = tmp->next;
        
        // if the node to be removed would be the head node in the ring buffer
        if (nodeToRemove == pb->head)
        {
            // the new head node is now the node after the node to be removed
            pb->head = nodeToRemove->next;
#ifdef SHOW_DEBUG_CONTENT
            printf("Head node is now: %d\n", pb->head->data);
#endif
        }
        
        // oldest node in ring buffer is now next of node to be removed
        pb->oldest = nodeToRemove->next;
        
        // shrink ring buffer
        tmp->next = nodeToRemove->next;

        // free the node to remove (oldest) from memory
        free(nodeToRemove);

        // calculate the new length
        currentLength = getLength(pb);

#ifdef SHOW_DEBUG_CONTENT
        printf("New length of ring buffer: %d\n", currentLength);
        displayList(pb);
        printf("\n");
#endif
    }
}

void expandRingbuffer(ring_buffer_t *pb, int increase)
{
    if (increase == 0)
    {
        // nothing to do
        return;
    }
    
    int currentLength = getLength(pb);
    int desiredLength = currentLength + increase;
    node_t *latestNode = NULL;
    
#ifdef SHOW_DEBUG_CONTENT
    printf("Expanding ring buffer from %d to %d\n", currentLength, desiredLength);
#endif
    
    // loop until the desired length is reached
    // e.g. latest node: 9 (latestNode)
    // 8->9->5->6->7
    // 8->9->10->5->6->7
    while (currentLength < desiredLength)
    {
        // get the latest node
        latestNode = pb->latest;
        
        // create new empty node in memory
        node_t *newNode = getNode();
        
        // set the empty flag
        newNode->isEmpty = true;
        
        // the next of new node is the next of latest node
        newNode->next = latestNode->next;
        
        // next of latest node is the new node
        latestNode->next = newNode;
        
        // latest node in ring buffer is new node
        pb->latest = newNode;
        
        // calculate the new length
        currentLength = getLength(pb);
        
#ifdef SHOW_DEBUG_CONTENT
        printf("New length of ring buffer: %d\n", currentLength);
        displayList(pb);
#endif
    }

#ifdef SHOW_DEBUG_CONTENT
    printf("Oldest node after expansion is: %d\n", pb->oldest->data);
#endif
}

void resizeRingbuffer(ring_buffer_t *pb, int change)
{
    if (change > 0)
    {
        expandRingbuffer(pb, change);
    }
    else if (change < 0)
    {
        shrinkRingbuffer(pb, change);
    }
    else
    {
        // pass, ring buffer has already desired size
    }
}

void printAverage(ring_buffer_t *pb)
{
    int average = 0;
    
    calcAverage(pb, &average);
    
    printf("Average: %d\n", average);
}

int main()
{
    // each node requires 20 byte of RAM
    int size = 5;
    // printf("Enter the fixed size of the buffer: ");
    // scanf("%d", &size);
    
    ring_buffer_t *newRing = create_new_buffer(size);
    printf("Size of ringbuffer: %d\n", getLength(newRing));
    printf("\n");
    
    printf("Content after init:\n");
    displayList(newRing);
    printf("\n");
    
    printf("Start inserting content to ring buffer\n");
    for (int i = 1; i <= size+2; i++)
    {
        printf("\t"); insert(newRing, i);
        // displayList(newRing);
        // printAverage(newRing);
        // printf("\n");
    }
    displayList(newRing);
    printf("Ring buffer filled\n");
    printf("\n");
    
    // find node before the oldest node
    printf("Node before oldest node: content: ");
    getNodeBefore(newRing, newRing->oldest);
    printf("\n");
    
    // find node before the latest node
    printf("Node before latest node: content: ");
    getNodeBefore(newRing, newRing->latest);
    printf("\n");
    
    // shrinking ring buffer
    int shrinkSize = 1;
    shrinkRingbuffer(newRing, shrinkSize);
    printf("Finished shrinking\n");
    printf("\n");

    // expanding ring buffer
    int expansionSize = 7;
    expandRingbuffer(newRing, expansionSize);
    printf("Finished expansion\n");
    printf("\n");

    printf("Filling ring buffer up again\n");
    for (int i = 1; i <= expansionSize+1; i++)
    {
        printf("\t"); insert(newRing, i+100);
        // displayList(newRing);
        // printAverage(newRing);
        // printf("\n");
    }
    displayList(newRing);
    printf("Ring buffer filled\n");
    printf("\n");
    
    printf("Finished all operations\n");
    
    return 0;
}

