#include <stdio.h>
#include <cs50.h>

int first_step(long long ccn);
int second_step(long long ccn);
bool checksum(long long ccn);
int return_length(long long ccn);
string return_company(long long cc_number);

int main(void)
{
    printf("Number: ");
    long long cc_number = get_long_long();
    return_company(cc_number);
    printf ("%s", return_company(cc_number));
    return 0;
}

bool checksum(long long ccn)
{
    if ((first_step(ccn) + second_step(ccn)) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int first_step(long long ccn)
{
    int firstStepSum = 0;
    long long mod = 100;
    long long divisor = 10;
    for (int i = 0; i < 8; i++)
    {
        firstStepSum += (/*first digit*/((ccn % mod) / divisor * 2) % 10) + (/*second digit*/((ccn % mod) / divisor * 2) % 100 / 10);
        mod *= 100;
        divisor *= 100;
    }
    return firstStepSum;
}

int second_step(long long ccn)
{
    int secondStepSum = 0;
    long long mod = 10;
    long long divisor = 1;
    for (int i = 0; i < 8; i++)
    {
        secondStepSum += (ccn % mod) / divisor;
        mod *= 100;
        divisor *= 100;
    }
    return secondStepSum;
}

int return_length(long long ccn)
{
    if (ccn < 10000000000000000/*17 digit number*/ && ccn > 999999999999/*12 digit number*/) 
    {
        if (ccn < 1000000000000000/*16 digit number*/)
        {
            if (ccn < 10000000000000/*14 digit number*/)
            {
                return 13;
            }
            else
            {
                return 15;
            }
        }
        else
        {
            return 16;
        }
    }
    else
    {
        return 0;
    }
}

string return_company(long long cc_number)
{
        if (checksum(cc_number) == true && return_length(cc_number) == 15 && (cc_number / 10000000000000 == 34 || cc_number / 10000000000000 == 37)/*starts with 34 || 37*/)
    {
        return "AMEX\n";
    }
    else if (checksum(cc_number) == true && return_length(cc_number) == 16 && (cc_number / 100000000000000 > 50 && cc_number / 100000000000000 < 56)/*starts with > 50 && < 56*/)
    {
        return "MASTERCARD\n";
    }
    else if (checksum(cc_number) == true && (cc_number / 1000000000000 == 4 || cc_number / 1000000000000000 == 4) && (return_length(cc_number) == 13 || return_length(cc_number) == 16))
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}