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
            for(int i=0;i<numOfServers;i++){
                if(!servers[i]->isFree()){
                    printf("should not trigger");
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
            for(int i=0;i<numOfServers;i++){
                servers[i]->decreaseTransactionTime();
            }
        }

        ServerList(int serverCount) {
            numOfServers=serverCount;
            servers=new Server*[serverCount];
            for(int i=0;i<serverCount;i++){
                servers[i]=new Server();
            }
        }
};

class TaskQueue{
    public:
        Task **tasks;
        int numOfTasksInQueue=0;


        bool isEmptyQueue(){
            return numOfTasksInQueue<=0;
        }

        Task pop(){
            Task *output = tasks[0];

            numOfTasksInQueue--;
            Task **newTasks = new Task*[numOfTasksInQueue];
            for(int i=0;i<numOfTasksInQueue;i++){
                newTasks[i]=tasks[i+1];
            }
            tasks=newTasks;

            return *output;
        }

        void push(Task *t){
            numOfTasksInQueue++;
            Task **newTasks = new Task*[numOfTasksInQueue];
            newTasks[0]=t;
            for(int i=1;i<numOfTasksInQueue;i++){
                newTasks[i]=tasks[i-1];
            }
            tasks=newTasks;
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

    // printf("hi");
    Task *t = new Task(1,2,3,4);
    Task *t2 = new Task(5,6,7,8);
    // printf("%d",t->getArrivalTime());


    Server *s = new Server();
    Server *s2 = new Server();

    ServerList sl = ServerList(5);

    // printf("%d",sl.getFreeServerID());

    sl.decrementTheTransactionTimeOfAllTheBusyServersPlease();

    s->setCurrentTask(t);


    TaskQueue q;
    q.push(t);
    q.push(t2);
    printf("%d",q.pop().getArrivalTime());
    printf("%d",q.pop().getArrivalTime());

    // printf("%d",q.isEmptyQueue());


    // printf("%d",s->getCurrentTaskWaitingTime());
    return 0;
}

// int main() {
// 	int nus, nut, tTimeL, tTimeU, aTimeRate, simTime;

// 	taskQueue tQueue;
	
// 	std::cout << "Welcome to the tasks' simulator\n\n";

// 	std::cout << "Enter number of servers:";
// 	std::cin >> nus;
// 	serverList sList(nus);
	
// 	std::cout << "Enter number of tasks:";
// 	std::cin >> nut;

// 	std::cout << "For transaction time, enter the range's lower value:";
// 	std::cin >> tTimeL;

// 	std::cout << "For transaction time, enter the range's upper value:";
// 	std::cin >> tTimeU;

// 	int oldRange = (RAND_MAX - 0);
// 	int newRange = (tTimeU - tTimeL);

// 	std::cout << "Enter task's arrival time rate:";
// 	std::cin >> aTimeRate;

// 	std::cout << "Enter total time of simulation:";
// 	std::cin >> simTime;

// 	srand(10);
// 	int taskNu = 1;

// 	for (int tCo = 1; tCo <= simTime; tCo++) {
// 		std::cout << "Time: " << tCo << std::endl;
// 		// 1- Update all servers transaction time (decrement by 1)
// 		sList.updateServers();
// 		// 2- Update waiting time (increment by 1) of all tasks in the queue
// 		tQueue.updateWaitTime();
// 		// 3- Check if it is time for arrival of tasks
// 		if (tCo % aTimeRate == 0) {
// 			// Generate random transaction time
// 			int r = rand();
// 			r = (((r-0) * newRange) / oldRange) + tTimeL;
// 			// Create a new task
// 			task t(taskNu,tCo, 0, r);
// 			tQueue.addQueue(t);
// 			std::cout << "New task " << taskNu << " arrived at time " << tCo << " with transaction time of " << r << "\n";
// 			++taskNu;
// 		}
// 		// 4- Check if a server is free and tasks' queue is non empty to push a task
// 		int sID = sList.getFreeServerID();
// 		if (sID != -1) {
// 			if (tQueue.isEmptyQueue() == false) {
// 				task t = tQueue.front();
// 				sList.setServerBusy(sID, t);
// 				tQueue.deleteQueue();
// 				std::cout << "Task " << t.getTaskNumber() << " is admitted to server " << sID << "\n";
// 			}
// 		}
// 	}

// 	return 0;
// }
