#include <iostream>
#include <unistd.h>

using namespace std;

class Singleton {
public:
    static Singleton* Instance()
    {
        static Singleton instance;
            return &instance;
    }
private:
    Singleton() {cout << "Construct singleton\n";};
    ~Singleton() {};
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};

int main()
{
    Singleton *single1;
    Singleton *single2;

    single1 = single1->Instance();
    cout << "Single1 ptr = " << single1 << "\n";

    single2 = single2->Instance();
    cout << "Single2 ptr = " << single2 << "\n";

    return 0;
}
