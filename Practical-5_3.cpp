#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{	
    int choice;

    do
    {
        cout<<"\n\nPress 1 for Adding a New Item."<<endl;
        cout<<"Press 2 for View All Items."<<endl;
        cout<<"Press 3 for Searching a Perticular Item."<<endl;
        cout<<"Press 4 to Exit."<<endl;

        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    ofstream file("Prac5_3.txt",ios::app);

                    string name;
                    int quantity;
                    float price;

                    cout<<"Enter the name of the Item : ";
                    cin>>name;

                    cout<<"Enter the Quantity : ";
                    cin>>quantity;

                    cout<<"Enter the Price : ";
                    cin>>price;

                    file<<name<<" "<<quantity<<" "<<price<<endl;

                    file.close();

                    cout<<"Item Added Successfully..."<<endl;
                }
            break;

            case 2:
                {
                    ifstream file("Prac5_3.txt");

                    string name;
                    int quantity;
                    float price;
                    
                    cout<<"\nItems in Inventory : "<<endl;

                    while(file>>name>>quantity>>price)
                    {
                        cout<<"Name : "<<name<<" , ";
                        cout<<"Quantity : "<<quantity<<" , ";
                        cout<<"Price : "<<price<<endl;
                    }

                    file.close();
                }
            break;

            case 3:
                {
                    ifstream file("Prac5_3.txt");

                    string searchName;
                    string name;
                    int quantity;
                    float price;

                    cout<<"Enter Item Name to be Searched : ";
                    cin>>searchName;

                    int found = 0;

                    while(file>>name>>quantity>>price)
                    {
                        if(name==searchName)
                        {
                            cout<<"\nItem Found!"<<endl;
                            cout<<"Name : "<<name<<" , "; 
                            cout<<"Quantity : "<<quantity<<" , "; 
                            cout<<"Price : "<<price<<endl;
                            found = 1;
                        }
                    }

                    if(!found)
                    {
                        cout<<"\nItem not found!"<<endl;
                    }   
                }
            break;

            case 4:
                {
                    cout<<"\nExited Successfully..."<<endl;
                    return 0;
                }
            break;

            default:
                {
                    cout<<"Please Enter a Valid Choice!!!"<<endl;
                }
            break;
        }
    }while(1);
    
    return 0;
}