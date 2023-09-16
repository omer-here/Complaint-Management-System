#include <iostream>
#include <cstdlib>                     //efficient for memory allocations dynmaics
#include <string>
#include <cctype>              //checks character whether satisfy certain condition or belong to certian group  
#include <fstream>                     //for reading and writing of statements 

using namespace std;

class complaint	                 //base class
{
    int count = 0;          //counting no of complaints
public:
    void create_complaint();            //member functions declarations
    void cancel_complaint();
    void update_complaint();
    void print_complaint();
    void view_complaint();
    void exit();

    complaint();                  //constructor declaration
};

complaint::complaint()           //constuctor with no parameters
{

}


struct node          //construct node
{
    int complaint_number;
    string customerName; 
    string date;
    string x;          // for storing description about complaint

    node* next;
};
   
//pointer declaration and initilization

node* start_ptr = NULL;

node* last = NULL;


class Admin : public complaint                           //inherited class Admin publically from complaint 
{
    string userName, userPassword;
public:                                   
    void create_complaint()
    {
        complaint::create_complaint();                  //call to parent class member functions
    };
    void cancel_complaint()
    {
        complaint::cancel_complaint();
    };

    void update_complaint()
    {
        complaint::update_complaint();
    };
    void print_complaint()
    {
        complaint::print_complaint();
    };
    void view_complaint()
    {
        complaint::view_complaint();
    };


    Admin ()  //constructor
    {
        userName = "user";          //private member defination
        userPassword = "pass";
    }

    complaint admin;          //object of class complaint (see return type)
    int menu;

    int admin_menu()                 
    {
        system("cls");
        cout << "\n";
        cout << "\t\t ===================================================\n";
        cout << "\t\t|   Complaint Management System - TRAVEL AGENCY    |\n";
        cout << "\t\t ===================================================\n\n\n";
        cout << "\t\t----------------------------------------------------\n";
        cout << "\t\t\t  Administrator / Staff Login      \n";
        cout << "\t\t----------------------------------------------------\n\n";
        cout << "\n\n\t\tPlease enter your user name: ";
        cin >> userName;
        cout << "\n\n\t\tPlease enter your user password: ";
        cin >> userPassword;

        if (userName == "user" && userPassword == "pass")
        {
            do       // work atleast once
            {
                system("cls");
                cout << "\n";
                cout << "\t\t ===================================================\n";
                cout << "\t\t|   Complaint Management System - TRAVEL AGENCY    |\n";
                cout << "\t\t ===================================================\n\n\n";
                cout << "\t\t--------------------------------------------------\n";
                cout << "\t\t||\t1. Create a Complaint \t\t\t ||\n";
                cout << "\t\t||\t2. View Complaint\t\t\t ||\n";
                cout << "\t\t||\t3. Update Complaint Status \t\t ||\n";
                cout << "\t\t||\t4. Print the complaint \t\t\t ||\n";
                cout << "\t\t||\t5. Cancel a Complaint \t\t\t ||\n";
                cout << "\t\t||\t6. Logout\t\t\t\t ||\n";
                cout << "\t\t--------------------------------------------------\n";
                cout << "Enter choice: ";
                //
                cin >> menu;

                switch (menu)
                {
                case 1:
                {
                    admin.create_complaint();
                    break;
                }


                case 2:
                {
                    admin.view_complaint();
                    system("PAUSE");
                    break;
                }

                case 3:
                {
                    admin.update_complaint();
                    system("PAUSE");
                    break;
                }

                case 4:
                {
                    admin.print_complaint();
                    system("PAUSE");
                    break;
                }
                case 5:
                {
                    admin.cancel_complaint();
                    system("PAUSE");
                    break;
                }
                case 6:
                {
                    cout << "You are Logged Out...!\n\n\n\n";
                    exit();
                    system("cls");
                    //return admin_menu();
                    break;
                }

                }                            //end Switch

            } while (menu != 6);//end do
            cout << "thank you" << endl;
            system("PAUSE");
        }

        else
        {
            cout << "\n\n\t\tInvalid login attempt. Please try again.\n" << '\n';
            system("PAUSE");
            system("cls");
            return admin_menu();


        }
    };
};


class customer : public complaint                // inherited class customer publically from complaint
{
    //no private members
public:
    void create_complaint()
    {
        complaint::create_complaint();
    };

};


//Functions definations
 
void complaint::create_complaint()
{
    system("cls");
    cout << "\n";
    cout << "\t\t ================================================\n";
    cout << "\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
    cout << "\t\t ================================================\n\n\n";
    cout << "\nAdd Complaint Details of Customer\n";
    cout << "_____________________________________ \n\n";

    node* temp;     // creates node type of pointer temp
    temp = new node;      // (pointing address to un-named object of type node)  
    cout << "Type Complaint no: ";
    cin >> temp->complaint_number;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, temp->customerName);
    cout << "Enter Date : ";
    cin >> temp->date;
    cout << "Complaint Description:";
    cout << "( 1000 words maximum ) \n";
    cin.ignore();
    getline(cin, temp->x);

    cout << "===========================================================================" << endl;
    cout << "Complaint added Successfully" << endl;
    cout << "===========================================================================" << endl;
    cout << "Go to Print Complaint to print the Complaint" << endl;
    cout << "===========================================================================" << endl;
    count++;
    system("PAUSE");

    temp->next = NULL;

    if (start_ptr != NULL)
    {
        temp->next = start_ptr;           //next then get assigned to start_ptr  
    }

    start_ptr = temp;           //start_ptr will get assigned to temp (new node)
    system("cls");
}

void complaint::view_complaint()
{
    int num;
    bool found;			//variable of type bool to search
    system("cls");

    node* temp;

    temp = start_ptr;   // placing address of start_part in temp 

    found = false;     // setting one condition either true or false
    cout << "\n";

    cout << "\t\t ================================================\n";
    cout << "\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
    cout << "\t\t ================================================\n\n\n";
    cout << " Enter the Complaint Number To Look into The Complaint Details\n";
    cin >> num;
    cout << "\n";
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tHere is the Complaint list\n";
    cout << "---------------------------------------------------------------------------" << endl;


    if (temp == NULL)    // it means if start_ptr = null (means no complaint has created before)
    {
        cout << "\tThere is no Complaint to show\n\t\t\tSo The List is Empty\n\n\n";
    }

    while (temp != NULL && !found)         // loop untill found is false and temp is not null
    {
        if (temp->complaint_number == num)
        {
            found = true;
        }

        if (found)     // found = true.. (means temp->complaint_number == num) 
        {
            cout << "Complaint Number : " << temp->complaint_number;
            cout << "\n";
            cout << "Customer Name: " << temp->customerName << endl;

            cout << "Complain Date : " << temp->date << endl;

            cout << "_____________________________________________________________________________" << endl;
            cout << "-------------------------" << endl;
            cout << "|Complaint description: |" << endl;
            cout << "-------------------------" << endl;
            cout << temp->x;

            cout << "\n";
            cout << "_____________________________________________________________________________" << endl;

        }


    }
}


void complaint::cancel_complaint()
{
    system("cls");
    int num;
    cout << "\n";
    cout << "\t\t ================================================\n";
    cout << "\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
    cout << "\t\t ================================================\n\n\n";
    cout << "Enter the Complaint number you want to delete \n";
    cin >> num;

    node* q;            // a pointer which will get deleted 
    node* temp;


    if (start_ptr == NULL)
        cerr << "Can not cancel from an empty list.\n";
    else
    {
        if (start_ptr->complaint_number == num)
        {
            q = start_ptr;       // assign address of start_ptr to q
            start_ptr = start_ptr->next;      // assign address of start_ptr->next to start_ptr
            count--;             // decerase the count

            if (start_ptr == NULL)   // if complaint created till now ,star_ptr == null
                last = NULL;   // assigning last = NULL

            delete q;       //deletes q
            cout << "The Complaint is Cancelled Successfully" << endl;
        }
        else
        {
            cout << "Invalid Input";
            cout << "Complaint to be Cancelled is not in the list." << endl;
        }
    }
}	//End function


void complaint::update_complaint()
{
    system("cls");
    node* temp;
    int num;        //int variable to get complaint number to be updated
    bool found;
    found = false;     // set found to false
    temp = start_ptr;     // assign address of start_ptr to temp
    cout << "\n";
    cout << "\t\t ================================================\n";
    cout << "\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
    cout << "\t\t ================================================\n\n\n";
    cout << "Enter Complaint Number To Update: ";
    cin >> num;

    if (temp == NULL && num == 0)    //ofcourse, if num ==0 and nothing in temp , then
    {
        cout << "No Complaint To Update..!" << endl;
    }

    else
    {
        while (temp != NULL && !found)        // loop untill found is false and temp is not null
        {
            if (temp->complaint_number == num)    //if given complaint number matches to sid 
            {
                found = true;
            }
            else
            {
                temp = temp->next;     //assign address of temp->next to temp
            }

            if (found)           // if found = true 
            {
                cout << "Change  Complaint Number: ";
                cin >> temp->complaint_number;
                cout << "Change Customer Name: ";
                cin.ignore();
                getline(cin, temp->customerName);
                cout << "Change Date : ";
                cin >> temp->date;
                cout << "Complaint Description:" << endl;
                cout << "( 1000 words maximum ) \n";
                cout << "  ";
                cin.ignore();
                getline(cin, temp->x);

                system("PAUSE");
                temp = temp->next;


            }

            cout << "COMPLAINT RECORD UPDATED....!\n\n" << endl;
        }

        if (temp != NULL && temp->complaint_number != num)   // if temp has some value and number does'nt matches,then
        {
            cout << "Invalid Complaint Number...!\n\n" << endl;
        }

    }

}		//End function

void complaint::print_complaint()
{
    int num;
    bool found;			//variable to search 
    system("cls");
    fstream mycomplaint;
    mycomplaint.open("complaint.txt", ios::out);
    node* temp;
    temp = start_ptr;     // setting info of stored complaint
    found = false;   //setting condition 
    cout << "\n";
    cout << "\t\t ================================================\n";
    cout << "\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
    cout << "\t\t ================================================\n\n\n";

    mycomplaint << "\n";
    mycomplaint << "\t\t ================================================\n";
    mycomplaint << "\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
    mycomplaint << "\t\t ================================================\n\n\n";
    
    cout << " Enter the Complaint Number To Print The Complaint Details\n";
    cin >> num;
    cout << "\n";
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tHere is the Complaint list\n";
    cout << "---------------------------------------------------------------------------" << endl;


    if (temp == NULL)
    {
        cout << "\tThere is no Complaint to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    while (temp != NULL && !found)      // while temp has some info and condition is false (as set earlier)
    {
        if (temp->complaint_number == num)
        {
            found = true;
        }
        else
        {
            temp = temp->next;  // assign address of temp->next to temp
        }
        if (found)	//print the complaint
        {
            cout << "Complaint Number : " << temp->complaint_number;
            
            cout << "\n";
            mycomplaint << "Complaint Number : " << temp->complaint_number;

            mycomplaint << "\n";
            cout << "Customer Name: " << temp->customerName << endl;
            mycomplaint << "Customer Name: " << temp->customerName << endl;
            
            cout << "Order Date : " << temp->date << endl;
            mycomplaint << "Order Date : " << temp->date << endl;
            cout << "____________________________________________________________________________" << endl;
            mycomplaint << "____________________________________________________________________________" << endl;
            
            cout << "Complaint description: " << endl;
            mycomplaint << "Complaint description: " << endl;
            
            cout << "----------------------" << endl;
            mycomplaint << "----------------------" << endl;
            

            cout << temp->x;
            mycomplaint << temp->x;
            cout << "\n";
            cout << "____________________________________________________________________________" << endl;
            mycomplaint << "\n";
            mycomplaint << "____________________________________________________________________________" << endl;
            
            temp = temp->next;   // assign address of temp->next to temp

        }
        mycomplaint.close();
        cout << "Complaint Printed Succesfully....!\n";


    }
}	//End function

void complaint::exit() //Function to exit
{
    cout << "\nYou choose to exit.\n" << endl;
}	//end function exit



int main()
{
    Admin admin;        //instance of class Admin
    customer customer;    //instance of class customer
    system("COLOR 9F");		//Color to change background
    int option;            // option to choose
    
    char input = 0;      //option to choose for returning to main menu
    
    do
	{
        cout << "\n";
        cout << "\t\t ================================================\n";
        cout << "\t\t|    Welcome To Complaint Management System      |\n";
        cout << "\t\t ================================================\n\n\n";

        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t1. Customer \t\t\t\t|\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t2. Administrator \t\t\t|\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t3. EXIT \t\t\t\t|\n";
        cout << "\t\t-------------------------------------------------\n\n";

        cout << "\t\tInput number Associated with Your User Type: ";
        cin >> option;
		 switch (option)
        {
        case 1:
        	{
            customer.create_complaint();
            break;
            }
            
        case 2:
          {
            admin.admin_menu();
            break;


            //Returning to main     
            cout << "\n\nDo you want to return to main?:(R/r)" << endl;
            cin >> input;
            system("CLS");
            if (input == 'R' || input == 'r')
                return main();
            break;
          }
        case 3:
          {
            admin.exit();	//function exit
            break;
          }
		}
	 
    } while (option != 3);
    cout << "thank you" << endl;
    system("PAUSE");
    system("cls");
  
    
}



