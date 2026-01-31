

Skip to content
Using Gmail with screen readers
Enable desktop notifications for Gmail.
   OK  No thanks
Out of storage
Emails will stop on Feb 17, 2026
Get 30 GB for ₹59 ₹15 for 3 months
15 GB of 15 GB used
Conversations
100% of 15 GB used
Terms · Privacy · Program Policies
Last account activity: 0 minutes ago
Details
#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;

    //create and write to a file
    fp = fopen("data.txt","w");
    fprintf("hello , this is file handling in C.\n",fp);
    fclose(fp);


    //Append data to the file
    fp = fopen("data.txt","a");
    fprintf("hello this is for appending the data in file handling in C.\n",fp);
    fclose(fp);

    //read and display the data
    fp = fopen("data.txt","r");
    printf("Contents of the file : \n",fp);
    while((ch =fgetp(fp)) !=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    
    return 0;

}
tempCodeRunnerFile.c
Displaying tempCodeRunnerFile.c.