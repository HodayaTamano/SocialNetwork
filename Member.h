#pragma once
#include <set>
using namespace std;

class Member{
private:
    set <Member*> Following;
    set <Member*> Followers;
    static int counting;
public:
    Member();
    void follow (Member& member);
    void unfollow (Member& member);
    // void setFollowers(int f1);
    // void setFollowing(int f2);
    // int getFollowers();
    // int getFollowing();
    int numFollowers() const{ return Followers.size(); }
    int numFollowing() const{ return Following.size(); }
    static int count (){ return counting; }
    ~Member();
    
};