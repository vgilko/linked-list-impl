//
// Created by avmd on 28.02.23.
//

#ifndef UNTITLED1_DUALLINKEDLIST_H
#define UNTITLED1_DUALLINKEDLIST_H

template<class T>
class CDualLinkedList {
private:
    struct leaf {
        T data;
        leaf *pnext, *pprev;

        leaf(const T &_data, leaf *_pnext, leaf *_pprev) : data(_data), pnext(_pnext), pprev(_pprev) {
        }
    };

public:
    class CIterator {
    public:
        CIterator(leaf *p) {
            if (p->pprev != nullptr)
                m_pBegin = p->pprev;
            else if (p->pnext == nullptr)
                m_pEnd = p->pnext;

            m_pBegin = p->pnext;
            m_pCurrent = p;
        }

        CIterator(const CIterator &src) {
            m_pBegin = src.m_pBegin;
            m_pCurrent = src.m_pCurrent;
            m_pEnd = src.m_pEnd;
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

            m_pCurrent = m_pBegin;
            if (m_pBegin)
                m_pBegin = m_pBegin->pnext;
        }

        void operator--() {
            m_pCurrent = m_pCurrent->pprev;
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

        explicit operator bool() const {
            if (m_pCurrent != nullptr)
                return true;
            else
                return false;
        }

        leaf *getLeaf() {
            if (m_pCurrent)
                return m_pCurrent;
            return 0;
        }

        // ??????????? ? erase ? eraseAndNext
        void setLeaf(leaf *p) {
            m_pCurrent = p;
        }

        // ??????????? ? erase ? eraseAndNext
        void setLeafPreBegin(leaf *p) {
            m_pBegin = p;
        }

        // ??????????? ? erase ? eraseAndNext
        void setLeafPostEnd(leaf *p) {
            m_pEnd = p;
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
        //?????? ????? ??????, ???? ?? ????????? ????? ?????
        leaf *m_pEnd;

        friend class CDualLinkedList;
    };

public:

    CDualLinkedList() : m_pBegin(nullptr), m_pEnd(nullptr) {
    };

    virtual ~CDualLinkedList() {
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
    };

    void pushBack(const T &data) {
        if (!m_pBegin) {
            m_pBegin = new leaf(data, nullptr, nullptr);
            m_pEnd = m_pBegin;
        } else {
            m_pEnd->pnext = new leaf(data, nullptr, m_pEnd);
            m_pEnd = m_pEnd->pnext;
        }
    }

    T popBack() {
        if (getSize()) {
            T deletedLeafData = m_pEnd->data;

            if (m_pBegin == m_pEnd) {
                delete m_pBegin;

                m_pBegin = nullptr;
                m_pEnd = nullptr;
            } else {
                leaf *tempLeaf = m_pEnd;

                m_pEnd = tempLeaf->pprev;
                m_pEnd->pnext = nullptr;

                delete tempLeaf;
            }

            return deletedLeafData;
        }

        throw std::runtime_error("Error! No element!");
    }

    void pushFront(const T &data) {
        if (!m_pBegin) {
            m_pBegin = new leaf(data, nullptr, nullptr);
            m_pEnd = m_pBegin;
        } else {
            leaf *pn = new leaf(data, m_pBegin, nullptr);
            m_pBegin->pprev = pn;
            m_pBegin = pn;
        }

    }

    T popFront() {
        if (getSize()) {
            T deletedLeafData = m_pBegin->data;

            if (m_pBegin == m_pEnd) {
                delete m_pBegin;

                m_pBegin = nullptr;
                m_pEnd = nullptr;
            } else {
                leaf *tempLeaf = m_pBegin;

                m_pBegin = m_pBegin->pnext;
                m_pBegin->pprev = nullptr;

                delete tempLeaf;
            }

            return deletedLeafData;
        }

        throw std::runtime_error("Error! No element!");
    }

    // ???????? ????????? ?????????. ?????????? ?????????? ???????.
    void erase(CIterator &it) {
        if (it) {
            leaf *tmpprev = it.m_pCurrent->pprev;
            leaf *tmpnext = it.m_pCurrent->pnext;
            if (tmpprev)
                tmpprev->pnext = tmpnext;
            else
                m_pBegin = tmpnext;
            if (tmpnext)
                tmpnext->pprev = tmpprev;
            delete it.m_pCurrent;
            it.m_pCurrent = tmpprev;
        }
    }

    // ???????? ????????? ?????????. ?????????? ????????? ???????.
    void eraseAndNext(CIterator &it) {
        leaf *previousLeaf = it.m_pCurrent->pprev;
        leaf *nextLeaf = it.m_pCurrent->pnext;

        if (m_pBegin == m_pEnd) {
            delete it.m_pCurrent;
            it.m_pCurrent = nullptr;

            m_pBegin = nullptr;
            m_pEnd = nullptr;

            return;
        }

        if (it.m_pCurrent == m_pEnd) {
            previousLeaf->pnext = nullptr;
            m_pEnd = previousLeaf;

            delete it.m_pCurrent;
            it.m_pCurrent = nullptr;
        } else if (it.m_pCurrent == m_pBegin) {
            nextLeaf->pprev = nullptr;
            m_pBegin = nextLeaf;

            delete it.m_pCurrent;
            it.m_pCurrent = m_pBegin;
        } else {
            previousLeaf->pnext = nextLeaf;
            nextLeaf->pprev = previousLeaf;

            delete it.m_pCurrent;
            it.m_pCurrent = nextLeaf;
        }
    }

    int getSize() {
        int count = 0;

        if (m_pBegin) {
            leaf *tmp = m_pBegin;

            while (tmp) {
                count++;
                tmp = tmp->pnext;
            }
        }

        return count;

    }

    void clear() {
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

    CIterator begin() {
        return CIterator(m_pBegin);
    }

    CIterator end() {
        return CIterator(m_pEnd);
    }

private:
    leaf *m_pBegin, *m_pEnd;
};

#endif //UNTITLED1_DUALLINKEDLIST_H
