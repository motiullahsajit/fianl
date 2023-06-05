#include<stdio.h>

#define CAPACITY 5

int ourQueue[CAPACITY];

int front = 0, rear = -1, totalItem = 0;

int isFull(){
    if(totalItem == CAPACITY)
        return 1;
    else 
        return 0;
}

int isEmpty(){
    if(totalItem == 0) 
        return 1;
    else 
        return 0;
}

void enqueue(int item){
    if(isFull()){
        printf("Overflow\n");
    }else{
        rear = (rear + 1) % CAPACITY;
        ourQueue[rear] = item;
        totalItem++;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Underflow\n");
    }else{
        ourQueue[front] = NULL;
        front = (front + 1) % CAPACITY;
        totalItem--;
    }
}

void printQueue(){
    printf("Queue\n");

    for(int i=0; i<CAPACITY; i++){
        printf("%d ",ourQueue[i]);
    }
    printf("\n");
}

int main(){
    int input,x;

    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&input);

        if(input == 1){
            printf("Enter the element : ");
            scanf("%d",&x);
            enqueue(x);
        }else if(input == 2){
            dequeue();
        }else if(input == 3){
            printQueue();
        }else if(input == 4){
            break;
        }

    }
        
}
