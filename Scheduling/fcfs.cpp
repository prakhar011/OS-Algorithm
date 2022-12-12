#include<iostream>
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
        int waiting_time;
};

int main(){
    int number_of_process;
    cout<<"Enter the number of process: ";
    cin>>number_of_process;

    Process process[number_of_process];

    for(int i=0; i<number_of_process; i++){
        cout<<"Enter the arrival time of process "<<i+1<<": ";
        cin>>process[i].arrival_time;
        cout<<"Enter the burst time of process "<<i+1<<": ";
        cin>>process[i].burst_time;
        process[i].pid = i+1;
    }

    sort(process, process+number_of_process, [](Process a, Process b){
        return a.arrival_time < b.arrival_time;
    });

    int time = 0;

    for(int i=0; i<number_of_process; i++){
        if(time < process[i].arrival_time){
            time = process[i].arrival_time;
        }
        process[i].start_time = time;
        process[i].completion_time = time + process[i].burst_time;
        time = process[i].completion_time;
        process[i].turn_around_time = process[i].completion_time - process[i].arrival_time;
        process[i].waiting_time = process[i].turn_around_time - process[i].burst_time;
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
