package kshitjSir;

class user
{
    //private
    private String name;
    private String email;
    private String phone;
    private String pincode;

    
    // constructor
    public user(String name, String email, String phone, String pincode)
    {
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.pincode = pincode;
    }

    //from same city
    boolean sameCity(user u)
    {
        if(this.pincode.equals(u.pincode))
            return true;
        else
            return false;
    }
    //getters
    String getName()
    {
        return this.name;
    }
    String getEmail()
    {
        return this.email;
    }
    String getPhone()
    {
        return this.phone;
    }
    String getPincode()
    {
        return this.pincode;
    }
    //setters
    void setName(String name)
    {
        this.name = name;
    }
    void setEmail(String email)
    {
        this.email = email;
    }
    void setPhone(String phone)
    {
        this.phone = phone;
    }
    void setPincode(String pincode)
    {
        this.pincode = pincode;
    }

    //print profile
    public void printProfile() {
        System.out.println("Name: " + this.name);
        System.out.println("Email: " + this.email);
        System.out.println("Phone: " + this.phone);
    }
    //get 
}
class Student extends user {
    private String mentoremail;
    private int scholership;
    private double cgr;
    
    
    Student(String name, String email, String phone, String pincode, int scholership, double cgr){
        super(name, email, phone, pincode);
        this.scholership = scholership;
        this.cgr = cgr;
    }
    //setters
        void setMentorEmail(user u)
        {
            this.mentoremail = u.getEmail();
        }
        void setMentorEmail(String mentoremail)
        {
            this.mentoremail = mentoremail;
        }
        void setCgr(double cgr)
        {
            this.cgr = cgr;
        }

    //getters
        String getMentorEmail()
        {
            return this.mentoremail;
        }
        void setScholership(int scholership)
        {
            this.scholership = scholership;
        }
        int getScholership()
        {
            return this.scholership;
        }
        double getCgr()
        {
            return this.cgr;
        }

    double annualfee()
    {
        double fee = 5e5;
        if(this.scholership > 0 && this.scholership <= 100)
            fee = fee - (fee * this.scholership)/100;
        return fee;
    }
    //print profile
    // public void printProfile() {
    //     System.out.println("Name: " + this.getName());
    //     System.out.println("Email: " + this.getEmail());
    //     System.out.println("Phone: " + this.getPhone());
    // }
    // public void printProfile() {
    //     super.printProfile();
    //     System.out.println("Scholership: " + this.scholership);
    //     System.out.println("CGPA: " + this.cgr);
    // }


}
class Mentor extends user{

    String company;
    String jobProfile;
    int YOE; 
    public Mentor(String name, String email, String phone, String pincode, String company, String jobProfile, int YOE)
    {
        super(name, email, phone, pincode);
        this.company = company;
        this.jobProfile = jobProfile;
        this.YOE = YOE;
    }
    //print profile
    // public void printProfile() {
    //     System.out.println("Name: " + this.getName());
    //     System.out.println("Email: " + this.getEmail());
    //     System.out.println("Phone: " + this.getPhone());
    // }
}

class StudentData05Sep{
    public static void main(String[] args) {
        Student s1 = new Student("abhishek", "abhishek@google.com" , "9876543210", "123456", 50, 8.5);
        Mentor m1 = new Mentor("mentor", "mentor@eg.com", "1234567890", "123456", "google", "SDE", 5);
        s1.printProfile();
        m1.printProfile();
        //same city
        System.out.println(s1.sameCity(m1));
    }
}
