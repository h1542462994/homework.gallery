class Student {
public:
    Student(int n, float s) :num(n), score(s) {}
    void change(int n, float s);
    void display() const ;
private:
    int num;
    float score;
};