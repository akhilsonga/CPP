//First Come First Serve
#include<iostream>
using namespace std;
int main()
{
	int n,i,b[10],w[10],ta[10],s1=0,s2=0;
	float a1,a2;
	char s[10][10];
    cout<<"Enter no. of processes:";
    cin>>n;
    w[0]=0;
    for(i=0;i<n;i++)
    {
    	cout<<"Enter process id["<<i+1<<"]:";
    	cin>>s[i];
    	cout<<"Enter burst time["<<i+1<<"]:";
    	cin>>b[i];
        w[i+1]=w[i]+b[i];
        ta[i]=w[i+1];
	}
	for(i=0;i<n;i++)
	{
		s1=s1+w[i];
		s2=s2+ta[i];
	}
	a1=(float)s1/n;
	a2=(float)s2/n;
	cout<<"_";
	for(i=0;i<n;i++)
	cout<<"_____";
	cout<<"\n";
	for(i=0;i<n;i++)
	cout<<"| "<<s[i]<<" ";
	cout<<"|\n";
	cout<<"_";
	for(i=0;i<n;i++)
	cout<<"_____";
	cout<<"\n";
	for(i=0;i<n;i++)
	cout<<w[i]<<"   ";	
	cout<<ta[i-1]<<"\n";
	cout<<"Processes name\tBurst time\tWaiting time\tTurn around time\n";
	for(i=0;i<n;i++)
	cout<<s[i]<<"\t  \t"<<b[i]<<"\t  \t"<<w[i]<<"\t  \t"<<ta[i]<<"\n";
	cout<<"Average Waiting time:"<<a1<<"ms\n";
	cout<<"Average Turnaround time:"<<a2<<"ms\n";
	return 0;
}
