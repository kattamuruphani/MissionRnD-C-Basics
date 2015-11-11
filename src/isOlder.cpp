/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
#include<string.h>
int leap_year(int, int, int,int);
int isOlder(char *dob1, char *dob2) {
	int i, j, k;
	int dd[2], mm[2], yy[2];
	int decision;
	char a[2][10];
	strcpy(a[0], dob1);
	strcpy(a[1], dob2);
	for (j = 0; j <= 1; j++){
		dd[j] = 0;
		for (i = 0; a[j][i] != '-'&&a[j][i]!='\0'; i++){
			dd[j] *= 10;
			if (a[j][i] > '0' || a[j][i]<'9')
				dd[j] += a[j][i] - '0';
			else 
				return -1;
		}
		if (dd[j]<1 || dd[j]>31)
			return -1;
		mm[j] = 0;
		for (i; a[j][i] != '-'&&a[j][i] != '\0'; i++){
			mm[j] *= 10;
			if (a[j][i] > '0' || a[j][i]<'9')
				mm[j] += a[j][i] - '0';
			else
				return -1;
		}
		if (mm[j] <= 0 || mm[j] >= 13)
			return -1;
		yy[j] = 0;
		for (i; a[j][i] != '\0'; i++){
			yy[j] *= 10;
			if (a[j][i] > '0' || a[j][i]<'9')
				yy[j] += a[j][i] - '0';
			else
				return -1;
		}
		if (yy[j] <= 0 || yy[j] >= 10000)
			return -1;



		if (yy[j] % 400 == 0 || (yy[j] % 4 == 0 && yy[j] % 100 != 0))
			decision = leap_year(dd[j], mm[j], yy[j], 29);
		else
			decision = leap_year(dd[j], mm[j], yy[j], 28);
		if (decision == -1)
			return -1;
		else{

			if (yy[0] < yy[1])
				return 1;
			else if (yy[1] < yy[0])
				return 2;
			else{
				if (mm[0] < mm[1])
					return 1;
				else if (mm[1] < mm[0])
					return 2;
				else{
					if (dd[0] < dd[1])
						return 1;
					else if (dd[1] < dd[0])
						return 2;
					else
						return 0;
				}
			}
		}
	}


}

int leap_year(int dd, int mm, int yy, int leap){
	int monthdays[] = { 31, leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (dd != monthdays[mm - 1]){
		return -1;
	}
	else
		return 1;
}