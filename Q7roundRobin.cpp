#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;



class process{
    static int kk;

string name ="P"+to_string(kk);
int arrival_time;
int burst_time;

public:
int order = kk-1;
   int getArrival(){
       return arrival_time;}
       
       
       void setBurst(int n){
           burst_time=n;
    }

   int getBurst(){
     return burst_time;}

     process(int a,int b){
         
        arrival_time= a;
        burst_time=b;
        kk++;
     }

     void print(){
     cout<<name<<"  "<<"arrival :"<<arrival_time<<"burst time :"<<burst_time<<endl;}
     
      bool operator<(const process &r) const
    {
       
        return arrival_time <= r.arrival_time;

    }
 
    // overload the operator> (if required)
    bool operator>(const process &r) const
    {
  
        return arrival_time >= r.arrival_time;
    }


  

  
    bool equals(process b){
        if(name == b.name){
            
            return true;
        }else{
            return false;
        }
    }

};


void removeElement(vector<process> &v ,process p){

    for(int i=0;i<v.size();++i){
        if(v.at(i).equals(p)){
            v.erase(v.begin()+i);
        }
    }

}
int indexf(vector<process> &v ,process p){
      for(int i=0;i<v.size();++i){
        if(v.at(i).equals(p)){
            return i;
        }
    }
    return 0;
    
}

int process::kk = 1;


int main(){
    
    
    vector<process> v;
    process p1(0,5);
    process p2(1,4);
    process p3(2,2);
    process p4(4,1);
    
      v.push_back(p1);
      v.push_back(p2);
      v.push_back(p3);
      v.push_back(p4);
       vector<process> b;
        b.push_back(p1);
      b.push_back(p2);
      b.push_back(p3);
      b.push_back(p4);
    
    vector<process> temp ;
    vector<int> completiontime;
      
      
      
    sort(v.begin(),v.end());
    sort(temp.begin(),temp.end());
    
    int time_quantum =2;
    
    
    queue<process> readyque;
    vector<int> arr;
    int timer =0;
    
    arr.push_back(0);
    int process_done =0;
    bool done = true;
    int flag=0;
     process *prev ;
    while(process_done != 4 ){
    
        
        
         for(int i= 0; i< v.size();++i){       //this loop will make a queue of process for 2th seconds
        
        if(v.at(i).getArrival() <= timer){
            readyque.push(v.at(i));
              removeElement(v,v.at(i));
              --i;
        }
    }
    
    
    
    
    if(!done){
        readyque.push(*prev);
    }
    
    
    
    
        if(readyque.size() == 0){   //jab ready que is empty()
            timer += 1;
            flag +=1;
            if(flag==2){
                arr.push_back(time_quantum);
                flag=0;
            }
            
            
        }else{
            if(flag < time_quantum & flag > 0){
                  arr.push_back(flag);
            }
             
            flag=0;
            if(readyque.front().getBurst() - time_quantum < 0){   // 1 - 2
                
                   timer +=time_quantum - readyque.front().getBurst();
                        readyque.front().setBurst(0);
                
            }else{
                 readyque.front().setBurst(readyque.front().getBurst() - time_quantum);
                 timer +=2;
               
                prev = &readyque.front();
                 
            }
           
            
            if(readyque.front().getBurst() == 0){
                process_done++;
                arr.push_back(timer);
                completiontime.push_back(timer);
                done = true;
                
                temp.push_back(readyque.front());
                readyque.pop();
             
            }else{
                done = false;
                readyque.pop();
            }
            
            
        }
    }


cout<<endl;
vector<int> tat ;
int sum=0;
for(int i=0;i < completiontime.size();++i){
    tat.push_back(completiontime.at(i) - temp.at(i).getArrival());
    sum += tat.at(i);
    cout<<tat.at(i)<<endl;
}    
cout<<"avg compl. time : "<<sum/4.0<<endl;

int total=0;
vector<int> wt ;

 for(int i=0;i < completiontime.size();++i){
     cout<<tat.at(i)<<"  -  "<<b.at(indexf(b,temp.at(i))).getBurst()<<endl;
   wt.push_back( tat.at(i) - b.at(indexf(b,temp.at(i))).getBurst());
    total += wt.at(i);
    cout<<wt.at(i)<<endl;
}  
  cout<<"avg waiting time : "<<total/4.0<<endl;
    
    return 0;
}
