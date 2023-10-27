#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
template <typename T>

class Array
{
private:
    int _n;
    T *t;

public:
    Array() : _n(0) ,t(new T[0])
    {

    }

    Array(unsigned int n): _n(n),t(new T[n])
    {
        try
        {
            if((int) n < 0)
                throw std :: out_of_range("Out Of Range");

        }
        catch(const std::exception e)
        {
            std :: cout << e.what() << std :: endl;
        }
    }

    Array(Array &copy) : _n(0) ,t(NULL)
    {
        *this = copy;
    }

    Array& operator=(Array &copy)
    {
        this->_n = copy._n;
        if(this->t)
        {
            delete [] t;
        }
        if(copy._n > 0)
        {
            this->t = new T[copy._n];
            for (int i = 0; i < copy._n; i++)
                this->t[i] = copy.t[i];
        }
        return *this;
    }
    
    ~Array()
    {
        if(this->t)
            delete [] this->t;
    }

    void size() const
    {
        return(this->_n);
    }

    T& operator[](int i)
    {
        try
        {
            if(i > this->_n || i < 0)
                throw std :: out_of_range("Out Of Range");
            else
            {
                return this->t[i];
            }
        }
        catch(std :: exception e)
        {
            std :: cout << e.what() << std :: endl;
            return(*this->t);
        }
    }
};
#endif