#include<iostream>
#include<math.h>
#include<string>
using namespace std;

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}
string processHelper(string s)
{
	string cnt = s;
	string status = s;
	int seek = 0;
	while (seek < s.length())
	{
		if (seek != 0)
		{
			swap(status[seek], status[0]);
			cnt += " " + status;

		}
		for (int i = 1; i < s.length() - 1; i++)
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				swap(status[i], status[j]);
				cnt += " " + status;
				status = s;
			}
		}
		seek++;
	}

	return cnt+" ";
}

void process(string input)
{
	for (int level = 1; level <= input.length(); level++)
	{
		//input:abc
		//output: a, b, c, ab, ac, ba, bc, ca, cb, abc, acb, bac, bca, cab, cba
		for (int i = 0; i < input.length(); i++)
		{
			char getChar = input[i];
			string cnt = "";
			cnt += getChar;
			if (level == 1)
			{

				cout << cnt << " ";
			}
			else
			{
				for (int merge = i+1; merge < input.length(); merge++)
				{
					cnt = "";
					cnt+=input[i];
					if (merge != i)
					{
						int m = merge;
						for (int find = 2; find <= level; find++)
						{
							cnt += input[m];
							if (m < input.length())
								m++;
							if (m >= input.length())
								break;
						}
						cout << processHelper(cnt);
					}
					if (level == input.length())
						break;
				}
				break;
			}
		}
	}
}


void main()
{
	string input;
	cout << "Nhap day ky tu khong chua khoang trang: ";
	cin >> input;
	process(input);
}