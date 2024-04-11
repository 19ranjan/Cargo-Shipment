

#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>

using namespace std;
int getch();

double m[10];
double amt[10];
void bill();
int res;
int a;
int b=0;
int c;
void enter_weight();
void main_menu();
void ship(int);
void map1();

#define V 9

//To find Min Distance
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

//To print the solution of Map
void printSolution(int dist[])
{
	int n;
	cout<<"\n\t\t+---------+---------------------------------------------+";
	cout<<"\n\t\t|  Code   |                 Port Name                   |";
	cout<<"\n\t\t+---------+---------------------------------------------+";
	cout<<"\n\t\t|    0    |   Indira Gandhi International Airport(IGIA) |";
	cout<<"\n\t\t|    1    |   Port of Long Beach, California            |";
	cout<<"\n\t\t|    2    |   Port of New York and New Jersey           |";
	cout<<"\n\t\t|    3    |   Port of Savannah, Georgia                 |";
	cout<<"\n\t\t|    4    |   Port of Houston, Texasar                  |";
	cout<<"\n\t\t|    6    |   Port of Virginia, Virginia                |";
	cout<<"\n\t\t|    7    |   Port of Charleston, South Carolina        |";
	cout<<"\n\t\t|    8    |   Cargo international airport               |";
	cout<<"\n\t\t|    9    |   Chhatrapati Shivaji International Airport |";
	cout<<"\n\t\t+---------+---------------------------------------------+";
	cout<<"\n  Enter the port Code you want deliver : ";
	cin>>n;
	cout <<"\nPort \t     Distance from Source" << endl;
	char a[200][100]={ "Port of Long Beach, California ","Port of New York and New Jersey","Port of Savannah, Georgia","Port of Houston, Texasar",
	"Port of Virginia, Virginia","Port of Charleston, South Carolina","Cargo international airport","Chhatrapati Shivaji International Airport"};
	for (int i = 0; i <=n; i++)
    {
    cout << a[i] << " \t\t"<<dist[i]<< endl;
		b+=dist[i];
    }
    cout<<"Total Distance : "<<b<<" Miles ";
    getch();
    system("cls");
    main_menu();
}

//Dijkstra Function
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
            	&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}

//Max function to find max weight
int max(int a, int b)
{
    return (a > b) ? a : b;
}

//Function for Find Max profit and Selected items
void knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    res = K[n][W];
    c=res;
    cout<< "\n Profit is Rs."<<c<<" K\n";
    cout<<"\n Weight selected : ";
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            cout<<" "<<wt[i - 1] ;
            a=a+wt[i-1];
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    ship(a);

}

//Function to display the size of ship
void size_ship()
{
    cout<<"\n\t\t+-------+-------------------+------------------+";
    cout<<"\n\t\t|  Ship |Air-ship Capacity  |  Transport cost  |";
    cout<<"\n\t\t+-------+-------------------+------------------+";
    cout<<"\n\t\t|   1   |      99 tonnes    |    Rs. 21000     |";
    cout<<"\n\t\t|   2   |     194 tonnes    |    Rs. 41000     |";
    cout<<"\n\t\t|   3   |     286 tonnes    |    Rs. 51000     |";
    cout<<"\n\t\t|   4   |     377 tonnes    |    Rs. 70000     |";
    cout<<"\n\t\t|   5   |     538 tonnes    |    Rs. 100000    |";
    cout<<"\n\t\t+-------+-------------------+------------------+";
}

//Function which finds the Ship to dispatch
void ship(int a)
{
    size_ship();
    cout<<"\n\n";
    for(int i=0;i<5;i++){
    if(a>0&& a<100)
    {
        cout<<" Air carrier 1 will dispatch carrying a load of "<<a<< " tonnes";
        amt[i]=0.21;
        m[i]=1;
        break;
    }
    else if(a>99&& a<195)
    {
        cout<<" Air carrier 2 will dispatch carrying a load of "<<a<< " tonnes";
        amt[i]=0.41;
        m[i]=2;
        break;
    }
    else if(a>194&& a<287)
    {
        cout<<" Air carrier 3 will dispatch carrying a load of "<<a<< " tonnes";
        amt[i]=0.51;
        m[i]=3;
        break;
    }
    else if(a>286&& a<378)
    {
        cout<<" Air carrier 4 will dispatch carrying a load of "<<a<< " tonnes";
        amt[i]=0.71;
        m[i]=4;

        break;
    }
    else if(a>377&& a<539)
    {
        cout<<" Air carrier 5 will dispatch carrying a load of "<<a<< " tonnes";
        amt[i]=1;
        m[i]=5;

        break;
    }

    else if(a>538)
        cout<<" You delivered all the containers!!\n Wait for arrival of new Containers...";
        break;
    }
    getch();
    system("cls");
    main_menu();
}

//Function to enter max weight to dispatch
void enter_weight()
{
    int val[] = {0,55,10,47,5,4,50,8,61,85,87};
    cout<<"\n+-----------------+---+----+----+----+----+----+----+----+----+----+----+";
    cout<<"\n|Rs(in lac)/tonne | 0 | 55 | 10 | 47 |  5 |  4 | 50 |  8 | 61 | 85 | 87 |";
    cout<<"\n+-----------------+---+----+----+----+----+----+----+---+-----+----+----+";
    cout<<"\n| weight(in tonne)| 0 | 95 |  4 | 60 | 32 | 23 | 72 | 80 | 62 | 65 | 46 |";
    cout<<"\n+-----------------+---+----+----+----+----+----+----+----+----+----+----+";
	int wt[] = {0,95,4,60,32,23,72,80,62,65,46};
	int tw=538;
	int k[11][11];
	int W;
	cout<<"\n\n Enter the total weight you want to dispatched : ";
	cin>>W;
	int n = sizeof(val) / sizeof(val[0]);
	if(W<539){
	cout<<"\n You want to Load "<<W<<" tonnes of weight.";
	getch();
    knapSack(W, wt, val, n);
 	getch();
	system("cls");
	}
	else{
        cout<<" You Delivered all the containers\n Please wait for arriving new Containers.";
    getch();
	system("cls");
	}
}

//Function for admin Login(Security Purpose)
void adm_log()
{
    int u,p[9],i;
    system("cls");
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\t\t\t | ADMINISTRATION LOGIN  |";
    cout << "\n\t\t\t +-----------------------+";
    cout << "\n\n Enter the login details";
    for (i = 1; i <=3; i++)
    {
        cout << "\n\n Enter Admin ID    : ";
        cin >> u;
        cout << " Enter 4 Digit Pin : ";
        for (int i = 1; i <= 4; i++) {
      cin>>p[i];}
        getch();
        fflush(stdin);
        if (u == 1 && p[1]==49 && p[2]==50 && p[3]==51 && p[4]==52)
        {
            cout << "\n\n Access Granted..!";
            cout << "\n Press any key to continue....!!";
            getch();
            system("cls");
            main_menu();
            break;
        }
        else
        {
            cout << "\n Sorry wrong User Id and Password \n Enter the detail again:";
            cout << "\n Chance left: " << 3 - i << "\n";
        }
    }
}

//Function telling about the Port
void about()
{
    cout<<"\n, Indira Gandhi International Airport (IGIA) in Delhi is used for shipping materials. It is the largest cargo handling airport in India";
    cout<<"the preferred air cargo hub of the country due to its strategic location, elaborate infrastructure, and efficient air cargo handling ";
    cout<<" The airport has a cargo terminal that handles both domestic and international cargo, including perishable goods, dangerous goods, and live animals";
    cout<<" In addition, the airport has been recognized for its environmentally sustainable practices, which include reducing carbon emissions and waste, and promoting the use of renewable energy";
    cout<<"\n\n All about IGIA Airport.. Press any key to Continue..";
    getch();
    system("cls");
    main_menu();
}

//Function which is for Main menu
void main_menu()
{
    int choice;
        cout << "\n-> Main Menu";
        cout << "\n\n1.  Flight Assignment";
        cout << "\n2.  Map";
        cout << "\n3.  Generate Bill";
        cout << "\n4.  About ";
        cout << "\n5.  Exit";
        cout << "\n\  Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: system("cls");
            enter_weight();
            break;
            case 2:map1();
                break;
            case 3: bill();
            break;
            case 4: about();
            break;
            case 5: cout<<"You are Logged Out...\n\n Press any key to Continue...";
            getch();
                return ;
            break;
            default : cout<<"Wrong Choice";
            main_menu();
            break;
        }
}

//Pre defined Map Function
void map1(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 0);
}


//Function printing the Bill
void bill()
{
    double gst;
    time_t timer = time(NULL);
    system("cls");
    cout<<" Your Digital Invoice\n\n";
    cout<<"\n***********************************************************************";
    cout<<"\n*               Indira Gandhi International Airport                      *";
    cout<<"\n*                           , New Delhi, Delhi 110037                            *";
    cout<<"\n***********************************************************************";
    cout<<"\n*                              INVOICE                                *";
    cout<<"\n***********************************************************************";
    cout<<"\n    Time                   : " << ctime(&timer);
    cout<<"\n                                                         ||||| ||| ||||";
    cout<<"\n    Profit               Rs. "<<c<<" K";
    cout<<"\n    Ship Number            : IMO 95043"<<*m;
    cout<<"\n    Container weight       : "<<a<<" Tonnes";
    cout<<"\n    Total Distance         : "<<b<<" miles";
    cout<<"\n    Expense              Rs. "<<*amt<<" lacs";
    cout<<"\n    Transport(Rs1000/NM) Rs. "<<b*1000;
    cout<<"\n    Remaining Amount     Rs. "<<c-(*amt)-(b*1)<<" K";
    gst=0.18*(c-(*amt)-(b*1));
    cout<<"\n    GST(18%)             Rs. "<<gst<<" K" ;
    cout<<"\n    Total Profit         Rs. "<<c-(*amt)-(b*1)-gst<<" K";
    cout<<"\n***********************************************************************";

    getch();
    system("cls");
    main_menu();
}

int main()
{
    int ch;
    cout << "\n\t\t\t\tJaypee Institute of Information Technology";
    cout << "\n\t\t\t\t\t\tNoida-62";
    cout << "\n\n\t\t\t\t   APS Project On Shipment Management.";
    cout << "\n\n\t\t\t\t->Developed By:  TANISH MIRAKHUR, HARSHITA RANJAN, MANSI TYAGI \n\n";
    cout << "\n\n\t\t\t\t\tPress Any key to continue...!";
    getch();
    system("cls");
    login:
    cout << "****************************************************************";
    cout << "\n*                             WELCOME                          *";
    cout << "\n****************************************************************";
    cout << "\n\n +----------+";
    cout << "\n |  Portal  |";
    cout << "\n +----------+";
    cout << "\n\n 1.  ADMIN LOGIN";
    cout << "\n2.  EXIT";
    cout << "\n\n Enter your Choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        adm_log();
        break;
    case 2:
        cout<<"\nTHANK YOU";
        return 0;
        break;
    default:
        cout << "\n Wrong Choice,Try again";
        getch();
        system("cls");
        goto login;
        break;
    }
system("cls");
}
