//4.猫狗队列
#include<iostream>
#include<vector>
#include<stdexcept>
#include<queue>
#include<string>
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
class DogCatQueue{
    private:
        Pet pet;
        long count ;
    public:
        void EnterQueue(Pet pet ,long count )
        {
            this->pet = pet;//DogCatQueue.pet
            this->count = count ;//DogCatQueue.count
        }
        Pet GetPet()
        {
            return this->pet;
        }
        long GetCount()
        {
            return this->count;
        }
        string GetEnterType()
        {
            return this->pet.GetType();
        }
};


class PetQueue
{
    private:
        queue<DogCatQueue> Dog;
        queue<DogCatQueue> Cat;
        long count ;
        Pet p;//暂存队首元素
    public:
        //构造函数
        PetQueue()
        {//开辟内存空间，count赋初值
            this.Dog = new queue<PetEnterQueue>;
            this.Cat = new queue<PetEnterQueue>;
            this.count = 0 ;
        }
        //猫狗入栈函数
        void Add()
        {
            if(pet.GetType() == "dog")
            {
                //推入狗队
                this.Dog.push(new PetEnterQueue(pet, this.count++));

            }
            else if (pet.GetType() == "cat")
            {
                //推入猫队
                this.Cat.push( new PetEnterQueue (pet,this.count++));
            }
            else
            {
                throw out_of_range("No cat or dog");
            }
        }
        //猫狗全部出队
        Pet PollAll()
        {
            if(!this.Dog.empty() && !this.Cat.empty())
            {
                if(this.Dog.front().GetCount() < this.Cat.front().GetCount())
                {
                    PullDog();
                }
            }
            else if(!this.Dog.empty())
            {
                PollDog();
            }
            else if(!this.Cat.empty())
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
            if(!this->Dog.empty())
            {
                p = this->Dog.front().GetPet();//暂存队首元素
                this->Dog.pop();//出队
                return p ;

            }
            else
            {
                throw out_of_range("Dog Queue is empty!");
            }
        }

        //猫队出队
        Cat *PollCat()
        {
            if(!this->Cat.empty())
            {
                p = this->Cat.front().GetPet();//暂存队首元素
                this->Cat.pop();//出队
                return p ;

            }
            else
            {
                throw out_of_range("Dog Queue is empty!");
            }
        }


        //检查队列中是否有Cat或Dog类实例
        bool Empty()
        {
            return this->Dog.Empty() && this.Cat.Empty();
        }
        //检查队列中是否有Cat类实例
        bool CatQEmpty()
        {
            return this->Dog.Empty();
        }
        //检查队列中是否有Dog类实例
        bool DogQEmpty()
        {
            return this->Cat.Empty();
        }
};


int main()
{
    return 0;
}
