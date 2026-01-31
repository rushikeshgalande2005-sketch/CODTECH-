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