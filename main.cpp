#include <iostream>
#include <string>

using namespace std;


int main()
{
    string t_string;
    int start=0;
    int stop=0;
    int hours_to_seconds = 0;
    int minutes_to_seconds = 0;
	int total=0;
	bool count=true;

  	cout << "Enter String" <<endl;
		getline( cin, t_string );
		
		for(int i=0; i<t_string.length(); i++)
			switch(t_string[i])
			{
				case '+':
					if(count)
					{
						stringstream myStream( t_string.substr( start, stop ) );
						mystream<<hours_to_seconds;
						hours_to_seconds *= 3600;
						start = stop + 1;
						stop = length( t_string );
						stringstream myStream( t_string.substr( start, stop ) );
						myStream<<minutes_to_seconds;
						total = hours_to_seconds + (minutes_to_seconds*60);
						start = i + 1;
						stop = length(t_string);
					}
					if(t_string.find('+') < t_string.find('-'))
						stop = t_string.find('+');
					else
						stop = t_string.find('-');
					stringstream myStream( t_string.substr( start, stop ) );
					mystream<<hours_to_seconds;
					hours_to_seconds *= 3600;
					start = stop + 1;
					stop = length( t_string );
					stringstream myStream( t_string.substr( start, stop ) );
					myStream<<minutes_to_seconds;
					total += hours_to_seconds + (minutes_to_seconds*60);
					start=i+1;					
					stop = length(t_string);
					break;
				case '-':
					if(count)
					{
						stringstream myStream( t_string.substr( start, stop ) );
						mystream<<hours_to_seconds;
						hours_to_seconds *= 3600;
						start = stop + 1;
						stop = length( t_string );
						stringstream myStream( t_string.substr( start, stop ) );
						myStream<<minutes_to_seconds;
						total = hours_to_seconds + (minutes_to_seconds*60);
						stop = length(t_string);
						start=i+1;
					}
					if(t_string.find('+') < t_string.find('-'))
						stop = t_string.find('+');
					else
						stop = t_string.find('-');
					stringstream myStream( t_string.substr( start, stop ) );
					mystream<<hours_to_seconds;
					hours_to_seconds *= 3600;
					start = stop + 1;
					stop = length( t_string );
					stringstream myStream( t_string.substr( start, stop ) );
					myStream<<minutes_to_seconds;
					total -= hours_to_seconds + (minutes_to_seconds*60);
					start=i+1;	
					stop = length(t_string);
					break;
				default: break;
			}
	
	
}
