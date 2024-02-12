#include "bitset.hpp"
#include <iostream>
#include <cstdlib>

Bitset::Bitset()
{
    bitset = new uint8_t[8];
    N = 8;

    for (int i = 0; i < 8; i++) 
    {
        bitset[i] = 0;
            std::cout << bitset[i]<<std::endl;
    }

}

Bitset::Bitset(intmax_t size)
{
    N= size;
    if (size <= 0)
    {
        valid = "invalid";
    }
    else if (size > 0)
    {
        bitset = new uint8_t[size];

        for (int i = 0; i < size; i++)
        {
            bitset[i] = 0;
        }
    }
//std::cout << "check 2";
}

Bitset::Bitset(const std::string &value)
{
    bitset = new uint8_t[value.length()];
    N = value.length();

    for (int i = 0; i < value.length(); i++)
    {

        if (value[i] == '0')
        {
            bitset[i] = 0;
        }
        if (value[i] == '1')
        {
            bitset[i] = 1;
        }
        if (value[i] != '1' && value[i] != '0')
        {
            //std::cout << "Cant have a value not 0 or 1";
            valid = "invalid";
        }
    }
    // std::cout<<"check 3";
    // for(int i=0;i<value.length();i++){
    // std::cout<<std::endl<<static_cast<int>(bitset[i])<<std::endl;
    // }
}

Bitset::~Bitset()
{
    delete[] bitset;
}

intmax_t Bitset::size() const
{
    return N;
}
// TODO COMMENT
bool Bitset::good() const
{
        bool temp = 0;
    /*
    bool temp = 0;

    for (int i = 0; i < size(); i++)
    {
        if (bitset[i] != 1 && bitset[i] != 0)
        {
            temp = 1;
        }
    }
    */
   if(valid == "invalid"){
    temp = 0;
   }
    else if(valid == "valid"){
    temp = 1;
   }

return temp;
}

// TODO COMMENT
void Bitset::set(intmax_t index)
{

    if (index > size()-1)
    {
      //  std::cout << "invalid because index is greaeter than size" << std::endl;
        valid = "invalid";
    }
    else if (index <= size()-1)
    {
        bitset[index] = 1;
    }
}

// TODO COMMENT
void Bitset::reset(intmax_t index)
{
    if (index > size()-1)
    {
       // std::cout << "invalid because index is greaeter than size" << std::endl;
        valid = "invalid";
    }
    else if (index <= size()-1)
    {
        bitset[index] = 0;
    }
}

// TODO COMMENT
void Bitset::toggle(intmax_t index)
{

    if (index > size()-1)
    {
       // std::cout << "invalid because index is greaeter than size" << std::endl;
        valid = "invalid";
    }
    if (index <= size()-1)
    {
        if (bitset[index] == 1)
        {
            bitset[index] = 0;
        }
        else if (bitset[index] == 0)
        {
            bitset[index] = 1;
        }
    }
}

// TODO COMMENT
bool Bitset::test(intmax_t index)
{
    bool temp = 0;

    if (index > size()-1)
    {
        //std::cout << "invalid because index is greaeter than size" << std::endl;
        valid = "invalid";
        temp = 0;
    }

    if (index <= size()-1)
    {
        if (bitset[index] == 1)
        {
            temp = 1;
        }
    }

    return temp;
}

// TODO COMMENT
std::string Bitset::asString() const
{
    std::string temp = "";

    for (int i = 0; i < size(); i++)
    {

        if (bitset[i] == 0)
        {
            temp+='0';
        }
        if (bitset[i] == 1)
        {
            temp+='1';
        }
        //std::cout<<std::endl<<static_cast<int>(bitset[i])<<std::endl;
    }

    return temp;
}
