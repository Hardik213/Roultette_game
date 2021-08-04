#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;
int B[37]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
int C[5]={1,2,3,0,0};

void intro(){
    system("cls");
    string var="\n=========================================================================================="
    "\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     "
    "\n CC          A  A      SS             III     NN N   NN   OO      OO    "
    "\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    "
    "\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO   " 
    "\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO   "  
    "\n==============================================================================================\n";
    
    for(int i=0;i<var.size();i++){
        Sleep(10);
        cout<<var[i];
    }
}

class Roulette_game{
    public:
    int N, rand_num,New;                                 // 'N' is the Number of players playing the game.
    char repeat,Add_player;
    vector<string>names;
    vector<long>total_chips;
    vector<int>betway;
    vector<long>bet_chips;
    vector<int>Guess_num;
    vector<int>Guess_column;

    void info();
    void chip_in();
    void bet_type();
    void betting();
    void main_game();
    void results();
    void removal();
    void final_chips();
    void repeater();
    void New_players();
};

void Roulette_game::info(){
    label:
        cout<<"\nEnter the number of players who want ot play the game(maximum 5): ";
        cin>>N;
    if (N>0&&N<6){
        for (size_t i = 0; i < N; i++){
        string x;
        cout<<"Player "<<i+1<<", Enter your name: ";
        cin>>x;
        names.push_back(x);
        }
        cout<<"\n";
        cout<<"-------------------------------------------------------------------------------------------------\n";
    }
    else{
        cout<<"This many Players cannot play this Game. Please enter appropriate Number."<<endl;
        goto label;
    }
}   

void Roulette_game::chip_in(){
    cout<<"\n";
    for (size_t i = 0; i < N; i++){
        int chips;
        cout<<"Player "<<i+1<<"("<<names.at(i)<<"), Enter the Amount of chips you want: ";
        cin>>chips;
        total_chips.push_back(chips);
    }
    cout<<"\n";
    cout<<"-------------------------------------------------------------------------------------------------\n";
}


void Roulette_game::bet_type(){
    system("cls");
    cout<<"\nThere are three different types of bet to play:-"<<endl;
    label1:
        cout<<"1. Bet on a single number. Profit--> 35 times the bet"<<endl;
        cout<<"2. Bet on outcome of Even Number. Profit--> 2 times the bet."<<endl;
        cout<<"3. Bet on outcome of Odd Number. Profit--> 2 times the bet."<<endl;
        cout<<"4. Bet on a column on the board. Profit--> 5 times the bet."<<endl<<endl;
        cout<<"Enter the respective Number to choose the way you want to bet.\nOnly a single type of bet can be played at a time."<<endl<<endl;
    for (size_t i = 0; i < N; i++){
    label4:
        int bet_way;
        cout<<"Player "<<i+1<<"("<<names.at(i)<<"), Choose the way you want to bet: ";
        cin>>bet_way;
        if(bet_way==1){
            betway.push_back(bet_way);
        }
        else if(bet_way==2){
            betway.push_back(bet_way);
        }
        else if (bet_way==3){
            betway.push_back(bet_way);
        }
        else if (bet_way==4){
            betway.push_back(bet_way);
        }
        else{
            cout<<"Please make a valid choice...."<<endl;
            goto label4;
        }
    }
    cout<<"\n";
    cout<<"-------------------------------------------------------------------------------------------------\n"; 
}

void Roulette_game::betting(){
    label2:
        for (size_t i = 0; i < N; i++){
            int bet;
            cout<<"Player "<<i+1<<"("<<names.at(i)<<"), Enter the amount you want to bet: ";
            cin>>bet;
            bet_chips.push_back(bet);
        }
    cout<<"\n";
    for (size_t i = 0; i < N; i++){
        if (bet_chips.at(i)>total_chips.at(i)){
            cout<<"Player "<<i+1<<"("<<names.at(i)<<") doesn't have this much chips. Please choose a valid amount."<<endl;
            bet_chips.erase(bet_chips.begin(), bet_chips.end());
            goto label2;
        }
        else{
            continue;
        }
    }
    cout<<"\n";
    cout<<"-------------------------------------------------------------------------------------------------\n"; 
    for (size_t i = 0; i < N; i++){
        total_chips.at(i)-=bet_chips.at(i);
    }
}

void Roulette_game::main_game(){
    system("cls");
    for (size_t i = 0; i < N; i++){
        int num;
    label3:
        switch (betway.at(i)){
        case 1:
            int x;
            cout<<"\nIt is Player "<<i+1<<"("<<names.at(i)<<")'s turn:"<<endl;
            cout<<"\nPlease choose a number between 0 to 36: ";
            cin>>num;
            Guess_num.push_back(num);
            Guess_column.push_back(40);

            if(num>=0 && num<37){
                cout<<"\nNow please wait for the ball to Roll."<<endl;
            }
            else{
                cout<<"\nPlease make a valid choice...."<<endl;
                goto label3;
            }
            break;
        case 2:
            cout<<"\nPlayer "<<i+1<<"("<<names.at(i)<<") had chosen to bet on Even Number. Please wait for the outcome."<<endl;
            Guess_num.push_back(40);
            Guess_column.push_back(40);
            break;
        case 3:
            cout<<"\nPlayer "<<i+1<<"("<<names.at(i)<<") had chosen to bet on Odd Number. Please wait for the outcome."<<endl;
            Guess_num.push_back(40);
            Guess_column.push_back(40);
            break;
        case 4:
            int z;
            cout<<"\nIt is Player "<<i+1<<"("<<names.at(i)<<")'s turn:"<<endl;
            cout<<"\nPlease choose A column to bet On the Board (Choose any from 1,2 or 3): ";
            cin>>z;
            Guess_column.push_back(z);
            Guess_num.push_back(40);

            if(z>=1 && z<4){
                cout<<"\nNow please wait for the ball to Roll."<<endl;
            }
            else{
                cout<<"\nPlease make a valid choice...."<<endl;
                goto label3;
            }
            break;
        default:
            break;
        }
    }
        cout<<"\nPress Enter to Roll the Ball...";
        getch();
}

void Roulette_game::results(){
    system("cls");
    srand(time(0));
    rand_num=(rand()%36-0+1)+0;
    cout<<"\nAaaaaand The Number on the Wheel is: "<<rand_num<<endl;
    for (size_t i = 0; i < N; i++){
        switch (betway.at(i))
        {
        case 1:
            if(Guess_num.at(i)==rand_num){
                cout<<"\n"<<names.at(i)<<", Congratulations! You guessed correct Number. You Win!"<<endl;
                bet_chips.at(i)*=35;
                total_chips.at(i)+=bet_chips.at(i);
            }
            else{
                cout<<"\n"<<names.at(i)<<", You Guessed Wrong Number. You Lose!"<<endl;
            }
            break;

        case 2:
            if((rand_num)%2==0){
                cout<<"\n"<<names.at(i)<<", It is Even Number. You Win."<<endl;
                bet_chips.at(i)*=2;
                total_chips.at(i)+=bet_chips.at(i);
            }
            else{
                cout<<"\n"<<names.at(i)<<", It is Odd Number. You Lose."<<endl;
            }
            break;

        case 3:
            if((rand_num)%2!=0){
                cout<<"\n"<<names.at(i)<<", It is Odd Number. You Win."<<endl;
                bet_chips.at(i)*=2;
                total_chips.at(i)+=bet_chips.at(i);
            }
            else{
                cout<<"\n"<<names.at(i)<<", It is Even Number. You Lose."<<endl;
            }
            break;
        case 4:
            if(Guess_column.at(i)==1){
                int c=1;
                int d=0;
                while (c<35){
                    if(c==rand_num){
                        d++;
                        break;
                    }else{}
                    c+=3;
                }
                if(d!=0){
                    cout<<"\n"<<names.at(i)<<", Congratulations! You guessed correct column. You Win!"<<endl;
                    bet_chips.at(i)*=5;
                    total_chips.at(i)+=bet_chips.at(i);
                }
                else{
                    cout<<"\n"<<names.at(i)<<", You Guessed wrong Column. You Lose."<<endl;
                }
            }
            else if(Guess_column.at(i)==2){
                int c=2;
                int d=0;
                while (c<36){
                    if(c==rand_num){
                        d++;
                        break;
                    }else{}
                    c+=3;
                }
                if(d!=0){
                    cout<<"\n"<<names.at(i)<<", Congratulations! You guessed correct column. You Win!"<<endl;
                    bet_chips.at(i)*=5;
                    total_chips.at(i)+=bet_chips.at(i);
                }
                else{
                    cout<<"\n"<<names.at(i)<<", You Guessed wrong Column. You Lose."<<endl;
                }
            }
            else if(Guess_column.at(i)==3){
                int c=3;
                int d=0;
                while (c<37){
                    if(c==rand_num){
                        d++;
                        break;
                    }else{}
                    c+=3;
                }
                if(d!=0){
                    cout<<"\n"<<names.at(i)<<", Congratulations! You guessed correct column. You Win!"<<endl;
                    bet_chips.at(i)*=5;
                    total_chips.at(i)+=bet_chips.at(i);
                }
                else{
                    cout<<"\n"<<names.at(i)<<", You Guessed wrong Column. You Lose."<<endl;
                }
            }else{}
            break;  
        default:
            break;
        }
    }
}

void Roulette_game::final_chips(){
    cout<<"-------------------------------------------------------------------------------------------------\n";
    for (size_t i = 0; i < N; i++){
        cout<<"Total chips for Player "<<i+1<<"("<<names.at(i)<<") is: "<<total_chips.at(i)<<endl;
    }
    betway.clear();
    bet_chips.clear();
    Guess_num.clear();
    Guess_column.clear();
    cout<<"\n";
}

void Roulette_game::repeater(){
    cout<<"\n";
    int i=0;
    while (i<N){
        label5:
        cout<<names.at(i)<<", do you want to leave the table?(Type 'y' for Yes and 'n' for No): ";
        cin>>repeat;
        if(repeat=='y'||repeat=='Y'){
            cout<<names.at(i)<<", leaves the table\n"<<endl;
            for (size_t j = i; j < N-1; j++){
                names.at(j)=names.at(j+1);
                total_chips.at(j)=total_chips.at(j+1);
            }
            N--;
            i--;
            names.erase(names.end());
        }
        else if (repeat!='y'&&repeat!='Y'&&repeat!='n'&&repeat!='N'){
            cout<<"Invalid Input!"<<endl;
            goto label5;
        }
        ++i;
    } 
}

void Roulette_game::New_players(){
    cout<<"\n";
    if(N>=0 && N<5){
        cout<<"Do any New Players want to join the Game (Max. Seats available: "<<5-N<<") (Type 'Y' for Yes & 'N' for No): ";
        cin>>Add_player;
        if(Add_player=='y'||Add_player=='Y'){
            cout<<"Enter the Amount of Player want to join in: ";
            cin>>New;
            N+=New;
            cout<<"Enter the Names of New Players: "<<endl;
            for (size_t i = 0; i < New; i++){
                string x;
                cout<<"\tNew-Player "<<i+1<<" Name: ";
                cin>>x;
                names.push_back(x);
            }
            for (size_t i = New+1; i < N; i++){
                int x;
                cout<<"New-Player "<<i+1<<"("<<names.at(i)<<"), Enter the Amount of chips you want: ";
                cin>>x;
                total_chips.push_back(x);
            }
        }
        else if (Add_player=='n'||Add_player=='N'){
            if(N>0){
            cout<<"Then, The Game shall continue as is!"<<endl;
            }
            else{}
        }
        else{}
    }
    else{}
}

void board(){
    int i=0;
    cout<<"\t\t\t _______________________"<<endl;
    cout<<"\t\t\t|          ";
    B[0]==0?cout<<" 0 ":cout<<"{"<<(char)B[0]<<"}";
    cout<<"          |"<<endl;
    cout<<"\t\t\t -----------------------"<<endl;
    while(i<36){
        if(i<9){
            cout<<"\t\t\t|  ";
            B[i+1]==i+1?cout<<" "<<i+1<<" ":cout<<"{"<<(char)B[i+1]<<"}";
            cout<<"  |  ";
            B[i+2]==i+2?cout<<" "<<i+2<<" ":cout<<"{"<<(char)B[i+2]<<"}";
            cout<<"  |  ";
            B[i+3]==i+3?cout<<" "<<i+3<<" ":cout<<"{"<<(char)B[i+3]<<"}";
            cout<<"  |"<<endl;
        }
        else{
            cout<<"\t\t\t|  ";
            B[i+1]==i+1?cout<<" "<<i+1:cout<<"{"<<(char)B[i+1]<<"}";
            cout<<"  |  ";
            B[i+2]==i+2?cout<<" "<<i+2:cout<<"{"<<(char)B[i+2]<<"}";
            cout<<"  |  ";
            B[i+3]==i+3?cout<<" "<<i+3:cout<<"{"<<(char)B[i+3]<<"}";
            cout<<"  |";
            if(i==15)
            {
                cout<<"  Even |  "<<(char)C[3];
            }
            else if(i==18)
            {
                cout<<"  Odd  |  "<<(char)C[4];
            }
            cout<<endl;
        }
        if(i==33){
            cout<<"\t\t\t _______________________"<<endl;
            cout<<"\tColumns:\t|  ";
            C[0]==1?cout<<" 1 ":cout<<"{"<<(char)C[0]<<"}";
            cout<<"  |  ";
            C[1]==2?cout<<" 2 ":cout<<"{"<<(char)C[1]<<"}";
            cout<<"  |  ";
            C[2]==3?cout<<" 3 ":cout<<"{"<<(char)C[2]<<"}";
            cout<<"  |"<<endl;
            cout<<"\t\t\t _______________________"<<endl<<endl;
        }
        else{
            cout<<"\t\t\t -----------------------"<<endl;
        }
        i+=3;
    }
}

int main(){
    Roulette_game game;
    // intro();
    board();
    game.info();
    game.chip_in();
label6:
    game.bet_type();
    game.betting();
    game.main_game();
    game.results();                                   
    game.final_chips();
    game.repeater();
    game.New_players();
    if(game.N==0){
        cout << "-------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tGAME OVER!!!\t\t\t\t\t\n";
        cout << "-------------------------------------------------------------------------------------------------\n";
    }
    else{
        cout<<"Enjoy the Next round.\n"<<endl;
        goto label6;
    }

    return 0;
}