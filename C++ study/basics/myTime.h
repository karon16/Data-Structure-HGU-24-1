//
// Created by Christopher Buhendwa on 4/3/24.
//

#ifndef C_STUDY_TIME_H
#define C_STUDY_TIME_H


// Specification file (Time.h)
class Time // Declares a class data type
{ // does not allocate memory
private : // Three private data members
    int hrs;
    int mins;
    int secs;
public : // Five public function members
    void Set (int hours , int mins , int secs);
    void Increment ();
    void Write () const;
    bool Equal (Time otherTime) const;
    bool LessThan (Time otherTime) const;
};


#endif //C_STUDY_TIME_H
