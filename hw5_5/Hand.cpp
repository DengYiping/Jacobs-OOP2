#include "Hand.h"

using namespace std;
Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()  
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}
 
void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total = 0;
    bool hasAce = false;
    int val = -1;

    for(auto& c: m_Cards){
        //sum over the cards
        val = c->GetValue();
        total += val;

        //if there is a ace
        if(val == 1)
            hasAce = true;
    }

    if(total <= 11 && hasAce)
        total += 10; //count ace as 11

    return total;
}


