#include <iostream>
#include <string>
using namespace std;

class Task {       // The class
  public:             // Access specifier
    int task_number;        // Attribute (int variable)
    int arrival_time;  // Attribute (string variable_n
    int waiting_time;
    int transaction_time;

    void setCustomerInfo(int taskNum = 0, int waitingTime = 0, int arrivalTime = 0, int transactionTime = 0) {
         this.task_number = taskNum;
         this.waiting_time = waitingTime;
         this.arrival_time = arrivalTime;
         this.transaction_time = transactionTime;
      }

    int getWaitingTime()
    {
        return this.waiting_time;
    }
    void setWaitingTime(int waitingTime){
        this.waiting_time = waitingTime;
    }
    void incrementWaitingTime()
    {
        this.waiting_time++;
    }

    const int getArrivalTime(){
        return this.arrival_time;
    }

    const int getTransactionTime()
    {
        return this.transaction_time;
    }

    int getTaskNumber(){
        return this.task_number;
    }

    Task(int taskNum, int waitingTime, int arrivalTime, int transactionTime) {
      this.task_number = taskNum;
      this.waiting_time = waitingTime;
      this.arrival_time = arrivalTime;
      this.transaction_time = transaction_time;
    }
};

class Server{
    Task currentTask;
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
        this.transaction_time=transactionTime;
    }

    void setTransactionTime(){
        this.transaction_time=currentTask.transaction_time;
    }

    const int getRemainingTransactionTime()
    {
        return this.transaction_time;
    }

    void decreaseTransactionTime(){
        this.transaction_time--;
    }
    
    void setCurrentTask(Task task)
    {
        this.currentTask = task;
    } 
    int getCurrentTaskNumber(){
        return this.currentTask.task_number;
    }

    int getCurrentTaskArrivalTime()
    {
        return this.currentTask.arrival_time;
    }
    int getCurrentTaskWaitingTime(){
        return this.currentTask.waiting_time;
    }

    int getCurrentTaskTransactionTime()
    {
        return this.currentTask.transaction_time;
    }



    Server() {
      this.currentTask=NULL;
      this.status="Free";
      this.transaction_time=0;
    }



}