package sandbox;

class hi {
    public static void main(String[] args) {
        String[] arr = getNames().split("\n");
        String[] arr2 = getNames2().split("\n");
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr2.length; j++) {
                if (arr[i].equals(arr2[j])) {
                    arr[i] = "";
                    arr2[j] = "";
                }
            }
        }
        //  print distinct names
        for (int i = 0; i < arr.length; i++) {
            if (!arr[i].equals(""))
                System.out.println(arr[i]);
        }

    }

    private static String getNames2() {
        String s = "Pritam\n" + 
                "Aman Anand\n" + 
                "Amritesh Indal\n" + 
                "Vibhu\n" + 
                "Krishna Patidar\n" + 
                "Anuj\n" + 
                "Prem B Shah\n" + 
                "prathmesh bhardwaj\n" + 
                "Archisman Midya\n" + 
                "Saksham jain\n" + 
                "THRISHAL\n" + 
                "Vijay gaurav kummetha\n" + 
                "Keshav Makkad\n" + 
                "Naresh Kumar Thodupunoori\n" + 
                "Shivam Tiwari\n" + 
                "Y N V S D L SANJANA\n" + 
                "Rudraksh Rankawat\n" + 
                "Aditya Jaiswal\n" + 
                "Vinay Kumar Reddy\n" + 
                "priyanshu baul majumder\n" + 
                "Arth\n" + 
                "Harshit\n" + 
                "Shruti Verma\n" + 
                "ABHINAV KUMAR JHA\n" + 
                "Arjun Ojha\n" + 
                "Sushant\n" + 
                "Arnavya Chettri\n" + 
                "V Shravanth\n" + 
                "Harsh kumar\n" + 
                "Sachin\n" + 
                "Karan Das A\n" + 
                "Neel Dholiya\n" + 
                "Amlan Buragohain\n" + 
                "Suraj Guduru\n" + 
                "narasimha\n" + 
                "Vishesh Paliwal\n" + 
                "Hemkesh kantawala\n" + 
                "Rajat Tyagi\n" + 
                "Srujan Reddy Dharma\n" + 
                "Mahak Juriani\n" + 
                "Naga Chaitanya\n" + 
                "Ajai Sharan\n" + 
                "Chikoti Ruthwik\n" + 
                "Nymish Kashivishwanath\n" + 
                "Ayush Kesharwani\n" + 
                "Himanshu Sainani\n" + 
                "srikrrishn choudhary\n" + 
                "Vatsal Omar\n" + 
                "Medha Shree\n" + 
                "Abhishek Kumar Shah\n" + 
                "Ayaan Khan\n" + 
                "Zaid Sharieff\n" + 
                "Aryan Choudhary\n" + 
                "Harsh Kumar\n" + 
                "Adarsh Singh Tomar\n" + 
                "Aman yadav\n" + 
                "Jenish Thapa\n" + 
                "Siddham Jain\n" + 
                "Tushar Khurana\n" + 
                "Sudharsan S\n" + 
                "Kushi Varadaraj\n" + 
                "Jiya Singhal\n" + 
                "Dipti Hatwar\n" + 
                "Harsh Kumar\n" + 
                "Abhinav Kumar Narayan\n" + 
                "Daksh Kanaujia\n" + 
                "Satish\n" + 
                "Pooja Talele\n" + 
                "Suryansh Shakya\n" + 
                "Vinayak Paka\n" + 
                "Varun Deep Saini\n" + 
                "Ansuman kumar\n" + 
                "Sourashis Sarkar\n" + 
                "KOHANTIKA NATH\n" + 
                "Krupakar Reddy\n" + 
                "Navneet\n" + 
                "Parth Arora\n" + 
                "Ishan Avasthi\n" + 
                "Abhinav Nagar\n" + 
                "Atharv sanjay jain\n" + 
                "Tejas Ghatule\n" + 
                "Lokendra Singh Rajawat\n" + 
                "Prince kumar\n" + 
                "K Manoj krishna\n" + 
                "Vikramaditya\n" + 
                "Siddharth R\n" + 
                "Tanvi Agarwal\n" + 
                "Syed Ayaan Ali\n" + 
                "MAYANK GUPTA\n" + 
                "Charanjeet\n" + 
                "Aatmik Panse\n" + 
                "Shrinibas Mahanta\n" + 
                "Sai Venkatesh Alampally\n" + 
                "Utkersh\n" + 
                "Bhavya Jain\n" + 
                "Spoorthy\n" + 
                "Sandip Dey\n" + 
                "HARSH KUMAR PANCHAL\n" + 
                "Nayanshi singh\n" + 
                "suraj kumar\n" + 
                "Shivam Goel\n" + 
                "SHRIMAY SOMANI\n" + 
                "Yashraj Sunil Kupekar\n" + 
                "Bhargav M\n" + 
                "Divyanshu Pandey\n" + 
                "Vivek Yadav\n" + 
                "Prashant Singh Chauhan\n" + 
                "Bishal Jena\n" + 
                "Abhinav Gupta\n" + 
                "SWARNIM\n" + 
                "Shivansh Singh\n" + 
                "Loukik\n" + 
                "Manish rachakonda\n" + 
                "GARVIT JAIN\n" + 
                "Daksh jain\n" + 
                "Harsh Kumar\n" + 
                "Shreshtha Sharma\n" + 
                "Deepak\n" + 
                "Nishant Dwivedi\n" + 
                "harshit sachan\n" + 
                "Harshit Goel\n" + 
                "Aniruddha patil\n" + 
                "Shreyas Garg\n" + 
                "Kumar Kartikay\n" + 
                "Tamanna Mohan\n" + 
                "Aditya Kumar Singh\n" + 
                "Siva Rama Krishna Gogineni\n" + 
                "Samrudh\n" + 
                "Naresh Biradar\n" + 
                "Arjun Kshirsagar\n" + 
                "kartik deshpande\n" + 
                "om Annasaheb waghchavare\n" + 
                "Rudra Kumar Chauhan\n" + 
                "UDIT KUMAR NAYAK\n" + 
                "Souvik Kumar\n" + 
                "Yash Agarwal\n" + 
                "Rohan Danny Skaria\n" + 
                "Pranav Aggarwal\n" + 
                "Aditya Prasad Dash\n" + 
                "Aditya singh\n" + 
                "Harshini Reddy Nellore\n" + 
                "Amrutha c a\n" + 
                "Thirunagari Rohith";
        return s;
    }

    private static String getNames() {
        String s = "Suraj Guduru\n" + 
                "Sudharsan S\n" + 
                "Krupakar Reddy\n" + 
                "GARVIT JAIN\n" + 
                "Chikoti Ruthwik\n" + 
                "Tushar Khurana\n" + 
                "Daksh Kanaujia\n" + 
                "MAYANK GUPTA\n" + 
                "Shivansh Singh\n" + 
                "suraj kumar\n" + 
                "Aditya Prasad Dash\n" + 
                "THRISHAL\n" + 
                "Satish\n" + 
                "Vikramaditya\n" + 
                "Aatmik Panse\n" + 
                "Abhinav Gupta\n" + 
                "Harsh Kumar\n" + 
                "Archisman Midya\n" + 
                "Keshav Makkad\n" + 
                "Naresh Kumar Thodupunoori\n" + 
                "Arth\n" + 
                "Neel Dholiya\n" + 
                "narasimha\n" + 
                "Vishesh Paliwal\n" + 
                "Hemkesh kantawala\n" + 
                "srikrrishn choudhary\n" + 
                "Zaid Sharieff\n" + 
                "Jenish Thapa\n" + 
                "Harsh Kumar\n" + 
                "Abhinav Kumar Narayan\n" + 
                "Suryansh Shakya\n" + 
                "Sourashis Sarkar\n" + 
                "Abhinav Nagar\n" + 
                "Prince kumar\n" + 
                "Sandip Dey\n" + 
                "Vivek Yadav\n" + 
                "Nishant Dwivedi\n" + 
                "Naresh Biradar\n" + 
                "Shivam Tiwari\n" + 
                "Tejas Ghatule\n" + 
                "harshit sachan\n" + 
                "Prem B Shah\n" + 
                "Sachin\n" + 
                "Srujan Reddy Dharma\n" + 
                "Mahak Juriani\n" + 
                "KOHANTIKA NATH\n" + 
                "Shrinibas Mahanta\n" + 
                "HARSH KUMAR PANCHAL\n" + 
                "SHRIMAY SOMANI\n" + 
                "Loukik\n" + 
                "Aditya Jaiswal\n" + 
                "Harsh Kumar\n" + 
                "Manish rachakonda\n" + 
                "Deepak\n" + 
                "Siva Rama Krishna Gogineni\n" + 
                "Rudra Kumar Chauhan\n" + 
                "Yash Agarwal\n" + 
                "Arnavya Chettri\n" + 
                "Bhargav M\n" + 
                "kartik deshpande\n" + 
                "Kushi Varadaraj\n" + 
                "Karan Das A\n" + 
                "Abhishek Kumar Shah\n" + 
                "Jiya Singhal\n" + 
                "Atharv sanjay jain\n" + 
                "Krishna Patidar\n" + 
                "Sushant\n" + 
                "Harsh kumar\n" + 
                "Utkersh\n" + 
                "Amritesh Indal\n" + 
                "Souvik Kumar\n" + 
                "Aniruddha patil\n" + 
                "Saksham jain\n" + 
                "Sai Venkatesh Alampally\n" + 
                "Vibhu\n" + 
                "Ajai Sharan\n" + 
                "Pooja Talele\n" + 
                "Aditya singh\n" + 
                "Arjun Ojha\n" + 
                "Vatsal Omar\n" + 
                "priyanshu baul majumder\n" + 
                "Naga Chaitanya\n" + 
                "Aman yadav\n" + 
                "Siddharth R\n" + 
                "prathmesh bhardwaj\n" + 
                "Y N V S D L SANJANA\n" + 
                "Bhavya Jain\n" + 
                "UDIT KUMAR NAYAK\n" + 
                "Harshit Goel\n" + 
                "Parth Arora\n" + 
                "Siddham Jain\n" + 
                "Harshit\n" + 
                "Ayaan Khan\n" + 
                "SWARNIM\n" + 
                "Kumar Kartikay\n" + 
                "Harshini Reddy Nellore\n" + 
                "Amrutha c a\n" + 
                "Amlan Buragohain\n" + 
                "Rajat Tyagi\n" + 
                "Bishal Jena\n" + 
                "Shivam Goel\n" + 
                "Dipti Hatwar\n" + 
                "Varun Deep Saini\n" + 
                "Lokendra Singh Rajawat\n" + 
                "Thirunagari Rohith\n" + 
                "Arjun Kshirsagar\n" + 
                "Vijay gaurav kummetha\n" + 
                "Samrudh\n" + 
                "Rohan Danny Skaria\n" + 
                "Yashraj Sunil Kupekar\n" + 
                "K Manoj krishna\n" + 
                "Vinayak Paka\n" + 
                "Shreshtha Sharma\n" + 
                "Anuj\n" + 
                "Ayush Kesharwani\n" + 
                "Prashant Singh Chauhan\n" + 
                "Himanshu Sainani\n" + 
                "Charanjeet\n" + 
                "V Shravanth\n" + 
                "Pritam\n" + 
                "Divyanshu Pandey\n" + 
                "Nymish Kashivishwanath\n" + 
                "Adarsh Singh Tomar\n" + 
                "Rudraksh Rankawat\n" + 
                "Nayanshi singh\n" + 
                "Aman Anand\n" + 
                "om Annasaheb waghchavare\n" + 
                "Ishan Avasthi\n" + 
                "Daksh jain\n" + 
                "Vinay Kumar Reddy\n" + 
                "Aditya Kumar Singh\n" + 
                "ABHINAV KUMAR JHA\n" + 
                "Medha Shree\n" + 
                "Aryan Choudhary\n" + 
                "Spoorthy\n" + 
                "Shreyas Garg\n" + 
                "Aayush Khopade\n" + 
                "Tamanna Mohan\n" + 
                "Shruti Verma\n" + 
                "Tanvi Agarwal\n" + 
                "Pranav Aggarwal\n" + 
                "Ansuman kumar\n" + 
                "Navneet\n" + 
                "Syed Ayaan Ali\n" + 
                "Keshav Agarwal";
        return s;
    }

}
