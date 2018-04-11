#include <iostream>
#include "Member.h"
#include <set>

using namespace std;

int Member::counting = 0;

Member::Member(){
    counting++;
}
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

void Member::follow(Member& m){
    if (m != this){
        Following.insert(&m);
        m.Followers.insert(this);
    }

    // this->Following++;
    // m.Followers++;

    
}

void Member::unfollow(Member& m){

    Following.erase(&m);
    m.Followers.erase(this);

    // this->Following--;
    // m.Followers--;
    
}
// int Member::numFollowers(){
//     return numFollowers;
// }

// int Member::numFollowing(){
//     return numFollowing;
// }


