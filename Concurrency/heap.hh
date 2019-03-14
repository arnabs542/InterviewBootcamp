/*
   Comments
*/

#ifndef MY_HEAP_HH
#define MY_HEAP_HH

template <typename T, class Compare = std::less<T> >
class Heap
{
    public:
        Heap();
        ~Heap();

        bool    empty();
        size_t  size();
        T&      top();
        int     push(const T&);
        void    pop();
        bool    remove(int index);


    private:

        Compare comp;



};

#endif

