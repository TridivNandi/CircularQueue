# CircularQueue
This repository contains an implementation of Circular Queue. 

A 'queue' data structure is analogous to waiting in line at a grocery store. The first person to the checkout counter is served, followed by the next person, and then the next until the line is empty. A queue is what is known as a 'first-in first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed.

This is a specific implementation of a queue using an array. This data structure is also called a circular queue (specifically a ring buffer when the maximum storage size is fixed).

## Part 1 - Queue implementation as an array (Ring Buffer).

A circular buffer has a fixed sized, or maximum number of elements that it can hold. This is advantageous if we know how many elements are typically stored in a data structure (If we do not know, then a queue with a linked list implemetation is needed). 

For more information on the Circular buffer, see here: https://en.wikipedia.org/wiki/Circular_buffer

This animation below gives an idea about how the data structure 'wraps' around. Think about what mathematical operator could be useful in your implementation when enqueuing and dequeuing items in your queue.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)

## Part 2 - Why is a ring buffer/circular queue useful?

Ring buffer is useful for the following reason: <br />
        > Effecient memory management: If we are using normal queues then there can be certain scenarios where there is space at the front of the queue but we cannot enter elements which leads to ineffecient memory management. In case of circular queue there is always effecient management of memory as we keep moving the back pointer to the beginning of the queue when it reaches the maximum capacity.<br />
        > Effecient time complexity: Circular queue provides O(1) i.e constant time complexity for both enqueue and dequeue operations. Hence, it is widely used in operations where we need fast insertion and deletion of data in First-In-First-Out manner. <br />

Ring Buffer is  used in the following scenarios:<br />
        > In case of any job scheduling problems, we can use circular queue so that there is effecient management of memory and we can get enqueuing and dequeuing operations in constant time complexity. Moreover, it gives priority to that job which has been waiting for the longest time. <br />
        > In case of I/O buffering, we can use use circular queue as always need the data in First-In-First-Out manner. Using a circular queue for this use case also makes sure that we do effecient memory management in our implementation of queue.<br />
        > In case of realtime processing where older entries are discarded and overwritten when the buffer is overflown, circular queue is an ideal choice of data structure.<br />
        
