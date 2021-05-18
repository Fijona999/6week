#include <iostream>
#include <vector>
#include< iomanip>
#include <time.h>
#include <string>
#include <sstream>
#include <stdexcept>

#include <Rooms.h>

using namespace std;

namespace gl{
    class Rooms::innerRooms{
      string colour;
      friend class Rooms;
      vector<string> Rooms;
      int ID;
  };
  
   int Rooms::inerRooms::idCount = 0;
    
   Rooms::Rooms()
   {
    ptr=NULL;
   }

   void Rooms::init(int idCount, const string &colour)
    {
     setidCount(idCount);
     setColour(colour);
    }
  
   Rooms::~Rooms()
    {
      --innerRooms::idCount;
        delete ptr;
     }

    void setColour(const string &colour)
    {
        if(ptr == NULL){
          ptr = new innerRooms();
        }
      this->ptr->colour = colour;
    }
  
     void Rooms::setID(int ID)
    {
        if(ptr == NULL){
            ptr = new innerRooms();
        }
        this->ptr->ID = ID;
    } 
  
    string Rooms::getColour() const
    { 
       if(ptr == NULL){
          throw logic_error("No inner");
       }
      return ptr->colour;
    }

    int Rooms::ID() const
    {
        if(ptr == NULL){
            throw logic-error("no Inner");
        }
        return ptr->ID;
        
    void Rooms::addRooms(string input)
    {
        rooms.push_back(input);
    }
    void Rooms::printRooms() const
    {
        if(ptr == NULL){
          throw logic_error("No int");
        }
        
        cout << colour << " ";
        for (int i = 0; i < Rooms.size(); ++i)
        {
            cout << Rooms[i]<<" ";
        }
        
        cout << endl;
        
        ostringstream  oss;
        oss << "Colour: " << getColour() << endl;
        oss << " " << getidCount() << endl;
        return oss.str();
    }
    
    bool Rooms::operator!=(const Rooms &other) const{
      if(colour==other.colour){
        return true;
        }else{
          return false;
          }
         }
         
     bool Rooms::operator!=(const Rooms &other) const{
    return !(*this == other);
}

    bool Rooms::operator>(const Rooms &other) const{
    if(colour > other.colour){
        return true;
    }else{
        return false;
    }
}

   bool Rooms::operator<(const Rooms &other) const{
    return other > *this;
}

   bool Rooms::operator>=(const Rooms &other) const{
    if(*this ==other){
        return true;
    }else{
        return *this > other;
    }
}

   bool Rooms::operator<=(const Rooms &other) const{
    if(*this ==other){
        return true;
    }else{
        return *this < other;
    }
}

  Rooms Rooms::operator++(){
    ++colour;
    return *this;
}

 Rooms Rooms::operator++(int){
    Rooms temp = *this;
    ++colour;
    return temp;
}

  Rooms Rooms::operator--(){
    --colour;
    return *this;
}

   Rooms Rooms::operator--(int){
    Rooms temp = *this;
    --colour;
    return temp;
}    

  istream& operator >> (istream &is, Rooms &is_Rooms){
   string t_colour;
   int temp_Rooms;
   int temp_ID;
   
  is >>temp_ID >> temp_colour >> temp_Rooms;
  is_Rooms.int(temp_ID ,temp_colour, temp_Rooms);
  
  return is;
  }

  ostream& operator<<(ostream &os, const Rooms &os_Rooms){
    os << os_Rooms.printRooms();
    return os;
    }
    

    
};
