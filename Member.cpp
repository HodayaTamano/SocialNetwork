#include <iostream>
#include "Member.h"

#include <set>

using namespace std;

int Member::counting = 0;
//constructor
Member::Member(){
    counting++;
}

//distractor
Member::~Member(){
    counting--;
    
    for(Member* m: Followers){
        m->unfollow(*this);
        this->unfollow(*m);
    }
    for(Member* m: Following){
        m->unfollow(*this);
        this->unfollow(*m);
    }
    
}
// follow
void Member::follow(Member& m){
    if (&m != this){
        Following.insert(&m);
        m.Followers.insert(this);
    }

    
    
}
// unfollow
void Member::unfollow(Member& m){
if (&m != this){
    Following.erase(&m);
    m.Followers.erase(this);
}
   
}

