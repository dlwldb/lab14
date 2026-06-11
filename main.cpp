#include<iostream>

int* doubler(int*a, int size)
{
    //std::cout << "in func: " << sizeof(a) << std::endl; //8
    int* b{ new int[size] };
    for (int i = 0; i<size; ++i)
      b[i] = 2 * a[i];
    return b;
}
void printArray(const int a[], int size)
{
    for (int i =0; i<size; ++i)
      std::cout << a[i] << " ";
    std::cout << std::endl;
}
int main()
{
    int a[]{1,2,3,4,5};  //std::cout << "in main: " << sizeof(a) << std::endl;//20
    int* b{doubler(a,5)};
    printArray(a,5);
    printArray(b,5);
    delete[] b;
    return 0;
}

다차원 동적배열
using intArrayPtr = int*;
int main()
{
    int d1{},d2{};
    std::cout << "Enter the row and column dimensions of the array: ";
    std::cin >> d1 >> d2;
    intArrayPtr *m{new intArrayPtr[d1]}; //m[0], m[1], ...m[d1-1]
    for(int i=0; i<d1; ++i)
       m[i] = new int[d2];
    std::cout << "Enter " << d1 << "rows of " << d2 << "integers: \n";
    for (int i=0; i<d1; ++i)
       for(int j=0; j<d2; ++j)
          std::cin >> m[i][j];
    for (int i=0; i<d1; ++i)
    {
        for(int j =0; j<d2; ++j)
          std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i=0; i<d1; ++i)
       delete[] m[i];
    delete[] m;
}

문자열을 포함한 구조체를 하나 선언하고 구조체 동적 배열 테스트
struct CDAccount
{
    char name[21]{};
    double deposit{};
    double interstRate{};
    int month{};
    double balance{};
};
void setAccount(CDAccount& theAccount)
{
    std::cout << "Enter account name (max 20 charcters): ";
    std::cin >> theAccount.name;
    std::cout << "Enter deposit (won): ";
    std::cin >> theAccount.deposit;
    std::cout << "Enter interest rate: ";
    std::cin >> theAccount.interstRate;
    std::cout << "Enter month: ";
    std::cin >> theAccount.month;
    theAccount.balance = theAccount.deposit * (1+theAccount.interstRate/100 * theAccount.month/12);
}
void printAccont(CDAccount& theAccount)
{
   std::cout << "Account name: " << theAccount.name << std::endl 
   << "deposit: " << theAccount.deposit << std::endl 
   << "interest rate: " << theAccount.interstRate << "%\n"
   << "month: " << theAccount.month <<std::endl
   << "balance: " << theAccount.balance << "won\n";
}
int main()
{
   CDAccount account;
   CDAccount* accountPtr{new CDAccount};
   setAccount(*accountPtr);
   printAccont(*accountPtr);
   delete accountPtr;
}