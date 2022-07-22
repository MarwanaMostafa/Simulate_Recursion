#include <stack>
#include <iostream>
using namespace std;
struct operation
{
    int n;
    int a;
    int b;
    int c;
    int d;

    int ValueOf = 0; // means if  F() has value return Which A ,B or D ,A=>0, B=>1, D=>2
    int state;       // where we are now in a ,b or d
};
int F(int n)
{
    if (n <= 1)
        return 1;

    int returunResult = 0;

    operation currentoperation;
    currentoperation.n = n;
    currentoperation.a = n; // mean from equation a=n+F(n-1),hence we add first value to a and it's n then we add value of F(n-1)
    currentoperation.b = 0; // why 0 because in this time we don't know values so we put 0 until caluclate these
    currentoperation.c = 0; // why 0 because in this time we don't know values so we put 0 until caluclate these
    currentoperation.d = 0; // why 0 because in this time we don't know values so we put 0 until caluclate these
    currentoperation.state = 0; // now we exaxcute  a

    stack<operation> stackoperation;

    stackoperation.push(currentoperation);

    while (!stackoperation.empty())
    {
        operation topStack = stackoperation.top();
        stackoperation.pop();

        switch (topStack.state)
        {
        case 0: // we remain call all recursive function  for equation A
            // example if N=4:  we call :
            /*
                F4: A=4+F(4-1)   * done above *
                F3: A=3+F(3-1)
                F2: A=2+F(2-1)
                F1: A=1
            all these calls occur in case 0
            */
            if (topStack.n > 1)
            {

                topStack.state = 1; //  go to calculate B for n and n-1 .....
                stackoperation.push(topStack);
                operation newOperation;
                newOperation.n = topStack.n - 1;
                newOperation.a = newOperation.n;
                newOperation.b = 0;
                newOperation.d = 0;
                newOperation.ValueOf = 0; // means if  F(n-1) has value return this value to Equation A
                newOperation.state = 0;
                stackoperation.push(newOperation);
                continue;
            }
            else
            {

                if (topStack.ValueOf == 0) // mean we now in F(1)so we will return 1 to F(2) so we add 1 to F(2)
                {
                    operation calledTopStack = stackoperation.top();
                    stackoperation.pop();
                    calledTopStack.a++;
                    stackoperation.push(calledTopStack);
                }
                continue;
            }
            break;
        case 1:
            if (topStack.n > 1)
            {
                topStack.state = 2; // go to calculate C,D for n and n-1 .....

                topStack.b = topStack.n; // mean if we at F4 so B must will B =4*F(4/2) so we put firslty 4 to B
                stackoperation.push(topStack);

                // calculate F(n/2)
                operation newOperation;
                newOperation.n = topStack.n / 2;
                newOperation.a = newOperation.n;
                newOperation.b = 0;
                newOperation.d = 0;
                newOperation.ValueOf = 1; // means if  F(n/2) has value return this value to Equation B
                newOperation.state = 0;
                stackoperation.push(newOperation);
                continue;
            }
            // why hence we don't add else (n<1) because return value will don't effect on result becauser we multiply 1
        case 2:
            topStack.c = topStack.n - 2 - (topStack.a + topStack.b) % 2;

            // if value for F(c) is 1 so d will be 1 and go to case 3 and finish for this iterative
            if (topStack.c <= 1)
            {

                topStack.d = 1;
                topStack.state = 3; // finish return result
                stackoperation.push(topStack);
            }
            // Go to calculate F(c)
            else
            {
                topStack.state = 3; // finish return result
                stackoperation.push(topStack);

                operation calculateFC;
                calculateFC.n = topStack.c;
                calculateFC.a = calculateFC.n;
                calculateFC.b = 0;
                calculateFC.d = 0;
                calculateFC.state = 0;   // means go to case 0 and calculate all eqaution from the beginning
                calculateFC.ValueOf = 2; // means if  F(C) has value return this value to Equation D
                stackoperation.push(calculateFC);
            }
            continue;
            break;
        case 3:
            returunResult = topStack.a + topStack.b + topStack.d;

            // now we need know this result is final return or return other recursive so if enter if condition, result will be return for recursive otherowise will be final return
            if (!stackoperation.empty())
            {
                // hence we get last block in stack to take result
                operation hasThisIterative = stackoperation.top();
                stackoperation.pop();
                if (topStack.ValueOf == 0)
                    hasThisIterative.a += returunResult;

                else if (topStack.ValueOf == 1)
                    hasThisIterative.b *= returunResult;

                else if (topStack.ValueOf == 2)
                    hasThisIterative.d = returunResult;

                stackoperation.push(hasThisIterative);
            }
            continue;
            break;
        }
    }
    return returunResult;
}
int main()
 
{
    cout << "when n =1    then   F =   " << F(1) << endl;
    cout << "when n =2    then   F =   " << F(2) << endl;
    cout << "when n =3    then   F =   " << F(3) << endl;
    cout << "when n =4    then   F =   " << F(4) << endl;
    cout << "when n =5    then   F =   " << F(5) << endl;
    cout << "when n =6    then   F =   " << F(6) << endl;
    cout << "when n =7    then   F =   " << F(7) << endl;
    cout << "when n =8    then   F =   " << F(8) << endl;
    cout << "when n =9    then   F =   " << F(9) << endl;
    cout << "when n =10   then   F =  " << F(10) << endl;
    cout << "when n =11   then   F =  " << F(11) << endl;
    cout << "when n =12   then   F =  " << F(12) << endl;
    cout << "when n =13   then   F =  " << F(13) << endl;
    cout << "when n =14   then   F =  " << F(14) << endl;
    cout << "when n =15   then   F =  " << F(15) << endl;
    cout << "when n =16   then   F =  " << F(16) << endl;
    cout << "when n =17   then   F =  " << F(17) << endl;
    cout << "when n =18   then   F =  " << F(18) << endl;
    cout << "when n =19   then   F =  " << F(19) << endl;
    cout << "when n =20   then   F =  " << F(20) << endl;
}
