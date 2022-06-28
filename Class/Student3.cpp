class Student3
{
    static int totalstudents;

public:
    int rollnumber;
    int age;

    Student3(){
        totalstudents++;
    }

    int getrollnumber(){
        return rollnumber;
    }

    static int gettotalstudents(){
        return totalstudents;
    }
};

int Student3 :: totalstudents = 0;

