#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;



class Task {
  public:    
    int task_number;  
    int arrival_time;
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
        
        void setCurrentTask(Task *task)
        {
            currentTask = task;
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
    
        Server **servers;
        int numOfServers;
        // Server servers[numOfServers]={}

        const int getFreeServerID(){
            for(int i=0;i<numOfServers;i++){
                if(servers[i]->isFree()){
                    return i;
                }
            }
            printf("no free servers");
            return -1;
        }

        const int getNumberOfBusyServers()
        {
            int count = 0;
            for(int i=0;i<numOfServers;i++){
                if(!servers[i]->isFree()){
                    count++;
                }
            }
            return count;
        }

        void decrementTheTransactionTimeOfAllTheBusyServersPlease(){
            for(int i=0;i<sizeof(servers);i++){
                if(!servers[i]->isFree()){
                    servers[i]->decreaseTransactionTime();
                }
            }
        }

        void setServerBusy(int a, Task task, int b){ //no clue what he wants    
        }

        void setServerBusy(int serverIndex,Task *task){
            servers[serverIndex]->setCurrentTask(task);
        }

        void updateServers(){
            for(int i=0;i<sizeof(servers);i++){
            servers[i]->decreaseTransactionTime();
            }
        }

        ServerList(int serverCount) {
            serverCount=serverCount;
            servers=new Server*[serverCount];
            for(int i=0;i<serverCount;i++){
                servers[i]=new Server();
            }
        }
};



int main(){
    int 
        simulationTime, 
        numberOfServers, 
        numberOfTasks, 
        transactionTimeMin,
        transactionTimeMax,
        timeBetweenTasks;

    printf("hi");
    Task *t = new Task(1,2,3,4);
    printf("%d",t->getArrivalTime());


    Server *s = new Server();

    s->setCurrentTask(t);
    printf("%d",s->getCurrentTaskWaitingTime());
    return 0;
}