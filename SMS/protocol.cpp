#include "protocol.h"
#include <vector>
#include <iostream>
using namespace std;


protocol::protocol()
{
}


protocol::~protocol()
{
}

void protocol::readToVector(char* x, int size)
{

    if (x[0] != '!') // hvis dette er sandt skal der ikke ske noget da det ikke er et tegn vi arbejder med.
    {
        // meld fejl tilbage til bruger
    }
    else if (x[0] == '!')
    {
        for (auto i = 0; i < size; i++)     // her læser vi det char array vi får ind i en vector som er nemmere at arbejde med
        {
            SaveVector.push_back(x[i]);

        }//end for loop
    }
}
void protocol::readToVector(vector<char> a) // denne funktion gør det samme som ovenstående, men tager bare en vector i stedet for char array
{

    SaveVector = a;
}

int protocol::antalElementer(int& size) // denne tæller hvor mange forskellige alarmer der ligger i vectoren ved at tælle antallet af N
{
    int antal = 0;

    for (auto i = 0; i <size ; i++)
    {
        if (SaveVector[i] == 'N')
        {
            antal++;
        } // end if

    } // end for

    return antal;
}

void protocol::makeRawTime(int& size)
{

    for (auto i = 0; i < size; i++)
    {
        if (SaveVector[i] == 'H' || SaveVector[i] == 'M')
        {
            for (auto j = i+1; j < i + 3; j++)
            {
                RawtimeVec.push_back(charIntConverter(SaveVector[j]));
            }   // end inner for
        }// end if

    }// end outer for

}

vector<int> protocol::times(int &size)
{
    makeRawTime(size);
    vector<int> useable;
    for (auto i = 0; i < RawtimeVec.size();)
    {

        auto a = RawtimeVec[i] * 10 + RawtimeVec[i + 1];
        useable.push_back(a);
        i = i + 2;
    }
    return  useable;
}

void protocol::pushBack(char a)
{
    SaveVector.push_back(a);
}

char protocol::charIntConverter(int a) // dette er en hardcoded int til char converter
{
    if (a == 1)
    {
        return '1';
    }
    if (a ==2)
    {
        return '2';
    }
    if (a == 3)
    {
        return '3';
    }
    if (a == 4)
    {
        return '4';
    }
    if (a == 5)
    {
        return '5';
    }
    if (a == 6)
    {
        return '6';
    }
    if (a == 7)
    {
        return '7';
    }
    if (a == 8)
    {
        return '8';
    }
    if (a == 9)
    {
        return '9';
    }
    else
    {
        return '0';
    }
}

vector<char> protocol::getSaveVector() // retunere den savevector som er gemt.
{
    return SaveVector;
}


