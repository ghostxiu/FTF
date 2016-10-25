//4.猫狗队列
#include<iostream>
#include<vector>
#include<stdexcept>
#include<queue>
using namespace std;
class Pet{
    private:
        string type;
    public:
        Pet(const string &type) :type(type){}
        string &GetType()
        {
            return this->type;
        }
};
class Dog:public Pet{
    public:
        Dog():Pet("dog")
        {

        }
};
class Cat:public Pet{
    public:
        Cat():Pet("cat")
        {

        }
};


//自己写
class PetEnterQueue{
    private:
        Pet *pet;
        long count ;
    public:
        //构造函数
        PetEnterQueue(Pet *pet,long count)
        :pet(pet),count(count)
            {

            }
        Pet *GetPet()
        {
            return this->pet;
        }
        long GetCount()
        {
            return this->count;
        }
        string &GetEnterType()
        {
            return this->pet->GetType();
        }
};


class PetQueue
{
    private:
        queue<PetEnterQueue *> DogQ;
        queue<PetEnterQueue *> CatQ;
        long count;
    public:
        //构造函数
        PetQueue(long count = 0):count(count)
        {//开辟内存空间，count赋初值
        }
        //猫狗入栈函数
        void Add(Pet *pet)
        {
            if(pet->GetType() == "dog")
            {
                //推入狗队
                this->DogQ.push(new PetEnterQueue(pet, count++));

            }
            else if (pet->GetType() == "cat")
            {
                //推入猫队
                this->CatQ.push( new PetEnterQueue (pet,count++));
            }
            else
            {
                throw out_of_range("No cat or dog");
            }
        }
        //猫狗全部出队
        Pet PollAll()
        {
            if(!this->DogQ.empty() && !this->CatQ.empty())
            {
                if(this->DogQ.front()->GetCount() < this->CatQ.front()->GetCount())
                {
                    PollDog();
                }
            }
            else if(!this->DogQ.empty())
            {
                PollDog();
            }
            else if(!this->CatQ.empty())
            {
                PollCat();
            }
            else
            {
                throw out_of_range("No cat or dog!");
            }
        }

        //狗队出队
        Dog *PollDog()
        {
            if(!this->DogQ.empty())
            {
                Dog *d = (Dog *)this->DogQ.front()->GetPet();//暂存队首元素
                this->DogQ.pop();//出队
                return d ;

            }
            else
            {
                throw out_of_range("Dog Queue is empty!");
            }
        }

        //猫队出队
        Cat *PollCat()
        {
            if(!this->CatQ.empty())
            {
                Cat *c = (Cat *)this->CatQ.front()->GetPet();//暂存队首元素
                this->CatQ.pop();//出队
                return c ;

            }
            else
            {
                throw out_of_range("Cat Queue is empty!");
            }
        }


        //检查队列中是否有Cat或Dog类实例
        bool Empty()
        {
            return this->DogQEmpty() && this->CatQEmpty();
        }
        //检查队列中是否有Cat类实例
        bool CatQEmpty()
        {
            return this->DogQ.empty();
        }
        //检查队列中是否有Dog类实例
        bool DogQEmpty()
        {
            return this->CatQ.empty();
        }
};


int main()
{
    return 0;
}
