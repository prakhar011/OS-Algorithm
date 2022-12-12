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
        cout<<"Page Request: "<<pageRequestSequence[i]<<" // ";
        it = find(frame.begin(), frame.end(), pageRequestSequence[i]);

        if(it == frame.end()){
            if(frame.size() == frameSize){
                frame.pop_back();
            }
            frame.push_back(pageRequestSequence[i]);
            pageFaults++;
        }
        else{
            frame.erase(it);
            frame.push_back(pageRequestSequence[i]);
        }

        // cout<<"Frame: ";
        // for(auto itr = frame.begin(); itr != frame.end(); itr++){
        //     cout<<*itr<<" ";
        // }
        // cout<<endl;
    }

    cout<<"Number of page faults: "<<pageFaults<<endl;
    return 0;
}


// 123456123456123456123456
// framesize = 4, pagefaults = 12
