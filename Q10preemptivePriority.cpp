//Preemptive priority

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>
 
using namespace std;
  
class process{
    static int kk;
 
string name ="P"+to_string(kk);
 
int pnum;
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
 
     process(int p,int a,int b){
         pnum = p;
        arrival_time= a;
        burst_time=b;
        kk++;
     }
 
     void print(){
     cout<<name<<"  "<<"arrival :"<<arrival_time<<"burst time :"<<burst_time<<endl;}
 
 
       bool operator<(const process &r) const
    {
         if(pnum == r.pnum){
            return arrival_time <= r.arrival_time;
   }
        return pnum< r.pnum;
 
    }
 
    // overload the operator> (if required)
    bool operator>(const process &r) const
    {
         if(pnum == r.pnum){
            return arrival_time <= r.arrival_time;
}
        return pnum < r.pnum;
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
 
int main()
{
 
     process p1(3,0,3);
    process p2(2,1,4);
    process p3(4,2,6);
    process p4(6,3,4);
    process p5(10,5,2);
 
 
    vector<process> v ,b;
 
    vector<process> temp;
 
      v.push_back(p1);
      v.push_back(p2);
      v.push_back(p3);
      v.push_back(p4);
      v.push_back(p5);
 
      b.push_back(p1);
      b.push_back(p2);
      b.push_back(p3);
      b.push_back(p4);
      b.push_back(p5);
 
 
 
    vector<int> arr;
    vector<int> tracking;
    vector<int> comp_time;
 
    list<process> que;
 
 
    int timer=0;
 
 
 
 
    for(int i=0;i<5;i++){
        if(v.at(i).getArrival() <=timer){  // 0
            que.push_back(v.at(i));
        }
    }
    que.sort();
 
 
    bool flag=false;
 
 
 
     arr.push_back(0);   
   while(v.size() != 0){
 
 
   if(que.size()==0){
    timer++;                                  //4 5
     for(int z=0;z<v.size();z++){
        if(v.at(z).getArrival() <=timer){
            que.push_back(v.at(z));
        }
    }
    que.sort();
    flag = true;
 
   }else{
 
 
 
  if(flag){
     tracking.push_back(0);
     arr.push_back(timer);
   }
tracking.push_back(1);
timer += 1;   //right
 
   // arr.push_back( arr.at(arr.size()-1)+1);
 
   que.front().print();
    v.at(indexf(v,que.front())).setBurst(que.front().getBurst()-1);
    que.front().setBurst(que.front().getBurst()-1);
 
 
 
    if(que.front().getBurst() ==0){
        comp_time.push_back(timer);
        temp.push_back(que.front());
         removeElement(v,que.front());
    }
 
 
flag=false;
 
 
 
 
que.clear();
              for(int i=0;i<v.size();i++){
        if(v.at(i).getArrival() <=timer){
            que.push_back(v.at(i));
        }
    }
    que.sort();
 
   }
 
}
//calculating waiting time
int total=0;
for(int z=0;z<comp_time.size();++z){
    cout<<comp_time.at(z)<<"  - "<<temp.at(z).getArrival()<<endl;
    total += comp_time.at(z) -temp.at(z).getArrival();
}
cout<<"total turn around time : "<<total/5.0<<endl;
 
int sum=0;
for(int z=0;z<comp_time.size();++z){
    cout<<comp_time.at(z)-temp.at(z).getArrival()<<" - "<<b.at(indexf(b,temp.at(z))).getBurst()<<endl;
    sum += comp_time.at(z) -temp.at(z).getArrival() - b.at(indexf(b,temp.at(z))).getBurst();
}
cout<<"waiting time : "<<sum/5.0<<endl;
 
 
    return 0;
}
