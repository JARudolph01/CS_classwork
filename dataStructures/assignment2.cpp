#include <iostream>
#include <string>
#include <queue>

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

    Task(int taskNum, int waitingTime, int arrivalTime, int transactionTime) {
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
    
        Server *servers;
        int numOfServers=sizeof(servers);

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
            servers=new Server[serverCount];
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




    queue<Task> tasks;

    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    return 0;
};