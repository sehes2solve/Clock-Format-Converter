#include <iostream>
#include <string>
#include <regex>

using namespace std;

const regex format("^\\d{1,2}\\:\\d{1,2}\\s(AM|PM)$");
/// <summary>
/// Checks whether the string is valid for clock format and has logical values indicates time
/// </summary>
/// <param name="time">the string that should be valid as clock time<param>
/// <returns>returns true if the string is valid and false if the string is invalid</returns>
bool HasValidFormat(string time);
/// <summary>
/// check whether values of hr section & min section within logical range
/// </summary>
/// <param name="time">the string that should be contain hr & min valid values<param>
/// <returns>return true if hr and min sections are valid otherwise return false</returns>
bool HasValidValue(string time);
/// <summary>
/// takes string of clock in AM/PM Format And convert it into it's equivalent Military Format
/// </summary>
/// <param name="time">the clock time that will be converted into military format</param>
/// <returns>return the equivalent military format</returns>
string MilitaryFormat(string time);
/// <summary>
/// convert the hr string to the equivalent int value & do operations according to the dayhalf to get it's equivalent 
/// int value in 24-hr format then return it as string
/// </summary>
/// <param name="Hr">Hr string that will be convert to it's equivalent string hr in 24-hr format</param>
/// <param name="dayhalf">the first char in dayhalf(A/P) that determines whether the past hour after or before noon</param>
/// <returns>return string after it's converted to it's equivalent 24-hr format</returns>
string ConvertHr(string Hr, char dayhalf);
/// <summary>
/// Add char of the assci of zero from the left if the string is one char to suit military time format
/// </summary>
/// <param name="time">the string that will be added by char of zero incase it's one char</param>
/// <returns>returns the string after it's added by zero char if it contain one char</returns>
string AddZero(string time);

int main()
{
	string time;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter Time : ";
		getline(cin,time,'\n');
		if (HasValidFormat(time))
			cout << "Military Format : " << MilitaryFormat(time) << endl;
		else
			cout << "Invalid Format !!!" << endl;
		cout << "Chance : " << i + 1;
		cout << "\n\n";
	}
	system("pause");
	return 0;
}

bool HasValidFormat(string time)
{
	if (regex_match(time, format))// check whether the time string format is in clock format HH:MM (AM/PM)
	{
		if (HasValidValue(time))//check whether values of hr and min are logical values
			return true;
		else
			return false;
	}
	else
		return false;
}
bool HasValidValue(string time)
{
	bool is_Colon = false;//bolon check whether the colon char in the string reached or 
						  //not that indicates that hr section is read and min section is the next
	for (unsigned int i = 0; i < time.length(); i++)
	{
		if (time[i] >= '0' && time[i] <= '9')//check whether the char is number
		{
			if (time[i + 1] >= '0' && time[i + 1] <= '9')//check whether the following char is number too
			{
				if (is_Colon)//check whethere those two numbers belong hr or min
				{
					if (time[i] > '5')//check if the tenth of the min is doesn't excess five so the whole value of min doesn't esceed 60
						return false;
				}
				else if (time[i] > '1')//check if the tenth of the hr is doesn't excess one so the whole value of hr doesn't esceed 12
					return false;
				else
					i++;//if the char number and followed by number then no need to check that number follow the char
			}
		}
		else if (time[i] == ':')
			is_Colon = true;
	}
	return true;
}
string MilitaryFormat(string time)
{
	int HourBoundary = time.find(':'), MinuteBoundary = time.find(' ');//variables saves indecies of last char after the hr section & min section
	string HrsStr, MinsStr;
	if (HourBoundary == 1)//the hr section consists of one digit
		HrsStr = time[0];
	else
		HrsStr = time.substr(0, 2);// takes substring from index zero with length 2
	if ((MinuteBoundary == 4 && HourBoundary == 2) || (MinuteBoundary == 3 && HourBoundary == 1))//the values of indecies that makes min 
												                                                 //section consists of one digit
		MinsStr = time[MinuteBoundary - 1];
	else
		MinsStr = time.substr(MinuteBoundary - 2, 2);// takes substring from index of the char before the space by one char with length 2
	return ConvertHr(HrsStr,time[time.length() - 2]) + AddZero(MinsStr) ;//return string consists of the equivalent hr string in 24-hr 
																		 //military format of hrs added to it min string in military format
}
string ConvertHr(string Hr,char dayhalf)
{
	int hr = stoul(Hr, nullptr, 10);//converts the Hr string into it's equivalent int value in decimal format
	if (dayhalf == 'A')//Clock time at AM
	{
		if (hr == 12)//if it's 12 before noon
			hr = 0;
	}
	else
	{
		if (hr != 12)// if it's not 12 and after noon
			hr += 12;
	}
	return to_string(hr);
}
string AddZero(string time)
{
	if (time.length() == 1)
		time = '0' + time;
	return time;
}
