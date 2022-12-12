#include<iostream>
#include <vector>
#include<list>
#include<algorithm>
using namespace std;

class Process{
    public:
        int pid;
        int arrival_time;
        int burst_time;
        int start_time;
        int completion_time;
        int turn_around_time;
        int remaining_time;
        int waiting_time;
};

int main(){
    int number_of_process;
    cout<<"Enter the number of process: ";
    cin>>number_of_process;

    int time_quantum;
    cout<<"Enter the time quantum: ";
    cin>>time_quantum;

    Process process[number_of_process];

    for(int i=0; i<number_of_process; i++){
        cout<<"Enter the arrival time of process "<<i+1<<": ";
        cin>>process[i].arrival_time;
        cout<<"Enter the burst time of process "<<i+1<<": ";
        cin>>process[i].burst_time;
        process[i].pid = i+1;
        process[i].remaining_time = process[i].burst_time;
        process[i].start_time = -1;
    }

    sort(process, process+number_of_process, [](Process a, Process b){
        return a.arrival_time < b.arrival_time;
    });

    int time = 0;

    list<Process> ready_queue;

    ready_queue.push_back(process[0]);
    cout<<"Process "<<process[0].pid<<" is added to the ready queue"<<endl;
    int i = 1;
    while(!ready_queue.empty()){
        Process current_process = ready_queue.front();
        ready_queue.pop_front();
        if(time < current_process.arrival_time){
            time = current_process.arrival_time;
        }
        if(current_process.start_time == -1)
            current_process.start_time = time;
        if(current_process.remaining_time <= time_quantum){
            time += current_process.remaining_time;
            current_process.completion_time = time;
            current_process.remaining_time = 0;
        }
        else{
            time += time_quantum;
            current_process.completion_time = time;
            current_process.remaining_time -= time_quantum;
        }
        if(current_process.remaining_time == 0){
        current_process.turn_around_time = current_process.completion_time - current_process.arrival_time;
        current_process.waiting_time = current_process.turn_around_time - current_process.burst_time;
        }
        while(i < number_of_process && process[i].arrival_time <= time){
            ready_queue.push_back(process[i]);
            i++;
        }
        if(current_process.remaining_time > 0){
            ready_queue.push_back(current_process);
        }
        else{
            process[current_process.pid-1] = current_process;
        }
    }


    cout<<"\nProcess ID\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for(int i=0; i<number_of_process; i++){
        cout<<process[i].pid<<"\t\t"
            <<process[i].arrival_time<<"\t\t"
            <<process[i].burst_time<<"\t\t"<<
            process[i].start_time<<"\t\t"<<
            process[i].completion_time<<"\t\t"
            <<process[i].turn_around_time<<"\t\t"
            <<process[i].waiting_time<<endl;
    }

    return 0;
}
