//Shortest Job First Non Preemptive with Arrival time
#include<iostream> 
using namespace std; 
template< class T >
void swap(T *a, T *b) 
{ 
	T t = *a; 
	*a = *b; 
	*b = t; 
}  
int main() 
{ 
	char s[10];
    int w[10],c[10],a[10],b[10],ta[10];
	int n, t,k,i,j,s1=0,s2=0; 
	float a1,a2;	
	cout<<"Enter number of Process: "; 
	cin>>n; 
	for(i=0; i<n; i++) 
	{ 
		cout<<"Enter Process Id: "; 
		cin>>s[i]; 
		cout<<"Enter Arrival Time: "; 
		cin>>a[i]; 
		cout<<"Enter Burst Time: "; 
		cin>>b[i]; 
	} 
	c[0] = a[0] + b[0]; 
	ta[0] = c[0] - a[0]; 
	w[0] = ta[0] - b[0]; 	
	for( i=1; i<n; i++) 
	{ 
		t = c[i-1]; 
		int l = b[i]; 
		for( j=i; j<n; j++) 
		{ 
			if(t >= a[j] && l >= b[j]) 
			{ 
				l = b[j]; 
				k = j; 
			} 
		} 
		c[k] = t + b[k]; 
		ta[k] = c[k] - a[k]; 
		w[k] = ta[k] - b[k]; 
			swap(s[k], s[i]); 
			swap(a[k], a[i]); 
			swap(b[k], b[i]); 
			swap(c[k], c[i]); 
			swap(w[k], w[i]); 
			swap(ta[k], ta[i]); 
	} 
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
	cout<<a[0]<<"   ";
	for(i=0;i<n;i++)
	cout<<c[i]<<"   ";	
    cout<<"\n"; 
	for(i=0;i<n;i++)
	{
		s1=s1+w[i];
		s2=s2+ta[i];
	}
	a1=(float)s1/n;
	a2=(float)s2/n;	  
	cout<<"Process ID\tArrival Time\tBurst Time\tCompletion time\tWaiting Time\tTurnaround Time\n"; 
	for(int i=0; i<n; i++) 
	cout<<s[i]<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<c[i]<<"\t\t"<<w[i]<<"\t\t"<<ta[i]<<"\n";
	cout<<"Average of Waiting time:"<<a1<<"ms\n";
	cout<<"Average of Turnaround time:"<<a2<<"ms\n";
	return 0;
}
