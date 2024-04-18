// package kshitjSir;

class person {
    String name;
    int age;

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

public class diwakarSir08Sep {
    public static void main(String[] args) {
        person p1 = new person();
        person p2 = new person();
        p1.age = 10;
        p2.age = 20;
        p1.name = "Kshitij Sir";
        p2.name = "Diwakar Sir";
        swap(p1, p2);
        p1.display();
        p2.display();
    }

    static void swap(person p1, person p2) {
        person temp = p1;
        p1 = p2;
        p2 = temp;
    }
}
