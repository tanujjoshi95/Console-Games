#include <iostream>
#include <string>
using namespace std;
class game
{
private:
    int bettingamount;
    int totalbalance;
    string name;
    int guessednumber;
    int outnumber;

public:
    
    void rules();
    void input();
    void gamefunction();
    void numberguess();
    void output();
    void check();
    void amountcheck();
};

void game ::rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. 1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

void game ::input()
{
    // contian initial balace and enter the betting amount

    cout << "\nEnter the player name : ";
    getline(cin, name);
    //  cin>>name;
    cout << "\nEnter the amount to put in balance : ";
    cin >> totalbalance;
    system("cls");
    rules();
    amountcheck();
}

void game::amountcheck()
{
    if(totalbalance==0)
    {
        cout<<"\t!!!!!!!! YOU CAN NOT PLAY ANYMORE !!!!!!!!\n"<<endl;
        
    }
    else{  // take the number and compare it with random generated number
    cout << "\nEnter the betting amount : ";
    cin >> bettingamount;
    if (totalbalance < bettingamount)
    {
        cout << "\n\t!!!!!!!!THE BETTING AMOUNT IS MORE THAN TOTAL BALANCE ENTER THE AMOUNT  AGAIN !!!!!!!! \n "<<endl;
        amountcheck();
    }

    else{
        numberguess();
    }
    }
}

void game ::numberguess()
{
  
    cout << "\nEnter the number to bet btw 1 to 10 : ";
    cin >> guessednumber;
    if (guessednumber > 10 || guessednumber <= 0)
    {
        cout << "\t!!!!!!!! INVALID INPUT ENTER AGAIN !!!!!!!!\n\n";
        numberguess();
    }
    else
    {

        gamefunction();
    }
}



void game ::gamefunction()
{
    // working of the game and do not exit until the balance ==0 or user say
    // exit;
    outnumber = rand() % 10 + 1;

    if (guessednumber == outnumber)
    {
        cout << "\nYOU WON AMOUNT : " << 10 * bettingamount << endl;
        totalbalance = totalbalance + 10 * bettingamount;
        cout<<"\nYOUR TOTAL AMOUNT IS : "<<totalbalance<<endl;
    }

    else
    {
        cout << "\nYOU LOOSE !! YOUR MONEY IS DEDUCTED " << endl;
        totalbalance = totalbalance - bettingamount;
        cout<<"\nYOUR TOTAL AMOUNT IS : "<<totalbalance<<endl;
    }
     if(totalbalance==0)
    {
        cout<<"\t!!!!!!!! YOU CAN NOT PLAY ANYMORE !!!!!!!!\n"<<endl;
        
    }
    else{
    check();
    }

}

void game ::check()
{
    string c;

    cout << "\nTO CONTINUE THE GAME TYPE YES AND TO EXIT TYPE NO : ";
    cin>>c;

    if (c == "YES")
    {
        amountcheck();
    }

    else if (c == "NO")
    {
        output();
    }

    else
    {
        cout << "\n\t!!!!!!!!INVALID INPUT ENTER AGAIN !!!!!!!!\n " << endl;
        check();
    }
}

void game ::output()
{
    // give the output about wining and looss and add or subtract from the
    // the total balance
    cout<<endl;
    cout<<"  ******** THANKS FOR PLAYING ******** "<<endl;
    cout<< " \n" <<name<<endl;

    cout << "\nYOUR FINAL  AMOUNT IS : " << totalbalance << endl;
}


int main()
{ 
    game g;
    g.input();
    return 0;
}