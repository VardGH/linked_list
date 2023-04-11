#pragma once

template <typename T>
class linked_list
{
public:
    linked_list();

    // copy semantics
    linked_list(const linked_list<T>& other);
    linked_list<T>& operator=(const linked_list<T>& other);

    //move semantics
    linked_list(linked_list<T>&& other);
    linked_list<T>& operator=(linked_list<T>&& other);

    // dtor
    ~linked_list();

public:
    void clear();

    void print() const;

    void insert(const size_t pos, const T& value);
    void remove_at(const size_t pos);

    void push_front(const T& value);
    void push_back(const T& value);

    void pop_front();
    void pop_back();

    bool is_empty() const;
    size_t get_size() const;

    T& front() const;
    T& back() const;

private:
    struct Node
    {
        Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr)
            : m_data(data)
            , m_next(next)
            , m_prev(prev)
         {
         }

        T m_data;
        Node* m_next;
        Node* m_prev;
    };

private:
    Node* m_head;
    Node* m_tail;
    size_t m_size;
};

#include "list_impl.hpp"

