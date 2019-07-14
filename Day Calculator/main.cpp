//DAY CALCULATOR

#include<iostream>
#include<stdlib.h>
using namespace std;

main()
{
    int d, m, y, y1, q, dd, mn, mm, cn, cmm, r;
    char ch;
    do
    {
        system("cls"); // To clear the screen

        cout<<"\n DAY CALCULATOR.\n";
        cout<<"\n Enter the date \n";
        cout<<"\n Enter the day (1-31) : ";
        cin>>d;
        cout<<"\n Enter the month (1-12) : ";
        cin>>m;
        cout<<"\n Enter the year : ";
        cin>>y;
        cout<<"\n The date is "<<d<<"/"<<m<<"/"<<y<<".";

        y1 = y % 100; // 1. Take the last two digits of the year.
        q = y1 / 4; // 2. Divide it by 4 and take the quotient.
        dd = d + q; // 3. Add the day of the month to the quotient

        // The months key value are as follows:
        if(m == 9 || m == 12) // For September and December
        {
            mn = 6;
        }
        else if(m == 2 || m == 3 || m == 11) // For February, March and November
        {
            mn = 4;
        }
        else if( m == 10 || m == 1 ) // For October and January
        {
            mn = 1;
        }
        else if(m == 4 || m == 7) // For April and July
        {
            mn = 0;
        }
        else if(m == 5) // For May
        {
            mn = 2;
        }
        else if(m == 6) // For June
        {
            mn = 5;
        }
        else if(m == 8) // For August
        {
            mn = 3;
        }
        if(y % 4 == 0 && m == 2)
        {
            /* If it is a leap year and the month is February.
               Subtract 1 from the original key of February.
               i.e. 4 - 1 = 3
            */
            mn = 3;
        }
        else if(y % 4 == 0 && mn == 1)
        {
            /*If it is a leap year and the month is January.
              Subtract 1 from the original key of January.
              i.e. 1 - 1 = 0
            */
            mn = 0;
        }
        mm = dd + mn; // 4. Add the months key value to previous result.

        // The century code is as follows:
        while(true)
        {
            /* Suppose the year is not in the table.
               In this case all we have to do is add or subtract 400 until we have a year (century) that is in the table.
               This is because the Gregorian calender repeats every 400 years.
            */
            if (y < 1700) // If the year is less than 1700 add 400 to the year.
            {
                y = y + 400;
            }
            else if (y > 2100) // If the year is greater than 2100 subtract 400 to the year.
            {
                y = y - 400;
            }
            else
            {
                /* The century code from the years 1700's to 2000's are as follows:
                   Once the century code is found break out of while loop.
                */
                if(y >= 1700 && y <= 1799)
                {
                    cn = 4;
                }
                else if(y>=1800 && y<=1899)
                {
                    cn = 2;
                }
                else if(y >= 1900 && y <= 1999)
                {
                    cn = 0;
                }
                else if(y >= 2000 && y<=2099)
                {
                    cn = 6;
                }
                break;
            }
        }
        cmm = mm + cn + y1; // 5. Add the century code and last two digits of the year to the previous result.
        r = cmm % 7; // 6. Divide the result by 7

        // The day of thee week will be based on the value of the remainder as follows:
        if(r == 1)
        {
            cout<<"\n It's a Sunday."<<endl;
        }
        else if(r == 2)
        {
             cout<<"\n It's a Monday."<<endl;
        }
        else if(r == 3)
        {
            cout<<"\n It's a Tuesday."<<endl;
        }
        else if(r == 4)
        {
            cout<<"\n It's a Wednesday."<<endl;
        }
        else if(r == 5)
        {
            cout<<"\n It's a Thursday."<<endl;
        }
        else if(r == 6)
        {
            cout<<"\n It's a Friday."<<endl;
        }
        else if(r == 0)
        {
            cout<<"\n It's a Saturday."<<endl;
        }
        cout<<"\n Do you want to do it again (y/n) : ";
        cin>>ch;
    }
    while(ch == 'y' || ch == 'Y');
}
