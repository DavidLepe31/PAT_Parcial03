#include "Ejercicio02.h"
#include<map>
#include<string>
vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    Node<char>* tmp = head;
    Node<char>* count = head;
    string sequence = "";
    vector<string>* adn = new vector<string>();
    vector<string>tmpadn;
    std::map<string, int>tmp2;
    while (count)
    {
        if (sequence.size() < 10 && tmp)
        {
            sequence += tmp->value;
            tmp = tmp->next;
        }
        else if (sequence.size() >= 10)
        {
            tmpadn.push_back(sequence);
            sequence.erase(sequence.begin());
            count = count->next;
        }
        else {
            break;
        }

    }
    int i = 0;
    while (i < tmpadn.size())
    {
        tmp2[tmpadn[i]]++;
        i++;
    }
    for (auto it : tmp2)
    {
        if (it.second > 1)
        {
            adn->push_back(it.first);
        }

    }
    return adn;
}
