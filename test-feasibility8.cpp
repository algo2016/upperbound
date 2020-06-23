// test-feasibility.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int p[9], f[9];
	float temp;
	int sum;

	p[1] = 12;
	p[2] = 8;
	p[3] = 6;
	p[4] = 8;
	p[5] = 6;
	p[6] = 8;
	p[7] = 9;
	p[8] = 12;




	float upperbound = 0;
	for (int i= 1; i<= 8; i++)
	{
		upperbound += (8-i+0.5) / (8*p[i]);
	}

	cout << "upper bound is  " << upperbound << endl;

	for (int t = 1; t<= 72; t++)
	{
		sum = 0;
		for (int i = 1; i <= 8; i++ )
		{
			temp = t - i;
			if (temp < 0)
			{
				f[i] = 0;
			}
			else
			{
				temp = temp / p[i];
				f[i] = (int)floor(temp)+1;
			}
			sum += f[i];
		}
		if (sum > t)
		{
			cout << "infeasible at time " << t << endl;
			break;
		}
	}
    return 0;
}

