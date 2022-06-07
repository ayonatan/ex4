#ifndef MTM_HW4_QUEUE_H
#define MTM_HW4_QUEUE_H

const int EXPAND_RATE = 2;
const int INITIAL_SIZE = 10;
const double MINIMIZE_RATE = 0.75;

template<class T>
class Queue
{
public:
    Queue();

    Queue(const Queue<T> &queue);

    Queue<T> &operator=(const Queue<T> &queue);

    ~Queue();

    //add T item to back of the queue
    void pushBack(const T &item);

    //amount of T items in the queue
    int size() const;

    //return T reference of the first item in queue
    T &front() const;

    //free first T item in the Queue
    void popFront();

    class EmptyQueue {};

    class ConstIterator;

    ConstIterator begin() const;

    ConstIterator end() const;

    class Iterator;

    Iterator begin();

    Iterator end();

private:
    T *m_data;
    int m_lastItemIndex;
    int m_maxSize;

    //expand the queue when there's no space left
    void expand();

    //moves all T items one place left
    void moveOneLeft();

    //free 25% of the space allocated when only half is used
    void minimize();

};

template<class T>
class Queue<T>::ConstIterator
{
public:
    ConstIterator(const ConstIterator &it) = default;

    ConstIterator &operator=(const ConstIterator &) = default;

    ~ConstIterator() = default;

    const T &operator*();

    // prefix: ++it
    ConstIterator &operator++();

    // postfix: it++
    ConstIterator operator++(int);

    bool operator!=(const ConstIterator it) const;

    class InvalidOperation {};

private:
    const Queue<T> *m_queue;
    int m_index;

    ConstIterator(const Queue<T> *queue, int index);

    friend class Queue<T>;
};

template<class T>
class Queue<T>::Iterator
{
public:
    Iterator(const Iterator &) = default;

    Iterator &operator=(const Iterator &) = default;

    ~Iterator() = default;

    T &operator*();

    // prefix: ++it
    Iterator &operator++();

    // postfix: it++
    Iterator operator++(int);

    bool operator!=(const Iterator it) const;

    class InvalidOperation {
    };

private:
    Queue<T> *m_queue;
    int m_index;

    Iterator(Queue<T> *queue, int index);

    friend class Queue<T>;

};

#endif //EX3_QUEUE_H

// declaration of filter and transform - outside class funcs
template<typename T, typename FilterFunc>
Queue<T> filter(Queue<T> &queue, FilterFunc filterFunc);

template<typename T, typename Transform>
void transform(Queue<T> &queue, Transform transformOperator);


/******** implementing Queue funcs ********/
template<typename T>
Queue<T>::Queue() {
//Queue::Queue() {
    m_data = new T[INITIAL_SIZE];
    m_maxSize = INITIAL_SIZE;
    m_lastItemIndex = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &queue) {
    m_data = new T[queue.m_maxSize];
    m_maxSize = queue.m_maxSize;
    m_lastItemIndex = queue.m_lastItemIndex;
    try {
        for (int i = 0; i < m_lastItemIndex; ++i) {
            m_data[i] = queue.m_data[i];
        }
    }
    catch (...) {
        delete[] m_data;
        throw;
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &queue) {
    if (this == &queue) {
        return *this;
    }
    T *tempData = new T[queue.m_maxSize];
    try {
        m_maxSize = queue.m_maxSize;
        m_lastItemIndex = queue.m_lastItemIndex;
        for (int i = 0; i < m_lastItemIndex; ++i) {
            tempData[i] = queue.m_data[i];
        }
    } catch (...) {
        delete[] tempData;
        throw;
    }
    delete[] m_data;
    m_data = tempData;
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] m_data;
}

template<typename T>
void Queue<T>::pushBack(const T &item) {
    T tempObj = item;
    if (m_lastItemIndex >= m_maxSize) {
        expand();
    }
    m_data[m_lastItemIndex] = tempObj;
    m_lastItemIndex++;
}

template<typename T>
void Queue<T>::expand() {
    int newSize = m_maxSize * EXPAND_RATE;
    T *tempData = new T[newSize];
    try {
        for (int i = 0; i < m_maxSize; ++i) {
            tempData[i] = m_data[i];
        }
    }
    catch (...) {
        delete[] tempData;
        throw;
    }
    delete[] m_data;
    m_data = tempData;
    m_maxSize = newSize;
}

template<typename T>
int Queue<T>::size() const {
    //return m_lastItemIndex;
    return m_lastItemIndex;
}

template<typename T>
T &Queue<T>::front() const {
    if (m_lastItemIndex == 0) {
        throw Queue<T>::EmptyQueue();
    }
    return m_data[0];
}

template<typename T>
void Queue<T>::popFront() {
    if (m_lastItemIndex == 0) {
        throw EmptyQueue();
    }
    moveOneLeft();
    if (m_lastItemIndex - 1 <= 0.5 * m_maxSize) {
        minimize();
    }
}

template<typename T>
void Queue<T>::moveOneLeft() {
    for (int i = 0; i < m_lastItemIndex - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    m_lastItemIndex--;
}

template<typename T>
void Queue<T>::minimize() {
    int newSize = m_maxSize * MINIMIZE_RATE;
    T *tempData = new T[newSize];
    try {
        for (int i = 0; i < m_lastItemIndex; ++i) {
            tempData[i] = m_data[i];
        }
    }
    catch (...) {
        delete[] tempData;
        throw;
    }
    delete[] m_data;
    m_data = tempData;
    m_maxSize = newSize;
}

template<typename T, typename FilterFunc>
Queue<T> filter(Queue<T> &queue, FilterFunc filterFunc) {
    // what if given queue smaller
    Queue<T> newQueue;
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it) {
        if (filterFunc(*it)) {
            newQueue.pushBack(*it);
        }
    }
    return newQueue;
}

template<typename T, typename Transform>
void transform(Queue<T> &queue, Transform transformOperator) {
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it) {
        transformOperator(*it);
    }
}
/******** end Queue ********/


/******** implementing Iterator funcs ********/
template<typename T>
Queue<T>::Iterator::Iterator(Queue<T> *queue, int index) :
        m_queue(queue), m_index(index) {}

template<typename T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator(this, 0);
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(this, m_lastItemIndex);
}

template<typename T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++() {
    ++m_index;
    if (m_index > m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return *this;
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) { //it++
    Queue<T>::Iterator result = *this;
    ++m_index;
    if (m_index > m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return result;
}

template<typename T>
T &Queue<T>::Iterator::operator*() {
    if (m_index >= m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator it) const {
    if (m_queue != it.m_queue) {
        throw InvalidOperation();
    }
    return m_index != it.m_index;
}
/******** end Iterator ********/


/******** implementing ConstIterator funcs ********/
template<typename T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T> *queue, int index) :
        m_queue(queue), m_index(index) {}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    return ConstIterator(this, 0);
}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    return ConstIterator(this, m_lastItemIndex);
}

template<typename T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++() {
    ++m_index;
    if (m_index > m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return *this;
}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int) {
    Queue<T>::ConstIterator result = *this;
    ++m_index;
    if (m_index > m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return result;
}


template<typename T>
const T &Queue<T>::ConstIterator::operator*() {
    if (m_index >= m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}

template<typename T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator it) const {
    if (m_queue != it.m_queue) {
        throw InvalidOperation();
    }
    return m_index != it.m_index;
}
/******** end ConstIterator ********/






