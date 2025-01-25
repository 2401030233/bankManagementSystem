# include <iostream>
using namespace std;
class bankAc
{
private:
    string name, htype;
    float balance, Withdraw, Deposit;
public:
    int AcNo;
    void Assign();
    void display();
    void deposit();
    void withdraw();
    void checkBalance();
};
void bankAc::Assign()
{
    cout<<"\nInput your name"<<endl;
    cin>>name;
    cout<<"Input your Account number"<<endl;
    cin>>AcNo;
    cout<<"Input holder type"<<endl;
    cin>>htype;
    balance=1000; //Initializing balance with 1000 Rs.
    cout<<"\nAccount created successfully!\nYour initial bank balance is : "<<balance<<endl;
}
void bankAc::display()
{
    cout<<"\nName : "<<name<<endl;
    cout<<"Account No.: "<<AcNo<<endl;
    cout<<"Holder Type : "<<htype<<endl;
    cout<<"Bank Balance : "<<balance<<endl;
}
void bankAc::checkBalance()
{
    cout<<"\nYour current bank balance : "<<balance<<endl;
}
void bankAc::deposit()
{
    cout<<"\nInput amount to be deposited"<<endl;
    cin>>Deposit;
    if (Deposit<=0)
    {
        cout<<"\n[ERROR : Input valid amount!]"<<endl;
    }
    else
    {
        balance+=Deposit;
        cout<<"\nAmount of "<<Deposit<<" Deposited successfully!\nYour updated bank balance : "<<balance<<endl;
    }
}
void bankAc::withdraw()
{
    cout<<"\nInput amount to be withdrawn"<<endl;
    cin>>Withdraw;
    if (Withdraw<=0)
    {
        cout<<"\n[ERROR : Input valid amount!]"<<endl;
    }
    else
    {
        if (Withdraw<=balance)
        {
            balance-=Withdraw;
            cout<<"\nAmount withdrawn successfully!\nYour updated bank balance : "<<balance<<endl;
        }
        else
        {
            cout<<"\n[ERROR : Insufficient bank balance!]"<<endl;
        }
    }
}
int main()
{
    int n;
    cout<<"\nInput number of applicants\n";
    cin>>n;
    bankAc *b=new bankAc[n]; //dynamically allocating memory
    for (int i=0; i<n; i++)
    {
        cout<<"\nCreating Account Number "<<i+1<<", "<<endl;
        b[i].Assign();
    }
    int ch;
    do
    {
        cout<<"\n=================\nMenu :-\n\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Display\n5. Exit"<<endl;
        cout<<"\nInput ch"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            int AcN;
            cout<<"Input A/c number\n";
            cin>>AcN;
            bool flag=false;
            int r;
            for (int i=0; i<n; i++)
            {
                if (AcN==b[i].AcNo)
                {
                    flag=true;
                    r=i;
                    b[r].deposit();
                    break;
                }
            }
            if (!flag)
            {
                cout<<"\n[ERROR : Account Number not available!]"<<endl;
            }
        }
        break;
        case 2:
        {
            int AcN;
            cout<<"Input A/c number\n";
            cin>>AcN;
            bool flag=false;
            int r;
            for (int i=0; i<n; i++)
            {
                if (AcN==b[i].AcNo)
                {
                    flag=true;
                    r=i;
                    b[r].withdraw();
                    break;
                }
            }
            if (!flag)
            {
                cout<<"\n[ERROR : Account Number not available!]"<<endl;
            }
        }
        break;
        case 3:
        {
            int AcN;
            cout<<"Input A/c number\n";
            cin>>AcN;
            bool flag=false;
            int r;
            for (int i=0; i<n; i++)
            {
                if (AcN==b[i].AcNo)
                {
                    flag=true;
                    r=i;
                    b[r].checkBalance();
                    break;
                }
            }
            if (!flag)
            {
                cout<<"\n[ERROR : Account Number not available!]"<<endl;
            }
            break;
        }

        case 4:
        {
            int AcN;
            cout<<"Input A/c number\n";
            cin>>AcN;
            bool flag=0;
            int r;
            for (int i=0; i<n; i++)
            {
                if (AcN==b[i].AcNo)
                {
                    flag=true;
                    r=i;
                    b[r].display();
                    break;
                }
            }
            if (!flag)
            {
                cout<<"\n[ERROR : Account Number not available!]"<<endl;
            }
            break;
        }
        case 5:
            cout<<"\n======[Exiting the program...]======\n";
            exit(0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while(ch!=5);
    delete []b;
    return 0;
}
