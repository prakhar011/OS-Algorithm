#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main(){
    string pageRequestSequence;
    int frameSize;
    cin>>pageRequestSequence;
    cin>>frameSize;
    int numberOfPageRequests = pageRequestSequence.length();
    int pageFaults = 0;
    list<char> frame;
    list<char>::iterator it;

    for(int i=0; i<numberOfPageRequests; i++){
        it = find(frame.begin(), frame.end(), pageRequestSequence[i]);
        if(it == frame.end()){
            if(frame.size() == frameSize){
                frame.pop_front();
            }
            frame.push_back(pageRequestSequence[i]);
            pageFaults++;
        }
        else{
            frame.erase(it);
            frame.push_back(pageRequestSequence[i]);
        }
    }
    cout<<"Number of page faults: "<<pageFaults<<endl;
}


// 123215216256313
// framesize = 3, pagefaults = 8

// 12321521625631361243
// framesize = 3, pagefaults = 11
