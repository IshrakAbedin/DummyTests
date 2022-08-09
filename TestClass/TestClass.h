#pragma once

class ClassUnderTest
{
private:
    int m_Member1;
    int m_Member2;

public:
    inline ClassUnderTest(int m1, int m2) : m_Member1{m1}, m_Member2{m2} {}
    explicit inline ClassUnderTest(int m) : ClassUnderTest(m, m) {}
    inline ClassUnderTest() : ClassUnderTest(0, 0) {}

    inline int& m1() { return m_Member1; }
    inline int& m2() { return m_Member2; }

    inline bool operator==(const ClassUnderTest& other) const
    {
        return m_Member1 == other.m_Member1 && m_Member2 == other.m_Member2;
    }

    inline bool operator!=(const ClassUnderTest& other) const
    {
        return !(*this == other);
    }

    inline bool TakeAwayFromM1(int value)
    {
        if(value <= m_Member1)
        {
            m_Member1 -= value;
            return true;
        }
        else
            return false;
    }

    inline bool TakeAwayFromM2(int value)
    {
        if(value <= m_Member2)
        {
            m_Member2 -= value;
            return true;
        }
        else
            return false;
    }

    inline void IncreaseBoth(int value)
    {
        m_Member1 += value;
        m_Member2 += value;
    }
};