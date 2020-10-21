using System;
using System.Reflection;

namespace exp3 {
    public abstract class Animal {
        protected string Name {get;set;}
        public abstract void Bark();
    }

    public class Cat : Animal
    {
        public Cat(string name){
            this.Name = name;
        }
        public override void Bark()
        {
            System.Console.WriteLine($"cat {Name}: miao~~");
        }
    }

    public class Dog : Animal
    {
        public Dog(string name){
            this.Name = name;
        }
        public override void Bark()
        {
            System.Console.WriteLine($"dog {Name}: wang wang ~~");
        }
    }

    public class Cow : Animal 
    {
        public Cow(string name){
            this.Name = name;
        }
        public override void Bark()
        {
            System.Console.WriteLine($"cow {Name}: mou mou~");
        }
    }

    public class AnimalFactory {
        public Animal Create<T>(string name) where T: Animal {
            Animal animal = (Animal)Activator.CreateInstance(typeof(T),args: new object[]{name});
            return animal;
        }
    }

    class Program {
        
        
        public static void Main(){
            AnimalFactory animalFactory = new AnimalFactory();
            Animal animal;
            animal = animalFactory.Create<Cat>("a");
            animal.Bark();
            animal = animalFactory.Create<Dog>("b");
            animal.Bark();
            animal = animalFactory.Create<Cow>("c");
            animal.Bark();
        }
    }
}