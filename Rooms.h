#ifndef ROOMS_H
#define ROOMS_H
#include <string>
#include <stdexcept>

namespace gl{
           class Rooms {
               private:
             
                     class innerRooms;
                     innerRooms *ptr;
             
                public:
                       
                     Rooms();
                     void init(int, const string&);
                     ~Rooms();
             
                     void setColour(const string&);
                     void setID(int);
             
                     string getColour() const; 
                     string getID() const;
             
                     void addRooms(string input);
                     void printRooms();
  
                     bool operator==(const  Rooms&) const;
                     bool operator!=(const  Rooms&) const;
                     bool operator>(const  Rooms&) const;
                     bool operator<(const  Rooms&) const;
                     bool operator>=(const  Rooms&) const;
                     bool operator<=(const  Rooms&) const; 
             
                     Rooms operator++();
                     Rooms operator++(int);
                     Rooms operator--();
                     Rooms operator--(int);
             
                     friend ostream &operator<<(ostream&, const Rooms&);
                     friend istream &operator>>(istream&, Rooms&);
	  }
  };
	
#endif
