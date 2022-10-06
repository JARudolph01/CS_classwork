#include <iostream>
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