//Non Preemptive SJF
#include<stdio.h>
int main()
{
	int at[6],bt[6],proc[6],btemp,ptemp,atemp,wt[6],tt[6],sum=0,i,j,num,pt[6];
	float avrg,avg;
	printf("Enter Number Of Process = ");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("\nEnter The Process Number :: ");
		scanf("%d",&proc[i]);
		printf("\nEnter The Process Arival Time :: ");
		scanf("%d",&at[i]);
		printf("\nEnter The Process Burst Time :: ");
		scanf("%d",&bt[i]);
		printf("\nEnter The Process Priority :: ");
		scanf("%d",&pt[i]);
	}
	printf("\n\nBefore Sorting On Arival Time \n\n");
	printf("\nProcess \t Arival Time \t Burst Time \t Priority \n");
	for(i=0;i<num;i++)
	{
		printf("\nP%d  \t\t",proc[i]);
		printf("\t%d  \t",at[i]);
		printf("\t%d  \t",bt[i]);
		printf("\t%d  \t",pt[i]);
	}
	for(i=0;i<num;i++)
	{
		if(at[i]==0)
		{
			atemp=at[0];
			at[0]=at[i];
			at[i]=atemp;
			btemp=bt[0];
			bt[0]=bt[i];
			bt[i]=btemp;
			ptemp=proc[0];
			proc[0]=proc[i];
			proc[i]=ptemp;
			atemp=pt[0];
			pt[0]=pt[i];
			pt[i]=atemp;
		}
	}
	for(i=1;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(pt[i]<pt[j])
			{
				atemp=at[i];
				at[i]=at[j];
				at[j]=atemp;
				btemp=bt[i];
				bt[i]=bt[j];
				bt[j]=btemp;
				ptemp=proc[i];
				proc[i]=proc[j];
				proc[j]=ptemp;
				atemp=pt[i];
				pt[i]=pt[j];
				pt[j]=atemp;
			}
		}
	}
	for(i=1;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(pt[i]==pt[j])
			{
				if(at[i]<at[j])
				{
					atemp=at[i];
					at[i]=at[j];
					at[j]=atemp;
					btemp=bt[i];
					bt[j]=bt[j];
					bt[j]=btemp;
					ptemp=proc[i];
					proc[i]=proc[j];
					proc[j]=ptemp;
					atemp=pt[i];
					pt[i]=pt[j];
					pt[j]=atemp;
				}
			}
		}
	}
	printf("\n\nAfter Sorting On Arival Time \n\n");
	printf("\nProcess \t Arival Time \t Burst Time \t Priority\n");
	for(i=0;i<num;i++)
	{
		printf("\nP%d \t \t",proc[i]);
		printf("\t%d  \t",at[i]);
		printf("\t%d  \t",bt[i]);
		printf("\t%d  \t",pt[i]);
	}
	wt[0]=0;
	for(i=0;i<num;i++)
	{
		wt[i+1]=wt[i]+bt[i];
		sum=(wt[i]-at[i]);
	}
	wt[num]=wt[num-1]+bt[num-1];
	printf("\n\nThe Waiting Time is \t %d ",sum);
	avrg=(float)sum/(float)num;
	printf("\nThe Average Waiting Time is \t%f ",avrg);
	sum=0;
	for(i=0;i<num;i++)
	{
		tt[i]=wt[i+1]-at[i];
		sum+=tt[i];
	}
	printf("\n\nThe Turnaround Time is \t %d ",sum);
	avg=(float)sum/(float)num;
	printf("\nThe Average Turnaround Time is \t%f ",avg);
	printf("\n\n\nGANTT CHART\n\n\n");
	printf("\n-----------------------------------------\n");
	for(i=0;i<num;i++)
	{
		printf("|  P%d\t",proc[i]);
	}
	 printf("\n----------------------------------------\n");
	 for(i=0;i<=num;i++)
	{
		printf("%d\t",wt[i]);
	}
}
