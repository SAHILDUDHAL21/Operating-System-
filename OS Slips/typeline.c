#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>     
int main(int argc,char *argv[])
{
 FILE *f1;
 char ch,s1[100];
 int choice,cnt,i;
 f1=fopen(argv[3],"r");
 
 if(f1==NULL)
 {
 	printf("File Not Found...");
 	exit(0);
 }
 
 ch=argv[2][0];
 
 
 if(ch=='a')
 {
 	while(!feof(f1))
 	{
 	  fgets(s1,50,f1);	
 	  printf("%s",s1);
	}
 }
 else
 {
 	choice=atoi(argv[2]);
 	if(choice>0)
 	{
 	   	
 	   while(choice>0)
 	   {
 	      fgets(s1,50,f1);	
 	       printf("%s",s1);
 	       choice--;
		}
	}
	if(choice<0)
 	{
 		
 	  cnt=0;
	  while(!feof(f1))
 	  {
 	   fgets(s1,50,f1);	
 	    cnt++;
	  }
	  fseek(f1,0,SEEK_SET);  //file pointer start 
	  i=0;
      while(!feof(f1))
 	  {
 	  	i++;
 	   fgets(s1,50,f1);
		if(i>(cnt+choice))	
 	      printf("%s",s1); 
	  }	  
	}
 }
}