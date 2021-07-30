#include"global.h"

using namespace std;
class User{
    public:
    User(int id,string name):_id(id),_name(name){}
    int id(){return _id;}
    string name(){return _name;}
    void stat(){cout<<to_string(_id)<<" "<<_name<<endl;}
    private:
    int _id;
    string _name;
};