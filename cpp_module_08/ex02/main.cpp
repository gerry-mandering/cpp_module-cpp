#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // Testing default test
    std::cout << "<Testing default test>" << std::endl;

    MutantStack< int > mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(6);
    mstack.push(23);
    mstack.push(0);

    MutantStack< int >::iterator it = mstack.begin();
    MutantStack< int >::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack< int > s(mstack);
    (void)s;
    std::cout << std::endl;

    // Testing list test
    std::cout << "<Testing list test>" << std::endl;

    std::list< int > lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();

    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(6);
    lst.push_back(23);
    lst.push_back(0);

    std::list< int >::iterator it2 = lst.begin();
    std::list< int >::iterator ite2 = lst.end();

    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::list< int > s2(lst);
    (void)s2;
    std::cout << std::endl;

    // Testing iterator
    std::cout << "<Testing iterator>" << std::endl;

    MutantStack< int > iterTestStack;
    iterTestStack.push(1);
    iterTestStack.push(2);
    iterTestStack.push(3);
    iterTestStack.push(4);
    iterTestStack.push(5);

    MutantStack< int >::iterator iter = iterTestStack.begin();
    *iter = 42;

    for (; iter != iterTestStack.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << std::endl;

    // Testing reverse_iterator
    std::cout << "<Testing reverse_iterator>" << std::endl;

    MutantStack< int >::reverse_iterator riter = iterTestStack.rbegin();
    for (; riter != iterTestStack.rend(); riter++)
    {
        std::cout << *riter << std::endl;
    }
    std::cout << std::endl;

    // Testing const_iterator
    std::cout << "<Testing const_iterator>" << std::endl;

    const MutantStack< int > constIterTestStack(iterTestStack);

    MutantStack< int >::const_iterator constIter = constIterTestStack.begin();
    //*constIter = 42;

    for (; constIter != constIterTestStack.end(); constIter++)
    {
        std::cout << *constIter << std::endl;
    }
    std::cout << std::endl;

    // Testing const_reverse_iterator
    std::cout << "<Testing const_reverse_iterator>" << std::endl;

    MutantStack< int >::const_reverse_iterator constRiter = constIterTestStack.rbegin();
    for (; constRiter != constIterTestStack.rend(); constRiter++)
    {
        std::cout << *constRiter << std::endl;
    }

    return 0;
}
