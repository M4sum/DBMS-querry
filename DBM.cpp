#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void displayActivity(string s)
{
	if(s.compare("1")==0){
		cout<<"Recording seizure activity\n";
	}
	else if(s.compare("2")==0)
		cout<<"recording EEG from area of tumor\n";
	else if(s.compare("3")==0)
		cout<<"identified tumor area and recording healthy brain area\n";
	else if(s.compare("4")==0)
		cout<<"patient had eyes closed\n";
	else if(s.compare("5")==0)
		cout<<"patient had eyes opened\n";
	else
		cout<<"there appears to be a problem"<<endl;
}

string getOneSecondData(int n)
{
    string x;
    int a=1;
    ifstream file("data.csv");
    if (!file)
    {
        cout << "Unable to open file";
    }
	else
	{
		getline(file,x);
		for(int i=0;i<n;i++)
		{
			a=1;
			while(a<180)
			{
				getline(file,x,',');
				a++;
			}
			getline(file,x,'\n');
		}
		return x;
    }
}

int dataForEachIndividual()
{
	string token;
	string x("V1."),y;
	string msg;
	cout<<"Enter the patient number:";
	cin>>y;
	y=x+y;
    ifstream file("data.csv");
    if (!file)
    {
        cout << "Unable to open file";
    }
	else
	{
		getline(file,token);
		for(int i=1;i<11503;i++)
		{
			getline(file,token,'.');
			getline(file,token,'"');
			if(y.compare(token)==0){
				msg=getOneSecondData(i);
				//cout<<msg<<endl;
				displayActivity(msg);
				return 0;
			}
		}
    }
}

void data()
{
	string b;
	cout<<"Enter condition:"<<endl;
	cin>>b;
	string x;
	int a = 1;
	int count=0;
	ifstream file("data.csv");
	if (!file)
	{
		cout << "Unable to open file";
	}
	else
	{
		getline(file, x);
		for (int i = 0; i < 11503; i++)
		{
			a = 1;
			while (a < 180)
			{
				getline(file, x, ',');
				a++;
			}
			getline(file, x, '\n');
			if(x.compare(b)==0){
				count++;
			}
		}
		count=count/23;
		cout<<count;
	}
}

int main() {
	data();
    //dataForEachIndividual();
}