#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{	
    int no_line = 0;
    int no_char = 0;
    int no_words = 0;

    ifstream file("Prac5_2.txt");

    string line;

    while(getline(file,line))
    {
        no_line++;

        int flag = 0;

        for(int i=0; i<line.length(); i++)
        {
            char c = line[i];

            if(c != ' ' && c != '\t')
            {
                no_char++;

                if(!flag) 
                {
                    no_words++;
                    flag = 1;
                }
            } 

            else 
            {
                flag = 0;
            }
        }
    }

    file.close();

    cout<<"Number of Lines : "<<no_line<<endl;
    cout<<"Number of Characters : "<<no_char<<endl;
    cout<<"Number of Words : "<<no_words<<endl;
    
    return 0;
}