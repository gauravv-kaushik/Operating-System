#include <iostream>

using namespace std;

void FCFS(int process,int arrival[],int burst[],int waiting[],int turnaround[],int completion[]){
	 int burs=1;
	 
	 for(int i=0;i<process;i++){
	 	burs+=burst[i];
	 	completion[i]=burs;
	 	turnaround[i]=burs-arrival[i];
	 }
	 for(int i=0;i<process;i++){
	 	waiting[i]=turnaround[i]-burst[i];
	 }
	 	float avg=0,avgw=0;
	
		cout<<"Arrival time\t\tBurst Time\t\tcompletion time\t\tTurnaround time\t     Waiting time" <<endl;
	for(int i=0;i<process;i++)
	{
		cout<<"    "<<arrival[i]<<"\t\t\t"<<"   "<<burst[i]<<"\t\t\t"<<"   "<<completion[i]<<"\t\t\t"<<turnaround[i]<<"\t\t\t"<<waiting[i]<<endl;
	
	}
	for(int i=0;i<process;i++)
	{
		avg=avg+turnaround[i];
	
	}
	for(int i=0;i<process;i++)
	{
		avgw=avgw+waiting[i];
	
	}
	cout<<"Average turnaround  : "<<avg/process<<endl;
	cout<<"Average waiting  : "<<avgw/process;	
}

int main(){
	int ch,process;
	
	cout<<"Enter the  number of process ";
	cin>>process;
	int arrival[process];
	int burst[process];
	int waiting[process];
	int completion[process];
	int turnaround[process];

	for(int i=0;i<process;i++){
		cout<<"Enter the arrival time for process P"<<i<<"  ";
		cin>>arrival[i];
	}
	for(int i=0;i<process;i++){
		cout<<"Enter the burst time for process P"<<i<<"  ";		
		cin>>burst[i];
	}
	FCFS(process,arrival,burst,waiting,turnaround,completion);
	
	
}

