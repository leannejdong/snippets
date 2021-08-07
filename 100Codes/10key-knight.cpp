#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#define DEPTH 9
#define VOWELS 2
#define NO_OUTPUT 1

using namespace std;

string A = "AHL";
string B = "BIKM";
string C = "CFJLN";
string D = "DGMO";
string E = "EHN";
string F = "FCM";
string G = "GDN2";
string H = "HAEKO13";
string I = "IBL2";
string J = "JCM3";
string K = "KBH2";
string L = "LACI3";
string M = "MBDFJ";
string N = "NCEG1";
string O = "ODH2";
string P = "1FHN";
string Q = "2GIKO";
string R = "3HL";

int moveCounter;
long int combinationsCounter;
int vowelCounter;

string path;
vector <string> keys;

unsigned int getIndex (char in)
{
    char c;
    c = in;
    
    switch (c )
    {
        case '1' : c = 'P'; break;
        case '2' : c = 'Q'; break;
        case '3' : c = 'R'; break;
        default: break;
    } 
    return (c - 'A');
}

void moveTen (string key, char option, char startChar)
{
    unsigned char c; 
    unsigned int index;

    if ( DEPTH <= moveCounter )
    {
        char cc;
        int vowelCnt; 
        if ( DEPTH  < path.size() )  
            path.erase(path.begin());

        vowelCnt = 0; 
        cc = startChar;
        if ( 'A' == cc || 'E' == cc || 'I' == cc || 'O' == cc )
        vowelCnt++; 

        for (size_t i = 0; i < path.size(); i++)
        {
            cc = path.at(i); 
            if ( 'A' == cc || 'E' == cc || 'I' == cc || 'O' == cc )
                vowelCnt++; 
        }
     
        if ( VOWELS > vowelCnt ) 
        {
            if ( NO_OUTPUT != option)
                cout << startChar + path<<endl;
            combinationsCounter++;
        }
    return;
    }
 
    else 
    {
        for ( size_t i = 1; i < key.length(); i++ )
        {
            c = key.at (i);
            path += c;      
            index = getIndex (c);
            moveCounter++;
            moveTen (keys.at(index),option,startChar);
            moveCounter--;
            path.erase(path.end()-1);
        }
        return;
    }
}

int getKey (char char_in)
{
    if ( ('A' <= char_in && 'O' >= char_in ) || ('1' <= char_in && '3' >= char_in) ) 
    {
        return (getIndex (char_in));
    }

    else
    {
        return -1;
    }
}

int main()
{
    keys.push_back (A);
    keys.push_back (B);
    keys.push_back (C);
    keys.push_back (D);
    keys.push_back (E);
    keys.push_back (F);
    keys.push_back (G);
    keys.push_back (H);
    keys.push_back (I);
    keys.push_back (J);
    keys.push_back (K);
    keys.push_back (L);
    keys.push_back (M);
    keys.push_back (N);
    keys.push_back (O);
    keys.push_back (P);
    keys.push_back (Q);
    keys.push_back (R);
 
    combinationsCounter = 0;
    moveCounter = 0;
 
    char ch;
    int startKey;
    char startChar;
    string str;

    path = "";
    startChar = 'A';

    printf ("\nPress key in range A-O or 1-3\n");

    ch = getchar();
    startKey = getKey  (ch); 
    if ( -1 == startKey )
    {   
        cout << "Number of KnightMove combinations = " << combinationsCounter << "\n";
      // std::this_thread::sleep_for(10s);

        return 0;
    }

    //printf ("\nKey Number  = %d", startKey );
    str = keys.at(startKey);    
    startChar = str.at(0);    
    moveTen(keys.at(startKey),NO_OUTPUT,startChar);
    cout << "Number of KnightMove combinations = " << combinationsCounter << "\n";
    printf ("\nPress \"Space bar\" to continue\n");
    do
    {
        ch = getchar();
    } while ( (ch != 0x20) );

    moveTen(keys.at(startKey),~NO_OUTPUT,startChar);

    printf ("\nPress \"Y\" to exit\n");
    do
    {
        ch = getchar();
    } while ( (ch != 'Y') );

    return 0;
}
