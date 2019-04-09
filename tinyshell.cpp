#include<iostream>
#include<string.h>
#include<list>
#include<sys/types.h>
#include<unistd.h>
#include<sys/time.h>
#include<ctime>
#include<cmath>
/* GROUP MEMBERS
 Rhea Gupta UID: 3035453658
 Tanmay Nautiyal UID: 3035452941
 */
using namespace std;

typedef struct Command
{
    char s[256];
    float t;
}Command; //stores each command and the time it took to execute

class history
{
private:
    list <Command> cmlist;
    
public:
    void insert(char s[],float t);
    void display();
    void display2();
    friend bool operator<(const Command & c1,const Command & c2);
};//stores the list of type Command

bool operator>(const Command & c1,const Command & c2)
{
    return c1.t<c2.t;
}//overloaded operator < to sort Commands based on execution time for history -sbu

void history::insert(char s[],float t)
{
    Command tmp;
    strcpy(tmp.s,s);
    tmp.t=t;
    cmlist.push_front(tmp);
    if(cmlist.size()>5)
        cmlist.pop_back();
}//function to insert a new element to the history of commands

void history::display()
{
    list<Command>::iterator itr;
    for(itr=cmlist.begin(); itr!=cmlist.end(); itr++)
    {
        cout<<(*itr).s<<"  "<<(*itr).t<<"s"<<endl;
    }
}//prints last 5 commands based on order of execution

void history::display2()
{
    list<Command>::iterator itr;
    Command arr[5];
    int i=0;
    int n=cmlist.size();
    for(itr=cmlist.begin();itr!=cmlist.end();itr++)
    {
        strcpy(arr[i].s,(*itr).s);
        arr[i].t=(*itr).t;
        i++;
    }
    int j=0;
    for (i = 0; i < n; i++)
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                char tmp[256];
                float temp;
                strcpy(tmp,arr[j].s);
                strcpy(arr[j].s,arr[j+1].s);
                strcpy(arr[j+1].s,tmp);
                temp=arr[j].t;
                arr[j].t=arr[j+1].t;
                arr[j+1].t=temp;
            }
    for(i=0;i<n;i++)
    {
        cout<<arr[i].s<<"  "<<arr[i].t<<"s"<<endl;
    }
}//prints last 5 commands sorted based on execution time

int removeSpaces(char str[])
{
    int count = 0;    // To keep track of non-space character count
    char str2[256];
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
            str2[count++] = str[i];
    }
    str2[count] = '\0';
    
    if(strcmp(str2,"history")==0)
        return 0;
    if(strcmp(str2,"history-sbu")==0)
        return 1;
    if(strcmp(str2,"exit")==0)
        return 2;
    return 3;
}

int main()
{
    history comms;
    char s[256]="";
    cout<<"tinyshell>";
    while(cin.getline(s,256))//accept input
    {
        int a=removeSpaces(s);
        if(a<2)
        {
            pid_t pid;
            pid = fork();
            if(pid==0)//checks if the process is a child process or not
            {
                if(a==0)
                    comms.display();
                else if(a==1)
                    comms.display2();
                cout<<"tinyshell>";
                exit(0);
            }
        }
        else if(a==2)
            exit(0);
        else//uses system() to execute commands not built by tinyshell
        {
            clock_t timereq;
            timereq = clock();
            int i;
            i=system (s);
            timereq = clock() - timereq;
            float t=(float)timereq/CLOCKS_PER_SEC;
            comms.insert(s,t);//adds the command to the list of commands
            cout<<"tinyshell>";
        }
    };
    return 0;
}
