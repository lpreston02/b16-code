#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        // Ensure this is space in queue for more elements
        assert(this->_size < this->_storage.size());
        this->_size++;
        // Sets the first element in the queue equal to value
        this->_storage[this->_head()] = value;

    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // Ensure there are elements in the queue
        assert(this->_size >= 1);

        //Sets position to last element in the queue
        this->_position++;

        // Decrease size to get rid of element
        this->_size--;

    }

    // Remove all elements from the queue
    void clear() { 
        // If there are elements in the queue, dequeue them until it is empty
        if (this->_size >= 1){
            this->dequeue();
        }
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // Ensures the queue isn't empty
        assert(this->_size >= 1);

        // Position points to second to last element
        auto index = this->_position + 1;

        if (index >= this->_storage.size()) { index -= this->_storage.size(); }

        // Index returned
        return index;
    }
};

#endif // __queue_enhanced__