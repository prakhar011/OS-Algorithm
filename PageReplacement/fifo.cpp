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

    cout << "Number of page faults: " << pageFaults << endl;
    return 0;

}

// 1303563 ,freame size = 3, page faults = 5
// 70120304230323 ,freame size = 4, page faults = 6
