#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

class Task {       // The class
  public:             // Access specifier
    int task_number;        // Attribute (int variable)
    int arrival_time;  // Attribute (string variable_n
    int waiting_time;
    int transaction_time;

    void setCustomerInfo(int taskNum = 0, int waitingTime = 0, int arrivalTime = 0, int transactionTime = 0) {
         task_number = taskNum;
         waiting_time = waitingTime;
         arrival_time = arrivalTime;
         transaction_time = transactionTime;
    }

    int getWaitingTime()
    {
        return waiting_time;
    }
    void setWaitingTime(int waitingTime){
        waiting_time = waitingTime;
    }
    void incrementWaitingTime()
    {
        waiting_time++;
    }

    const int getArrivalTime(){
        return arrival_time;
    }

    const int getTransactionTime()
    {
        return transaction_time;
    }

    int getTaskNumber(){
        return task_number;
    }

    Task(int taskNum, int arrivalTime, int transactionTime, int waitingTime=0) {
      task_number = taskNum;
      waiting_time = waitingTime;
      arrival_time = arrivalTime;
      transaction_time = transaction_time;
    }
};

class Server{
    public:
        Task *currentTask;
        string status;
        int transaction_time;

        bool isFree(){
            return status=="Free";
        }
        void setBusy()
        {
            status = "Busy";
        }
        void setFree(){
            status="Free";
        }

        void setTransactionTime(int transactionTime){
            transaction_time=transactionTime;
            status="Busy";
        }

        void setTransactionTime(){
            transaction_time=currentTask->transaction_time;
        }

        const int getRemainingTransactionTime()
        {
            return transaction_time;
        }

        void decreaseTransactionTime(){
            transaction_time--;
            if(transaction_time<=0){
                status="Free";
            }
        }
        
        void setCurrentTask(Task task)
        {
            currentTask = &task;
            status="Busy";
            setTransactionTime();
        } 
        int getCurrentTaskNumber(){
            return currentTask->task_number;
        }

        int getCurrentTaskArrivalTime()
        {
            return currentTask->arrival_time;
        }
        int getCurrentTaskWaitingTime(){
            return currentTask->waiting_time;
        }

        int getCurrentTaskTransactionTime()
        {
            return currentTask->transaction_time;
        }



        Server() {
            currentTask=NULL;
            status="Free";
            transaction_time=0;
        }
};


class ServerList{
    public:
    
        // Server servers[0]={};
        int numOfServers;
        Server servers[numOfServers]={}

        const int getFreeServerID(){
            for(int i=0;i<sizeof(servers);i++){
                if(servers[i].isFree()){
                    return i;
                }
            }
            printf("no free servers");
            return -1;
        }

        const int getNumberOfBusyServers()
        {
            int count = 0;
            for(int i=0;i<sizeof(servers);i++){
                if(!servers[i].isFree()){
                    count++;
                }
            }
            return count;
        }

        void decrementTheTransactionTimeOfAllTheBusyServersPlease(){
            for(int i=0;i<sizeof(servers);i++){
                if(!servers[i].isFree()){
                    servers[i].decreaseTransactionTime();
                }
            }
        }

        void setServerBusy(int a, Task task, int b){ //no clue what he wants    
        }

        void setServerBusy(int serverIndex,Task task){
            servers[serverIndex].setCurrentTask(task);
        }

        void updateServers(){
            for(int i=0;i<sizeof(servers);i++){
            servers[i].decreaseTransactionTime();
            }
        }

        ServerList(int serverCount) {
            serverCount=serverCount;
            servers=new Server[serverCount];
            for(int i=0;i<serverCount;i++){
                servers[i]=new Server();
            }
            
        }
};



int main()
{
    int simulationTime, numberOfServers, numberOfQueues, numberOfTasks, taskMinimumTransactionTime, taskMaximumTransactionTime, timeBetweenTasks;

    printf("simulationTime: ");
    scanf("%d", int simulationTime);
    printf("Number of Servers: ");
    scanf("%d", int numberOfServers);
    printf("Number of Queues: ");
    scanf("%d", int numberOfQueues);
    printf("Number of Tasks: ");
    scanf("%d", int numberOfTasks);
    printf("Minimum transaction time: ");
    scanf("%d", int taskMinimumTransactionTime);
    printf("Maximum transaction time: ");
    scanf("%d", int taskMaximumTransactionTime);
    printf("Time between task arrivals: ");
    scanf("%d", int timeBetweenTasks);

    serverList = new ServerList(numberOfServers);


    queue<Task> tasks;
    int currentTaskNum=0;

    for(int i = 0; i < simulationTime; i++)
    {
        //queue new tasks
        if(i % timeBetweenTasks == 0 && numberOfTasks != 0)
        {
            tasks.push(new Task(currentTask, i, (rand() % (taskMaximumTransactionTime-taskMinimumTransactionTime)+taskMinimumTransactionTime),0));
            currentTaskNum++;
            numberOfTasks--;
        }

        //send task to server
        int freeID=serverList.getFreeServerID();
        if(freeID!=-1 && !tasks.empty()){
            serverList.setServerBusy(freeID, tasks.front());
            tasks.pop();
        }

        serverList.updateServers();


        
        serverList.decrementTheTransactionTimeOfAllTheBusyServersPlease();

        Task tmpTasks = [numberOfTasks];
        int tmpIndex=0;
        while(!tasks.empty()){
            tmpTasks[tmpIndex]=tasks.front();
            tmpIndex++;
            tasks.pop();
        }
        for(int i=0;i<numberOfTasks;i++){
            tmpTasks[tmpIndex].waiting_time++;
            tasks.push(tmpTasks[tmpIndex]);
        }
    }





    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    return 0;
};