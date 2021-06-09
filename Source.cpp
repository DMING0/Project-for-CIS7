#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

//Function to make the key the same length as the plaintext
string key_length(string plaintext, string key_01)
{
    if (key_01.size() < plaintext.size())
        //checks if the key lenght is smaller than the plaintext lenght
        //makes the key the same lenght as the plaintext if the key was smaller
    {
        int ptdiff = plaintext.size() - key_01.size();//the size difference between the key and the plaintext
        int key_size = key_01.size();//size of the key
        for ( ptdiff; ptdiff >= key_size; ptdiff -= key_size)//makes sure the key is the sane size or longer than the pt or ct 
        {
            key_01 += key_01;
        }//end of for loop
        key_01 += key_01.substr(0, ptdiff);//makes sure the key is the exact same lenght as the plaintext
        return key_01;
    }//end of if statement
    else if (key_01.size() >= plaintext.size())
    {
        return key_01;
    }//end of else if statement
}//end of key_length



//The encryption function
string encryption(string plaintext, string key_01)
{
    string cyphertext = "";
    for (int i = 0; i < plaintext.size(); i++)
    {
        cyphertext += (char)((plaintext[i] + key_01[i]) % 26) + 'A';//uses vingerene cypher to turn the value into an ASCII value the + 'A' at the end helps with a problem I had
        //the char turns the values into an ASCII value 
    }//end of for loop
    return cyphertext;
}//end of encryption



string decryption(string ciphertext, string key_01)
{
    string plaintext = "";
    for (int i = 0; i < ciphertext.size(); i++)
    {
        
        plaintext += (char)((ciphertext[i] - key_01[i] + 26) % 26) + 'A';
        
    }//end of for loop
    return plaintext;
}//end of decryption


int main()
{
    string ct;//this is where I declare the variables that I will need
    string pt;
    string k;
    string e_or_d;
    int i = 0;
    while (e_or_d != "Exit")//I'm implementing a while loop that will run until user types Exit
    {
        cout << "\n Would you like to Encrypt or Decrypt a message?(Type E for encrypt, D for decrypt, or type Exit to exit the program): ";
        cin >> e_or_d;
        if (e_or_d == "E")// for encryption
        {
            i = 0;
            //here is where the code asks for the values that are needed.
            cout << "\n What message would you like Encrypted? ";
            cin >> pt;
            cout << "\n What would you like the Keyword to be? ";
            cin >> k;
            cout << "\nPlaintext: " << pt;

            while (i < pt.size())//this while loop should solve my problem with lower case inputs for the pt I will implement a similar one for the key and ct
            {
                if (isupper(pt[i]) == false)
                {
                    pt[i] = toupper(pt[i]);
                    i += 1;
                }//if statements checks if the values is lowercase and turns it into an uppercase 
                else
                {
                    i += 1;
                }// of else statement
            }//end of while loop. This was the first while loop I made to make sure the letters were uppercased the other loops are a litte different

            k = key_length(pt, k);
            i = 0;
            while (i < k.size())
            {
                if (isupper(k[i]) == false)
                {
                    k[i] = toupper(k[i]);//makes sure the key is uppercase so that the program runs correctly
                }//end of If statement
                i++;
            }//end of while loop

            ct = encryption(pt, k);
            cout << "\nKeyword: " << k;
            cout << "\nCiphertext: " << ct;
        }//end of encrytion

        else if (e_or_d == "D")//for decryption
        {
            i = 0;
            cout << "\n What message would you like Decrypted? ";
            cin >> ct;
            cout << "\n What would you like the Keyword to be? ";
            cin >> k;
            cout << "\nCiphertext: " << ct;

            while (i < ct.size())
            {
                if (isupper(ct[i]) == false)// makes sure the ciphertext is uppercase
                {
                    ct[i] = toupper(ct[i]);
                }//end of if statement
                i++;
            }//end of while loop

            i = 0;
            k = key_length(ct, k);
            while (i < k.size())
            {
                if (isupper(k[i]) == false)//makes sure the Key is uppercased otherwise the code won't encrypt correctly
                {
                    k[i] = toupper(k[i]);
                }//end of if statement
                i++;
            }//end of while loop

            pt = decryption(ct, k);
            cout << "\nKeyword: " << k;
            cout << "\nPlaintext: " << pt;
        }//end of decryption

        else if (e_or_d == "Exit")
        {
            return 0;
        }//in case the user wants to exit the very first time the loop is used
    }//end of while loop
    return 0;
}// end of main

