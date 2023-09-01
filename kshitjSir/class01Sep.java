class Circle
{
    int r;
    float pi=3.14f;
    Circle(int r)
    {
        this.r=r;
    }
    float getArea()
    {
        return pi*r*r;
    }
    float getPerimeter()
    {
        return 2*pi*r;
    }
    boolean equals(Circle c)
    {
        if(r==c.r)
            return true;
        else
            return false;
    }
}
class rectangle
{
    int l,b;
    rectangle(int l,int b)
    {
        this.l=l;
        this.b=b;
    }
    int getArea()
    {
        return l*b;
    }
    int getPerimeter()
    {
        return 2*(l+b);
    }
    boolean equals(rectangle r)
    {
        if(this.l==r.l && this.b==r.b)
            return true;
        else
            return false;
    }
    boolean isSquare()
    {
        if(l==b)
            return true;
        else
            return false;
    }
}
public class class01Sep
{
    public static void main(String[] args) 
    {
        // Circle c1=new Circle(5);
        // Circle c2=new Circle(6);
        // System.out.println("Area of circle is "+c1.getArea());
        // System.out.println("Area of circle is "+c2.getArea());
        // System.out.println("Perimeter of circle is "+c2.getPerimeter());
        // System.out.println("Perimeter of circle is "+c1.getPerimeter());
        rectangle r1=new rectangle(5,6);
        rectangle r2=new rectangle(5,6);
        System.out.println("Area of rectangle is "+r1.getArea());
        System.out.println("Area of rectangle is "+r2.getArea());
        System.out.println("Perimeter of rectangle is "+r1.getPerimeter());
        System.out.println("Perimeter of rectangle is "+r2.getPerimeter());
        
    }
}