#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class User {
private:
    int  id;
    char name[40];
    char email[40];

public:
    User(int count) {
        id = count;
        name[0]  = '\0';
        email[0] = '\0';
    }

    int   getId()    { return id; }
    char* getName()  { return name; }
    char* getEmail() { return email; }

    void setName(const char* newName) {
        strncpy(this->name, newName, 39);
        this->name[39] = '\0';
    }

    void setEmail(const char* newEmail) {
        strncpy(this->email, newEmail, 39);
        this->email[39] = '\0';
    }

    void inputData() {
        char buf[40];
        printf("  Enter Name  : ");
        scanf("%39s", buf);
        setName(buf);
        printf("  Enter Email : ");
        scanf("%39s", buf);
        setEmail(buf);
    }

    void display() {
        printf("  | ID: %-3d | NAME: %-20s | EMAIL: %-30s |\n",
               id, name, email);
    }
};

class UserManager {
private:
    User** userList = NULL;
    int    count    = 0;

    int findIndexById(int id) {
        for (int i = 0; i < count; i++) {
            if (userList[i]->getId() == id)
                return i;
        }
        return -1;
    }

public:
    void addUser() {
        User* u = new User(count + 1);
        printf("\n[ ADD USER - ID: %d ]\n", count + 1);
        u->inputData();

        if (count == 0) {
            userList = (User**) calloc(1, sizeof(User*));
        } else {
            userList = (User**) realloc(userList, (count + 1) * sizeof(User*));
        }

        userList[count] = u;
        count++;
        printf("  >> User added successfully.\n");
    }

    void removeLastUser() {
        if (count == 0) {
            printf("\n[ REMOVE ] List is already empty.\n");
            return;
        }
        delete userList[count - 1];
        userList = (User**) realloc(userList, (count - 1) * sizeof(User*));
        count--;
        printf("\n[ REMOVE ] Last user removed successfully.\n");
    }

    void updateEmail(int id, const char* newEmail) {
        int index = findIndexById(id);
        if (index == -1) {
            printf("\n[ UPDATE ] User with ID %d not found.\n", id);
            return;
        }
        userList[index]->setEmail(newEmail);
        printf("\n[ UPDATE ] Email updated for ID %d.\n", id);
    }

    void updateName(int id, const char* newName) {
        int index = findIndexById(id);
        if (index == -1) {
            printf("\n[ UPDATE ] User with ID %d not found.\n", id);
            return;
        }
        userList[index]->setName(newName);
        printf("\n[ UPDATE ] Name updated for ID %d.\n", id);
    }

    void displayAll() {
        printf("\n[ USER LIST ]\n");
        if (count == 0) {
            printf("  (empty)\n");
            return;
        }
        printf("  +-------+----------------------+--------------------------------+\n");
        for (int i = 0; i < count; i++) {
            userList[i]->display();
        }
        printf("  +-------+----------------------+--------------------------------+\n");
        printf("  Total: %d user(s)\n", count);
    }

    int getCount() { return count; }

    ~UserManager() {
        for (int i = 0; i < count; i++) {
            delete userList[i];
        }
        free(userList);
    }
};

int main() {
    UserManager* um = new UserManager();

    um->addUser();
    um->addUser();
    um->updateEmail(1, "updated@example.com");
    um->updateName(2, "RenamedUser");
    um->displayAll();
    um->removeLastUser();
    um->displayAll();

    delete um;
    return 0;
}