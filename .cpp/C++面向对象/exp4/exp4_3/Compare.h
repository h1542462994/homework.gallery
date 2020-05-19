#pragma once

template<typename TNum>
class Compare 
{
public:
    Compare(TNum a, TNum b);
    TNum max();
    TNum min();
private:
    TNum x, y;
};