#include<stdio.h>
void main()
{
        int i,j,temp,btemp,at[6],bt[6],tt[6],wt[6],sum=0,num,proc[6];
        float avrg,avg;
        printf("Enter No Of Process :: ");
        scanf("%d",&num);

        for(i=0;i<num;i++)
        {
                printf("\nEnter The Process Number = ");
                scanf("%d",&proc[i]);
                printf("\nEnter The Arival Time Of Process  = ");
                scanf("%d",&at[i]);
                printf("\nEnter The Burst Time of Process  = ");
                scanf("%d",&bt[i]);
        }
        printf("\n\nBefore Sorting On Arival Time \n\n");
	printf("\nProcess \t Arival Time \t Burst Time \n");
	for(i=0;i<num;i++)
	{
		printf("\nP%d  \t\t",proc[i]);
		printf("\t%d  \t",at[i]);
		printf("\t%d  \t",bt[i]);
	}

        for(i=0;i<num;i++)
        {
                for(j=i+1;j<num;j++)
                {
                        if(at[i]>at[j])
                        {
                                temp=at[i];
                                at[i]=at[j];
                                at[j]=temp;
                                btemp=bt[i];
                                bt[i]=bt[j];
                                bt[j]=btemp;
                                temp=proc[i];
                                proc[i]=proc[j];
                                proc[j]=temp;
                        }
                }
        } 

        printf("\n\nAfter Sorting On Arival Time\n\n");
        printf("\nProcess\tArival Time\tBurst Time\n");

        for(i=0;i<num;i++)
        {
                printf("\nP%d\t",proc[i]);
                printf("%d\t",at[i]);
                printf("%d\t",bt[i]);
        }

        wt[0]=0;

        for(i=0;i<num;i++)
        {
                wt[i+1]=wt[i]+bt[i];
                sum+=(wt[i]-at[i]);
        }

        wt[num]=wt[num-1]+bt[num-1];
        printf("\nWaiting Time = %d",sum);
        avrg=(float)sum/(float)num;
        printf("\nAverage Waiting Time = %f",avrg);
        sum=0;

        for(i=0;i<num;i++)
        {
                tt[i]=wt[i+1]-at[i];
                sum+=tt[i];
        }

        printf("\nTurnaround  Time = %d",sum);
        avg=(float)sum/(float)num;
        printf("\nAverage Turnaround Time = %f",avg);
        printf("\n\n\n\nGANTT CHART \n\n");
        printf("\n------------------------------------------------\n");
        for(i=0;i<num;i++)
        {
                printf("\tP%d\t",proc[i]);
        }
        printf("\n-------------------------------------------------\n");
        for(i=0;i<=num;i++)
        {
                printf("%d\t\t",wt[i]);
        }
}

/*
┌──(sahil㉿kali)-[~/Desktop/OS]
└─$ gcc FCFS.c 
                                                                                
┌──(sahil㉿kali)-[~/Desktop/OS]
└─$ ./a.out
Enter No Of Process :: 3

Enter The Process Number = 1

Enter The Arival Time Of Process  = 3

Enter The Burst Time of Process  = 2

Enter The Process Number = 2

Enter The Arival Time Of Process  = 0

Enter The Burst Time of Process  = 3

Enter The Process Number = 3

Enter The Arival Time Of Process  = 4

Enter The Burst Time of Process  = 2


After Sorting On Arival Time


Process	Arival Time	Burst Time

P2	0	3	
P1	3	2	
P3	4	2	
Waiting Time = 1
Average Waiting Time = 0.333333
Turnaround  Time = 8
Average Turnaround Time = 2.666667



GANTT CHART 


------------------------------------------------
	P2		P1		P3	
-------------------------------------------------
0		3		5		7		                                           
*/