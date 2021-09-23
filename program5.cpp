#include<iostream>
using namespace std;
int main()
{
	int a[10],b[10],c[10],w[10],ta[10],py[10],i,j,n,q,s1=0,s2=0;
	string p[10],t;
	float a1,a2;
	cout<<"Enter no. of processes:";
    cin>>n;
	for(i=0;i<n;i++)
    {
    	cout<<"Enter process id["<<i+1<<"]:";
    	cin>>p[i];
    	cout<<"Priority:";
		cin>>py[i];
    	cout<<"Enter burst time["<<i+1<<"]:";
    	cin>>b[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(py[i]>py[j])
			{
				t=p[j];
				p[j]=p[i];
				p[i]=t;
				q=b[j];
				b[j]=b[i];
				b[i]=q;
				q=py[j];
				py[j]=py[i];
				py[i]=q;				
			}
		}
	}
	w[0]=0;
	for(i=0;i<n;i++)
	{
		w[i+1]=w[i]+b[i];
        ta[i]=w[i+1];
        c[i]=ta[i];
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
	cout<<"| "<<p[i]<<" ";
	cout<<"|\n";
	cout<<"_";
	for(i=0;i<n;i++)
	cout<<"_____";
	cout<<"\n";
	for(i=0;i<n;i++)
	cout<<w[i]<<"    ";	
	cout<<ta[i-1]<<"\n";
	cout<<"Processes name\tBurst time\tComplition time\tWaiting time\tTurn around time\n";
	for(i=0;i<n;i++)
	cout<<p[i]<<"\t  \t"<<b[i]<<"\t  \t"<<c[i]<<"\t  \t"<<w[i]<<"\t  \t"<<ta[i]<<"\n";
	cout<<"Average Waiting time:"<<a1<<"ms\n";
	cout<<"Average Turnaround time:"<<a2<<"ms\n";
	return 0;
}
