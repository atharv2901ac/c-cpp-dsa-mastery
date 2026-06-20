#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>

class Sales{
    private:
        int id;
        std::string product;
        int price;
        std::string buyer;
    public:
        Sales(int count){
            id = count;
            price = 0;
        }
        void print(){
            printf("| ID: %d | PRODUCT: %s | PRICE: %d | BUYER: %s |\n",
                   id, product.c_str(), price, buyer.c_str());
        }
        int getId(){
            return id;
        }
        std::string getBuyerName(){
            return buyer;
        }
        void setName(char* name){
            buyer = name;
        }
        void acceptData(){
            char buf[256];

            printf("ENTER THE PRODUCT'S NAME: ");
            scanf("%255s", buf);
            product = buf;

            printf("ENTER THE PRICE OF THE PRODUCT: ");
            scanf("%d", &price);

            printf("ENTER THE BUYER'S NAME: ");
            scanf("%255s", buf);
            buyer = buf;
        }
};

class ProductManager{
    private:
        Sales** productlist = NULL;
        int count = 0;
    public:
        void addEntry(){
            Sales* s = new Sales(count+1);
            if(productlist == NULL){
                productlist = (Sales**) calloc(count+1, sizeof(Sales*));
            }
            else{
                productlist = (Sales**) realloc(productlist, (count+1)*sizeof(Sales*));
            }
            productlist[count] = s;
            productlist[count]->acceptData();
            count++;
        }
        void remove(){
            if(count != 0){
                delete productlist[count-1];
                productlist = (Sales**) realloc(productlist, (count-1)*sizeof(Sales*));
                count--;
            }
            else{
                printf("CANNOT PERFORM THE GIVEN ACTIONS :(\n");
            }
        }
        int getProIndex(int id){
            int index = -1;
            for(int i = 0; i < count; i++){
                if(productlist[i]->getId() == id){
                    index = i;
                }
            }
            return index;
        }
        void printList(){
            if(count == 0){
                printf("LIST IS EMPTY\n");
            }
            else{
                for(int j = 0; j < count; j++){
                    productlist[j]->print();
                }
            }
        }
};

int main(int argc, char const *argv[])
{
    ProductManager* pm = new ProductManager();
    pm->addEntry();
    pm->addEntry();
    pm->addEntry();
    pm->addEntry();
    pm->addEntry();
    pm->addEntry();
    pm->remove();
    pm->printList();
    delete pm;
    return 0;
}