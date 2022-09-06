class Person implements Comparable<Person> {
    String name;
    int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        return this.age;
    }

    @Override
    public int compareTo(Person o) {
        // TODO Auto-generated method stub
        return 0;
    }
}

interface B {

}

abstract class C {

}

public class Test {
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
