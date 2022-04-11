#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input = "";
    string inputrev = "";
    int stringsize = 0;
    int countIt = 0;
    int countIt2 = 0;
    char conv;
    stack <char> s1;
    vector <char> s2;


    //this code is for single-use execution
        cout << "\nEnter your string here to run through the REGEX (a|b)*abb: ";
        cin >> input;

        inputrev = input;

        /*we need this in order to place the last 3 characters in the bottom of the thread*/
        reverse(input.begin(), input.end());

        stringsize = input.size();

        /*If statement that will terminate if string is less
          than 3, no point in processing if any string less than 3
          cannot be accepted in a FA*/

        if (input.size() < 3)
        {
            cout << "Not accepted, string count is less than 3." << endl;
            return -1;
        }

        /*Vector install*/
        for (int i = 0; i < input.size(); i++)
        {
            conv = input[i];
            //s1.push(conv);
            s2.push_back(conv);
            //countIt++; //stack needs a counter, do not rely on stack size for whatever reason
        }

        /*Vector push to stack.*/
        for (int j = 0; j < stringsize; j++)
        {
            s1.push(s2[j]);
            s2.push_back(conv);
            countIt++; //stack needs a counter, do not rely on stack size for whatever reason
        }

        countIt2 = stringsize;


        /*THIS IS THE FIRST STATE, Q0, WHERE WE READ IN X A'S AND X B'S, WE DO NOT CARE UNTIL WE REACH A LOWER COUNT*/
        while (countIt2 > 3)
        {
            //THIS WAS USED TO CHECK PROPER STACK POPS
           // cout << "COUNT [" << countIt2 << "]" << s1.top() << endl;
            s1.pop();
            countIt2 = countIt2 - 1;
        }


        /*ONCE WE DEAL WITH (A|B)*, WE MOVE TO Q1 TO PROCESS ABB*/
        for (int i = 0; i < 3; i++)
        {

            if (i == 0 && s1.top() == 'a') //Q1
                s1.pop();
            else if (i > 0 && s1.top() == 'b') //Q2 THEN Q3
                s1.pop();

            else
                //DO NOT ACCEPT, STRING PATTERN IS NOT ABB
            {
                cout << "STRING " << inputrev << " is not accepted!" << endl;
                return -1;
            }
        }



        /*IF WE HAVE AN EMPTY STACK, THAT MEANS THE FOR LOOP ABOVE POPPED OFF THE MANDATORY PARTIAL STRING ABB, WHICH MEANS THAT
        THE STRING WILL BE ACCEPTED.*/
        if (s1.empty() == true)
            cout << "THIS STRING " << inputrev << " IS ACCEPTED.......";
    

    return 0;
}