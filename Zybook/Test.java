import java.util.Random;

class Person implements Comparable<Person> {
    String name;
    int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        Random rand = new Random();
        int x = rand.nextInt(2);
        return x;
    }

    @Override
    public int compareTo(Person o) {
        // TODO Auto-generated method stub
        if (this.name.equals(o.name)) {

        }
        return 0;
    }
}

interface B {

}

abstract class C {

}

class A {
    int a;

    public A(int a) {
        this.a = a;

        if (this.a == 2) {

        }
    }
}

class BC extends A {
    public BC() {
        super(5);
        if (true) {

        }
    }
}

public class Test extends C {
    public static void main(String[] args) {
        System.out.println("hi");
        Person a = new Person("Sebastian", 20);
        System.out.println(a.age);
    }

    @Override
    public String toString() {
        return "";
    }
}
