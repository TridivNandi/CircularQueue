// ================== Assignment2 =================================================================================
// Name: 							TridivNandi
// Hours required to complete the Assignment:			9 hours
// Did you collaborate with any students/TAs/Professors? 	No
// Did you use any external resources?				No
// What was your favourite part of the assignment?		I have solved similar data structure design questions using Java and Python before. It was nice implementing the same concepts with a lower level language like C where you have full control over everything like memory allocation and memory deallocation




// =================== Support Code =================
// Queue
//
// - Implement each of the functions.
// - Do not change any of the function declarations
//   - (i.e. queue_t* create_queue(unsigned int _capacity) should not have additional arguments)  
// ==================================================
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// The main data structure for the queue
struct queue{
	unsigned int back;	    // The next free position in the queue
				                  // (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
				                  // (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we have enqueued.
	unsigned int capacity;  // Number of items the queue can hold
	int* data; 		          // The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity){
	
	
	queue_t* myQueue = (queue_t*) malloc(sizeof(queue_t));
	myQueue->front = 0;
	myQueue->back = 0;
	myQueue->size = 0;
        myQueue->capacity = _capacity;
	myQueue->data = (int*) malloc(sizeof(int) * _capacity);	
	return myQueue;
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has more space available)
int queue_empty(queue_t* q){
	
	// if size == 0 then the queue is empty
	if(q->size==0){
		return 1;
	}
	else{
		return 0;
	}
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available)
int queue_full(queue_t* q){
	
	// if size == capacity then the queue is full
	if(q->size == q->capacity){
		return 1;
	}
	else{
		return 0;
	}
}


// Enqueue a new item
// i.e. push a new queue into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the queue is full).
int queue_enqueue(queue_t *q, int item){
	
	if(queue_full(q) == 1){
		return -1;
	}
	else{
		q->data[q->back++] = item;
		q->back = q->back % q->capacity;
		q->size = q->size + 1;
		return 0;
	}
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
int queue_dequeue(queue_t *q){

	if(queue_empty(q) == 1){
		printf("Queue is empty! Please enqueue some elements before dequeue operation...\n");
//		exit(0);
	}
	else{
		int retVal = q->data[q->front++];
		q->front = q->front % q->capacity;
		q->size = q->size - 1;
		return retVal;
	}
}


// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL q cannot return the size.)
unsigned int queue_size(queue_t* q){

	return q->size;
}


// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
	
	free(q->data);
	free(q);
}



// =============================================================================================================
// =================================================== Utility Methods =========================================
// =============================================================================================================

// Prints the elements of the queue
// It starts printing elements from the front of the queue and prints all of it's elements
void printElements(queue_t* q){

        if(queue_empty(q)){
                printf("The queue is empty!\n");
        }
        else if(q->back > q->front){
                for(int i=q->front; i<q->back; i++){
                        printf("%d\n", q->data[i]);
                }
        }
        else{
                for(int i=q->front; i<q->capacity; i++){
                        printf("%d\n", q->data[i]);
                }
                for(int i=0; i<q->back; i++){
                        printf("%d\n", q->data[i]);
                }
        }
 }

// Prints a seperator line 
void printSeperator(){
        printf("==============================================================================================\n");
}




// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	printSeperator();

	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
	printSeperator();

}


// Unit test for Overflow condition
void unitTest_overflow(){
	
	printSeperator();
	
	printf("Creating a queue of capacity 3... \n");
	queue_t* sampleQueue = create_queue(3);

	printf("Size of the queue is  %d\n", queue_size(sampleQueue));
	printf("Attempting to add. Addition attempt Success: %d\n", queue_enqueue(sampleQueue, 1));
	printf("Attempting to add. Addition attempt Success: %d\n", queue_enqueue(sampleQueue, 2));
	printf("Attempting to add. Addition attempt Success: %d\n", queue_enqueue(sampleQueue, 3));
	printf("Attempting to add. Addition attempt Success: %d\n", queue_enqueue(sampleQueue, 4));
	printf("Size of the queue is  %d\n", queue_size(sampleQueue));
	
	printf("Printing Elements... \n");
	printElements(sampleQueue);

	free_queue(sampleQueue);
	printSeperator();
}

// Unit test for Underflow condition
void unitTest_underflow(){

	printSeperator();
	printf("Creating a queue of capacity 1... \n");

	queue_t* sampleQueue = create_queue(1);
	printf("Size of the queue is %d\n", queue_size(sampleQueue));	
	printf("Attempting to delete... \n");
	queue_dequeue(sampleQueue);

	free_queue(sampleQueue);
	printSeperator();
}

// Unit test for checking the conditions when the queue is full 
void unitTest_queueFull(){
		
	printSeperator();
	printf("Creating a queue of capacity 1... \n");

	queue_t* sampleQueue = create_queue(1);
	printf("Is Queue full: %d\n", queue_full(sampleQueue));
	printf("Attempting to add. Addition attempt Success: %d\n", queue_enqueue(sampleQueue, 1));
	printf("Is Queue full: %d\n", queue_full(sampleQueue));

	free_queue(sampleQueue);
	printSeperator();
}

// Unit test for checking the conditions when the queue is empty
void unitTest_queueEmpty(){

	printSeperator();
	printf("Creating a queue of capacity 1... \n");

	queue_t* sampleQueue = create_queue(1);
	printf("Is Queue empty: %d\n", queue_empty(sampleQueue));
        printf("Attempting to add. Addition attempt Success: %d\n", queue_enqueue(sampleQueue, 1));
	printf("Is Queue empty: %d\n", queue_empty(sampleQueue));
	printf("Removing: %d\n",queue_dequeue(sampleQueue));
	printf("Is Queue empty: %d\n", queue_empty(sampleQueue));

	free_queue(sampleQueue);
	printSeperator();
}

// Unit test for checking enqueue and dequeue opearations in the circular queue
void unitTest_insertionAndDeletion(){

	printSeperator();

	printf("Creating a queue of capacity 3... \n");

	queue_t* sampleQueue = create_queue(3);

	printf("Printing elements... \n");
	printElements(sampleQueue);
	
	printf("Adding elements. \n");
	queue_enqueue(sampleQueue, 3);
	queue_enqueue(sampleQueue, 33);
	queue_enqueue(sampleQueue, 333);

	printf("Printing elements... \n");
	printElements(sampleQueue);

	printf("Removing elements... \n");
	printf("Removing: %d\n",queue_dequeue(sampleQueue));
	printf("Removing: %d\n",queue_dequeue(sampleQueue));

	printf("Printing elements... \n");
	printElements(sampleQueue);

	printf("Adding elements again. \n");
	queue_enqueue(sampleQueue, 93);
	queue_enqueue(sampleQueue, 933);
	queue_enqueue(sampleQueue, 1433);

	printElements(sampleQueue);

	printf("The front is: %d\n", sampleQueue->front);
	printf("The back is: %d\n", sampleQueue->back);
	
	printf("Removing: %d\n",queue_dequeue(sampleQueue));
	printf("The front is: %d\n", sampleQueue->front);
        printf("The back is: %d\n", sampleQueue->back);
	
	printf("Adding elements again. \n");
	queue_enqueue(sampleQueue, 1733);
	printf("Printing elements... \n");
	printElements(sampleQueue);
	printf("The front is: %d\n", sampleQueue->front);
        printf("The back is: %d\n", sampleQueue->back);

	printSeperator();
}

// Unit test for checking the size on a NULL queue
void unitTest_sizeCheckOnNull(){
	
	queue_size(NULL);
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest_overflow();
	unitTest_underflow();
	unitTest_queueFull();
	unitTest_queueEmpty();
	unitTest_insertionAndDeletion();
//	unitTest_sizeCheckOnNull();

	printf("Reached end of program. \n");
	return 0;
}
