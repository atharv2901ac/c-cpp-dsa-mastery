#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string_view>
class User{
    private:
    int id;
    char name[40];
    char email[40];

    public:

    User(int count){
        id = count; 
    }

    // print user
    void print(){
        printf("id:%d,name:%s,email:%s\n",id,name,email);
    }

    char* getEmail(){
       return email;
    }

    void setEmail(std::string_view email){
        email = email;
    }

    int getId(){
        return id;
    }

    char* getName(){
        return name;
    }

    void setName(char* name){
          name = name;
    }

    void acceptData(){
        printf("enter name:");
        scanf("%s",name);
        printf("enter email:");
        scanf("%s",email);
    }

    //
};

class UserManager{
    private:
    // User* userlist[5];
    User** userlist = NULL;
    int count = 0;
  
    public:
   // add user
   void add()
   {
        User* u  = new User(count+1);
        u->acceptData();
       if(count == 0){
       userlist =(User**)calloc(count+1,sizeof(User*));
       }else{
        userlist =(User**) realloc(userlist,(count+1)*sizeof(User*));
       }
        userlist[count] = u;
        count++;
   }
   // remove user
   void remove(){
        if(count!=0){
            userlist =(User **) realloc(userlist,(count-1)*sizeof(User*));
            count--;
        }else{
            printf("can not perform remove as list is empty");
        }
   }

    int getUserIndexById(int id){
        int index = -1;
        for(int i=0;i<count;i++){
            if(userlist[i]->getId()==id){
               index = i;
            }
        }
        return index;
    }

   // update user
   void updateEmail(int id, char* newEmail){
        int index = getUserIndexById(id);
        User* u =userlist[index];
        u->setEmail(newEmail);
   }
   
   // print list users
   void printList(){
    if(count == 0){
        printf("list is empty");
    }else{
        for(int i=0;i<count;i++){
            userlist[i]->print();
        }
    }
   }

   int getCount(){
    return count;
   }


};

int main(int argc, char const *argv[])
{
   // Userlist
   UserManager* um = new UserManager();
   um->add();
//    um->add();
//    um->remove();
   um->updateEmail(1,"demo2");
   um->printList();
  
}