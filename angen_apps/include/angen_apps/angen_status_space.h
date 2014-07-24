#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string actuator_status[9][4];
class AngenStatusSpace
{
        
        
        public:
        void init_actuator_status();
        void set_actuator_status(string , string , string );
        string get_actuator_status(string , string );
        int room_index(string );
        int actuator_index(string );
        void print_status_table();
        
        AngenStatusSpace() { init_actuator_status(); }
        ~AngenStatusSpace() { init_actuator_status(); }       
};

void AngenStatusSpace::init_actuator_status()
{
        actuator_status [0][0] = "room_Name";
        actuator_status [0][1] = "door";
        actuator_status [0][2] = "window";
        actuator_status [0][3] = "light";
        actuator_status [1][0] = "bedroom";
        actuator_status [2][0] = "kitchen";
        actuator_status [3][0] = "workroom";
        actuator_status [4][0] = "livingroom";
        actuator_status [5][0] = "balcony";
        actuator_status [6][0] = "bathroom";
        actuator_status [7][0] = "closet";
        actuator_status [8][0] = "entrance";
        
        for (int i=1; i<9; i++)
        {
                actuator_status [i][1] = "close";
                actuator_status [i][2] = "close";
                actuator_status [i][3] = "off";
        }                                   
}

void AngenStatusSpace::print_status_table()
{
        cout<<endl<<"The actuator status table:"<<endl;
        cout<<"    ----------------------------------------------------------------   "<<endl;
        for(int i=0; i<9; i++)
            {
                for(int j=0; j<4; j++)
                   cout<<setw(12)<<actuator_status [i][j]<<"   ";
                cout<<endl;
            }
        cout<<"    ----------------------------------------------------------------    "<<endl<<endl;    
}
                 
int AngenStatusSpace::actuator_index(string actuator)
{
        int k = 0;
        for(int j=1; j<4; j++)
           if (!actuator_status[0][j].compare(actuator))
               k = j;
        return k;       
}

int AngenStatusSpace::room_index(string room)
{
        int k = 0;
        for(int i=1; i<9; i++)
                if(!actuator_status[i][0].compare(room))
                        k = i;
        return k;
}
                                              
void AngenStatusSpace::set_actuator_status(string room, string actuator, string status)
{
        actuator_status[room_index(room)][actuator_index(actuator)] = status;   
        print_status_table();   
}

string AngenStatusSpace::get_actuator_status(string room, string actuator)
{
          cout<<"Status before actuation:"<<actuator_status[room_index(room)][actuator_index(actuator)]<<endl;
          return actuator_status[room_index(room)][actuator_index(actuator)];
}
