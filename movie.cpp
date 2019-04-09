#include&lt;fstream.h&gt;
#include&lt;iostream.h&gt;
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#include&lt;conio.h&gt;

//Constant character declarations
Const char TL=218,TR=191,BL=192,BR=217,HL=196,VL=179,
PL=197,CD=194,CR=195,CL=180,CU=193;
const int seatlim=6, price=400, MC=6, MR=6;
//FUNCTION PROTOTYPES
void DispCh(int C,int R,char Ch);
void DispCh(int C,int R,int Ch);
void DispCh(int C,int R,char Ch[]);
void Color(int TC,int TB);
void Recta(int C1,int R1,int C2,int R2);
int VMenu(int C,int R,char Men[][15],int Noo);
void RectaH(int C1, int R1, int C2, int R2);

Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh

Jain Page:#7/30

class Movie
{
    char name[30],rate[2];
    int time[2],seats,code;
    int S[2][3];
public:
    Movie();
    void Accept(char[],char[],int[]);
    int ReturnCode();
    void CodeVal(int);
    void Display(int);
    int ReturnSeats();
    int ReturnSeatVal(int,int);
    void ChangeSeatVal(int , int );
    void NoSeats(int );
};
void Movie:: Movie()
{
    seats=0;
    for(int i=0; i&lt;2; i++)
    {
        for(int j=0; j&lt;3; j++)
            S[i][j]=0;
    }
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#8/30
    
}
void Movie::Accept( char N[30], char r[2], int t[2])
{
    strcpy(name,N);
    strcpy(rate,r);
    time[0]=t[0];
    time[1]=t[1];
}
int Movie::ReturnCode()
{
    return code;
}

void Movie::CodeVal(int x)
{
    code=x;
}

void Movie::Display(int n)
{
    cout&lt;&lt;code&lt;&lt;&quot; &quot;&lt;&lt;name&lt;&lt;&quot; &quot;;
    if(n==0)
        cout&lt;&lt;rate&lt;&lt;&quot; &quot;&lt;&lt;time[0]&lt;&lt;&quot;:&quot;&lt;&lt;time[1]&lt;&lt;endl;
    
    else if(n==1)
        
        Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#9/30
    
    cout&lt;&lt;seats&lt;&lt;endl;
}

int Movie:: ReturnSeats()
{
    return seats;
}

int Movie:: ReturnSeatVal(int i, int j)
{
    return S[i][j];
}

void Movie:: ChangeSeatVal(int i, int j)
{
    S[i][j]=1;
}

void Movie::NoSeats(int x)
{
    seats+=x;
}

void BSearch(int &amp;f, int &amp;n, Movie &amp;m);
void BSeats(Movie &amp;m, int n);

int AssignCode()

Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh

Jain Page:#10/30

{
    fstream fil(&quot;MList.dat&quot;, ios::binary|ios::in);
    Movie M;
    int n;
    fil.seekg(0,ios::end);
    int rec=fil.tellg()/sizeof(M);
    cout&lt;&lt;&quot;Rec = &quot;&lt;&lt;rec;getch();
    n=101 + rec;
    fil.close();
    return n;
}

void Add()
{
    clrscr();
    fstream fil;
    Movie M;
    fil.open(&quot;MList.dat&quot;, ios::binary| ios::app);
    
    char N[30],r[2],ch;
    int t[2];
    
    cout&lt;&lt;&quot;Enter the name of the movie&quot;&lt;&lt;endl;
    gets(N);
    cout&lt;&lt;&quot;Enter rating&quot;&lt;&lt;endl;
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#11/30
    
    gets(r);
    cout&lt;&lt;&quot; Enter Time (hh,mm)&quot;&lt;&lt;endl;
    cin&gt;&gt;t[0]&gt;&gt;t[1];
    
    M.Accept(N,r, t);
    M.CodeVal(AssignCode());
    fil.write((char*)&amp;M, sizeof(M));
    fil.close();
}

void DispRep (int n)
{
    clrscr();
    fstream fil;
    int SeatSum=0;
    Movie M;
    fil.open(&quot;MList.dat&quot;,ios::binary|ios::in);
    
    while(fil.read((char*)&amp;M,sizeof(M)))
    {
        M.Display(n);
        if(n==1)
            SeatSum+=M.ReturnSeats();
    }
    
    if(n==1)
        
        Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#12/30
    
    {
        cout&lt;&lt;&quot;Total no. of booked seats:&quot;&lt;&lt;SeatSum&lt;&lt;endl;
        cout&lt;&lt;&quot;Profit per booking: Rs 400&quot;&lt;&lt;endl;
        cout&lt;&lt;&quot;Total profitthis week:&quot;&lt;&lt;SeatSum * 400&lt;&lt;endl;
    }
    fil.close();
    getch();
}

void Remove()
{
    clrscr();
    int N;
    cout&lt;&lt;&quot;Enter code of movie to be removed&quot;&lt;&lt;endl;
    cin&gt;&gt;N;
    fstream fil1(&quot;MList.dat&quot;, ios::binary|ios::in);
    fstream fil2(&quot;temp.dat&quot;, ios::binary|ios::out);
    Movie M;
    
    while( fil1.read((char*)&amp;M, sizeof(M)))
    {
        if(M.ReturnCode()!=N)
            fil2.write((char*)&amp;M, sizeof(M));
    }
    
    remove(&quot;MList.dat&quot;);
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#13/30
    rename(&quot;temp.dat&quot;, &quot;MList.dat&quot;);
    
    fil1.close();
    fil2.close();
}

void Edit(Movie M, int C)
{
    
    Movie A;
    int f=0,x;
    fstream fil;
    fil.open(&quot;MList.dat&quot;, ios::binary|ios::out|ios::in);
    while(!f &amp;&amp; fil.read((char*)&amp;A,sizeof(A)) )
    {
        if(A.ReturnCode()==C)
            f++;
    }
    
    if(f)
    {
        int n= fil.tellg()-sizeof(A);
        fil.seekp(n);
        fil.write((char*)&amp;M,sizeof(M));
    }
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#14/30
    
    else
        cout&lt;&lt;&quot;Movie not found,&quot;;
    fil.close();
    cout&lt;&lt;&quot;Successful&quot;;
    getch();
}
void EEdit()
{
    clrscr();
    Movie M;
    char n[30],r[2],ch;
    int t[2];
    int a;
    cout&lt;&lt;&quot;Enter the code of the movie to be edited: &quot;;
    cin&gt;&gt;a;
    cout&lt;&lt;&quot;Enter Name: &quot;;
    gets(n);
    cout&lt;&lt;&quot;Enter Rate: &quot;;
    cin&gt;&gt;r;
    cout&lt;&lt;&quot;Enter time(hhmm): &quot;;
    cin&gt;&gt;t[0]&gt;&gt;t[1];
    M.Accept(n,r,t);
    M.CodeVal(a);
    M.Display(0);
    getch();
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#15/30
    
    Edit(M,a);
}
void Book()
{
    clrscr();
    int f=0,n;
    Movie m;
    
    BSearch(f,n,m);
    if(f==1)
    {
        BSeats(m,n);
        clrscr();
        cout&lt;&lt;&quot;Total cost= Rs&quot;&lt;&lt;n*price;
        
        m.NoSeats(n);
        Edit(m,m.ReturnCode());
    }
}
void BSearch(int &amp;f, int &amp;n, Movie &amp;m)
{
    int x;
    char ch;
    
    cout&lt;&lt;&quot; Enter code of movie for which tickets are to be
        booked&quot;&lt;&lt;endl;
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#16/30
    
    cin&gt;&gt;x;
    fstream fil(&quot;MList.dat&quot;,ios::binary|ios::in);
    
    while(!f &amp;&amp; fil.read((char*)&amp;m,sizeof(m)))
    {
        if(m.ReturnCode()==x)
        {
            f++;
        }
    }
    
    if(f==1)
    {
        if(m.ReturnSeats()==seatlim)
        {
            cout&lt;&lt;&quot;Show is fully booked&quot;;
            f++;
        }
        else
        {
            cout&lt;&lt;&quot;Enter No of tickets&quot;;
            cin&gt;&gt;n;
            if((n+ m.ReturnSeats())&gt;seatlim)
            {
                cout&lt;&lt;&quot;Not enough seats&quot;&lt;&lt;endl;
                f++;
                
            Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
                
                Jain Page:#17/30
                
            }
        }
    }
    else
        cout&lt;&lt;&quot;File not found.&quot;&lt;&lt;endl;
    getch();
}

void BSeats(Movie &amp;m, int n)
{
    clrscr();
    int j;
    int C1=2,R1=2,C2=C1+(MC*3),R2=R1+(MR*2);
    int A,B;
    Color( WHITE,BLUE);
    RectaH(C1, R1, C2,R2 ); //Displaying the seats
    for(int i=0; i&lt;MR; i++)
    {
        for( int j=0; j&lt;MC; j++)
        {
            if(m.ReturnSeatVal(i,j)==1)
                Color(WHITE,RED);
            A=C1+1+3*j;
            B=R1+1+i*2;
            DispCh(A,B,char(65+i));
            DispCh(A+1,B,j+1);
            
        Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
            
            Jain Page:#18/30
            
            Color(WHITE,BLUE);
        }
    }
    
    int Sel[1][2]={C1+1, R1+1}; //Selection of seats
    int r=0;
    i=0; j=0;
    
    do
    {
        int Tsel[1][2];
        Tsel[0][0]=Sel[0][0];
        Tsel[0][1]=Sel[0][1];
        j=(Sel[0][0]-C1-1)/3;
        i=(Sel[0][1]-R1-1)/2;
        
        Color (BLUE ,WHITE);
        DispCh(Sel[0][0],Sel[0][1],char(65+i));
        DispCh(Sel[0][0]+1,Sel[0][1],j+1);
        Color(WHITE,BLUE);
        char ch=getch();
        switch(ch)
        {
            case 75: // LEFT
                if(Sel[0][0]==C1+1)
                    
                    Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
                
                Jain Page:#19/30
                
                Sel[0][0]= C2-2;
                else
                    Sel[0][0]-=3;
                break;
                
            case 77: //RIGHT
                if(Sel[0][0]==C2-2)
                    Sel[0][0]=C1+1;
                else
                    Sel[0][0]+=3;
                break;
                
            case 72: //UP
                if(Sel[0][1]==R1+1)
                    Sel[0][1]=R2-1;
                else
                    Sel[0][1]-=2;
                break;
                
            case 80:
                if(Sel[0][1]==R2-1) //DOWN
                    Sel[0][1]=R1+1;
                else
                    Sel[0][1]+=2;
                break;
                
            Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
                
                Jain Page:#20/30
                
            case 13:
                r++;
                m.ChangeSeatVal(i,j);
                break;
        }
        if(ch!=13)
        {
            DispCh(Tsel[0][0],Tsel[0][1],char(65+i));
            DispCh(Tsel[0][0]+1,Tsel[0][1],j+1);
        }
    }while(r&lt;n);
    getch();
}

void RectaH(int C1, int R1, int C2, int R2)
{
    
    DispCh(C1,R1,TL); // Outer Lining of Box
    DispCh(C2,R1,TR);
    DispCh(C1,R2,BL);
    DispCh(C2,R2,BR);
    
    for (int i=C1+1;i&lt;C2;i+=3)
    {
        
    Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
        
        Jain Page:#21/30
        
        DispCh(i,R1,HL);
        DispCh(i,R2,HL);
        DispCh(i+1,R1,HL);
        DispCh(i+1,R2,HL);
        if(i+2&lt; C2)
        {
            DispCh(i+2,R1,CD);
            DispCh(i+2,R2,CU);
        }
    }
    
    for (i=R1+1;i&lt;R2;i+=2)
    {
        DispCh(C1,i,VL);
        DispCh(C2,i,VL);
        if(i+1&lt;R2)
        {
            DispCh(C1,i+1,CR);
            DispCh(C2,i+1,CL);
        }
    }
    
    for ( i=R1+1; i&lt;R2; i+=2) // Inner Lining Of Box
    {
        for (int j=C1+3; j&lt;C2 ; j+=3)
            
            Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
        
        Jain Page:#22/30
        
        {
            DispCh(j,i,VL);
            if(i+1&lt;R2)
                DispCh(j,i+1,PL);
        }
    }
    
    for (i=C1+1; i&lt;C2; i+=3)
    {
        for(int j=R1+2; j&lt;R2; j+=2)
        {
            DispCh(i,j, HL);
            DispCh(i+1,j, HL);
        }
    }
}

void DispCh(int C,int R,char Ch) //MENU
{
    gotoxy(C,R);cprintf(&quot;%c&quot;,Ch);
}

void DispCh(int C,int R,int Ch)
{
    gotoxy(C,R);cprintf(&quot;%d&quot;,Ch);
}

Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh

Jain Page:#23/30

void DispCh(int C,int R,char Ch[])
{
    gotoxy(C,R);cprintf(&quot;%s&quot;,Ch);
}

void Color(int TC,int TB)
{
    textcolor(TC);
    textbackground(TB);
}

void Recta(int C1,int R1,int C2,int R2)
{
    DispCh(C1,R1,TL);
    DispCh(C2,R1,TR);
    DispCh(C1,R2,BL);
    DispCh(C2,R2,BR);
    for (int i=C1+1;i&lt;C2;i++)
    {
        DispCh(i,R1,HL);
        DispCh(i,R2,HL);
    }
    for (i=R1+1;i&lt;R2;i++)
    {
        
    Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
        
        Jain Page:#24/30
        
        DispCh(C1,i,VL);
        DispCh(C2,i,VL);
    }
}

int VMenu(int C,int R,char Men[][9],int Noo)
{
    Color(WHITE,BLUE);
    Recta(C,R,C+strlen(Men[0])+1,R+Noo+1); //Drawing a rectangle
    enclosing options
    for (int i=0;i&lt;Noo;i++)
        DispCh(C+1,R+i+1,Men[i]); //Displaying All options
    int Exit=0,Sel=0;
    do
    {
        int Tsel=Sel;
        Color(BLUE,WHITE); //Changing color for
        highlighting
        DispCh(C+1,R+Sel+1,Men[Sel]); //Redisplaying the selected
        option with changed color
        Color(WHITE,BLUE); //Changing color to normal
        char Ch=getch(); //Accepting option from user
        switch(Ch)
        {
            case 71:
                Sel=0;
                break; //Move to first option
                
            case 79:
                
            Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
                
                Jain Page:#25/30
                
                Sel=Noo-1;
                break; //Move to Last option
            case 72:
                if (Sel==0) //Checking if already on top
                    Sel=Noo-1; //Move to the last option
                else
                    Sel--; //Move one option up
                break;
            case 80:
                if (Sel==Noo-1) //Checking if already at bottom
                    Sel=0; //Move to the first option
                else
                    Sel++; //Move one step down
                break;
            case 27:
                Sel=-1; //Getting out of the Menu without
                
                valid selection
                
            case 13:
                
                Exit=1; //Getting out of the Menu with
                
                current selection
        }
        
        DispCh(C+1,R+Tsel+1,Men[Tsel]); //Redisplaying the non-
        highlighted option
        
    }while (!Exit);
    
Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
    
    Jain Page:#26/30
    
    return Sel; //Returning the selected value
    from menu
}

void main()
{
    char Menu[][9]={ &quot;Display&quot;,
        &quot;Book &quot;,
        &quot;Add &quot;,
        &quot;Remove &quot;,
        &quot;Edit &quot;,
        &quot;Report &quot;,
        &quot;Exit &quot;
    };
    int N,SN;
    do
    {
        clrscr();
        N=VMenu(2,1,Menu,7);
        switch(N)
        {
            case 0:
                DispRep(0);
                break;
                
            case 1:
                Book();
                
            Project: Movie Cineplex Management System Developed By Rhea Gupta &amp; Rishabh
                
                Jain Page:#27/30
                
                break;
                
            case 2:
                Add();
                break;
                
            case 3:
                Remove();
                break;
                
            case 4:
                EEdit();
                break;
                
            case 5:
                DispRep(1);
                break;
            case 6:
                N=-1;
                
        }
        
    }while (N!=-1);
}
