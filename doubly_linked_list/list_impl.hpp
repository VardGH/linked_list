template <typename T>
linked_list<T>::linked_list()
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_size(0)
{
}

template <typename T>
void linked_list<T>::push_front(const T& value)
{
    Node* tmp = new Node(value, m_head, nullptr);

    if (m_head != nullptr) {
        m_head->m_prev = tmp;
    }
    else {
        m_tail = tmp;
    }

    m_head = tmp;
    ++m_size;
}


template <typename T>
void linked_list<T>::push_back(const T& value)
{
    Node* tmp = new Node(value, nullptr, m_tail);

    if (m_tail != nullptr) {
        m_tail->m_next = tmp;
    }
    else {
        m_head = tmp;
    }

    m_tail = tmp;
    ++m_size;
}

template <typename T>
bool linked_list<T>::is_empty() const
{
    return m_size == 0;
}

template <typename T>
size_t linked_list<T>::get_size() const
{
    return m_size;
}

template <typename T>
T& linked_list<T>::back() const
{
    return m_tail->m_data;
}

template <typename T>
T& linked_list<T>::front() const
{
    return m_head->m_data;
}

template <typename T>
void linked_list<T>::pop_front()
{
    if (is_empty) {
        return;
    }

    Node* old_head = m_head;
    m_head = m_head->m_next;

    if (m_head != nullptr) {
        old_head->m_prev = nullptr;
    }
    else {
        m_tail = nullptr;
    }

    delete old_head;
    --m_size;
}

template <typename T>
void linked_list<T>::pop_back()
{
    if (is_empty) {
        return;
    }

    Node* old_tail = m_tail;
    m_tail = m_tail->m_prev;

    if (m_tail != nullptr) {
        old_tail->m_next = nullptr;
    }
    else {
        m_head = nullptr;
    }

    delete old_tail;
    --m_size;
}


//copy ctor
template <typename T>
linked_list<T>::linked_list(const linked_list<T>& other)
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_size(0)
{
    Node* cur = other.m_head;
    while (cur != nullptr) {
        push_back(cur->m_data);
        cur = cur->m_next;
    }
}

// copy assignment operator
template <typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& other)
{
    if (this != &other) {
        clear();
        Node* cur = other.m_head;
        while (cur != nullptr) {
            push_back(cur->m_data);
            cur = cur->m_next;
        }
    }

    return *this;
}

// move ctor
template <typename T>
linked_list<T>::linked_list(linked_list<T>&& other)
    : m_head(other.m_head)
    , m_tail(other.m_tail)
    , m_size(other.m_size)
{
    other.m_head = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}


// move assignment operator
template <typename T>
linked_list<T>& linked_list<T>::operator=(linked_list<T>&& other)
{
    if (this != & other) {
        std::swap(m_head, other.m_head);
        std::swap(m_tail, other.m_tail);
        std::swap(m_size, other.m_size);
    }
    return *this;
}

template <typename T>
void linked_list<T>::clear()
{
    Node* cur = m_head;

    while (cur != nullptr) {
        Node* tmp = cur->m_next;
        delete cur;
        cur = tmp;
    }

    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

//dtor
template <typename T>
linked_list<T>::~linked_list()
{
    clear();
}

template <typename T>
void linked_list<T>::print() const
{
    if (m_size == 0) {
        std::cout << "List is empty\n";
        return;
    }

    Node* cur = m_head;
    while(cur != nullptr) {
        std::cout << cur->m_data << " ";
        cur = cur->m_next;
    }
    std::cout << std::endl;
}

template <typename T>
void linked_list<T>::insert(const size_t pos, const T& value)
{
    if (pos < 0 || pos > m_size) {
        std::cout << "Wrong position\n";
        return;
    }

    if (pos == 0) {
        push_front(value);
        return;
    }

    if (pos == m_size){
        push_back(value);
        return;
    }

    Node* cur = m_head;
    for (int i = 0; i < pos - 1; ++i) {
        cur = cur->m_next;
    }

    Node* new_node = new Node(value, cur->m_next, cur);
    cur->m_next->m_prev = new_node;
    cur->m_next = new_node;
    ++m_size;
}

template <typename T>
void linked_list<T>::remove_at(const size_t pos)
{
    if (pos < 0 || pos >= m_size) {
        return;
    }

    Node* cur = m_head;
    for (int i = 0; i < pos; i++) {
        cur = cur->m_next;
    }

    if (cur == m_head) {
        m_head = cur->m_next;
    }
    else if (cur == m_tail) {
        m_tail = cur->m_prev;
    }
    else if (cur->m_prev != nullptr && cur->m_next != nullptr) {
        cur->m_prev->m_next = cur->m_next;
        cur->m_next->m_prev = cur->m_prev;
    }

    delete cur;
    --m_size;
}
