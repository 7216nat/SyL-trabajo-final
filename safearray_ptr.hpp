#include <iostream>
#include <memory>
#include <cstdlib>
#include <cassert>
using namespace std;

template <class T>
class safearray_ptr
{
private:
    int low, high;
    unique_ptr<T[]> p;

public:
    // default constructor
    safearray_ptr()
    {
        low = 0;
        high = -1;
        p = NULL;
    }

    // 1 parameter constructor
    safearray_ptr(initializer_list<T> l)
    {
        low = 0;
        high = (int)l.size() - 1;
        p = unique_ptr<T[]>(new T[(int)l.size()]);
        int i = 0;
        for (auto e : l)
        {
            p[i++] = e;
        }
    }

    // 1 parameter constructor
    // SA x(10); array x con indices 0 a 9

    safearray_ptr(int i)
    {
        low = 0;
        high = i - 1;
        p = unique_ptr<T[]>(new T[(int)i]);
    }

    // constructor copia de otro array pasado por referencia

    safearray_ptr(const safearray_ptr &s)
    {
        int size = s.high - s.low + 1;
        p = unique_ptr<T[]>(new T[(int)size]);
        for (int i = 0; i < size; i++)
            p[i] = s.p[i];
        low = s.low;
        high = s.high;
    }

    unique_ptr<T[]> get_p(){
        return p;
    }
    
    // destructor
    ~safearray_ptr(){
        p.reset();
    }
    // sobrecargar []

    int &operator[](int i)
    {
        if (i < low || i > high)
        {
            cout << "acceso a indice " << i << " fuera del rango" << endl;
            exit(1);
        }
        return p[i - low];
    }

    // sobrecargar =

    safearray_ptr &operator=(const safearray_ptr &s){
        if(this==&s)return *this;
        p.reset();
        int size=s.high-s.low+1;
        p = move(s.p);
        low=s.low;
        high=s.high;
        return *this;
    }

    // overloads << so we can directly print SAs
    template <class U>
    friend ostream &operator<<(ostream &os, SA<U> s);
};

template <class T>
ostream &operator<<(ostream &os, safearray_ptr<T> s)
{
    int size = s.high - s.low + 1;
    for (int i = 0; i < size; i++)
        cout << s.p[i] << endl;
    return os;
};