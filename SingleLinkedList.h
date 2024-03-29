//
// Created by avmd on 28.02.23.
//

#ifndef UNTITLED1_SINGLELINKEDLIST_H
#define UNTITLED1_SINGLELINKEDLIST_H

template<class T>
class CSingleLinkedList {
private:
    struct leaf {
        T data;
        leaf *pnext;

        leaf() : data(T()), pnext(nullptr) {}

        leaf(const T &_data, leaf *_pnext) : data(_data), pnext(_pnext) {
        }

    };

public:
    class CIterator {
    public:
        /* CIterator()
             : m_pCurrent(0), m_pBegin(0)
         {
         }*/

        explicit operator bool() const {
            if (m_pCurrent != nullptr)
                return true;
            else
                return false;
        }

        CIterator(leaf *p) {
            m_pCurrent = p;
        }

        CIterator(const CIterator &src) {
            m_pBegin = src.m_pBegin;
            m_pCurrent = src.m_pCurrent;
        }

        ~CIterator() {
            m_pCurrent = nullptr;
            m_pBegin = nullptr;
        }

        CIterator &operator=(const CIterator &src) {
            if (this != &src) {
                m_pBegin = src.m_pBegin;
                m_pCurrent = src.m_pCurrent;
            }

            return *this;
        }

        bool operator!=(const CIterator &it) const {
            if (m_pCurrent != it.m_pCurrent)
                return true;
            return false;
        }

        void operator++() {
            if (m_pCurrent->pnext)
                m_pCurrent = m_pCurrent->pnext;
            else m_pCurrent = nullptr;
        }

        T getData() {
            if (m_pCurrent)
                return m_pCurrent->data;
            return T();
        }

        T &operator*() {
            if (m_pCurrent)
                return m_pCurrent->data;
        }

        leaf *getLeaf() {
            if (m_pCurrent)
                return m_pCurrent;
            return 0;
        }

        void setLeaf(leaf *p) {
            m_pCurrent = p;
        }

        void setLeafPreBegin(leaf *p) {
            m_pBegin = p;
        }

        bool isValid() {

            if (m_pCurrent)
                return true;
            return false;
        }

    private:
        //?????? ?????? ??????, ???? ?? ????????? ????? ???????
        leaf *m_pBegin;
        // ?????? ??????? ?????????
        leaf *m_pCurrent;

        friend class CSingleLinkedList;
    };

public:

    CSingleLinkedList() : m_pBegin(0), m_pEnd(0) {}

    virtual ~CSingleLinkedList() {
        if (m_pBegin == m_pEnd) {
            delete m_pBegin;
            return;
        }

        leaf *tmp = m_pBegin;
        while (tmp) {
            m_pBegin = m_pBegin->pnext;
            delete tmp;
            tmp = m_pBegin;
        }
    }

    void pushBack(const T &data) {
        if (!m_pBegin) {
            m_pBegin = new leaf(data, nullptr);
            m_pEnd = m_pBegin;
        } else {
            m_pEnd->pnext = new leaf(data, nullptr);
            m_pEnd = m_pEnd->pnext;
        }
    }

    void pushFront(const T &data) {
        leaf *tmp = new leaf(data, m_pBegin);
        m_pBegin = tmp;
    }

    T popFront()   // ????????? ???? ??? ???? ?????????
    {
        if (m_pBegin) {
            T tmp = m_pBegin->data;

            leaf *secondLeaf = m_pBegin->pnext;
            delete m_pBegin;
            m_pBegin = secondLeaf;

            return tmp;
        } else throw "Eror! No element!";
    }

    // ???????? ????????? ?????????. ?????????? ?????????? ???????.
    void erase(CIterator &it) {
        leaf *tempLeaf = m_pBegin;
        leaf *previousLeaf = nullptr;

        if (m_pBegin == m_pEnd) {
            delete m_pBegin;

            m_pBegin = nullptr;
            m_pEnd = nullptr;

            return;
        }

        while (tempLeaf && tempLeaf != it.m_pCurrent) {
            previousLeaf = tempLeaf;
            tempLeaf = tempLeaf->pnext;
        }


        if (tempLeaf == m_pBegin) {
            m_pBegin = tempLeaf->pnext;
            delete it.m_pCurrent;
        } else if (tempLeaf == m_pEnd) {
            delete previousLeaf->pnext;
            previousLeaf->pnext = nullptr;
            m_pEnd = previousLeaf;
        } else {
            leaf *leafAfterIterator = it.m_pCurrent->pnext;

            previousLeaf->pnext = leafAfterIterator;

            delete it.m_pCurrent;
        }


        it.m_pCurrent = previousLeaf;
    }

    int getSize() {
        if (m_pBegin) {
            int count = 0;
            leaf *tmp = m_pBegin;

            while (tmp) {
                count++;
                tmp = tmp->pnext;
            }

            return count;
        }

        return 0;
    }

    void clear() {
        if (m_pBegin) {
            leaf *tmp;

            while (m_pBegin) {
                tmp = m_pBegin->pnext;
                delete m_pBegin;
                m_pBegin = tmp;
            }

            m_pEnd = nullptr;
        }

    }

    CIterator begin() {
        return CIterator(m_pBegin);
    }

private:
    leaf *m_pBegin, *m_pEnd;
};

#endif //UNTITLED1_SINGLELINKEDLIST_H
